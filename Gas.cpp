#include"pch.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>

#include "Gas.h"

// Заправочная станция
// read/write

// отдельный майн для чтения заправочных станций в отдельном тхт

/* ул.Брянская 10
[ 
23.05.2032 AT-98 55.6 
23.05.2032 AT-98 55.6
]
*/

Gas Gas::createFromStream(std::istream& in, std::istream& ist)//считываем с потока
{
	Gas gasData;

	std::string DATE;

	in >> DATE;//из файла считываем в дату

	std::string Gtype;
	float cost = 0.0;

	in >> Gtype; //считали тип топлива 1 строчки
	in >> cost; //считали стоимость 1 строчик

	//std::string street;
	//int h = 0;

	//ist >> street;
	//ist >> h;
	/*std::string STAN;
	ist >> STAN;*/

	gasData.CorrectValues(Gtype, cost); //функция для коррекности

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

void Gas::CorrectValues(std::string Gt, float c) {//проверка на существование
	std::string val = " AI-95 AI-92 DT AI-98";
	if (!(val.find(Gt) != std::string::npos))  throw std::runtime_error{ "Неверно введен тип топлива! Введите другое значение" };
	if (c <= 0) throw std::runtime_error("Неверно введена цена! Введите другое значение");
}

void Gas::print(std::ostream& out)
{
	
	Date.printDate(out);

	out << " Тип топлива: " << Gtype << " Стоимость: " << cost << " Станция: ";
	Stan.printStan(out);
}

void Gas::readGas(std::istream& in, std::istream& ist, std::vector<Gas>& gvec) {//вектор аналог списков питона
	while (!in.eof() and !ist.eof()) {
		Gas gasData;
		gasData = gasData.createFromStream(in,ist); //построчно
		gvec.push_back(gasData);
	}
}

void Gas::printGas(std::vector<Gas>& gvec, std::ostream& out) {
	for (auto& data : gvec) {//выводим инфу каждый элемент из вектора
		data.print(out);
	}
}