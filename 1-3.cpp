#define _USE_MATH_DEFINES // for C++
#include <iostream>
using namespace std;

/**
* \brief Математическая функция, рассчитывающая количество теплоты q
* \param const m-масса детали
* \param const t0-начальная температура
* \param const t-конечная температура
* \return возвращает значение q
**/

double getQ(const double m, const double t0, const double t, const double c);

/**
* \brief точка входа в программу
* \return возвращает 0 в случае успешного выполнения
**/


int main()

{
	setlocale(LC_ALL, "Russian");
	const double c = 500;
	cout << "введите массу детали: \n";
	double m;
	cin >> m;

	cout << "введите начальную температуру: \n";
	double t0;
	cin >> t0;

	cout << "введите конечную температуру: \n";
	double t;
	cin >> t;

	const auto q = getQ(m, t0, t,c);
	cout << "q=" << q;
}

double getQ(const double m, const double t0, const double t, const double c)
{
	return c * m * (t - t0);
}