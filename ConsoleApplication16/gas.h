#pragma once

#include<fstream>
#include<vector>
#include"date.h"

struct Gas {
private:
	DateStruct Date;

	std::string Gtype;
	float cost = 0.0;

public:

	std::string getGtype();
	float getCost();
	DateStruct getDate();

	
	void setGtype(std::string value);
	void setCost(float value);
	void setDate(DateStruct date);

	
	static Gas createFromStream(std::istream& in);
	
	void print(std::ostream& out);

	
	void readGas(std::istream& file, std::vector<Gas>& pvec);

	//ќбъ€вление функции вывода давлени€
	void printGas(std::vector<Gas>& pvec, std::ostream& out);

	//ќбъ€вление функции проверки данных на корректность
	void CorrectValues(std::string gType, float cost);
};