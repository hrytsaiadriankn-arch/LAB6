#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void fillArray(int a[], int n, int low, int high);
int countElements(int a[], int n);
int sumElements(int a[], int n);
void zeroElements(int a[], int n);

namespace UnitTestArray
{
    TEST_CLASS(UnitTestArray)
    {
    public:

        TEST_METHOD(TestCountElements)
        {
            int a[25] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                          16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
            int expected = 2; 
            int result = countElements(a, 25);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestSumElements)
        {
            int a[25] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                          16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
            int expected = 2 + 16; 
            int result = sumElements(a, 25);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestZeroElements)
        {
            int a[25] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                          16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
            zeroElements(a, 25);
            Assert::AreEqual(0, a[0]);
            Assert::AreEqual(0, a[13]);
            Assert::AreEqual(4, a[2]); 
        }
    };
}
