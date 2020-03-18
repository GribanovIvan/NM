#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

void fillWithDefaultJacobi(double** array, double* res);
void fillWithDefaultSeidel(double** array, double* res);
void printArrayJacobi(double* array);
void printArraySeidel(double* array);
void printFullArrayJacobi(double** array, double* res);
void printFullArraySeidel(double** array, double* res);
void jacobiMethod(double** arrayA, double* arrayB, double eps);
void seidelMethod(double** arrayA, double* arrayB, double eps);
bool checkForRoots(double** arrayA, int size);
