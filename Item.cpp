#include "Item.h"

Item::Item()
{
	question = "unknown";
}

Item::Item(string question, vector<pair<string, bool>> answers)
{
	this->question = question;
	this->answers = answers;
}

bool Item::get_answer(int pos) const
{
	return answers.at(pos).second;
}

ostream& operator<<(ostream& out, const Item& item)
{
	int i = 0;
	out << "Вопрос: " << item.question << endl << endl;
	out << "Варианты ответов: " << endl;
	for (auto answer : item.answers)
	{
		out << ++i << ". " << answer.first << endl;
	}
	return out;
}

ofstream& operator<<(ofstream& os, const Item& item)
{
	os << item.question;

	int s = item.answers.size();
	os.write(reinterpret_cast<char*>(&s), sizeof(s));

	
	for (auto a : item.answers)
	{
		os << a.first;
		os << a.second;
	}

	return os;
}

ifstream& operator>>(ifstream& is, Item& item)
{
	is >> item.question;

	int s;
	is.read((char*)&s, sizeof(s));
	item.answers.resize(s);

	for (auto a : item.answers)
	{
		is >> a.first;
		is >> a.second;
	}
	
	return is;
}
