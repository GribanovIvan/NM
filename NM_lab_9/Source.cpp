#include "Header.h"
#include <cmath>
double* aproximation(const double* x, const double* y, const int k, const int n)
{
	auto a = new double* [n + 1];
	for (int i = 0; i <= n; ++i)
		a[i] = new double[n + 1];
	auto b = new double[n + 1];
	auto z = new double[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			double sum = 0;
			if (i == 0 && j == 0)
				a[i][j] = k;
			else
			{
				for (int q = 0; q < k; ++q)
				{
					sum += pow(x[q], i + j);
				}
				a[i][j] = sum;
			}
		}
		double sum = 0;
		for (int q = 0; q < k; ++q)
		{
			sum += y[q] * ((i == 0) ? 1 : pow(x[q], i));
		}
		b[i] = sum;
	}
	cout << "\nMatrix of coefficients:" << endl;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
			printf("% .3lf", a[i][j]);
		printf(" |% .3lf\n", b[i]);
	}
	gaussianMethod(n + 1, a, b, z);
	for (int i = 0; i <= n; ++i)
		delete a[i];
	delete a;
	delete b;
	return z;
}
void gaussianMethod(const int n, double** a, const double* b, double* rad)
{
	double coef = 0, temp, max;
	auto a1 = new double* [n];
	auto b1 = new double[n];
	auto x = new double[n];
	for (int i = 0; i < n; i++)
		a1[i] = new double[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a1[i][j] = a[i][j];
		b1[i] = b[i];
	}
	for (int f, k = 0; k < n; k++)
	{
		max = a1[k][k];
		f = k;
		for (int i = 0; i < n; i++)
		{
			if (i < k)
				continue;
			else if (a1[i][k] > fabs(max))
			{
				max = a1[i][k];
				f = i;
			}
		}
		if (max != a1[k][k])
		{
			for (int j = 0; j < n; j++)
			{
				temp = a1[f][j];
				a1[f][j] = a1[k][j];
				a1[k][j] = temp;
			}
			temp = b1[f];
			b1[f] = b1[k];
			b1[k] = temp;
		}
		for (int i = 0; i < n; i++)
		{
			if ((i < k) || (k == 0))
				continue;
			else
			{
				double tmp = a1[i][k - 1] / a1[k - 1][k - 1];
				for (int j = 0; j < n; j++)
				{
					if (j < k)
						a1[i][j] = 0;
					else
					{
						a1[i][j] = a1[i][j] - a1[i - 1][j] * tmp;
					}
				}
				b1[i] = b1[i] - b1[i - 1] * tmp;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		x[i] = (b1[i] - coef) / a1[i][i];
		if (i == 0)
			break;
		else
			coef += x[i] * a1[i - 1][i];
	}
	for (int i = 0; i < n; i++)
		rad[i] = x[i];
	for (int i = 0; i < n; i++)
		delete a1[i];
	delete a1;
	delete b1;
	delete x;
}
