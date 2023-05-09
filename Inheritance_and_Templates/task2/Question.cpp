#include "Question.h"
#include <iostream>
#include <cstring>

const int SIZE = 1024;

void Question::copyFrom(const Question& other)
{
	size = other.size;
	question = new char[size + 1];

	strcpy(this->question, other.question);
}

void Question::move(Question&& other)
{
	size = other.size;
	question = other.question;
	other.question = nullptr;
}

void Question::free()
{
	delete[] question;
}

Question::Question()
{
	size = 0;
	question = nullptr;
}

Question::Question(const Question& other)
{
	copyFrom(other);
}

Question& Question::operator=(const Question& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Question::Question(Question&& other)
{
	move(std::move(other));
}

Question& Question::operator=(Question&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

Question::~Question()
{
	free();
}

void Question::ask()
{
	char answer[SIZE];

	std::cout << this->question << std::endl;
	std::cin.getline(answer, SIZE);
}

int Question::grade(const Question& q, int points)
{
	return points;
}