#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

using namespace std;
int main()
{
	const double x = 0.3;
	const double y = 2.9;
	const double z = 0.5;


	double a = (pow(z, 2) * x + exp(-x) * cos(y * x)) / (y * x - exp(-x) * sin(y * x) + 1);
	double b = exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
	cout << x << " " << y << " " << z << " ";
	cout << a << endl << b;


}