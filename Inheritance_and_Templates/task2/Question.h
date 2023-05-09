#ifndef _QUESTION_H
#define _QUESTION_H


class Question
{
	char* question;
	int size;

	void copyFrom(const Question& other);
	void move(Question&& other);
	void free();

public:
	Question();
	Question(const Question& other);
	Question& operator=(const Question& other);
	Question(Question&& other);
	Question& operator=(Question&& other);
	~Question();

	void ask();
	int grade(const Question& q, int points);

};

#endif