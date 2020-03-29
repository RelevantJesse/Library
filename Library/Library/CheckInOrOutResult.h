#pragma once
enum class CheckInOrOutResult
{
	Success,
	BookNotFound,
	AlreadyCheckedOut,
	AlreadyCheckedIn,
	Failure
};