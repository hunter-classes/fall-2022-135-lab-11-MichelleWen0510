#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int Network::findID(std::string usrn)
{
	for(int i=0; i < numUsers; i++)
	{
		if(usrn==profiles[i].getUsername())
		{
			return i;
		}
	}
	return -1;
}

Network::Network()
{
	numUsers=0;
	for(int i=0;i<MAX_USERS;i++)
	{
		for(int j=0;j<MAX_USERS;j++)
		{
			following[i][j]=false;
		}
	}
}

bool Network::addUser(std::string usrn, std::string dspn)
{
	Profile temp(usrn, dspn);
	for(int j=0; j<usrn.length();j++)
	{
		if(!isalnum(usrn[j]))
		{	
			return false;
		}
	}
	for(int i=0; i<numUsers;i++)
	{
		if(usrn==profiles[i].getUsername())
		{
			return false;
		}
	}
	if(numUsers < 20)
	{
		profiles[numUsers]=temp;
		numUsers++;
		return true;
	}
	return false;
}

bool Network::follow(std::string usrn1, std::string usrn2)
{
	bool existOne=false;
	bool existTwo=false;
	for(int i=0;i<numUsers;i++)
	{
		if(usrn1==profiles[i].getUsername())
		{
			existOne=true;
		}
		if(usrn2==profiles[i].getUsername())
		{
			existTwo=true;
		}
	}
	if(existOne && existTwo)
	{
		following[findID(usrn1)][findID(usrn2)]=true;
		return true;
	}
	return false;
}

void Network::printDot()
{
	std::string text;
	text += "digraph { \n";
	for(int i=0;i<numUsers;i++)
	{
		text = text + "\"@"+profiles[i].getUsername() + "\"\n";
	}
	text += "\n";
	for(int j=0;j<numUsers;j++)
	{
		for(int k=0;k<numUsers;k++)
		{
			if(following[j][k])
			{
				text = text + "\"@" + profiles[j].getUsername() + "\" -> \"@" + profiles[k].getUsername() + "\"\n";
			}
		}
	}
	text += "}\n";
	std::cout << text;
}

