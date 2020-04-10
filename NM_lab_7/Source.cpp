#include "Header.h"
#define SIZE 2
double fi2(double y)
{
	return (0.5 - cos(y - 1));
}

double f2(double x, double y)
{
	return (x + cos(y - 1) - 0.5);
}

double fi1(double x)
{
	return (3 + cos(x));
}

double f1(double x, double y)
{
	return (y - cos(x) - 3);
}

double f2DX(double x, double y)
{
	return 1;
}

double f2DY(double x, double y)
{
	return -1 * sin(y - 1);
}

double f1DX(double x, double y)
{
	return sin(x);
}

double f1DY(double x, double y)
{
	return 1;
}

void IterationMethod(double(*f1)(double), double(*f2)(double), const double eps)
{
	auto* result = new double[SIZE];
	auto* initValues = new double[SIZE];
	int iterationsCount = 0;
	cout << "Enter initial approximation: ";
	cin >> initValues[0] >> initValues[1];
	
	while (true)
	{
		iterationsCount++;
		result[1] = f1(initValues[0]);
		result[0] = f2(initValues[1]);
		if ((fabs(result[0] - initValues[0]) + fabs(result[1] - initValues[1])) < eps)
			break;
		initValues[0] = result[0];
		initValues[1] = result[1];
	}
	cout << "Simple iteration method did " << iterationsCount << " iterations and gave a result:" << endl;
	cout << "x = " << result[0] << endl;
	cout << "y = " << result[1] << endl;
	
}

void NewtonMethod(double(*f1)(double, double), double(*f2)(double, double),
	double(*f1DX)(double x, double y), double(*f1DY)(double x, double y),
	double(*f2DX)(double x, double y), double(*f2DY)(double x, double y), const double eps)
{
	auto** JacobiMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; ++i) {
		JacobiMatrix[i] = new double[SIZE];
	}
	auto* initValues = new double[SIZE];
	cout << "Enter initial approximation: ";
	cin >> initValues[0] >> initValues[1];
	double dx;
	int iterationsCount = 0;
	double* freeMembers1 = new double[SIZE];
	double* freeMembers2 = new double[SIZE];

	do
	{
		iterationsCount++;

		JacobiMatrix[0][0] = f1DX(initValues[0], initValues[1]);
		JacobiMatrix[0][1] = f1DY(initValues[0], initValues[1]);
		JacobiMatrix[1][0] = f2DX(initValues[0], initValues[1]);
		JacobiMatrix[1][1] = f2DY(initValues[0], initValues[1]);

		freeMembers1[0] = -f1(initValues[0], initValues[1]);
		freeMembers1[1] = -f2(initValues[0], initValues[1]);

		GaussianMethod(JacobiMatrix, freeMembers1, &freeMembers2[0], &freeMembers2[1], SIZE);

		initValues[0] += freeMembers2[0];
		initValues[1] += freeMembers2[1];

		if (freeMembers2[0] > freeMembers2[1])
		{
			dx = freeMembers2[0];
		}
		else
		{
			dx = freeMembers2[1];
		}
	} while (fabs(dx) > eps);
	cout << "Newton method did " << iterationsCount << " iterations and gave a result: \n";
	cout << "x = " << initValues[0] << endl;
	cout << "y = " << initValues[1] << endl;
	delete[] freeMembers2;
	for (int i = 0; i < SIZE; ++i) {
		delete[] JacobiMatrix[i];
	}
	delete[] JacobiMatrix;
}

void GaussianMethod(double** array, double* result, double* X, double* Y, const int& dimension)
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
				if (i == j)
				{
					A[k][j] = 0.0;
				}
				else
				{
					A[k][j] += c * A[i][j];
				}
			}
		}
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
	*X = x[0];
	*Y = x[1];
}
