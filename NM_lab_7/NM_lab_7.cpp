#include "Header.h"

int main()
{
	double eps = 10e-4;
	cout << "\nSimple iteration method: \n";
	IterationMethod(fi1, fi2, eps);
	cout << "\nNewton method: \n";
	NewtonMethod(f1, f2, f1DX, f1DY, f2DX, f2DY, eps);
	system("pause");
	return 0;
}
