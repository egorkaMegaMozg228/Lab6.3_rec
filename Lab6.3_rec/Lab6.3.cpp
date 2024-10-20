#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(int* arr, int size, int Min = -20, int Max = 30, int i = 0)
{


    if (i < size)
    {
        arr[i] = Min + rand() % (Max - Min + 1);
        i++;
        create(arr, size, Min, Max, i);
    }
}


template <typename T>
void SecondCreate(T* arr, const int size,const T Min,const T Max, int i=0) {
    if (i < size)
    {
        arr[i] = Min + rand() % (Max - Min + 1);
        i++;
        create(arr, size, Min, Max, i);
    }
}


void Print(int* arr, int size,int i=0)
{
    if (i < size) {
        cout << setw(4) << arr[i];
        i++;
        Print(arr, size, i);
    }

}


template <typename T>
void Print1(const T* arr, int size,int i=0) {
    if (i < size) {
        cout << setw(4) << arr[i];
        i++;
        Print1(arr, size, i);
    }

}



void Sort(int* arr, const int size, int i=1,int j=0) // метод обміну (бульбашки)
{
    if (!(arr[j] > arr[j + 1])) // якщо порушено порядок
    { // - обмін елементів місцями
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
    }
    if (j < size - i - 1) // j - номер поточного елемента
        Sort(arr, size, i, j + 1); // перехід до наступного елемента

    if (i < size - 1) // i - лічильник ітерацій
        Sort(arr, size, i + 1, 0); // перехід до наступної ітерації
}




template <typename T>
void Sort1(T* arr, const int size,int i=1, int j=0) {
    if (!(arr[j] > arr[j + 1])) // якщо порушено порядок
    { // - обмін елементів місцями
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
    }
    if (j < size - i - 1) // j - номер поточного елемента
        Sort(arr, size, i, j + 1); // перехід до наступного елемента

    if (i < size - 1) // i - лічильник ітерацій
        Sort(arr, size, i + 1, 0); // перехід до наступної ітерації
}





int main()
{
    srand((unsigned)time(NULL));

    const int size = 10;
    int arr[size];
    create(arr, size);
    Print(arr, size); 
    cout << endl;
    Sort(arr, size);
    Print(arr, size);
    cout << endl;
    SecondCreate(arr, size, -20, 30);
    Print1(arr, size);
    cout << endl;
    Sort1(arr, size);
    Print1(arr, size);
    return 0;
}