#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void fillArray(int a[], int n, int low, int high) {
    for (int i = 0; i < n; i++)
        a[i] = low + rand() % (high - low + 1);
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int sumOddIndexElements(int a[], int n) {
    int sum = 0;
    for (int i = 1; i < n; i += 2)
        sum += a[i];
    return sum;
}

int main() {
    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    fillArray(a, n, 1, 20);
    printArray(a, n);
    int sum = sumOddIndexElements(a, n);
    cout << "Sum of elements with odd indices: " << sum << endl;
    delete[] a;
    return 0;
}
namespace UnitTestArray
{
    TEST_CLASS(UnitTestArray)
    {
    public:

        TEST_METHOD(TestSumOddIndexElements_EvenSize)
        {
            int arr[] = { 1, 2, 3, 4, 5, 6 };
            int expected = 2 + 4 + 6;
            int result = sumOddIndexElements(arr, 6);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestSumOddIndexElements_OddSize)
        {
            int arr[] = { 10, 20, 30, 40, 50 };
            int expected = 20 + 40;
            int result = sumOddIndexElements(arr, 5);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestSumOddIndexElements_EmptyArray)
        {
            int* arr = nullptr;
            int expected = 0;
            int result = sumOddIndexElements(arr, 0);
            Assert::AreEqual(expected, result);

        }

        TEST_METHOD(TestSumOddIndexElements_SingleElement)
        {
            int arr[] = { 7 };
            int expected = 0;
            int result = sumOddIndexElements(arr, 1);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestSumOddIndexElements_TwoElements)
        {
            int arr[] = { 5, 15 };
            int expected = 15;
            int result = sumOddIndexElements(arr, 2);
            Assert::AreEqual(expected, result);
        }
    };
}
