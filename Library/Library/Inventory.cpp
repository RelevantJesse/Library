#include "Inventory.h"
#include <vector>

void Inventory::AddBook(Book book)
{
	Inventory::Books.push_back(book);	
}

bool Inventory::FindBookByTitle(std::string title, Book &book)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));
	if (it != Inventory::Books.end())
	{
		book = *it;
		return true;
	}

	return false;
}

void Inventory::CheckOutBook(Book &book) 
{
	book.CheckedOut = true;
}

void Inventory::CheckInBook(Book& book)
{
	book.CheckedOut = false;
}