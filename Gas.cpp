#include"pch.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>

#include "Gas.h"

// ����������� �������
// read/write

// ��������� ���� ��� ������ ����������� ������� � ��������� ���

/* ��.�������� 10
[ 
23.05.2032 AT-98 55.6 
23.05.2032 AT-98 55.6
]
*/

Gas Gas::createFromStream(std::istream& in, std::istream& ist)//��������� � ������
{
	Gas gasData;

	std::string DATE;

	in >> DATE;//�� ����� ��������� � ����

	std::string Gtype;
	float cost = 0.0;

	in >> Gtype; //������� ��� ������� 1 �������
	in >> cost; //������� ��������� 1 �������

	//std::string street;
	//int h = 0;

	//ist >> street;
	//ist >> h;
	/*std::string STAN;
	ist >> STAN;*/

	gasData.CorrectValues(Gtype, cost); //������� ��� �����������

	gasData.Gtype = Gtype;
	gasData.cost = cost;

	gasData.Date.CorrectDate(DATE);

	
	gasData.Date.readDate(DATE); 

	gasData.Stan.readStan(ist);
	//gasData.Stan.setStreet(street);
	//gasData.Stan.setHome(h);
	
	return gasData;
}

std::string Gas::getGtype() {
	return Gtype;
}

float Gas::getCost() {
	return cost;
}

void Gas::setGtype(std::string val) {
	CorrectValues(val, 55);
	Gtype = val;
}

void Gas::setCost(float val) {
	CorrectValues("AI-98", val);
	cost = val;
}


DateStruct Gas::getDate() {
	return Date;
}

void Gas::setDate(DateStruct date) {

	date.Correct(date.getDD(), date.getMM(), date.getYY());

	Date = date;
}

void Gas::CorrectValues(std::string Gt, float c) {//�������� �� �������������
	std::string val = " AI-95 AI-92 DT AI-98";
	if (!(val.find(Gt) != std::string::npos))  throw std::runtime_error{ "������� ������ ��� �������! ������� ������ ��������" };
	if (c <= 0) throw std::runtime_error("������� ������� ����! ������� ������ ��������");
}

void Gas::print(std::ostream& out)
{
	
	Date.printDate(out);

	out << " ��� �������: " << Gtype << " ���������: " << cost << " �������: ";
	Stan.printStan(out);
}

void Gas::readGas(std::istream& in, std::istream& ist, std::vector<Gas>& gvec) {//������ ������ ������� ������
	while (!in.eof() and !ist.eof()) {
		Gas gasData;
		gasData = gasData.createFromStream(in,ist); //���������
		gvec.push_back(gasData);
	}
}

void Gas::printGas(std::vector<Gas>& gvec, std::ostream& out) {
	for (auto& data : gvec) {//������� ���� ������ ������� �� �������
		data.print(out);
	}
}