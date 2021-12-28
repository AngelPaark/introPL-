#include <iostream>
#include <sstream>
#include <random>
#include <cmath>

using namespace std;

/**
* \brief способы задания массива
*/

enum class Choice {
	/**
	* \brief ввод вручную
	*/
	Manually,

	/**
	* \brief ввод рандомных чисел
	*/
	Randomly
};

/**
* \brief способ заполнения массива
* \param size размер массива
* \param selection выбор заполнения массива
* \param min_value минимальное значение
* \param max_value максимальное значение
* \return массив
*/
int* getArray(const size_t size, const int selection, const int min_value, const int max_value);

/**
* \brief получение массива
* \param message мотивоционное сообщение для пользователя
* \return размер массива
*/
size_t getSize(const string& message);

/**
* \brief вывод элементов массива
* \param size размер массива
* \return строка со значениями индексов массива
*/
string toString(const int*, const size_t size);

/**
* \brief функция для замены последнего элемента массива, кратного 3, нулем
* \param size размер массива
*/
void replace(int*, const size_t size);

/**
* \brief функция вставляет число К после всех четных элементов
* \param size размер массива
* \param newSize размер нового массива
* \param K число вводимое пользователем
* \return массив, в котором добавлено число К 
*/
int* addElement(int*, size_t size, size_t newSize, const int K);

/**
* \brief считает количество четных элементов
* \param size размер массива
* \return количество четных чисел
*/
size_t getCount(int*, size_t size);

/**
* \brief формирует из массива Р массив М(первый  и последний элементы равны 0, каждый 4 равен Mi=4*abs(Pi), остальные Mi=-Pi(i+1)
* \param size размер массива
* \return массив М
*/
int* createArray(int*, const size_t size);

/**
* \brief точка входа в программу
* \return 0 в случае успеха
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int* my_array = nullptr;
    const int min_value = -100;
    const int max_value = 100;
    try
    {
        const auto size = getSize("Введите размер массива: ");
        cout << "Выберите способ создания массива: " << static_cast<int>(Choice::Manually) << " - вручную, " << static_cast<int>(Choice::Randomly) << " - заполнить случайными числами ";
        int input_type;
        cin >> input_type;
        my_array = getArray(size, input_type, min_value, max_value);
        cout << "Итоговый массив:\n";
        cout << toString(my_array, size);

        
        replace(my_array, size);
        cout << toString(my_array, size);

        size_t count = getCount(my_array, size);
        size_t newSize = size + count;
        int K;
        cout<<"введите число К";
        cin >> K;

        int* newArray= addElement(my_array,size,newSize,  K);
        cout << toString(newArray, newSize);

        cout << "массив М:\n";
        int* mass = createArray(my_array, size);
        cout << toString(mass, size);

        if (newArray != nullptr)
        {
            delete[] newArray;
            newArray = nullptr;
        }
        if (mass != nullptr)
        {
            delete[] mass;
            mass = nullptr;
        }

    }
    catch (exception& e)
    {
        cout << e.what();
        error_code = 1;
    }

    if (my_array != nullptr)
    {
        delete[] my_array;
        my_array = nullptr;
    }
    return error_code;
}

size_t getSize(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;

    if (size <= 0)
    {
        throw out_of_range("Неправильный размер массива");
    }

    return size;
}

int* getArray(const size_t size, const int selection, const int min_value, const int max_value)
{
    const auto array = new int[size];
    //Will be used to obtain a seed for the random number engine
    random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(min_value, max_value);
    for (size_t index = 0; index < size; index++)
    {
        switch (selection)
        {
        case static_cast<int>(Choice::Manually):
        {
            cout << "Введите " << index + 1 << " элемент массива в диапозоне [-100;100]: ";
            cin >> array[index];
            break;
        }
        case static_cast<int>(Choice::Randomly):
        {
            array[index] = uniformIntDistribution(gen);
            break;
        }
        }
    }

    return array;
}

string toString(const int* array, const size_t size)
{
    if (array == nullptr)
        throw invalid_argument("Массив не существует");

    stringstream buffer;
    buffer << "{";
    for (size_t index = 0; index < size - 1; index++)
    {
        buffer << array[index] << ", ";
    }
    buffer << array[size - 1] << "}";
    return buffer.str();
}

void replace(int* array, const size_t size) {
    for (size_t i = size; i>0; i--) {
        if (array[i] % 3==0) {
            array[i] = 0;
            break;
        }
        
    }
}

int* addElement(int* array, size_t size, size_t newSize, const int K) {
    int* newArray = new int[newSize];
   
    for (size_t i = size; i>0; i--) {
        if (array[i] % 2 == 0) {
            newArray[i] = K;
            newArray[i - 1] = array[i];


        }
        
    }
    return newArray;
}

size_t getCount(int* array, size_t size) {
    size_t counter = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            counter++;
        }

    }
    return counter;
}


int* createArray(int* P, const size_t size) {
    int* mass = new int[size];
  
    for (size_t i = 0; i < size; i++) {
        if (i == 0 || i == size) {
            mass[i] = 0;
        }
        
        if (i % 4 == 3) {
            mass[i] = 4 * abs(P[i]);
        }
        else {
            mass[i] = -P[i] * (i + 1);
        }
        
    }
    return mass;
}
