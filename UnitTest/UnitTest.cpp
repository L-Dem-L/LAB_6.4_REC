#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_6.4_REC/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Arrange
			const int size = 5;
			double arr[size] = { 0.0, -2.5, 1.8, -3.2, 4.7 };

			// Act
			int zerosCount = countZerosRecursive(arr, size, 0);
			double sumAfterMinResult = sumAfterMinRecursive(arr, size, 0, arr[0], 0);

			// Sorting odd elements
			double sortedArr[size];
			std::copy(arr, arr + size, sortedArr);
			sortOddElementsRecursive(sortedArr, size, 0);

			// Assert
			Assert::AreEqual(1, zerosCount);
			Assert::AreEqual(4.7, sumAfterMinResult, 0.001);

			double expectedSortedArr[size] = { 0.0, -2.5, 1.8, -3.2, 4.7 };
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expectedSortedArr[i], sortedArr[i], 0.001);
			}
		}
	};
}