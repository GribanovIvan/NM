#include "Header.h"

int main()
{
	const auto dd = 4; //default size of the array
	double precision = 1e-2;
	auto** AArray = new double* [dd];
	for (auto i = 0; i < dd; ++i)
		AArray[i] = new double[dd];
	auto* BArray = new double[dd];
	cout << "Firstly, iteration (Jacobi) method will be launched... " << endl;
	cout << "Do you want to enter new size and coefficients or use default ones?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	bool newValueEntered;
	while (cout << "So, your choice: " && !(cin >> newValueEntered))
	{
		std::cin.clear();																//clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
	int sizeCount;
	if (newValueEntered)
	{
		cout << "Enter new size: ";
		cin >> sizeCount;
		cout << "Enter new coefficients: " << endl;
		for (auto i = 0; i < sizeCount; ++i)
		{
			for (auto j = 0; j < sizeCount; ++j)
			{
				cin >> AArray[i][j];
			}
			cin >> BArray[i];
		}
		cout << "Enter precision: ";
		cin >> precision;
	}
	else
	{
		fillWithDefaultJacobi(AArray, BArray);
		sizeCount = 4;
	}
	cout << "\nHere is your matrix: " << endl;
	printFullArrayJacobi(AArray, BArray);
	cout << "Started Jacobi method..." << endl;
	jacobiMethod(AArray, BArray, precision);
	for (int i = 0; i < dd; ++i)
	{
		delete[] AArray[i];
	}
	delete[] AArray;
	delete[] BArray;
	//--------------------------------------------------------------------------//
	//--------------------------------------------------------------------------//

	AArray = new double* [dd];
	for (auto i = 0; i < dd; ++i)
		AArray[i] = new double[dd];
	BArray = new double[dd];
	cout << "\nNow, Seidel method will be launched... " << endl;
	cout << "Do you want to enter new dimension and coefficients or use default ones?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	while (cout << "So, your choice: " && !(cin >> newValueEntered))
	{
		std::cin.clear();																//clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
	if (newValueEntered)
	{
		cout << "Enter new size: ";
		cin >> sizeCount;
		cout << "Enter new coefficients: " << endl;
		for (auto i = 0; i < sizeCount; ++i)
		{
			for (auto j = 0; j < sizeCount; ++j)
			{
				cin >> AArray[i][j];
			}
			cin >> BArray[i];
		}
		cout << "Enter precision: ";
		cin >> precision;
	}
	else
	{
		fillWithDefaultSeidel(AArray, BArray);
		sizeCount = 4;
	}
	cout << "\nHere is your matrix: " << endl;
	printFullArraySeidel(AArray, BArray);
	cout << "Started Seidel method..." << endl;
	seidelMethod(AArray, BArray, precision);
	for (int i = 0; i < dd; ++i)
	{
		delete[] AArray[i];
	}
	delete[] AArray;
	delete[] BArray;
	system("pause");
	return 0;
}
