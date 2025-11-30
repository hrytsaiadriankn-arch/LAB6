#include <iostream>
#include <iomanip>
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
