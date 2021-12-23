#include<iostream>
#include<cmath>
#include <iomanip>
/**
* \brief Рассчитывает значение функции в заданной точке x
* \param const x- заданная точка
* \return Значение функции в заданной точке  x
*/
double myFunc(double x);

/**
* \brief Узнает, существует ли функция в заданной точке  x.
* \param x Заданная точка.
* \return true, если значение функции в заданной точке x существует.
*/
bool isCalculated(double x);

/**
* \brief Точка входа в программу.
* \return В случаен успеха код 0.
*/
int main()
{
	const double XSTART = 0;
	const double XFINISH = 1;
	const double STEP = 0.1;
	double x = XSTART;
	while (x <= XFINISH)
	{
		if (isCalculated(x))
		{
			const double y = myFunc(x);
			std::cout << "x = " << std::setw(5) << std::left << std::setprecision(5) << x << " y = " << y << "\n";
		}
		else
		{
			std::cout << "x = " << x << " y = не существует" << "\n";
		}
		x += STEP;
	}
	return 0;
}

double myFunc(const double x)
{
	return sqrt(1-x)-tan(x);
}

bool isCalculated(const double x)
{
	return ((x<=1) && (abs(cos(x)) >= std::numeric_limits<double>::min()));
}