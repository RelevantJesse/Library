#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>
#include "User.h"

using namespace std;

Inventory _inventory;
vector<User> _users;
User _loggedInUser;

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

	cout << "Enter username: ";
	string username;
	getline(cin, username);

	User user;
	user.Username = username;

	vector<User>::iterator it = find(_users.begin(), _users.end(), user);

	if (it != _users.end())
	{
		_loggedInUser = _users[it - _users.begin()];		
	}

}

void DisplayMainMenu()
{
	cout << endl;
	cout << "Choose an option:" << endl;

	if (_loggedInUser.Role == Role::Employee
		|| _loggedInUser.Role == Role::Admin)
	{
		cout << "1. Add book" << endl;
		cout << "5. Remove book from library" << endl;
		cout << "6. List all checked out books" << endl;
	}
	
	cout << "2. List all books" << endl;
	cout << "3. Check out book" << endl;
	cout << "4. Check in book" << endl;

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

	Book newBook( title, author);

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
	else if(result == CheckInOrOutResult::Success)
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
	Login();

	while (true) 
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
			AddNewBook();
			break;
		case 2:
			ListAllBooks();
			break;
		case 3:
			CheckInOrOutBook(true);
			break;
		case 4:
			CheckInOrOutBook(false);
			break;
		case 5:
			RemoveBook();
			break;
		case 6:
			DisplayCheckedOutBooks();
			break;
		default:
			cout << "Invalid selection. Try again." << endl;
			break;
		}
	}
}

