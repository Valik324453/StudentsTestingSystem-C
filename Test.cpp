#include "Test.h"

Test::Test()
{
	subject = "no subject";
	chapter = "no chapter";
}

Test::Test(string subject, string chapter, list<Item> test_list)
{
	this->subject = subject;
	this->chapter = chapter;
	this->test_list = test_list;
}

bool Test::operator<(const Test& t)const
{
	return (this->subject < t.subject) && (this->chapter < t.chapter);
}

ofstream& operator<<(ofstream& os, const Test& test)
{
	os << test.subject << test.chapter;

	int s = test.test_list.size();
	os.write((const char*)&s, sizeof(s));

	for (auto t : test.test_list)
	{
		os << t;
	}
	return os;
}
ifstream& operator>>(ifstream& is, Test& test)
{
	int s;
	is.read((char*)&s, sizeof(s));
	Item tmp;

	for (auto t : test.test_list)
	{
		is >> tmp;
		test.test_list.push_back(tmp);
	}

	is >> test.subject >> test.chapter;
	return is;
}
