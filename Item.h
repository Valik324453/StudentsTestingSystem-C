#pragma once
#include <iomanip>
#include<vector>

#include "objects to file.h"
using namespace std;
class Item
{
	string question;
	vector<pair<string, bool>> answers;
public:
	Item();
	Item(string question, vector<pair<string, bool>> answers);
	bool get_answer(int pos) const;

	friend ostream& operator<<(ostream& out, const Item& item);

	friend ofstream& operator<<(ofstream& os, const Item& item);
	friend ifstream& operator>>(ifstream& is, Item& item);
};

