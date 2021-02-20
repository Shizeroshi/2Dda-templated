#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Prototype.h"
#include "Realization.h"

using namespace std;

//template<typename T> void Random(T& variable);

typedef double DataType;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	int m; // Кол-во строк
	int n; // Кол-во столбцов (элементов строки)

	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во элементов строки: "; cin >> n;

	// 2.Выделяем память для строк двумерного динамического массива
	DataType** arr = Allocate<DataType>(m, n);
	//srand(time(NULL));
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << endl;

	cout << "Добавление строки в конец" << endl;
	push_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "Добавление строки в  начало" << endl;
	push_row_front(arr, m, n);
	Print(arr, m, n);
	int index;
	cout << "Добавление строки в по индексу: "; cin >> index;
	push_by_index(arr, m, n, index);
	Print(arr, m, n);
	cout << "Добавление столбика в конец" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	cout << "Добавление столбика в начало" << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление строки в конце" << endl;
	pop_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление строки в начале" << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление столбика в конце" << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	int index2;
	cout << "Удаление строки по индексу: "; cin >> index2;
	erase_row(arr, m, n, index2);
	Print(arr, m, n);
	cout << "Удаление столбика в начале" << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	int index3;
	cout << "Добавление столбика по индексу: "; cin >> index3;
	insert_col(arr, m, n, index3);
	Print(arr, m, n);
	int index4;
	cout << "Удаление столбика по индексу: "; cin >> index4;
	erase_col(arr, m, n, index4);
	Print(arr, m, n);
}