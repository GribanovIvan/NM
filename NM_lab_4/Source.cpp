#include "Header.h"
#include <vector>

void GaussianMethod(double** array, double* result, int size)
{
	double** A = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		A[i] = new double[size + 1];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size + 1; ++j)
		{
			if (j != size)
			{
				A[i][j] = array[i][j];
			}
			else
			{
				A[i][j] = result[i];
			}
		}
	}
	for (int i = 0; i < size; ++i) //for each column
	{
		double maxEl = fabs(A[i][i]);
		int maxRow = i; //row index
		for (int k = i + 1; k < size; ++k) //for each row
		{
			if (fabs(A[k][i]) > maxEl)
			{
				maxEl = fabs(A[k][i]);
				maxRow = k;
			}
		}
		for (int k = i; k < size + 1; ++k) //swapping row
		{
			double tempEl = A[maxRow][k];
			A[maxRow][k] = A[i][k];
			A[i][k] = tempEl;
		}
		for (int k = i + 1; k < size; ++k) //a[j] -= a[i]*coefficient 
		{
			double c = -A[k][i] / A[i][i];
			for (int j = i; j < size + 1; ++j)
			{
				if (i == j) //to avoid error while doing floating point operations
				{
					A[k][j] = 0.0;
				}
				else
				{
					A[k][j] += c * A[i][j];
				}
			}
		}
		printArray(A);
	}
	auto* x = new double[size];
	for (int i = size - 1; i >= 0; --i)
	{
		x[i] = A[i][size] / A[i][i];
		for (int k = i - 1; k >= 0; --k)
		{
			A[k][size] -= A[k][i] * x[i];
		}
	}
	cout << "Gaussian method gave a result: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << "x" << noshowpos << i + 1 << " = " << setprecision(8) << x[i] << endl;
	}
}

void findLU(double** a, double** l, double** u, int n)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j < i)
				l[j][i] = 0;
			else
			{
				l[j][i] = a[j][i];
				for (k = 0; k < i; k++)
				{
					l[j][i] = l[j][i] - l[j][k] * u[k][i];
				}
			}
		}
		for (j = 0; j < n; j++)
		{
			if (j < i)
				u[i][j] = 0;
			else if (j == i)
				u[i][j] = 1;
			else
			{
				u[i][j] = a[i][j] / l[i][i];
				for (k = 0; k < i; k++)
				{
					u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
				}
			}
		}
	}
}

void findY(double** array, double** l, double* y, int n)
{
	for (int i = 0; i < n; ++i)
	{
		double sum = array[i][n];
		for (int j = 0; j < i; ++j)
			sum -= y[j] * l[i][j];
		y[i] = sum / l[i][i];
	}
}
void findX(double** u, double* y, double* x, int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		double sum = y[i];
		for (int j = i + 1; j < n; ++j)
			sum -= x[j] * u[i][j];
		x[i] = sum / u[i][i];
	}
}

void LUMethod(double** array, double* res, int size)
{
	double** A = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		A[i] = new double[size + 1];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size + 1; ++j)
		{
			if (j != size)
			{
				A[i][j] = array[i][j];
			}
			else
			{
				A[i][j] = res[i];
			}
		}
	}
	double** l = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		l[i] = new double[size + 1];
	}
	double** u = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		u[i] = new double[size];
	}
	findLU(array, l, u, size);
	cout << "\nL decomposition: " << endl;
	printFullArray(l, res);
	cout << "\nU decomposition: " << endl;
	printFullArray(u, res);
	auto* y = new double[size];
	auto* x = new double[size];
	findY(A, l, y, size);
	findX(u, y, x, size);
	cout << "LU method gave a result: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << "x" << noshowpos << i + 1 << " = " << setprecision(8) << x[i] << endl;
	}
}

void printArray(double** array)
{
	for (auto i = 0; i < 3; ++i)
	{
		for (auto j = 0; j < 3; ++j)
		{
			cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
		}
		cout << "| " << setprecision(4) << setw(7) << showpos << array[i][3] << endl;
	}
	cout << endl;
}

void printFullArray(double** array, double* res)
{
	for (auto i = 0; i < 3; ++i)
	{
		for (auto j = 0; j < 3; ++j)
		{
			cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
		}
		cout << "| " << setprecision(4) << setw(7) << showpos << res[i] << endl;
	}
	cout << endl;
}

void fillWithDefault(double** array, double* res)
{
	const int dd = 3; //default size
	double def1[dd][dd] = { {0.46, 1.72, 2.53},
						  { 1.53, -2.23,  -1.83 },
                          { 0.75,  0.86, 3.72 } };
	double def2[dd] = { 2.44, 2.83, 1.06 };
	for (auto i = 0; i < dd; ++i)
	{
		for (auto j = 0; j < dd; ++j)
		{
			array[i][j] = def1[i][j];
		}
		res[i] = def2[i];
	}
}
