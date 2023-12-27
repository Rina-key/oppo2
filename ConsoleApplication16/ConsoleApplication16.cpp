#include <iostream>
#include<fstream>
#include<vector>
#include<string>

#include"date.h"
#include"Gas.h"

int main()
{
	setlocale(LC_ALL, "RU");

	std::ifstream file("test.txt");
    std::ifstream gin("st.txt");

	std::vector<Gas> gvec;

	Gas data;

	std::string error; //сюда будет записываться ошибка

	try {//для отлова ошибок, если нашли ушли в катч

		data.readGas(file, gin, gvec);
	}

	catch (std::runtime_error& errorMessage) {//вывод ошибки
		error = errorMessage.what();
	}

	data.printGas(gvec, std::cout);

	std::cout << error;
}