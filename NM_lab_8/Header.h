#pragma once
#include <iostream>

using namespace std;

double lagrange(const double* x, const double* y, const double x0, const int size);
double newton(const double* x, const double* y, const double x0, const int size);
unsigned findFactorial(int n);
