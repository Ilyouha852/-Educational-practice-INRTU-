#include <iostream>
#include <string>

// Функция для преобразования символа в двоичный вид
std::string charToBinary(char c) {
    std::string binary;
    for (int i = 7; i >= 0; --i) {
        binary += ((c >> i) & 1) ? '1' : '0';  // Сдвиг символа вправо и побитовая операция AND для получения каждого бита
    }
    return binary;
}

int main()
{
    std::cout << "Hello World!\n";
}

