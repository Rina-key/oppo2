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

	std::vector<Gas> gvec;

	Gas data;

	std::string error;

	try {

		data.readGas(file, gvec);
	}

	catch (std::runtime_error& errorMessage) {
		error = errorMessage.what();
	}

	data.printGas(gvec, std::cout);

	std::cout << error;
}