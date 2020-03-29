#include "Book.h"
#include <string>

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

std::string Book::GetBookFileData()
{
	return std::to_string(Id) + "|" + Title + "|" + Author + "|" + (CheckedOut ? "1" : "0");
}