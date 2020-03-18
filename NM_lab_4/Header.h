#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

void fillWithDefault(double** array, double* res);
void printArray(double** array);
void printFullArray(double** array, double* res);
void GaussianMethod(double** A, double* result, int size);
void findLU(double** a, double** l, double** u, int n);
void findY(double** array, double** l, double** y, int n);
void findX(double** u, double* y, double* x, int n);
void LUMethod(double** array, double* res, int size);
