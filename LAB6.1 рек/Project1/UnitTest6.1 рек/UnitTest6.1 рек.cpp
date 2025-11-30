#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int countRec(int a[], int i, int n);
int sumRec(int a[], int i, int n);
void zeroRec(int a[], int i, int n);

namespace UnitTestRecursive
{
	TEST_CLASS(UnitTestRecursive)
	{
	public:

		TEST_METHOD(TestCountRec)
		{
			int a[25] = { 2,5,7,8,9,4,6,3,2,1,5,7,8,10,4,6,7,8,1,3,2,4,6,8,10 };
			Assert::AreEqual(1, countRec(a, 0, 25));
		}

		TEST_METHOD(TestSumRec)
		{
			int a[25] = { 2,5,7,8,9,4,6,3,2,1,5,7,8,10,4,6,7,8,1,3,2,4,6,8,10 };
			Assert::AreEqual(2, sumRec(a, 0, 25));
		}

		TEST_METHOD(TestZeroRec)
		{
			int a[25] = { 2,5,7,8,9,4,6,3,2,1,5,7,8,10,4,6,7,8,1,3,2,4,6,8,10 };
			zeroRec(a, 0, 25);
			Assert::AreEqual(0, a[0]);
		}
	};
}
