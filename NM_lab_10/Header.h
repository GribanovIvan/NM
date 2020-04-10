#pragma once
#include <cmath>
#include <iostream>
using namespace std;

double myFunction(double x);
double Integral(double a, double b, int* N, double(*Function)(double a, double b, const int N));
double LeftRectangle(double a, double b, const int N);
double RightRectangle(double a, double b, const int N);
double MidRectangle(double a, double b, const int N);
double Trapezia(double a, double b, const int N);
double Simpsona(double a, double b, const int N);
