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

	//���������� ������� ������ ��������
	void printGas(std::vector<Gas>& pvec, std::ostream& out);

	//���������� ������� �������� ������ �� ������������
	void CorrectValues(std::string gType, float cost);
};