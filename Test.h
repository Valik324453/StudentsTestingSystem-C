#include<string>
#include<list>
#include <fstream>

#include "Item.h"

using namespace std;
class Test
{
	string subject;
	string chapter;
	list<Item> test_list;
public:
	Test();
	Test(string subject, string chapter, list<Item> test_list);
	bool operator<(const Test& t)const;

	string get_subject()const { return subject; }
	string get_chapter()const { return chapter; }
	list<Item> get_test_list()const { return test_list; }

	friend ofstream& operator<<(ofstream& os, const Test& test);
	friend ifstream& operator>>(ifstream& is, Test& test);
};
