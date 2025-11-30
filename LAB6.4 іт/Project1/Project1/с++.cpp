#include <iostream>
#include <iomanip>
using namespace std;

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5) << arr[i];
    cout << endl;
}

int countNegative(int arr[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0) c++;
    return c;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    fillArray(arr, n);
    printArray(arr, n);

    int neg = countNegative(arr, n);
    cout << neg << endl;

    printArray(arr, n);

    delete[] arr;
}