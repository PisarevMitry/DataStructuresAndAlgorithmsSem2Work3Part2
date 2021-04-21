#include <iostream>
#include <chrono>

using namespace std;

//Переменная для подсчета количества сравнений
int comparison;
//Переменная для подсчета количества перемещений
int movement;

void createMatrix(int**& matrix, int n, int m)
{
	matrix = new int* [n];//n строк
	for (int i = 0; i < n;i++)
	{
		matrix[i] = new int[m];//m столбцов
		for (int j = 0;j < m;j++)
		{
			matrix[i][j] = rand() % 5;
		}
	}
}

void printMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printMatrix(int* matrix, int n)
{
	for (int i = 0; i < n;i++)
	{
		cout << matrix[i];
		cout << endl;
	}
}

//Функция умножения матрицы на вектор
//Предусловие: на вход функции поступает ссылка на ненулевой двумерный массив размерности n*m, где n – количество строк, m – количество столбцов; ссылка на ненулевой вектор размерности k, где k – количество строк; ссылка на результирующий вектор. Параметры n, m, k больше нуля
//Постусловие: функция создает результирующий вектор по адресу переданному в параметрах
void matrixMultiplicat(int** matrix, int n, int m, int** vector, int k, int*& result)
{
	comparison = 0;
	movement = 0;

	comparison++;
	if (m != k)
	{
		cout << "Размерности не совпадаю, невозможно найти произведение." << endl;
	}
	else
	{
		movement++;
		result = new int[m];
		comparison++;
		for (int i = 0; i < m;i++)
		{
			movement++;
			result[i] = 0;
			comparison++;
		}

		comparison++;
		for (int i = 0;i < n;i++)
		{
			comparison++;
			for (int j = 0;j < m;j++)
			{
				movement++;
				result[i] += matrix[i][j] * vector[j][0];
				comparison++;
			}
			comparison++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int** matrix;
	int n = 9;
	int m = 10;
	createMatrix(matrix, n, m);
	cout << "Матрица: " << endl;
	printMatrix(matrix, n, m);

	int** vector;
	int k = 10;
	createMatrix(vector, k, 1);
	cout << "Вектор: " << endl;
	printMatrix(vector, k, 1);

	int* result = nullptr;

	auto begin = std::chrono::steady_clock::now();
	matrixMultiplicat(matrix, n, m, vector, k, result);
	auto end = chrono::steady_clock::now();

	cout << "Результирующий вектор: " << endl;
	printMatrix(result, n);

	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	cout << "Затраченнное время: " << elapsed_ms.count() << " ms\n";
}