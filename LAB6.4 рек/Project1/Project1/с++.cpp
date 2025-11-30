#include <iostream>
#include <iomanip>
using namespace std;

void fillArrayRec(int arr[], int n, int i = 0) {
    if (i == n) return;
    cin >> arr[i];
    fillArrayRec(arr, n, i + 1);
}

void printArrayRec(int arr[], int n, int i = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << setw(5) << arr[i];
    printArrayRec(arr, n, i + 1);
}

int countNegativeRec(int arr[], int n, int i = 0) {
    if (i == n) return 0;
    return (arr[i] < 0) + countNegativeRec(arr, n, i + 1);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    fillArrayRec(arr, n);
    printArrayRec(arr, n);

    int neg = countNegativeRec(arr, n);
    cout << neg << endl;

    printArrayRec(arr, n);

    delete[] arr;
}