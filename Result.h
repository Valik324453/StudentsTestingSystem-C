#pragma once
#include <ostream>
#include <fstream>
#include <string>
#include "objects to file.h"
using namespace std;
class Result
{
	string login;
	string subject;
	string chapter;
	int number_of_questions;
	int number_of_correct_answers;
	int number_of_wrong_answers;
	int evaluation;

public:
	Result();
	Result(
	string login,
	string subject,
	string chapter,
	int number_of_questions,
	int number_of_correct_answers,
	int number_of_wrong_answers,
	int evaluation);

	void clear_result();

	string get_login()const { return login; }
	string get_subject()const { return subject; }
	string get_chapter()const { return chapter; }

	friend ostream& operator<<(ostream& out, const Result& res);

	friend ofstream& operator<<(ofstream& fout, const Result& res);
	friend ifstream& operator>>(ifstream& fin, Result& res);
};

