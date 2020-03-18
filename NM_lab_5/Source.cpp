#include "Header.h"


void printArrayJacobi(double* array)
{
	for (auto i = 0; i < 4; ++i)
	{
		cout << setprecision(4) << setw(7) << showpos << array[i] << " " << noshowpos;
	}
	cout << endl;
}

void printArraySeidel(double* array)
{
	for (auto i = 0; i < 4; ++i)
	{
		cout << setprecision(4) << setw(7) << showpos << array[i] << " " << noshowpos;
	}
	cout << endl;
}


void printFullArrayJacobi(double** array, double* res)
{
	for (auto i = 0; i < 4; ++i)
	{
		for (auto j = 0; j < 4; ++j)
		{
			cout << setprecision(2) << setw(6) << showpos << array[i][j] << "x" << noshowpos << j + 1 << " ";
		}
		cout << setprecision(2) << setw(7) << showpos << res[i] << noshowpos << endl;
	}
	cout << endl;
}

void printFullArraySeidel(double** array, double* res)
{
	for (auto i = 0; i < 4; ++i)
	{
		for (auto j = 0; j < 4; ++j)
		{
			cout << setprecision(2) << setw(6) << showpos << array[i][j] << "x" << noshowpos << j + 1 << " ";
		}
		cout << setprecision(2) << setw(7) << showpos << res[i] << noshowpos << endl;
	}
	cout << endl;
}

void jacobiMethod(double** arrayA, double* arrayB, double eps)
{
	const int dd = 4;
	double max;
	double arrayX[dd],dif[dd], arrayX0[dd] = {0,0,0,0};
	auto** array = new double* [dd];
	for (int i = 0; i < dd; ++i)
	{
		array[i] = new double[dd];
	}
	auto* res = new double[dd];
	for (int i = 0; i < dd; ++i) {
		arrayX[i] = 0;
	}
	int iterationCount = 1;
	for (int i = 0; i < dd; ++i)
	{
		res[i] =  arrayB[i]/ arrayA[i][i];
	}
	for (int i = 0; i < dd; ++i) {
		for (int j = 0; j < dd; ++j)
		{
			if (i == j)
			{
				array[i][i] = 0;
				continue;
			}
			array[i][j] = -arrayA[i][j] / arrayA[i][i];
		}
	}
	cout << "\nMatrix was normed: " << endl;
	printFullArrayJacobi(array, res);
	if (checkForRoots(array, dd)) {
		do
		{
			for (int i = 0; i < dd; ++i)
			{
				arrayX0[i] = arrayX[i];
			}
			for (int i = 0; i < dd; ++i)
			{
				arrayX[i] = res[i];
				for (int j = 0; j < dd; ++j)
				{
					if (j == i) continue;
					arrayX[i] += array[i][j] * arrayX0[j];
				}
			}
			for (int i = 0; i < dd; i++) {
				dif[i] = abs(arrayX[i] - arrayX0[i]);
			}

			max = dif[0];

			for (int i = 0; i < dd; i++) {
				if (max < dif[i]) {
					max = dif[i];
				}
			}

			cout << iterationCount;
			printArrayJacobi(arrayX);
			iterationCount++;
		} while (max > eps);
	}
	else 
		cout << "Jacobi method couldn`t get a result. Given matrix don`t have a solution." << endl;
	for (int i = 0; i < dd; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
	delete[] res;
}

void seidelMethod(double** array, double* res, double eps)
{
	const int dd = 4;
	double arrayX[dd], arrayX0[dd];
	auto** arrayA = new double* [dd];
	for (int i = 0; i < dd; ++i)
	{
		arrayA[i] = new double[dd];
	}
	auto* arrayB = new double[dd];
	for (int i = 0; i < dd; ++i)
	{
		arrayB[i] = res[i] / array[i][i];
	}
	for (int i = 0; i < dd; ++i) {
		for (int j = 0; j < dd; ++j)
		{
			if (i == j)
			{
				arrayA[i][i] = 0;
				continue;
			}
			arrayA[i][j] = -array[i][j] / array[i][i];
		}
	}
	cout << "\nMatrix was normed: " << endl;
	printFullArraySeidel(arrayA, arrayB);
	if (checkForRoots(arrayA, dd)) {
		for (int i = 0; i < dd; ++i)
		{
			arrayX[i] = 0;
		}
		int iterationCount = 1;
		do
		{
			for (int i = 0; i < dd; ++i)
			{
				arrayX0[i] = arrayX[i];
			}
			for (int i = 0; i < dd; ++i)
			{
				arrayX[i] = arrayB[i];
				for (int j = 0; j < dd; ++j)
				{
					if (j == i) continue;
					arrayX[i] += arrayA[i][j] * arrayX[j];
				}
			}
			cout << iterationCount << " ";
			printArraySeidel(arrayX);
			iterationCount++;
		} while (!(fabs(arrayX[0] - arrayX0[0]) < (eps)));
	}
	else
	{
		cout << "Seidel method couldn`t get a result. Given matrix don`t have a solution." << endl;
	}
	for (int i = 0; i < dd; ++i)
	{
		delete[] arrayA[i];
	}
	delete[] arrayA;
	delete[] arrayB;
}

bool checkForRoots(double** arrayA, int size)
{
	double sum;
	for (int i = 0; i < size; ++i)
	{
		sum = 0;
		for (int j = 0; j < size; ++j)
		{
			sum += arrayA[i][j];
		}
		if (sum > 1)
		{
			return false;
		}
	}
	return true;
}

void fillWithDefaultJacobi(double** array, double* res)
{
	const int dd = 4; //default size
	double def1[dd][dd] = { { 0.63,  -0.14, 0.06, -0.12},
							{-0.12, 0.52,  0.0,  -0.18},
							{ 0.08,  -0.12, 1.23,  0.32},
							{ 0.25, 0.22,  0.14, 1.12} };
	double def2[dd] = { -1.21, -0.72, 0.58, -1.56 };
	for (auto i = 0; i < dd; ++i)
	{
		for (auto j = 0; j < dd; ++j)
		{
			array[i][j] = def1[i][j];
		}
		res[i] = def2[i];
	}
}

void fillWithDefaultSeidel(double** array, double* res)
{
	const int dd = 4; //default size
	double def1[dd][dd] = { { 0.63,  -0.14, 0.06, -0.12},
							{-0.12, 0.52,  0.0,  -0.18},
							{ 0.08,  -0.12, 1.23,  0.32},
							{ 0.25, 0.22,  0.14, 1.12} };
	double def2[dd] = { -1.21, -0.72, 0.58, -1.56 };
	for (auto i = 0; i < dd; ++i)
	{
		for (auto j = 0; j < dd; ++j)
		{
			array[i][j] = def1[i][j];
		}
		res[i] = def2[i];
	}
}
