#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void fillArray(int arr[], int n);
void printArray(int arr[], int n);
int countNegative(int arr[], int n);

namespace UnitTestArray
{
    TEST_CLASS(UnitTestArray)
    {
    public:

        TEST_METHOD(TestCountNegative_AllPositive)
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            int result = countNegative(arr, 5);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestCountNegative_AllNegative)
        {
            int arr[] = { -1, -2, -3, -4 };
            int result = countNegative(arr, 4);
            Assert::AreEqual(4, result);
        }

        TEST_METHOD(TestCountNegative_Mixed)
        {
            int arr[] = { -1, 0, 2, -3, 5, -6 };
            int result = countNegative(arr, 6);
            Assert::AreEqual(3, result);
        }

        TEST_METHOD(TestFillArray)
        {
            const int n = 3;
            int* arr = new int[n];

            istringstream input("10 -5 7");
            streambuf* cinbuf = cin.rdbuf();
            cin.rdbuf(input.rdbuf());

            fillArray(arr, n);

            cin.rdbuf(cinbuf);

            int expected[] = { 10, -5, 7 };
            for (int i = 0; i < n; i++)
                Assert::AreEqual(expected[i], arr[i]);

            delete[] arr;
        }

        TEST_METHOD(TestPrintArray_NoCrash)
        {
            const int n = 3;
            int arr[] = { 1, 2, 3 };

            printArray(arr, n);
            Assert::IsTrue(true);
        }
    };
}
