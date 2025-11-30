#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Create(int* a, int size);
int CountNegative(int* a, int size);

template <typename T>
int CountNegativeT(T* a, int size);

namespace UnitTestIterative
{
    TEST_CLASS(UnitTestIterative)
    {
    public:

        TEST_METHOD(TestCountNegative)
        {
            int a[5] = { -5, 3, -2, 0, 7 };
            int expected = 2;

            int result = CountNegative(a, 5);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestCountNegativeT)
        {
            int a[5] = { -5, 3, -2, 0, 7 };
            int expected = 2;

            int result = CountNegativeT<int>(a, 5);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestEmptyArray)
        {
            int* a = nullptr;
            int expected = 0;

            int result = CountNegative(a, 0);
            Assert::AreEqual(expected, result);

            int resultT = CountNegativeT<int>(a, 0);
            Assert::AreEqual(expected, resultT);
        }

        TEST_METHOD(TestAllNegative)
        {
            int a[4] = { -1, -2, -3, -4 };
            int expected = 4;

            int result = CountNegative(a, 4);
            Assert::AreEqual(expected, result);

            int resultT = CountNegativeT<int>(a, 4);
            Assert::AreEqual(expected, resultT);
        }

        TEST_METHOD(TestNoNegative)
        {
            int a[4] = { 1, 2, 3, 4 };
            int expected = 0;

            int result = CountNegative(a, 4);
            Assert::AreEqual(expected, result);

            int resultT = CountNegativeT<int>(a, 4);
            Assert::AreEqual(expected, resultT);
        }
    };
}
