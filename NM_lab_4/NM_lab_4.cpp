#include "Header.h"

int main()
{
	const auto dd = 3; //default size of the array
	auto** AArray = new double* [dd];
	for (auto i = 0; i < dd; ++i)
		AArray[i] = new double[dd];
	auto* BArray = new double[dd];
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
		}
		cout << "Enter new rvalues: " << endl;
		for (auto i = 0; i < sizeCount; ++i)
		{
			cin >> BArray[i];
		}
	}
	else
	{
		fillWithDefault(AArray, BArray);
		sizeCount = 3;
	}
	cout << "\nHere is your matrix: " << endl;
	printFullArray(AArray, BArray);
	cout << "\n Gaussian method was started..." << endl;
	GaussianMethod(AArray, BArray, sizeCount);
	cout << "\n LU method was started..." << endl;
	LUMethod(AArray, BArray, sizeCount);
	system("pause");
	return 0;
}
