#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int n, const int Low, const int High,int i)
{
    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        return Create(a, n, Low, High, i + 1);
    }
}

template<typename T>
void Create(T* a, const T n, const T Low, const T High, T i)
{
    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        return Create(a, n, Low, High, i + 1);
    }
}

void Print(int* a, const int n,int i)
{
    cout << setw(4) << a[i];
    if (i < n - 1)
    {
        Print(a, n, i + 1);
    }
    else
        cout << endl;
    
}

template<typename T>
void Print(T* a, const T n, T i)
{
    cout << setw(4) << a[i];
    if (i < n - 1)
    {
        Print(a, n, i + 1);
    }
    else
        cout << endl;

}


void Sort(int* a, const int size, int i, int j) // метод обміну (бульбашки)
{
    if (a[j] < a[j + 1]) // якщо порушено порядок
    { // - обмін елементів місцями
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
    }
    if (j < size - i - 1) // j - номер поточного елемента
        Sort(a, size, i, j + 1); // перехід до наступного елемента

    if (i < size - 1) // i - лічильник ітерацій
        Sort(a, size, i + 1, 0); // перехід до наступної ітерації
}

template<typename T>
void Sort(T* a, const T size, T i, T j) // метод обміну (бульбашки)
{
    if (a[j] < a[j + 1]) // якщо порушено порядок
    { // - обмін елементів місцями
        T tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
    }
    if (j < size - i - 1) // j - номер поточного елемента
        Sort(a, size, i, j + 1); // перехід до наступного елемента

    if (i < size - 1) // i - лічильник ітерацій
        Sort(a, size, i + 1, 0); // перехід до наступної ітерації
}


int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    int Low = 0;
    int High =7;
    Create(a, n, Low, High,0);
    Print(a, n,0);
    Sort(a, n, 1,0);
    Print(a, n, 0);
    delete[]a;
    a = nullptr;
    return 0;
}
