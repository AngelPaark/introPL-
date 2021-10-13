#include <iostream>
using namespace std;
int main()




{
	setlocale(LC_ALL, "Russian");
	cout << "введите скорость лодки = ";
	double a;
	cin >> a;

	cout << "введите скорость реки=";
	double b;
	cin >> b;

	cout << "введите время =";
	double c;
	cin >> c;
	if ((a <= 0) or (b <= 0) or (c <= 0))
	{
		cout << "введены неправильные числа";

	}
	else
	{


		double d = (a + b) / c;
		cout << d;
	}


}