#define _USE_MATH_DEFINES // for C++
#include <iostream>
using namespace std;


/**
 * \brief функция вычисляет факториал
 * \param k - переменная для вычисления элемента последовательности
 * \return значение факториала
*/
double Fakt(const double k);

/**
 * \brief функция считает текущий элемент последовательности
 * \param k - переменная для вычисления элемента последовательности
 * \return значение текущего элемента последовательности
*/
double getCurrentElement(const double k);

/**
 * \brief вычисление суммы первых n элементов последовательности
 * \param n - количество элементов последовательности
 * \param k - переменная для вычисления элемента последовательности
 * \return сумма первых n элементов последовательности
 */
double getSumm1(int n, double k);

/**
 * \brief вычисление суммы членов последовательности, не меньших числа e.
 * \param e - число, вводимое пользователем
 * \param k - переменная для вычисление элемента последовательности
 * \return сумма членов последовательности, не меньших числа e.
*/
double getSumm2(double e, double k);

/**
 * \brief точка входа в программу
 * \return 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	double e;
	double k = 0.0;
	cout << "Введите количество членов последовательности";
	cin >> n;
	cout << "Введите e ";
	cin >> e;
	cout << getSumm1(n, k)<<endl;
	cout << getSumm2(e, k);
	return 0;
}

double Fakt(const double k)
{
	if (k == 0)
		return 1;
	else
		return k * Fakt(k - 1);
}

double getCurrentElement(const double k) 
{
	return((1+k) /Fakt(k));
}

double getSumm1(int n, double k)
{
	double sum{};
	for (int i = 0; i <= n; i++)
	{
		sum = sum + getCurrentElement(k);
		k = k + 1;
	}
	return sum;
}

double getSumm2(double e, double k)
{
	double cur, sum{};
	cur = getCurrentElement(k);
	while (cur >= e)
	{
		sum = sum + cur;
		k++;
		cur = getCurrentElement(k);
	}
	return sum;
}