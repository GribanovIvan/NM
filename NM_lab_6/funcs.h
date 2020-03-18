#pragma once
#pragma comment(lib, "funcs.lib")
#include <iostream>
#include <iomanip>
using namespace std;

void printArray(double** array, const int& dimension);
void printFullArray(double** array, double* res, const int& rows, const int& cols);
void squaresMethod(double** array, double* res, const int& rowsCount, const int& colsCount);
void GaussianMethod(double** A, double* result, const int& dimension);
