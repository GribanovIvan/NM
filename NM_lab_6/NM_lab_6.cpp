#include "funcs.h"

int main()
{
	int rowsCount = 5, colsCount = 3;
	auto** AArray = new double* [rowsCount];
	for (auto i = 0; i < rowsCount; ++i)
		AArray[i] = new double[colsCount];
	auto* BArray = new double[rowsCount];
	cout << "Do you want to enter new dimension and coefficients or use default ones?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	bool newValueEntered;
	while (cout << "So, your choice: " && !(cin >> newValueEntered))
	{
		std::cin.clear();																//clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
	if (newValueEntered)
	{
		cout << "Enter new dimension: ";
		cin >> rowsCount >> colsCount;
		cout << "Enter new coefficients: " << endl;
		for (auto i = 0; i < rowsCount; ++i)
		{
			for (auto j = 0; j < colsCount; ++j)
			{
				cin >> AArray[i][j];
			}
		}
		cout << "Enter new rvalues: " << endl;
		for (auto i = 0; i < rowsCount; ++i)
		{
			cin >> BArray[i];
		}
	}
	else
	{
		double coeffsArray[5][3] = { {5,  -1, -3},
									{1, 2, -1},
									{2,  7, -1},
									{1, -2, -1},
									{-1, 3, -2} };
		double coeffsBArray[5] = { -1, 4, -1, 3, -2 };
		for (int i = 0; i < rowsCount; ++i)
		{
			for (int j = 0; j < colsCount; ++j)
			{
				AArray[i][j] = coeffsArray[i][j];
			}
			BArray[i] = coeffsBArray[i];
		}
	}
	cout << "\nHere is your matrix: " << endl;
	printFullArray(AArray, BArray, rowsCount, colsCount);
	cout << "\nSmallest squares method was started..." << endl;
	squaresMethod(AArray, BArray, rowsCount, colsCount);
	for (auto i = 0; i < rowsCount; ++i)
	{
		delete[] AArray[i];
	}
	delete[] AArray;
	delete[] BArray;
	system("pause");
	return 0;
}
