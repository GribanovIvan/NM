#include "header.h"

void printArray(double array[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << setw(10) << showpos << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printFullArray(double array[3][3], double res[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << showpos << array[i][j] << " ";
		}
		cout << "| " << res[i] << endl;
	}
	cout << endl;
}

double findDeterminant(double arr[3][3])
{
	double det = 0;
	det += arr[0][0] * arr[1][1] * arr[2][2];
	det += arr[0][1] * arr[1][2] * arr[2][0];
	det += arr[1][0] * arr[2][1] * arr[0][2];
	det -= arr[0][2] * arr[1][1] * arr[2][0];
	det -= arr[0][0] * arr[1][2] * arr[2][1];
	det -= arr[0][1] * arr[1][0] * arr[2][2];
	return det;
}

double findMinor(double array[3][3], int i0, int j0)
{
	double min[4];
	double minor;
	int z = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i != i0 && j != j0)
			{
				min[z] = array[i][j];
				z++;
			}
		}
	}
	minor = min[0] * min[3] - min[1] * min[2];
	return minor;
}

void copyArray(double array1[3][3], double array2[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array2[i][j] = array1[i][j];
		}
	}
}

void copyArrayAndSwapColumn(double array1[3][3], double array2[3][3], double res[3], int z)
{
	copyArray(array1, array2);
	for (int j = 0; j < 3; ++j)
	{
		array2[j][z] = res[j];
	}
}

void cramerMethod(double array[3][3], double res[3], bool printSteps)
{
	if (printSteps) cout << "\nCramer method was launched... " << endl;
	double roots[3];
	double array2[3][3];

	for (int z = 0; z < 3; ++z)
	{
		copyArrayAndSwapColumn(array, array2, res, z);
		if (printSteps) cout << "Determinant " << noshowpos << z + 1 << " = " << findDeterminant(array2) << endl;
		roots[z] = findDeterminant(array2) / findDeterminant(array);
	}
	cout << "\nCramer method gave a result: " << endl;
	cout << "x1 = " << roots[0] << "; x2 = " << roots[1] << "; x3 = " << roots[2] << endl;
}

void inverseMatrix(double array[3][3])
{
	double array2[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array2[i][j] = findMinor(array, i, j);
			if ((i + j) % 2)
			{
				array2[i][j] = -array2[i][j];
			}
		}
	}
	copyArray(array2, array);
}

void transpose(double array[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i < j)
			{
				double temp = array[i][j];
				array[i][j] = array[j][i];
				array[j][i] = temp;
			}
		}
	}
}

void multiplyArray(double array[3][3], double multVal)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array[i][j] *= multVal;
		}
	}
}

void matrixMethod(double array[3][3], double res[3], bool printSteps)
{
	if (printSteps) cout << "\nMatrix method was launched... " << endl;
	double multValue = 1 / findDeterminant(array);
	inverseMatrix(array);
	transpose(array);
	multiplyArray(array, multValue);
	cout << "Inversed matrix: " << endl;
	printArray(array);
	double roots[3]{ 0 };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			roots[i] += array[i][j] * res[j];
		}
	}
	cout << "Matrix method gave a result: " << endl;
	cout << noshowpos << "x1 = " << roots[0] << "; x2 = " << roots[1] << "; x3 = " << roots[2] << endl;
}

