#pragma once
#include <iostream>
#include <iomanip>

using namespace std;
void printArray(double array[3][3]);
void printFullArray(double array[3][3], double res[3]);
double findDeterminant(double array[3][3]);
double findMinor(double array[3][3], int i, int j);
void copyArray(double array1[3][3], double array2[3][3]);
void copyArrayAndSwapColumn(double array1[3][3], double array2[3][3], double res[3], int z);
void cramerMethod(double array[3][3], double res[3], bool printSteps);
void inverseMatrix(double array[3][3]);
void transpose(double array[3][3]);
void multiplyArray(double array[3][3], double multVal);
void matrixMethod(double array[3][3], double res[3], bool printSteps);

