#pragma once

#include "Book.h"
#include <vector>

class Inventory
{
private:
	std::vector<Book> Books;

public:

	int MaxBookId;

	Inventory();

	int GetNextBookId();
	int NumberOfBooks();
	Book* GetBookByIndex(int index);
	void AddBook(Book book);
	void RemoveBook(std::string title);
	int FindBookByTitle(std::string title);
	void CheckOutBook(Book* book);
	void CheckInBook(Book* book);	
};

