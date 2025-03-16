#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian"); 
    string octal;
    cout << "Введите число в восьмеричной системе счисления: ";
    cin >> octal;

    // Проверяем, начинается ли число с символа минус (для отрицательных чисел)
    bool isNegative = false;
    int index = 0;
    if (octal[0] == '-') {
        isNegative = true;
        index = 1;
    }

    // Алгоритм перевода из восьмеричной системы в десятичную:
    // Для каждого символа: decimal = decimal * 8 + (текущий символ - '0')
    long long decimal = 0;
    for (int i = index; i < octal.size(); i++) {
        char ch = octal[i];
        // Проверка: цифра должна быть от '0' до '7'
        if (ch < '0' || ch > '7') {
            cout << "Ошибка: введено некорректное число." << endl;
            return 1;
        }
        int digit = ch - '0';
        decimal = decimal * 8 + digit;
    }

    if (isNegative) {
        decimal = -decimal;
    }

    // Вывод результата в десятичном формате
    cout << "Десятичное представление: " << decimal << endl;

    return 0;
}