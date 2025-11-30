#include <iostream>
#include <iomanip>
using namespace std;

void Create(int* a, int size);
void Print(int* a, int size);
int CountNegative(int* a, int size);

template <typename T>
int CountNegativeT(T* a, int size);

int main()
{
    const int n = 10;
    int a[n];

    Create(a, n);
    Print(a, n);

    int c1 = CountNegative(a, n);
    cout << c1 << endl;

    int c2 = CountNegativeT<int>(a, n);
    cout << c2 << endl;

    return 0;
}

void Create(int* a, int size)
{
    for (int i = 0; i < size; i++)
        a[i] = rand() % 21 - 10;
}

void Print(int* a, int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int CountNegative(int* a, int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < 0)
            k++;
    return k;
}

template <typename T>
int CountNegativeT(T* a, int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < 0)
            k++;
    return k;
}