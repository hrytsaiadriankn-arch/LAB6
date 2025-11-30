#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void fillArrayRec(int a[], int i, int n, int low, int high) {
    if (i == n) return;
    a[i] = low + rand() % (high - low + 1);
    fillArrayRec(a, i + 1, n, low, high);
}

void printArrayRec(int a[], int i, int n) {
    if (i == n) { cout << endl; return; }
    cout << setw(4) << a[i];
    printArrayRec(a, i + 1, n);
}

int countRec(int a[], int i, int n) {
    if (i == n) return 0;
    return (i % 13 == 0 && a[i] % 2 == 0) + countRec(a, i + 1, n);
}

int sumRec(int a[], int i, int n) {
    if (i == n) return 0;
    return ((i % 13 == 0 && a[i] % 2 == 0) ? a[i] : 0) + sumRec(a, i + 1, n);
}

void zeroRec(int a[], int i, int n) {
    if (i == n) return;
    if (i % 13 == 0 && a[i] % 2 == 0) a[i] = 0;
    zeroRec(a, i + 1, n);
}

int main() {
    const int n = 25;
    int a[n];
    srand(time(0));
    fillArrayRec(a, 0, n, 15, 94);
    printArrayRec(a, 0, n);
    int c = countRec(a, 0, n);
    int s = sumRec(a, 0, n);
    zeroRec(a, 0, n);
    cout << c << " " << s << endl;
    printArrayRec(a, 0, n);
}
