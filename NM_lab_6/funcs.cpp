#include "funcs.h"

void printArray(double** array, const int& dimension)
{
	for (auto i = 0; i < dimension; ++i)
	{
		for (auto j = 0; j < dimension; ++j)
		{
			cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
		}
		cout << "| " << setprecision(4) << setw(7) << showpos << array[i][3] << endl;
	}
	cout << endl;
}

void printFullArray(double** array, double* res, const int& rows, const int& cols)
{
	for (auto i = 0; i < rows; ++i)
	{
		for (auto j = 0; j < cols; ++j)
		{
			cout << setprecision(4) << setw(7) << showpos << array[i][j] << " ";
		}
		cout << "| " << setprecision(4) << setw(7) << showpos << res[i] << endl;
	}
	cout << endl;
}

void squaresMethod(double** array, double* res, const int& rowsCount, const int& colsCount)
{
	double** transposed = new double* [colsCount];
	double** N = new double* [colsCount];
	double* C = new double[colsCount];
	for (int i = 0; i < colsCount; i++)
	{
		transposed[i] = new double[rowsCount];
		N[i] = new double[colsCount];
	}

	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < colsCount; j++)
		{
			transposed[j][i] = array[i][j];
		}
	}
	for (int i = 0; i < colsCount; i++)
	{
		double sum2 = 0;
		for (int j = 0; j < colsCount; j++)
		{
			double sum = 0;
			sum2 = 0;
			for (int k = 0; k < rowsCount; k++)
			{
				sum += transposed[i][k] * array[k][j];
				sum2 += transposed[i][k] * res[k];
			}
			N[i][j] = sum;
		}
		C[i] = sum2;
	}
	printFullArray(N, C, colsCount, colsCount);
	cout << "Gaussian method was started..." << endl;
	GaussianMethod(N, C, colsCount);
	for (int i = 0; i < colsCount; ++i)
	{
		delete[] N[i];
		delete[] transposed[i];
	}
	delete[] transposed;
	delete[] N;
	delete[] C;

}

void GaussianMethod(double** array, double* result, const int& dimension)
{
	double** A = new double* [dimension];
	for (int i = 0; i < dimension; ++i)
	{
		A[i] = new double[dimension + 1];
	}
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension + 1; ++j)
		{
			if (j != dimension)
			{
				A[i][j] = array[i][j];
			}
			else
			{
				A[i][j] = result[i];
			}
		}
	}
	for (int i = 0; i < dimension; ++i) //for each column
	{
		double maxEl = fabs(A[i][i]);
		int maxRow = i; //row index
		for (int k = i + 1; k < dimension; ++k) //for each row
		{
			if (fabs(A[k][i]) > maxEl)
			{
				maxEl = fabs(A[k][i]);
				maxRow = k;
			}
		}
		for (int k = i; k < dimension + 1; ++k) //swapping row
		{
			double tempEl = A[maxRow][k];
			A[maxRow][k] = A[i][k];
			A[i][k] = tempEl;
		}
		for (int k = i + 1; k < dimension; ++k) //a[j] -= a[i]*coefficient 
		{
			double c = -A[k][i] / A[i][i];
			for (int j = i; j < dimension + 1; ++j)
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
		printArray(A, dimension);
	}
	auto* x = new double[dimension];
	for (int i = dimension - 1; i >= 0; --i)
	{
		x[i] = A[i][dimension] / A[i][i];
		for (int k = i - 1; k >= 0; --k)
		{
			A[k][dimension] -= A[k][i] * x[i];
		}
	}
	cout << "Gaussian method gave a result: " << endl;
	for (int i = 0; i < dimension; ++i)
	{
		cout << "x" << noshowpos << i + 1 << " = " << setprecision(8) << x[i] << endl;
	}
}
