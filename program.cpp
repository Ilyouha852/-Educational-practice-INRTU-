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
    setlocale(LC_ALL, "Russian");

    std::string text;
    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);

    std::string key;
    std::cout << "Введите гамму(ключ), по которому будет шифроваться текст: ";
    std::getline(std::cin, key);
    return 0;
}

