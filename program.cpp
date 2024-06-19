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

// Функция для преобразования строки в двоичный вид
std::string stringToBinary(const std::string& text) {
    std::string binaryString;
    for (char c : text) {
        binaryString += charToBinary(c);  // Преобразование каждого символа строки в двоичный вид
    }
    return binaryString;
}

// Функция для преобразования двоичного представления в символ
char binaryToChar(const std::string& binary) {
    char c = 0;
    for (size_t i = 0; i < 8; ++i) {
        c = (c << 1) | (binary[i] - '0');  // Сдвиг влево и добавление текущего бита
    }
    return c;
}

// Функция для преобразования двоичной строки в текст
std::string binaryToString(const std::string& binary) {
    std::string text;
    for (size_t i = 0; i < binary.size(); i += 8) {
        text += binaryToChar(binary.substr(i, 8));  // Преобразование каждой 8-битной подстроки в символ
    }
    return text;
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

