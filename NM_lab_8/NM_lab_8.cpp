#include "Header.h"

int main()
{
	int size;
	double* arrayX, * arrayY;
	double x0;
	bool secondMode = false;
	cout << "New arguments? \n1 - Yes 0 - No : ";
	cin >> secondMode;
	if (secondMode)
	{
		cout << "Enter column count: ";
		cin >> size;
		arrayX = new double[size];
		arrayY = new double[size];
		for (int i = 0; i < size; ++i)
		{
			cout << "Enter X" << i+1 << " ";
			cin >> arrayX[i];
		}
		for (int i = 0; i < size; ++i)
		{
			cout << "Enter Y" << i+1 << " ";
			cin >> arrayY[i];
		}
		cout << "Enter X0: ";
		cin >> x0;
	}
	else
	{
		size = 10;
		arrayX = new double[size] {0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6};
		arrayY = new double[size] {5.615, 5.467, 5.352, 5.193, 5.066, 4.946, 4.832, 4.722, 4.618, 4.519};
		x0 = 0.439;
	}
	cout << "Lagrange polinom: \n";
	cout << "x = " << x0 << "; f(x) = " << lagrange(arrayX, arrayY, x0, size) << endl;
	cout << "Newton polinom: \n";
	cout << "x = " << x0 << "; f(x) = " << newton(arrayX, arrayY, x0, size) << endl;
	system("pause");
	return 0;
}
