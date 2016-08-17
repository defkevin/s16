#ifndef MULTIWIN_H
#define MULTIWIN_H
#include "TwitEng.h"
#include <QLabel>
#include <QListWidgetItem>
#include <QPushButton>
#include <QWidget>

class Multiwin : public QWidget {
  Q_OBJECT
public:
  Multiwin(TwitEng* twit_eng);
public slots:
  void outputFeedsButtonClicked();
  void setCurrentUser(QListWidgetItem*);
  void newTweet();
  void addFollowing();
  void searchTag();
  

private:
	void refreshCurrentUser();
  TwitEng* twit_eng_;
  User* currentUser_;

  QListWidget* feedListWidget_;
  QListWidget* followingWidget_;
  QListWidget* followersWidget_;
  QLineEdit* tweetLineEdit_;
  QLineEdit* followingEdit_;
  QLineEdit* searchLineEdit_;
  QWidget* searchTagWin_;
  QListWidget* tagSearchListWidget_;
};
#endif // MULTIWIN_H