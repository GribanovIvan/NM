#include "header.h"

int main()
{
	cout << "Do you want to enter new coefs or use default one?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	bool newValueEntered;
	while (cout << "So, your choice: " && !(cin >> newValueEntered))
	{
		std::cin.clear();														//clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
	double indecesArray[3][3] = { {0.46, 1.72, 2.53},
								  {1.53, -2.23,  -1.83},
								  {0.75,  0.86, 3.72 } };
	double resultArray[3] = { 2.44, 2.83, 1.06 };
	if (newValueEntered)
	{
		cout << "Enter new coefficients: " << endl;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> indecesArray[i][j];
			}
		}
		cout << "Enter new rvalues: " << endl;
		for (int i = 0; i < 3; ++i)
		{
			cin >> resultArray[i];
		}
	}
	cout << "\nDo you want to see the steps?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	while (cout << "So, your choice: " && !(cin >> newValueEntered))
	{
		std::cin.clear();														//clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
	cout << "\nHere is yout matrix: " << endl;
	printFullArray(indecesArray, resultArray);
	cout << "Determinant: " << findDeterminant(indecesArray) << endl;
	cramerMethod(indecesArray, resultArray, newValueEntered);
	matrixMethod(indecesArray, resultArray, newValueEntered);
	system("pause");
	return 0;
}
