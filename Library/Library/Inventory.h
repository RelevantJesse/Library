#pragma once

#include "Book.h"
#include <vector>

class Inventory
{
public:
	std::vector<Book> Books;

	void AddBook(Book book);
	void RemoveBook(Book book);
	bool FindBookByTitle(std::string title, Book &book);
	void CheckOutBook(Book &book);
	void CheckInBook(Book &book);
};

