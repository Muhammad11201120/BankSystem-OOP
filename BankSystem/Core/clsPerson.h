#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
	string _firstName;
	string _lastName;
	string _email;
	string _phone;
public:

	clsPerson( string firstName , string lastName , string email , string phone )
	{
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_email = email;
		this->_phone = phone;
	}

	void setFirstName( string firstName )
	{
		this->_firstName = firstName;
	}
	string FirstName()
	{
		return this->_firstName;
	}
	void setLastName( string lastName )
	{
		this->_lastName = lastName;
	}
	string LastName()
	{
		return _lastName;
	}
	string FullName()
	{
		return this->_firstName + " " + this->_lastName;
	}
	void setEmail( string email )
	{
		this->_email = email;
	}
	string Email()
	{
		return this->_email;
	}
	void setPhone( string phone )
	{
		this->_phone = phone;
	}
	string Phone()
	{
		return this->_phone;
	}
};


