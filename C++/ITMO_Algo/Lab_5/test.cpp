#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Функция для генерации кода Грея
void generateGrayCode(int n) {
    // Проверка на корректность входных данных
    if (n <= 0) {
        cout << "Введите число N больше 0." << endl;
        return;
    }

    // Вычисление количества двоичных чисел N-ой степени
    int numBinaryNumbers = 1 << n;

    // Создание вектора для хранения двоичных чисел
    vector<int> grayCode(numBinaryNumbers);

    // Генерация кода Грея
    for (int i = 0; i < numBinaryNumbers; ++i) {
        grayCode[i] = i ^ (i >> 1);
    }

    // Вывод результатов
    cout << "Двоичные числа " << n << "-ой степени с использованием кода Грея:" << endl;
    for (int i = 0; i < numBinaryNumbers; ++i) {
        bitset<32> binaryNumber(grayCode[i]); // Используем битовую маску для вывода числа
        cout << binaryNumber.to_string().substr(32 - n) << endl;
    }
}

int main() {
    int N;
    cout << "Введите число N: ";
    cin >> N;

    generateGrayCode(N);

    return 0;
}
