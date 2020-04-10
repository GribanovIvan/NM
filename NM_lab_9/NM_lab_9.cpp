#include "Header.h"
int main()
{
	double x[6] = { 0.62, 0.69, 0.8, 1.01, 1.1, 1.15 };
	double y[6] = { 2.8, 2.94, 3.2, 3.38, 3.53, 3.75 };
	for (int n = 0; n < 3; ++n)
	{
		//for (int i = 0; i < 40; ++i) cout << "*";
		//cout << endl;
		cout << n << " degree polynomial: " << endl;
		double* z = aproximation(x, y, 6, n);
		cout << "\n P(x) = ";
		for (int i = 0; i <= n; ++i)
		{
			if (i == 0)
			{
				cout << setprecision(3) << z[i];
			}
			else
			{
				cout << setprecision(3) << " " << z[i] << "x^" << i;
			}
		}
		cout << endl;
		/*for (int i = 0; i < 40; ++i) cout << "*";
		cout << endl;*/
		delete z;
	}
	return 0;
}
