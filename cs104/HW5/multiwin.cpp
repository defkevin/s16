#include "multiwin.h"
#include <QHBoxLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <cassert>
#include <iostream>
#include <set>
#include <QLineEdit>

using namespace std;

string GetTimestamp() {
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  char buffer[80];
  strftime(buffer, 80, "%F %T", timeinfo);

  string ts(buffer);
  return ts;
}

Multiwin::Multiwin(TwitEng* twitEng) : QWidget(NULL), twit_eng_(twitEng), currentUser_(nullptr) {
  // create main layout
  QVBoxLayout* mainLayout = new QVBoxLayout;
  setLayout(mainLayout);

  // create the Upper General User layout.
  QHBoxLayout* mainUserLayout = new QHBoxLayout;
  mainLayout->addLayout(mainUserLayout);

  // Create the user-list layout.
  QVBoxLayout* userLayout = new QVBoxLayout;
  userLayout->addWidget(new QLabel("Users", this));

  QListWidget* userListWidget = new QListWidget(this);
  vector<User*> users = twit_eng_->getUsers();
  for (size_t i = 0; i < users.size(); i++) {
    string username = users[i]->getName();
    new QListWidgetItem(username.c_str(), userListWidget);
  }
  userLayout->addWidget(userListWidget);
  

  mainUserLayout->addLayout(userLayout);



  // Add the followers layout.
  QVBoxLayout* followersLayout = new QVBoxLayout;
  followersLayout->addWidget(new QLabel("Followers", this));
  followersWidget_ = new QListWidget(this);
  followersLayout->addWidget(followersWidget_);

  mainUserLayout->addLayout(followersLayout);

  // Add the following layout.
  
  QVBoxLayout* followingLayout = new QVBoxLayout;

  followingLayout->addWidget(new QLabel("Following", this));

   followingEdit_ = new QLineEdit(this);
  followingEdit_->setPlaceholderText("Add User To Follow: ");

  followingLayout->addWidget(followingEdit_);
  followingWidget_ = new QListWidget(this);
  followingLayout->addWidget(followingWidget_);


  mainUserLayout->addLayout(followingLayout);

  // Add tweet box.
  tweetLineEdit_ = new QLineEdit(this);
  tweetLineEdit_->setPlaceholderText("Add tweet ...");
  mainLayout->addWidget(tweetLineEdit_);

    // Below Main User Layout Create the feed layout.
  QVBoxLayout* feedLayout = new QVBoxLayout;
  feedLayout->addWidget(new QLabel("User Feed", this));
  feedListWidget_ = new QListWidget(this);
  feedLayout->addWidget(feedListWidget_);

  mainLayout->addLayout(feedLayout);

  // Below Feed Layout create the Button Layout

  QHBoxLayout* buttonLayout = new QHBoxLayout;

  searchLineEdit_ = new QLineEdit(this);
  searchLineEdit_->setFixedWidth(250);
  
  searchLineEdit_->setPlaceholderText("Search Tags...");
  buttonLayout->addWidget(searchLineEdit_);

   QPushButton* outputFeedsButton = new QPushButton("&Output Feeds");
  buttonLayout->addWidget(outputFeedsButton);

  QPushButton* quitButton = new QPushButton("&Quit");
  buttonLayout->addWidget(quitButton);

  mainLayout->addLayout(buttonLayout);

  tagSearchListWidget_ = new QListWidget(this);
  QVBoxLayout* otherLayout= new QVBoxLayout;
  searchTagWin_ = new QWidget;
  otherLayout->addWidget(tagSearchListWidget_);
  searchTagWin_->setLayout(otherLayout);
  searchTagWin_->setFixedSize(700,100);


  QObject::connect(outputFeedsButton, SIGNAL(clicked()), this,
                   SLOT(outputFeedsButtonClicked()));
  QObject::connect(userListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this,
                   SLOT(setCurrentUser(QListWidgetItem*)));
  QObject::connect(tweetLineEdit_, SIGNAL(returnPressed()), this,
                   SLOT(newTweet()));
  QObject::connect(quitButton, SIGNAL(clicked()), this,
                   SLOT(close()));
  QObject::connect(followingEdit_, SIGNAL(returnPressed()), this,
                   SLOT(addFollowing()));
  QObject::connect(searchLineEdit_, SIGNAL(returnPressed()), this,
                   SLOT(searchTag()));

}

  void Multiwin::searchTag(){
  	searchTagWin_->close();
  	string tag = searchLineEdit_->text().toStdString();
  	searchLineEdit_->clear();
  	tagSearchListWidget_->clear();

  	std::set<const Tweet*> tags = twit_eng_->getTag(tag);
  	set<const Tweet*>::const_iterator it;
  	for(it = tags.begin();it!=tags.end();it++){
  		string text = (*it)->to_string();
  		cout << "Found tweet text: " <<text <<endl;
  		new QListWidgetItem(text.c_str(), tagSearchListWidget_);
  	}
  	searchTagWin_->show();
  }

