#include <iostream>
#include <iomanip>
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
