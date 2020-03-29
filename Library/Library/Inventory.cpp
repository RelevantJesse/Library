#include "Inventory.h"
#include <vector>

Inventory::Inventory()
{
	Inventory::MaxBookId = 0;
}

int Inventory::NumberOfBooks()
{
	return Inventory::Books.size();
}

Book Inventory::GetBookByIndex(int index)
{
	return Inventory::Books[index];
}

void Inventory::AddBook(Book book)
{
	Inventory::MaxBookId++;

	book.SetBookId(MaxBookId);

	Inventory::Books.push_back(book);
}

void Inventory::RemoveBook(std::string title)
{
	//TODO: Handle MaxBookId when removing

	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));
	if (it != Inventory::Books.end())
	{
		Inventory::Books.erase(it);
	}
}


int Inventory::FindBookByTitle(std::string title)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));
	if (it == Inventory::Books.end())
	{
		return -1;
	}

	int index = it - Inventory::Books.begin();

	return index;
}

CheckInOrOutResult Inventory::CheckInOrOutBook(std::string title, bool checkOut)
{
	int foundBookIndex = FindBookByTitle(title);

	if (foundBookIndex < 0)
	{
		return CheckInOrOutResult::BookNotFound;
	}
	else if (checkOut == Books[foundBookIndex].IsCheckedOut())
	{
		if (checkOut)
		{
			return CheckInOrOutResult::AlreadyCheckedOut;
		}
		else
		{
			return CheckInOrOutResult::AlreadyCheckedIn;
		}
	}

	Books[foundBookIndex].CheckInOrOut(checkOut);
	return CheckInOrOutResult::Success;
}

void Inventory::DisplayAllBooks()
{
	std::cout << "\nID\tTitle\tAuthor" << std::endl;
	for (int i = 0; i < NumberOfBooks(); i++)
	{
		Books[i].DisplayBook();
	}
	std::cout << std::endl;
}

void Inventory::DisplayCheckedOutBooks()
{
	std::cout << "\nID\tTitle\tAuthor" << std::endl;
	for (int i = 0; i < NumberOfBooks(); i++)
	{
		if (GetBookByIndex(i).IsCheckedOut())
		{
			Books[i].DisplayBook();
		}
	}
	std::cout << std::endl;
}