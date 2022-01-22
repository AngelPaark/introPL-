#include <iostream>
#include <sstream>
#include <random>

using namespace std;

/**
 * \brief Способы задания массива
 */
enum class Choice
{
    /**
     * \brief Ввод вручную
     */
    Manually,

    /**
     * \brief Ввод с помощью рандномных чисел
     */
     Randomly
};

/**
 * \brief Метод заполнения массива
 * \param size Размер массива
 * \param selection Выбор создания массива (вручную или случайными числами)
 * \param min_value Минимальное значение в интервале 
 * \param max_value Максимальное значение в интервале 
 * \return Массив
 */
int* getArray(const size_t size, const int selection, const int min_value, const int max_value);

/**
 * \brief Получение массива
 * \param message Мотивоционное сообщение для пользователя
 * \return Размер массива
 */
size_t getSize(const string& message);

/**
 * \brief Вывод элементов массива
 * \param size Размер массива
 * \return Строка со значениями индексов массива
 */
string toString(const int*, const size_t size);

/**
 * \brief Функция для замены второго элемента массива на максимальный среди отрицательных
 * \param size Размер массива
 * \return Массив с заменой
 */
void replace(int*, const size_t size);

/**
 * \brief Функция для нахождения элементов, значения которых положительны и по модулю не превосходят заданное число А
 * \param size Размер массива
 * \param A заданное число А
 * \return количество элементов
 */
int getQuantity(int*, const size_t size, const int A);

/**
 * \brief Находит номер первой пары соседних элементов, сумма которых меньше заданного числа
 * \param size Размер массива
 * \param B заданное число B
 * \return Индексы элементов
 */
void getNumber(int*, const size_t size, const int B);



/**
 * \brief Точка входа в программу
 * \return (Код ошибки 0) успех
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int* my_array = nullptr;
    const int min_value = -10;
    const int max_value = 10;
    try
    {
        const auto size = getSize("Введите размер массива: ");
        cout << "Выберите способ создания массива: " << static_cast<int>(Choice::Manually) << " - вручную, " << static_cast<int>(Choice::Randomly) << " - заполнить случайными числами ";
        int input_type;
        cin >> input_type;
        my_array = getArray(size, input_type, min_value, max_value);
        cout << "Итоговый массив:\n";
        cout << toString(my_array, size);

        cout << "\nМассив после замены второго элемента массива на максимальный среди отрицательных:\n";
        replace(my_array, size);
        cout << toString(my_array, size);
        int A;
        cout << "Введите число A: ";
        cin >> A;
        cout << "\nКоличество элементов, которые положительны и по модулю не больше числа А " << getQuantity(my_array, size, A) << '\n';
        int B;
        cout << "введите число В";
        cin >> B;
        cout << "Номер 1 пары: ";
        getNumber(my_array, size, B);
       
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
            cout << "Введите " << index + 1 << " элемент массива в диапозоне [-10;10]: ";
            cin >> array[index];
            break;
        }
        case static_cast<int>(Choice::Randomly):
        {
            array[index] = uniformIntDistribution(gen);
            break;
        }
        default:
            cout << "Ошибка!";
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
    int value = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] < value) {
            value = array[i];
            array[1] = value;
        }
    }
}

    int getQuantity(int* array, const size_t size, const int A)
    {
    int quan = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i]>0 and abs(array[i]<=A))
            quan += 1;
    }
    return quan;
}

    void getNumber(int* array, const size_t size, const int B) {
        size_t i = 0;
        int finish = 0;
        while (array[i] + array[i + 1] < B && i < size - 1) {
            finish = i;
            i++;

        }
        if (i < size - 1 && i != 0) {
            finish++;
            cout << finish << endl;
        }
      
     }