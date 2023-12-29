#pragma once

#include<fstream>
#include<vector>
#include"date.h"
#include"stan.h"

struct Gas {
private:
	DateStruct Date;

	std::string Gtype;
	float cost = 0.0; //просто приравн€ли, что потом изменить

	Stan Stan;
	
public:

	std::string getGtype();
	float getCost();
	DateStruct getDate();

	
	void setGtype(std::string value);
	void setCost(float value);
	void setDate(DateStruct date);

	
	static Gas createFromStream(std::istream& in, std::istream& ist);

	
	void print(std::ostream& out);

	
	void readGas(std::istream& in, std::istream& ist, std::vector<Gas>& pvec);

	//ќбъ€вление функции вывода давлени€
	void printGas(std::vector<Gas>& pvec, std::ostream& out);

	//ќбъ€вление функции проверки данных на корректность
	void CorrectValues(std::string gType, float cost);
};