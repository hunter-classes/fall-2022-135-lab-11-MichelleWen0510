#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile()
{
	username="";
	displayname="";
}

Profile::Profile(std::string usrn, std::string dspn)
{
	username=usrn;
	displayname=dspn;
}

std::string Profile::getUsername()
{
	return username;
}

std::string Profile::getFullName()
{
	std::string text = displayname + " (@" + username + ")";
	return text;
}

void Profile::setDisplayName(std::string dspn)
{
	displayname=dspn;
}
