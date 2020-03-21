#include "Inventory.h"
#include <vector>

Inventory::Inventory()
{
	Inventory::MaxBookId = 0;
}

int Inventory::GetNextBookId()
{
	Inventory::MaxBookId++;
	return Inventory::MaxBookId;
}

int Inventory::NumberOfBooks()
{
	return Inventory::Books.size();
}

Book* Inventory::GetBookByIndex(int index)
{
	return &Inventory::Books[index];
}

void Inventory::AddBook(Book book)
{
	Inventory::Books.push_back(book);
}

void Inventory::RemoveBook(std::string title)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));
	if (it != Inventory::Books.end())
	{
		Inventory::Books.erase(it);
	}
}


int Inventory::FindBookByTitle(std::string title)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));
	if (it == Inventory::Books.end())
	{
		return -1;
	}

	int index = it - Inventory::Books.begin();

	return index;
}

void Inventory::CheckOutBook(Book* book)
{
	book->CheckedOut = true;
}

void Inventory::CheckInBook(Book* book)
{
	book->CheckedOut = false;
}