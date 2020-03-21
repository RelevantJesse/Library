#pragma once

#include <iostream>

class Book
{
private:
	int Id;
	std::string Title;
	std::string Author;
	bool CheckedOut;

public:
	

	Book();
	Book(std::string title, std::string author);

	void SetBookId(int id);
	void CheckInOrOut(bool checkOut);
	void DisplayBook();
	bool IsCheckedOut();

	bool operator==(const Book &book) const
	{
		if (Title.compare(book.Title) == 0)
			return true;
		else
			return false;
	}
};

