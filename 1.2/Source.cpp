#include <iostream>
using namespace std;
int main()




{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� ����� = ";
	double a;
	cin >> a;

	cout << "������� �������� ����=";
	double b;
	cin >> b;

	cout << "������� ����� =";
	double c;
	cin >> c;
	if ((a <= 0) or (b <= 0) or (c <= 0))
	{
		cout << "������� ������������ �����";

	}
	else
	{


		double d = (a + b) / c;
		cout << d;
	}


}