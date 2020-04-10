#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double fi1(double x);
double f1(double x, double y);
double fi2(double y);
double f2(double x, double y);
double f1DX(double x, double y);
double f1DY(double x, double y);
double f2DX(double x, double y);
double f2DY(double x, double y);
void IterationMethod(double (*f1)(double), double(*f2)(double), const double eps);
void NewtonMethod(double(*f1)(double, double), double(*f2)(double, double),
	double(*f1DX)(double, double), double(*f1DY)(double, double),
	double(*f2DX)(double, double), double(*f2DY)(double, double), const double eps);
void GaussianMethod(double** A, double* result, double* X, double* Y, const int& dimension);
