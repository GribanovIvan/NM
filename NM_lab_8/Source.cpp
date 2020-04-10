#include "Header.h"

double lagrange(const double* x, const double* y, const double x0, const int size)
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		double denominator = 1, numerator = 1;
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				numerator *= x0 - x[j];
				denominator *= x[i] - x[j];
			}
		}
		result += numerator / denominator * y[i];
	}
	return result;

}

double newton(const double* x, const double* y, const double x0, const int size)
{
	double h = x[1] - x[0];
	double result = y[0];
	auto** dDeltaYArray = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		dDeltaYArray[i] = new double[size];
	}
	for (int i = 0; i < size; i++)
	{
		dDeltaYArray[i][0] = y[i];
	}

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			dDeltaYArray[j][i] = dDeltaYArray[j + 1][i - 1] - dDeltaYArray[j][i - 1];
		}
	}

	for (int i = 1; i < size; i++)
	{
		double numerator = dDeltaYArray[0][i], denominator = findFactorial(i), term = 0;
		for (int j = 0; j < i; j++)
		{
			numerator *= x0 - x[j];
			denominator *= h;
		}
		term = numerator / denominator;
		result += term;
	}
	return result;

}

unsigned findFactorial(int n)
{
	unsigned result = n;
	for (int i = n; i > 1; --i)
	{
		result *= i;
	}
	return result;
}
