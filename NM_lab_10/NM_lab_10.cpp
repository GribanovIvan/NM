#include "Header.h"
#include <iomanip>

int main()
{
	const double leftBorder = 2, rightBorder = 10;
	int count = 0;
	cout << "Left border = " << leftBorder << ", right border = " << rightBorder << endl << endl;
	cout << "Left rectangles method:   y = " << setprecision(10) << Integral(leftBorder, rightBorder, &count, LeftRectangle) << endl;
	cout << "Right rectangles method:  y = " << setprecision(10) << Integral(leftBorder, rightBorder, &count, RightRectangle) << endl;
	cout << "Middle rectangles method: y = " << setprecision(10) << Integral(leftBorder, rightBorder, &count, MidRectangle) << endl;
	cout << "Trapeze method:           y = " << setprecision(10) << Integral(leftBorder, rightBorder, &count, Trapezia) << endl;
	cout << "Simpson method:           y = " << setprecision(10) << Integral(leftBorder, rightBorder, &count, Simpsona) << endl;
	system("pause");
	return 0;
}
