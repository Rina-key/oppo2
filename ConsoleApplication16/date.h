#pragma once
#pragma once
#include<string>

struct DateStruct {
private:
	int dd = 0;
	int mm = 0;
	int yy = 0;

public:

	int getDD();

	int getMM();

	int getYY();


	void setDD(int value);

	void setMM(int value);

	void setYY(int value);


	void readDate(std::string& dateStr);

	void printDate(std::ostream& out);

	void CorrectDate(std::string& dateStr);

	bool isLeapYear(int year);

	void Correct(int dd, int mm, int yy);
};