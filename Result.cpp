#include "Result.h"
#include <iostream>
#include "objects to file.h"
Result::Result()
{
	this->login = "no login";
	this->subject = "no subject";
	this->chapter = "no chapter";
	this->number_of_questions = 0;
	this->number_of_correct_answers = 0;
	this->number_of_wrong_answers = 0;
	this->evaluation = 0;
}

void Result::clear_result()
{
	this->login = "no login";
	this->subject = "no subject";
	this->chapter = "no chapter";
	this->number_of_questions = 0;
	this->number_of_correct_answers = 0;
	this->number_of_wrong_answers = 0;
	this->evaluation = 0;
}

Result::Result(
	string login,
	string subject,
	string chapter,
	int number_of_questions,
	int number_of_correct_answers,
	int number_of_wrong_answers,
	int evaluation)
{
	this->login = login;
	this->subject = subject;
	this->chapter = chapter;
	this->number_of_questions = number_of_questions;
	this->number_of_correct_answers = number_of_correct_answers;
	this->number_of_wrong_answers = number_of_wrong_answers;
	this->evaluation = evaluation;
}

ostream& operator<<(ostream& out, const Result& res)
{
	out << "Предмет: " << res.subject << endl;
	out << "Раздел: " << res.chapter << endl;
	out << "Всего вопросов: " << res.number_of_questions << endl;
	out << "Количество верных ответов: " << res.number_of_correct_answers << endl;
	out << "Количество не верных ответов: " << res.number_of_wrong_answers << endl;
	out << "Оценка: " << res.evaluation << endl;

	return out;
}

ofstream& operator<<(ofstream& fout, const Result& res)
{
	fout << res.login;
	fout << res.subject;
	fout << res.chapter;
	fout.write((char*)&res.number_of_questions, sizeof(res.number_of_questions));
	fout.write((char*)&res.number_of_correct_answers, sizeof(res.number_of_correct_answers));
	fout.write((char*)&res.number_of_wrong_answers, sizeof(res.number_of_wrong_answers));
	fout.write((char*)&res.evaluation, sizeof(res.evaluation));
	return fout;
}

ifstream& operator>>(ifstream& fin, Result& res)
{
	fin >> res.login;
	fin >> res.subject;
	fin >> res.chapter;
	fin.read((char*)&res.number_of_questions, sizeof(res.number_of_questions));
	fin.read((char*)&res.number_of_correct_answers, sizeof(res.number_of_correct_answers));
	fin.read((char*)&res.number_of_wrong_answers, sizeof(res.number_of_wrong_answers));
	fin.read((char*)&res.evaluation, sizeof(res.evaluation));
	return fin;
}
