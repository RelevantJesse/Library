#pragma once
#include <iostream>
#include "Role.h"
class User
{
public:
	int Id;
	std::string FirstName;
	std::string LastName;
	std::string Username;
	Role Role;

	bool operator==(const User& user) const
	{
		if (Username.compare(user.Username) == 0)
			return true;
		else
			return false;
	}
};

