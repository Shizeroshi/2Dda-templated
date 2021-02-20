#pragma once

using namespace std;

template<typename T>
void erase_col(T**& arr, int& m, int& n, const int index)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n];
		for (int j = 0; j <= n; j++)
		{
			if (j == index)
				continue;
			buffer[j > index ? j - 1 : j] = arr[i][j];
		}
		arr[i] = buffer;
	}

}

template<typename T>
void insert_col(T**& arr, int& m, int& n, const int index)
{
	++n;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n];
		for (int j = 0; j < n; j++)
		{
			if (j == index)
			{
				buffer[j] = rand() % 1000;
				continue;
			}

			buffer[j] = arr[i][j > index ? j - 1 : j];
		}
		arr[i] = buffer;
	}
}

template<typename T>
void pop_col_front(T**& arr, int& m, int& n)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n];
		for (int j = 0; j <= n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		arr[i] = buffer;
	}
}

template<typename T>
void erase_row(T**& arr, int& m, const int n, int index)
{
	if (index > m) return;
	T** buffer = new T*[m - 1];
	for (int i = 0; i <= index; i++)
		buffer[i] = arr[i];
	for (int i = index + 1; i <= m; i++)
		buffer[i - 1] = arr[i];
	//delete[] arr;
	arr = buffer;
	//arr[index] = new int[m - 1];
	m--;
}

template<typename T>
void pop_col_back(T**& arr, int& m, int& n)
{
	T** buffer = new T*[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//delete[] arr;
	arr = buffer;
}

template<typename T>
void pop_row_front(T**& arr, int& m, int& n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//delete[] arr;
	arr = buffer;
}

template<typename T>
void pop_row_back(T**& arr, int& m, int& n)
{
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//delete[] arr;
	arr = buffer;
}

template<typename T>
void push_col_front(T**& arr, int& m, int& n)
{
	++n;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n];
		buffer[0] = rand() % 1000;
		for (int j = 1; j <= n; j++)
		{
			buffer[j] = arr[i][j - 1];
		}
		arr[i] = buffer;
	}
}

template<typename T>
void push_col_back(T**& arr, int& m, int& n)
{
	T** buffer = new T*[n + 1];
	buffer[m] = new T[n];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = n; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			buffer[j][i] = rand() % 1000;
		}
	}
	delete[] arr;
	arr = buffer;
	n++;
}

template<typename T>
void push_by_index(T**& arr, int& m, int& n, const int index)
{
	++m;
	T** buffer = new T*[m];
	for (int i = 0; i < m; i++)
	{
		if (i == index)
		{
			buffer[i] = new T[n];
			for (int j = 0; j < n; j++)
			{
				buffer[i][j] = rand() % 1000;
			}
			continue;
		}
		buffer[i] = arr[i > index ? i - 1 : i];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>
void push_row_front(T**& arr, int& m, int& n)
{
	++m;
	T** buffer = new T*[m];
	buffer[0] = new T[n];
	for (int i = 0; i < n; i++)
	{
		buffer[0][i] = rand() % 1000;
	}
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>
void push_row_back(T**& arr, int& m, int& n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[m] = new T[n];

	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = rand() % 1000;
	}
	++m;
	delete[] arr;
	arr = buffer;
}

void Clear(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete[] arr[i];

		}
	}
	delete[] arr;
}

template<typename T>
T** Allocate(const int m, const int n)
{
	// 1. Создаём массив указателей
	T** arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	return arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void FillRand(float** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = float(rand() % 100) / 10;
		}
	}
}

void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = double(rand() % 100) / 10;
		}
	}
}

void FillRand(char** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = char(rand() % 100);
		}
	}
}

//template<typename T> void Random(T& variable)
//{
//	if (typeid(variable) == typeid(int))
//	{
//		variable = rand() % 100;
//	}
//	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
//	{
//		variable == double(rand()10000) / 100;
//	}
//	else if (typeid(variable) == typeid(char))
//	{
//		variable == rand();
//	}
//	else
//	{
//		variable == T(); //записываем в переменную значение по умолчанию
//	}
//}

template<typename T>
void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}