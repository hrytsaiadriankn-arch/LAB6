#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdlib>
using namespace std;

void fillArray(int a[], int n, int low, int high, int i = 0) {
    if (i == n) return;
    a[i] = low + rand() % (high - low + 1);
    fillArray(a, n, low, high, i + 1);
}

void printArray(int a[], int n, int i = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    printArray(a, n, i + 1);
}

int sumOddIndexElements(int a[], int n, int i = 1) {
    if (i >= n) return 0;
    return a[i] + sumOddIndexElements(a, n, i + 2);
}

void test_sumOddIndexElements() {
    int a1[] = {5, 10, 3, 7, 2, 4};
    assert(sumOddIndexElements(a1, 6) == 21);

    int a2[] = {5};
    assert(sumOddIndexElements(a2, 1) == 0);

    int a3[] = {3, 7};
    assert(sumOddIndexElements(a3, 2) == 7);

    int a4[1] = {0};
    assert(sumOddIndexElements(a4, 0) == 0);

    cout << "sumOddIndexElements tests passed!" << endl;
}

void test_fillArray() {
    const int n = 10;
    int a[n];
    fillArray(a, n, 1, 20);

    for (int i = 0; i < n; i++) {
        assert(a[i] >= 1 && a[i] <= 20);
    }

    cout << "fillArray tests passed!" << endl;
}

int main() {
    test_sumOddIndexElements();
    test_fillArray();

    cout << "All unit tests passed successfully!\n\n";

    int n;
    cout << "n = ";
    cin >> n;

    int* a = new int[n];
    fillArray(a, n, 1, 20);

    cout << "Array: ";
    printArray(a, n);

    int sum = sumOddIndexElements(a, n);
    cout << "Sum of elements with odd indices: " << sum << endl;

    delete[] a;
    return 0;
}