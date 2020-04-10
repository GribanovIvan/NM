#include "Header.h"
#define EPS 1e-3

double myFunction(double x)
{
	return (exp(1 + pow(x,double(1) / 3))/(1 - pow(x, double(1) / 3)));
}
//--------------------------------------------------------------------------------
double Integral(double a, double b, int* N, double(*Function)(double a, double b, const int N))
{
	*N = 1;
	while (fabs(Function(a, b, *N) - Function(a, b, *N * 2)) > EPS)
	{
		(*N) *= 2;
	}
	return Function(a, b, *N);
}
//--------------------------------------------------------------------------------
double LeftRectangle(double a, double b, const int N)
{
	double sum = 0, k = 0, i = a;
	const double step = ((b - a) / (double)N);
	while (i < b)
	{
		k = (step)*myFunction(i);
		i += step;
		sum += k;
	}
	return sum;
}
//--------------------------------------------------------------------------------
double RightRectangle(double a, double b, const int N)
{
	double sum = 0, k = 0, i = a;
	const double step = ((b - a) / (double)N);
	while (i < b)
	{
		k = (step)*myFunction(i + step);
		i += step;
		sum += k;
	}
	return sum;
}
//--------------------------------------------------------------------------------
double MidRectangle(double a, double b, const int N)
{
	double sum = 0, k = 0, i = a;
	const double step = ((b - a) / (double)N);
	while (i < b)
	{
		k = (step)*myFunction((2 * i + step) / 2.0);
		i += step;
		sum += k;
	}
	return sum;
}
//--------------------------------------------------------------------------------
double Trapezia(double a, double b, const int N)
{
	double sum = 0, k = 0, i = a;
	const double step = ((b - a) / (double)N);;
	while (i < b)
	{
		k = (step) * (myFunction(i) + myFunction(i + step)) / 2.0;
		i += step;
		sum += k;
	}
	return sum;
}
//--------------------------------------------------------------------------------
double Simpsona(double a, double b, const int N)
{
	double sum = 0, k = 0, i = a;
	const double step = ((b - a) / (double)N);
	while (i < b)
	{
		k = (step / 6.0) * (myFunction(i) + 4 * myFunction((2 * i + step) / 2.0) + myFunction(i + step));
		i += step;
		sum += k;
	}
	return sum;
}
