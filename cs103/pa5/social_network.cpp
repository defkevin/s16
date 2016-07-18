#include "network.h"
#include "user.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;

void options(const char* filename){
	Network nw;
	nw.read_friends(filename);
	bool valid = true;
	while(valid){
		int input; 
		cout << "Option 1. Add a User ( 'firstname lastname BirthYear ZipCode' )" <<endl;
		cout << "Option 2. Add Friend Connection ('FN(User1) LN(User1) FN(User2) LN(User2)')" <<endl;
		cout << "Option 3. Remove Friend Connection ('FN(User1) LN(User1) FN(User2) LN(User2)')" <<endl;
		cout << "Option 4. Print Users " <<endl;
		cout << "Option 5. Print Friends ('firstname lastname')" <<endl;
		cout << "Option 6. Write To File ('filename.txt')" <<endl;
		cout << "Option 7. Exit" <<endl;
		cin >> input;
		switch(input){
			case 1:
			{
				string firstname, lastname, name;
				int year, zip;
				cin >> firstname >>lastname >> year >>zip;
				name = firstname + " "+lastname;
				nw.add_user(name, year, zip);
				break;
			}
			case 2:
			{
				string name1first, name1last, name2first, name2last, name1, name2;
				cin >> name1first >>name1last >>name2first >>name2last;
				name1 = name1first +" "+name1last;
				name2 = name2first +" "+name2last;
				int result = nw.add_connection(name1,name2);
				if(result == -1){
					cout << "One user does not exist. Unable to make connection." <<endl;
				}
				break;
			}
			case 3:
			{
				string name1first, name1last, name2first, name2last, name1, name2;
				cin >> name1first >>name1last >>name2first >>name2last;
				name1 = name1first +" "+name1last;
				name2 = name2first +" "+name2last;
				int result = nw.remove_connection(name1,name2);
				if(result == -1){
					cout << "One user does not exist. Unable to remove connection." <<endl;
				}
				break;
			}
			case 4:
			{
				nw.printUsers();
				break;
			}
			case 5:
			{
				string firstname, lastname, name;
				cin >> firstname >> lastname;
				name = firstname +" "+lastname;
				int id = nw.get_id(name);
				if(id>=0){
					User u = nw.getusers(id);
					int numFriends = u.getFriends().size();
					vector<int> friends = u.getFriends();
					cout <<setw(10) <<left <<"ID"  <<setw(25) <<left << "Name" <<setw(10) <<"Year" <<setw(10)<<"Zip" <<endl;
  					cout << "================================================================" <<endl;
					for(int i = 0; i <numFriends;i++){
						int friendindex = friends[i];
						User tempFriend = nw.getusers(friendindex);
						cout << setw(10)  <<tempFriend.getID() ;
    					cout  <<setw(25) << tempFriend.getName();
   						cout << setw(10) << tempFriend.getYear();
    					cout << setw(10) << tempFriend.getZip();
    					cout <<endl;
					}
				}
				break;
			}
		
		case 6:
		{
			string filename;
			//string filename;
			cin >>filename;
			const char*file = filename.c_str();
			nw.write_friends(file);
			break;
		}
		case 7:
		{
			valid = !valid;
			break;
		}
		default:
		{
			valid = !valid;
			break;
		}
	}


	}
	nw.printUsers();
}

int main(int argc, char*argv[]) {
	if(argc!=2){
		 cout<<"usage: "<< argv[0] <<" <filename>" <<endl;
	}
	else{
		Network nw;
		int good = nw.read_friends(argv[1]);
		cout <<endl;
  		if(good == 0){
  			nw.printUsers();
  			//options(argv[1]);
  			nw.bfs(1);
  			vector<int> path = nw.shortest_path(1,4);
  			nw.printPath(path);
  		}
	}

}