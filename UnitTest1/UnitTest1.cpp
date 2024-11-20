#include "pch.h"
#include "CppUnitTest.h"

#include "../lab-11.4/lab-11.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCalculateArithmeticMean)
		{

			double numbers1[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
			Assert::AreEqual(3.0, calculateArithmeticMean(numbers1, 5), 0.001, L"Неправильний результат для середнього арифметичного");

		}

		TEST_METHOD(TestCalculateGeometricMean)
		{

			double numbers1[] = { 1.0, 2.0, 3.0, 4.0 };
			Assert::AreEqual(2.213, calculateGeometricMean(numbers1, 4), 0.001, L"Неправильний результат для середнього геометричного");
		}

		TEST_METHOD(TestExtractNumbers)
		{
			string line1 = "12.5 and -3.4 are numbers";
			double numbers1[10];
			int count1 = extractNumbers(line1, numbers1, 10);
			Assert::AreEqual(2, count1, L"Кількість чисел неправильна");
			Assert::AreEqual(12.5, numbers1[0], 0.001, L"Перше число неправильне");
			Assert::AreEqual(-3.4, numbers1[1], 0.001, L"Друге число неправильне");
;
		}
	};
}
