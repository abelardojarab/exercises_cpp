#pragma once
using namespace std;
const string NULL_USER = " ";

class InvalidUserException : exception
{
	string _reason;
public:
	InvalidUserException (const string& user)
		:_reason(user +" is not a valid user")
	{
	}

	virtual const char* what() const throw()
	{
		return _reason.c_str();
	}

};

class Tweet
{

public:
	Tweet(const string& msg = "", const string& user = NULL_USER)
		:_msg(msg),_user(user)
	{
		if (!isValid(_user))
		{
			throw InvalidUserException(_user);
		}
	}

	virtual ~Tweet(void)
	{
	}

	// classes will have a default copy assignment operator
	Tweet& operator=(const Tweet& other)
	{
		if(&other == this)
			return *this;

		_msg = other._msg;
		_user = other._user;
		return *this;
	}
private:
	string _msg;
	string _user;

	bool isValid(const string& user)const
	{
		return '@' ==user[0];
	}
};
