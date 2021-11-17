#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
using namespace std;

/**
* \brief Находит количество отрицательных чисел
* \param const double a-число, вводимое пользователем
* \param const double b-число, вводимое пользователем
* \param const double c-число, вводимое пользователем
* \param counter-счетчик
* \return Возвращает значение NegativeNumbers
**/
double getNegativeNumbers(const double a, const double b, const double c);

/**
* \brief Находит абсолютное значение суммы чисел
* \param const double a-число, вводимое пользователем
* \param const double b-число, вводимое пользователем
* \param const double c-число, вводимое пользователем
* \return Возвращает значение sum
**/
double getSum(const double a, const double b, const double c);



enum class Numbers
{
	/**
	* \brief Находит абсолютное значение суммы чисел
	*/
	summ,

	/**
	* \brief Находит количество отрицательных чисел
	*/
	negative

};

/**
* \brief Точка входа в программу
* \return Возвращает 0 в случае успешного выполнения
**/


int main()

{
	setlocale(LC_ALL, "Russian");

	cout << "введите число a: \n";
	double a;
	cin >> a;

	cout << "введите число b: \n";
	double b;
	cin >> b;

	cout << "введите число c: \n";
	double c;
	cin >> c;

	cout << "выберите,что посчитать:"


		<<"\n сумма \n" << (static_cast<int>(Numbers::summ))
		<<"\n количество отрицательных чисел \n"<< (static_cast<int>(Numbers::negative))
		<< "\n ";
	int action;
	cin >> action;

	const auto numbers = static_cast<Numbers>(action);
	switch (numbers)
	{
	case Numbers::summ:
	{
		const auto sum = getSum(a, b, c);
		std::cout << "сумма равна \n" << sum;
		break;
	}
	case Numbers::negative:
		const auto NegativeNumbers = getNegativeNumbers(a, b, c);
		std::cout <<"количество отрицательных чисел равно \n "<< NegativeNumbers;
		break;
	
	}

	return 0;
}





double getNegativeNumbers(const double a, const double b, const double c)
{
	int counter = 0;
	if (a < 0)
		counter++;
	if (b < 0)
		counter++;
	if (c < 0)
		counter++;
	return counter;
}


double getSum(const double a, const double b, const double c)
{
	return fabs(a) + fabs(b) + fabs(c);
}