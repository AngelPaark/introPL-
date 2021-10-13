#include <iostream>
using namespace std;
int main()

{
	setlocale(LC_ALL, "Russian");
	const double c = 500;
	cout << "введите массу=";
	double m;
	cin >> m;

	cout << "введите начальную температуру=";
	double t;
	cin >> t;

	cout << "введите конечную температуру=";
	double t1;
	cin >> t1;

	if ((m <= 0) or (t > t1))
	{
		cout << "введены неправильные числа";
	}
	else
	{
		double q = c * m * (t1 - t);
		cout << q;
	}
}