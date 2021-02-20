#pragma once

void FillRand(int** arr, const int m, const int n);
void FillRand(float** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
void FillRand(char** arr, const int m, const int n);

template<typename T>
void Print(T** arr, const int m, const int n);
template<typename T>
T** Allocate(const int m, const int n);
void Clear(int** arr, const int m, const int n);

template<typename T>
void push_row_back(T**& arr, int& m, int& n);
template<typename T>
void push_row_front(T**& arr, int& m, int& n);
template<typename T>
void push_by_index(T**& arr, int& m, int& n, const int index);

template<typename T>
void push_col_back(T**& arr, int& m, int& n);
template<typename T>
void push_col_front(T**& arr, int& m, int& n);
template<typename T>
void insert_col(T**& arr, int& m, int& n, int index);

template<typename T>
void pop_row_back(T**& arr, int& m, int& n);
template<typename T>
void pop_row_front(T**& arr, int& m, int& n);
template<typename T>
void pop_col_back(T**& arr, int& m, int& n);

template<typename T>
void erase_row(T**& arr, int& m, const int n, int index);
template<typename T>
void pop_col_front(T**& arr, int& m, int& n);
template<typename T>
void erase_col(T**& arr, int& m, int& n, const int index);