#include "Header.h"
#include "Headerzadania1.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите номер задания 1 или 2: ";
    cin >> N;
    if (N == 1) {
        zadanie1();
    }
    else {
        zadanie2();
    }

}