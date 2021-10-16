#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая фунция, рассчитывающая значение a
* \param const double x-константа, имеющая тип данных с плавающей точкой
* \param const double y= константа, имеющая тип данных с плавающей точкой
* \param const double z=константа, имеющая тип данных с плавающей точкой
* \return возвращает значение a
**/
double getA(const double x, const double y, const double z);

/**
* \brief Математическая фунция, рассчитывающая значение b
* \param const double x-константа, имеющая тип данных с плавающей точкой
* \param const double y= константа, имеющая тип данных с плавающей точкой
* \param const double z=константа, имеющая тип данных с плавающей точкой
* \return возвращает значение b
**/

double getB(const double x, const double y, const double z);


/**
* \brief точка входа в программу
* \return возвращает 0 в случае успешного выполнения
**/


int main()
{
	const double x = 0.3;
	const double y = 2.9;
	const double z = 0.5;
	const auto a = getA(x, y, z);
	const auto b = getB(x, y, z);

	cout << "x=" << x << "\n y=" << y << "\n z=" << z << "\n a=" << a << "\n b=" << b;
	return 0;


}

double getA(const double x, const double y, const double z)
{
	return (pow(z, 2) * x + exp(-x) * cos(y * x)) / (y * x - exp(-x) * sin(y * x) + 1);
}

double getB(const double x, const double y, const double z)
{
	return exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
}
