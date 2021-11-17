#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
using namespace std;

/**
* \brief программа определяет, можно ли разместить 2 дома на 1 участке
* \param const widthLand-ширина участка
* \param const lendthLand-длина участка
*/
/**
* \brief функция находит максимальную ширину 2 домов
* \param const width1-ширина 1 дома
* \param const width2-ширина 2 дома
*/
double maxwidth(double width1, double width2);

/**
* \brief функция находит максимальную длину 2 домов
* \param const length1-длина 1 дома
* \param const length2-длина 2 дома
*/
double maxlength(double length1, double length2);


/**
* \brief точка входа в программу
**/

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "введите длину и ширину 1 дома:";
	double length1;
	double width1;
	cin >> length1;
	cin >> width1;

	cout << "введите длину и ширину 2 дома:";
	double length2;
	double width2;
	cin >> length2;
	cin >> width2;

	cout << "введите длину и ширину участка:";
	double lengthLand;
	double widthLand;
	cin >> lengthLand;
	cin >> widthLand;

	if (((width1 + width2 <= widthLand) and (maxlength(length1,length2) <= lengthLand)) or ((maxwidth(width1,width2) <= widthLand) and (length1 + length2 <= lengthLand)))
	{
		cout << "можно";

    }

	else {
		cout << "нельзя";
	}



}
double maxwidth(double width1,double width2)
{
	if (width1 > width2)
		return width1;
	else
		return width2;
}

double maxlength(double length1, double length2)
{
	if (length1 > length2)
		return length1;
	else
		return length2;
}
