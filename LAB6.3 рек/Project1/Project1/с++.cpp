#include <iostream>
#include <iomanip>
using namespace std;

void Create(int* a, int size, int i);
void Print(int* a, int size, int i);
int CountNegative(int* a, int size, int i);

template <typename T>
int CountNegativeT(T* a, int size, int i);

int main()
{
    const int n = 10;
    int a[n];

    Create(a, n, 0);
    Print(a, n, 0);

    int c1 = CountNegative(a, n, 0);
    cout << c1 << endl;

    int c2 = CountNegativeT<int>(a, n, 0);
    cout << c2 << endl;

    return 0;
}

void Create(int* a, int size, int i)
{
    if (i < size)
    {
        a[i] = rand() % 21 - 10;
        Create(a, size, i + 1);
    }
}

void Print(int* a, int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else
        cout << endl;
}

int CountNegative(int* a, int size, int i)
{
    if (i < size)
        return (a[i] < 0) + CountNegative(a, size, i + 1);
    else
        return 0;
}

template <typename T>
int CountNegativeT(T* a, int size, int i)
{
    if (i < size)
        return (a[i] < 0) + CountNegativeT<T>(a, size, i + 1);
    else
        return 0;
}