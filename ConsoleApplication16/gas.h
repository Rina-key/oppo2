#pragma once

#include<fstream>
#include<vector>
#include"date.h"
#include"stan.h"

struct Gas {
private:
	DateStruct Date;

	std::string Gtype;
	float cost = 0.0; //������ ����������, ��� ����� ��������

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

	//���������� ������� ������ ��������
	void printGas(std::vector<Gas>& pvec, std::ostream& out);

	//���������� ������� �������� ������ �� ������������
	void CorrectValues(std::string gType, float cost);
};