#pragma once
#pragma once
#include<string>

struct Stan {
private:
	std::string street;
	int home = 0;

public:
	std::string getStreet();
	int getHome();

	void setStreet(std::string str);
	void setHome(int h);

	void readStan(std::istream& file);
	void printStan(std::ostream& out);
	void correctHome(int h);
	//void CorrectStan(std::string& stanStr);

	//void Correct(int street, int home);
};