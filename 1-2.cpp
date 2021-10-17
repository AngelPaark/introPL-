#define _USE_MATH_DEFINES

#include <iostream>
using namespace std;

/**
* \brief Математическая функция, вычисляющая пройденный путь s
* \param const double v1 - скорость лодки
* \param const double v2 - скорость течения
* \param const double t - время движения
* \return возвращает значение s
**/
double getS(const double v1, const double v2, const double t);

/**
* \brief Точка входа в программу
* \return Возвращает 0 в случае успешного выполнения
**/


int main()

{
	setlocale(LC_ALL, "Russian");
	cout << "введите скорость лодки: \n";
	double v1;
	cin >> v1;

	cout << "введите скорость реки: \n";
	double v2;
	cin >> v2;

	cout << "введите время движения: \n";
	double t;
	cin >> t;

	const auto s = getS(v1, v2, t);
	cout << "s=" << s;
}

double getS(const double v1, const double v2, const double t)
{
	return (v1 + v2) * t;
}