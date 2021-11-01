#define _USE_MATH_DEFINES // for C++
#include <iostream>
using namespace std;

/**
* \brief Математическая функция, рассчитывающая количество теплоты q
* \param HEAT_CAPACITY-теплоемкость стали
* \param const m-масса детали
* \param const tStart-начальная температура
* \param const tFinish -конечная температура
* \return возвращает значение q
**/

double getQ(const double m, const double tStart, const double tFinish, const double HEAT_CAPACITY);

/**
* \brief точка входа в программу
* \return возвращает 0 в случае успешного выполнения
**/


int main()

{
	setlocale(LC_ALL, "Russian");
	const double HEAT_CAPACITY = 500;
	cout << "введите массу детали: \n";
	double m;
	cin >> m;

	cout << "введите начальную температуру: \n";
	double tStart;
	cin >> tStart;

	cout << "введите конечную температуру: \n";
	double tFinish;
	cin >> tFinish;

	const auto q = getQ(m, tStart, tFinish, HEAT_CAPACITY);
	cout << "q=" << q;
}

double getQ(const double m, const double tStart, const double tFinish, const double HEAT_CAPACITY)
{
	return HEAT_CAPACITY * m * (tFinish - tStart);
}
	