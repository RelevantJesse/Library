#include "Book.h"

Book::Book(){}

Book::Book(int id, std::string title, std::string author) 
{
	Book::Id = id;
	Book::Title = title;
	Book::Author = author;
	Book::CheckedOut = false;
}