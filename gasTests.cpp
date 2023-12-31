#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication16\date.h"
#include "..\ConsoleApplication16\gas.h"
#include "sstream"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gasTests
{
	TEST_CLASS(gasTests)
	{
	public:
		
		TEST_METHOD(correctValueTest)
		{
			Gas g;

			g.CorrectValues("AI-95", 51.29);
		}

		TEST_METHOD(correctDateTest)
		{
			DateStruct date;

			std::string d = "11.09.22";

			date.CorrectDate(d);
		}

		TEST_METHOD(correctHomeTest) 
		{
			Stan stn;
			int h = 11;
			stn.correctHome(h);
		}
		
		TEST_METHOD(correctStreetTest) 
		{
			Stan stn;
			std::string str = "st.Chkalova";
			stn.correctStreet(str);
		}

		TEST_METHOD(correctDateReadTest) {
			DateStruct date;

			std::string d = "11.09.22";

			date.readDate(d);
		}

		TEST_METHOD(correctStanpeintTest) 
		{
			Stan stn;
			stn.setStreet("st.Chakolava");
			stn.setHome(10);
			std::string d = "st.Chakolava 10";
			std::stringstream pp;
			stn.printStan(pp);
			Assert::AreEqual(pp.str(), d);
		}

		TEST_METHOD(correctDatePrintTest) {
			DateStruct date;

			date.setDD(12);
			date.setMM(11);
			date.setYY(21);

			std::string d = "����: 12.11.21";

			std::stringstream st;//����� �����
			date.printDate(st);//������� ���� � �����, ����������, ���� �� ��, �� �������
			Assert::AreEqual(st.str(), d);//�������� �� �������
		}

		TEST_METHOD(correctGasReadTest) {
			Gas gs;

			std::stringstream f("");
			std::stringstream i("");
			std::vector<Gas> gvec;

			try {
				gs.readGas(f, i, gvec);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(correctGasPrintTest) {//�����
			Gas gs;
			DateStruct date;

			date.setDD(17);
			date.setMM(12);
			date.setYY(21);

			gs.setDate(date);

			gs.setGtype("AI-98");
			gs.setCost(56.78);

			std::string d = "����: 17.12.21 ��� �������: AI-98 ���������: 56.78\n";

			std::stringstream st;
			gs.print(st);
			Assert::AreEqual(st.str(), d);
		}

		TEST_METHOD(correctIsLeapYear) {//���������
			DateStruct date;

			date.isLeapYear(2024);
		}

		TEST_METHOD(correctCorrectFunction) {//�������� �� ��� ������ �������� ������������
			DateStruct date;

			date.Correct(12, 12, 12);
		}

		TEST_METHOD(invalidCorrectFunction) {//�������� �� ������������ ������
			DateStruct date;

			try {
				date.Correct(-11, 15, 9);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidIsLeapYear) {
			try {
				DateStruct date;
				date.isLeapYear(-2048);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidValuesTest)
		{

			try {
				Gas gs;
				gs.CorrectValues("ASD", 58.22);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidDateTest)
		{
			try {
				DateStruct date;

				std::string d = "48.23.22";

				date.CorrectDate(d);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidDateReadTest) {
			DateStruct date;

			std::string d = "12.12.13";

			date.readDate(d);
		}

		TEST_METHOD(invalidDatePrintTest) {
			DateStruct date;
			date.setDD(13);
			date.setMM(12);
			date.setYY(21);

			std::string d = "����: 12.12.21";

			std::stringstream st;
			date.printDate(st);
			Assert::AreNotEqual(st.str(), d);
		}

		TEST_METHOD(invalidStanPrintTest) 
		{
			Stan stn;
			stn.setHome(10);
			stn.setStreet("st.Chkalovo");
			std::string d = "st.Chkalovo 33";
			std::ostringstream st;
			stn.printStan(st);
			Assert::AreNotEqual(st.str(), d);
		}

		TEST_METHOD(invalidCorrectStreetFunction) {//�������� �� ������������ ������
			Stan stn;
			try {
				stn.correctStreet("tt.Chakolo");
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidCorrectHomeFunction) {//�������� �� ������������ ������
			Stan stn;
			try {
				stn.correctHome(-11);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidGasPrintTest) {
			Gas gs;
			DateStruct date;

			date.setDD(13);
			date.setMM(12);
			date.setYY(21);

			gs.setDate(date);

			gs.setGtype("AI-98");
			gs.setCost(59.23);

			std::string d = "����: 12.12.21 ��� �������: 33.3 ����:  45\n";

			std::stringstream st;
			gs.print(st);
			Assert::AreNotEqual(st.str(), d);
		}
	};
}
