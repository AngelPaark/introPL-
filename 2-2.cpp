#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
using namespace std;

/**
* \brief эта функция выполняет вычисление при x<0.5
* \param const a - константа
* \param x- число, вводимое пользователем
* \return возвращает значение функции
**/
double getY1(const double a, const double x);

/**
* \brief эта функция выполняет вычисление при x>=0.5
* \param const a - константа
* \param x- число, вводимое пользователем
* \return возвращает значение функции
**/
double getY2(const double a, const double x);

/**
* brief Точка входа в программу
*  \return возвращает 0 в случае успешного выполнения
**/

int main()
{
	setlocale(LC_ALL, "Russian");
	const double a = 1.36;
	cout << "введите значение x: \n";
	double x;
	cin >> x;
	double y;

	if (x < 0.5)
	{
		y = getY1(a, x);
		cout << "y=" << y << "\n";
	}
	else
	{
		y = getY2(a, x);
		cout << "y=" << y;
	}

	return 0;
}

	double getY1(const double a, const double x)
	{
		return ( M_PI_2 + x * a - exp(a*x));
	}
	
	double getY2(const double a, const double x)
	{
		return (pow(x, 3) * a + 28);
	}