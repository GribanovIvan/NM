#pragma once
#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>
using namespace std;

double* aproximation(const double* x, const double* y, const int k, const int n);
void gaussianMethod(const int n, double** a, const double* b, double* rad);
