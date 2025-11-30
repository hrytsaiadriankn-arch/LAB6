#include <iostream>
#include <iomanip>
#include <cstdlib>
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

int countElements(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (i % 13 == 0 && a[i] % 2 == 0) c++;
    return c;
}

int sumElements(int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        if (i % 13 == 0 && a[i] % 2 == 0) s += a[i];
    return s;
}

void zeroElements(int a[], int n) {
    for (int i = 0; i < n; i++)
        if (i % 13 == 0 && a[i] % 2 == 0) a[i] = 0;
}

int main() {
    const int n = 25;
    int a[n];
    srand(time(0));
    fillArray(a, n, 15, 94);
    printArray(a, n);
    int c = countElements(a, n);
    int s = sumElements(a, n);
    zeroElements(a, n);
    cout << c << " " << s << endl;
    printArray(a, n);
}
