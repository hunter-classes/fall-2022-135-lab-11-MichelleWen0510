#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Profile")
{
	Profile p1("marco","Marco");
	CHECK(p1.getUsername()=="marco");
	CHECK(p1.getFullName()=="Marco");
	p1.setDisplayName("Marco Rossi");
	CHECK(p1.getFullName()=="Marco Rossi");
}

TEST_CASE("Network")
{
	Network nw;
	CHECK(nw.addUser("mario","Mario")==true);
	CHECK(nw.addUser("luigi","Luigi")==true);
	CHECK(nw.addUser("mario 2","Mario2")==false);
}

TEST_CASE("Following")
{
	Network newnw;
	newnw.addUser("mario","Mario");
	newnw.addUser("luigi", "Luigi");
	newnw.addUser("yoshi","Yoshi");

	CHECK(newnw.follow("mario","luigi")==true);
	CHECK(newnw.follow("luigi","mario2")==false);

	
}
