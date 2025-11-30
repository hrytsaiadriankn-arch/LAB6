#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void fillArrayRec(int arr[], int n, int i = 0);
void printArrayRec(int arr[], int n, int i = 0);
int countNegativeRec(int arr[], int n, int i = 0);

namespace UnitTestRecursive
{
    TEST_CLASS(UnitTestRecursive)
    {
    public:

        TEST_METHOD(TestCountNegativeRec)
        {
            int arr1[] = { 1, -2, 3, -4, 5 };
            int result1 = countNegativeRec(arr1, 5);
            Assert::AreEqual(2, result1);

            int arr2[] = { -1, -2, -3 };
            int result2 = countNegativeRec(arr2, 3);
            Assert::AreEqual(3, result2);

            int arr3[] = { 1, 2, 3 };
            int result3 = countNegativeRec(arr3, 3);
            Assert::AreEqual(0, result3);
        }

        TEST_METHOD(TestPrintArrayRec)
        {
            int arr[] = { 1, 2, 3 };
            ostringstream oss;
            streambuf* oldCout = cout.rdbuf(oss.rdbuf());

            printArrayRec(arr, 3);

            cout.rdbuf(oldCout);

            string expected = "    1    2    3\n";
            Assert::AreEqual(expected, oss.str());
        }

        TEST_METHOD(TestFillArrayRecManual)
        {
            int arr[3];
            arr[0] = 10;
            arr[1] = -5;
            arr[2] = 7;

            int neg = countNegativeRec(arr, 3);
            Assert::AreEqual(1, neg);
        }
    };
}

