#include "Book.h"

Book::Book(){}

Book::Book(std::string title, std::string author) 
{
	Book::Title = title;
	Book::Author = author;
	Book::CheckedOut = false;
}

void Book::CheckInOrOut(bool checkOut)
{
	CheckedOut = checkOut;
}

void Book::DisplayBook()
{
	std::cout << Id << "\t" << Title << "\t" << Author << std::endl;
}

bool Book::IsCheckedOut()
{
	return CheckedOut;
}

void Book::SetBookId(int id)
{
	Id = id;
}