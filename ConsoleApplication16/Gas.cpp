#include"pch.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>

#include "Gas.h"

Gas Gas::createFromStream(std::istream& in)
{
	Gas gasData;

	std::string DATE;

	in >> DATE;

	std::string Gtype;
	float cost = 0.0;

	in >> Gtype;
	in >> cost;

	gasData.CorrectValues(Gtype, cost);

	gasData.Gtype = Gtype;
	gasData.cost = cost;

	gasData.Date.CorrectDate(DATE);

	
	gasData.Date.readDate(DATE);

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

void Gas::CorrectValues(std::string Gt, float c) {
	std::string val = " AI-95 AI-92 DT AI-98";
	if (!(val.find(Gt) != std::string::npos))  throw std::runtime_error{ "Неверно введен тип топлива! Введите другое значение" };
	if (c <= 0) throw std::runtime_error("Неверно введена цена! Введите другое значение");
}

void Gas::print(std::ostream& out)
{
	Date.printDate(out);

	out << " Тип топлива: " << Gtype << " Стоимость: " << cost << "\n";
}

void Gas::readGas(std::istream& file, std::vector<Gas>& gvec) {
	while (!file.eof()) {
		Gas gasData = Gas::createFromStream(file);
		gvec.push_back(gasData);
	}
}

void Gas::printGas(std::vector<Gas>& gvec, std::ostream& out) {
	for (auto& data : gvec) {
		data.print(out);
	}
}