void Multiwin::outputFeedsButtonClicked() {
  twit_eng_->outputFeed();

  QMessageBox msgBox;
  msgBox.setText("Finished writing feeds!");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.exec();
}

void Multiwin::refreshCurrentUser(){
	std::vector<const Tweet*> feed = currentUser_->getFeed();
	feedListWidget_->clear();
	
	for (size_t i = 0; i < feed.size(); i++) {
    new QListWidgetItem(feed[i]->to_string().c_str(), feedListWidget_);
  }
  followingWidget_->clear();
  const std::set<User*>& following = currentUser_->getFollowing();
  set<User*>::const_iterator it;
  for (it = following.begin(); it != following.end(); it++) {
    const User* user = *it;
    new QListWidgetItem(user->getName().c_str(), followingWidget_);
  }
}




void Multiwin::setCurrentUser(QListWidgetItem* item) {
  string name = item->text().toStdString();
  //cout << "Set Current User To: " << name << endl;
  currentUser_ = twit_eng_->getUser(name);
  assert(currentUser_ != nullptr);
  

  std::vector<const Tweet*> feed = currentUser_->getFeed();
  const std::set<User*>& followers = currentUser_->getFollowers();
  const std::set<User*>& following = currentUser_->getFollowing();
  feedListWidget_->clear();
  followingWidget_->clear();
  followersWidget_->clear();
  for (size_t i = 0; i < feed.size(); i++) {
    new QListWidgetItem(feed[i]->to_string().c_str(), feedListWidget_);
  }
  set<User*>::const_iterator it;
  for (it = followers.begin(); it != followers.end(); it++) {
    const User* user = *it;
    new QListWidgetItem(user->getName().c_str(), followersWidget_);
  }
  for (it = following.begin(); it != following.end(); it++) {
    const User* user = *it;
    new QListWidgetItem(user->getName().c_str(), followingWidget_);
  }
}

void Multiwin::newTweet(){
	if(currentUser_==nullptr){
		QMessageBox msgBox;
	  	msgBox.setText("You Must Select A User");
	  	msgBox.setStandardButtons(QMessageBox::Ok);
	  	msgBox.exec();
	  	return;
	}
	string tweet_text = tweetLineEdit_->text().toStdString();
	string timestamp = GetTimestamp();
	tweetLineEdit_->clear();
	twit_eng_->addTweet(currentUser_->getName(),tweet_text,timestamp);
	refreshCurrentUser();
}

void Multiwin::addFollowing(){
	// No current user selected
	if(currentUser_==nullptr){
		QMessageBox msgBox;
	  	msgBox.setText("You Must Select A User");
	  	msgBox.setStandardButtons(QMessageBox::Ok);
	  	msgBox.exec();
	  	return;
	}
	string name = followingEdit_->text().toStdString();
	User* following = twit_eng_->getUser(name);
	// Invalid User
	if(following==nullptr){
		QMessageBox msgBox;
	  	msgBox.setText("This User is Not Valid");
	  	msgBox.setStandardButtons(QMessageBox::Ok);
	  	msgBox.exec();
	  	return;
	}
	// check if user is already following
	const std::set<User*>& following_set = currentUser_->getFollowing();
	if(following_set.find(following)!=following_set.end()){
		QMessageBox msgBox;
		string message = currentUser_->getName() + " is already following "+ name;
	  	msgBox.setText(message.c_str());
	  	msgBox.setStandardButtons(QMessageBox::Ok);
	  	msgBox.exec();
	  	return;
	}

	currentUser_->addFollowing(following);
	refreshCurrentUser();
	followingEdit_->clear();
}
