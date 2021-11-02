#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
using namespace std;
/**
* \brief Функция, определяющая можно ли разместить 2 дома на участке
* \param const x-степень
* \param const a-длина участка
* \param const b-ширина участка
**/

double getPlotOfLand(const double x, const double a, const double b);

/**
* param const x-степень
* \param const p-длина 1 дома
* \param const q-ширина 1 дома
**/

double getHouse1(const double x, const double p, const double q);

/**
* param const x-степень
* \param const r-длина 2 дома
* \param const s-ширина 2 дома
**/

double getHouse2(const double x, const double r, const double s);





/**
* \brief точка входа в программу
**/

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "введите степень: \n ";
	double x;
	cin >> x;

	cout << "введите длину участка: \n ";
	double a;
	cin >> a;

	cout << "введите ширину участка: \n ";
	double b;
	cin >> b;

	cout << "введите длину 1 дома: \n ";
	double p;
	cin >> p;

	cout << "введите ширину 1 дома: \n ";
	double q;
	cin >> q;

	cout << "введите длину 2 дома: \n ";
	double r;
	cin >> r;

	cout << "введите ширину 2 дома: \n ";
	double s;
	cin >> s;

	if (getHouse1(x, p, q) + getHouse2(x, r, s) <= getPlotOfLand(x, a, b))
	{
		cout << "можно";
	}
	else
	{
		cout << "нельзя";
	}
}

double getHouse1(const double x, const double p, const double q)
{
	return (pow(p, x) * q);
}

double getHouse2(const double x, const double r, const double s)
{
	return(pow(r, x) * s);
}

double getPlotOfLand(const double x, const double a, const double b)
{
	return(pow(a, x) * b);
}