#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>
#include "User.h"
#include <fstream>

using namespace std;

Inventory _inventory;
vector<User> _users;
User _loggedInUser;

Role GetRoleFromIntVal(int roleVal)
{
	Role outRole;

	if (roleVal == 0)
	{
		outRole = Role::Admin;
	}
	else if (roleVal == 1)
	{
		outRole = Role::Employee;
	}
	else
	{
		outRole = Role::Member;
	}

	return outRole;
}

void LoadUsers()
{
	ifstream inFile("users.txt");

	string lineData[2];
	// lineData[0] = username
	// lineData[1] = role int val

	string userLine;
	while (getline(inFile, userLine))
	{
		size_t index = userLine.find('|');
		lineData[0] = userLine.substr(0, index);
		lineData[1] = userLine.substr(index + 1);

		User loadedUser;
		loadedUser.Username = lineData[0];
		loadedUser.Role = GetRoleFromIntVal(stoi(lineData[1]));

		_users.push_back(loadedUser);
	}
}

int GetIntValFromRole(Role role)
{
	int roleVal = -1;
	if (role == Role::Admin)
	{
		roleVal = 0;
	}
	else if (role == Role::Employee)
	{
		roleVal = 1;
	}
	else if (role == Role::Member)
	{
		roleVal = 2;
	}

	return roleVal;
}

void CreateAccount()
{
	User newUser;

	/*cout << "First name:" << endl;
	string firstName;
	getline(cin, firstName);

	cout << "Last name:" << endl;
	string lastName;
	getline(cin, lastName);*/

	cout << "Username:" << endl;
	getline(cin, newUser.Username);

	cout << "Choose a role:" << endl;
	cout << "1. Admin" << endl;
	cout << "2. Employee" << endl;
	cout << "3. Member" << endl;

	int roleOption;
	cin >> roleOption;
	cin.ignore();

	if (roleOption == 1)
		newUser.Role = Role::Admin;
	else if (roleOption == 2)
		newUser.Role = Role::Employee;
	else
		newUser.Role = Role::Member;

	_users.push_back(newUser);

	ofstream oFile("users.txt", ios_base::app);
	oFile << newUser.Username << "|" << GetIntValFromRole(newUser.Role) << endl;
	oFile.close();
}

void Login()
{
	cout << "Choose an option:" << endl;
	cout << "1. Log In" << endl;
	cout << "2. Create account" << endl;

	int option;
	cin >> option;
	cin.ignore();

	if (option == 2)
	{
		CreateAccount();
	}

	while (true)
	{
		cout << "Enter username: ";
		string username;
		getline(cin, username);

		User user;
		user.Username = username;

		vector<User>::iterator it = find(_users.begin(), _users.end(), user);

		if (it != _users.end())
		{
			_loggedInUser = _users[it - _users.begin()];
			break;
		}
	}
}

void DisplayMainMenu()
{
	cout << endl;
	cout << "Choose an option:" << endl;

	cout << "1. List all books" << endl;
	cout << "2. Check out book" << endl;
	cout << "3. Check in book" << endl;

	if (_loggedInUser.Role == Role::Employee
		|| _loggedInUser.Role == Role::Admin)
	{
		cout << "4. Add book" << endl;
		cout << "5. Remove book from library" << endl;
		cout << "6. List all checked out books" << endl;
	}

	cout << "9. Log out" << endl;
	cout << "0. Exit" << endl;
}

void AddNewBook()
{
	cout << "Title: ";
	string title;
	getline(cin, title);

	cout << "Author: ";
	string author;
	getline(cin, author);

	Book newBook(title, author);

	_inventory.AddBook(newBook);
}

void ListAllBooks()
{
	_inventory.DisplayAllBooks();
}

void CheckInOrOutBook(bool checkOut)
{
	string inOrOut;
	if (checkOut)
	{
		inOrOut = "out";
	}
	else
	{
		inOrOut = "in";
	}

	cout << "Enter a book title to check " + inOrOut + ": ";
	string title;
	getline(cin, title);

	CheckInOrOutResult result = _inventory.CheckInOrOutBook(title, checkOut);

	if (result == CheckInOrOutResult::BookNotFound)
	{
		cout << "Book not found";
	}
	else if (result == CheckInOrOutResult::Success)
	{
		cout << "Book checked " + inOrOut + "!" << endl;
	}
	else if (result == CheckInOrOutResult::AlreadyCheckedIn
		|| result == CheckInOrOutResult::AlreadyCheckedOut)
	{
		cout << "Book already checked " + inOrOut << endl;
	}
	else
	{
		cout << "Book failed checking " + inOrOut + "!" << endl;
	}
}

void RemoveBook()
{
	cout << "Title: ";
	string title;
	getline(cin, title);

	_inventory.RemoveBook(title);
}

void DisplayCheckedOutBooks()
{
	_inventory.DisplayCheckedOutBooks();
}

int main()
{
	LoadUsers();

	while (true)
	{
		Login();

		_inventory.LoadBooks();
		bool isLoggedIn = true;
		while (isLoggedIn)
		{
			DisplayMainMenu();

			int input;
			cin >> input;
			cin.ignore();

			switch (input)
			{
			case 0:
				cout << "Thank you. Goodbye";
				return 0;
			case 1:
				ListAllBooks();
				break;
			case 2:
				CheckInOrOutBook(true);
				break;
			case 3:
				CheckInOrOutBook(false);
				break;
			case 4:
				AddNewBook();
				break;
			case 5:
				RemoveBook();
				break;
			case 6:
				DisplayCheckedOutBooks();
				break;
			case 9:
				isLoggedIn = false;
				break;
			default:
				cout << "Invalid selection. Try again." << endl;
				break;
			}
		}
	}
}

