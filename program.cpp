#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Функция для преобразования строки в двоичный вид
std::string stringToBinary(const std::string& text) {
    std::string binaryString;
    for (char c : text) {
        for (int i = 7; i >= 0; --i) {
            binaryString += ((c >> i) & 1) ? '1' : '0';  // Сдвиг символа вправо и побитовая операция AND для получения каждого бита
        }
    }
    return binaryString;
}

// Функция для преобразования двоичного представления в строку
std::string binaryToString(const std::string& binary) {
    std::string text;
    for (size_t i = 0; i < binary.size(); i += 8) {
        char c = 0;
        for (size_t j = 0; j < 8; ++j) {
            c = (c << 1) | (binary[i + j] - '0');  // Сдвиг влево и добавление текущего бита
        }
        text += c;
    }
    return text;
}

// Функция для выполнения побитовой операции XOR
std::string xorOperation(const std::string& textBinary, const std::string& keyBinary) {
    std::string result;
    for (size_t i = 0; i < textBinary.size(); ++i) {
        result += (textBinary[i] == keyBinary[i]) ? '0' : '1';  // Применение XOR к каждому биту
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    //Ввод текста
    std::string text;
    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);

    // Ввод гаммы
    std::string key;
    int keyLength = 0;

    std::cout << "\nВведите длину будущей гаммы.\nПРИМЕЧАНИЕ: длина гаммы должна превышать длину текста.\n";
    while (keyLength < text.size()) {
        std::cout << "\nДлина текста: " << text.size();

        std::cout << "\nДлина гаммы: ";
        std::cin >> keyLength;

    srand(time(NULL));
    for (int i = 0; i < keyLength; ++i) {
        key += text[rand() % text.size()];
    }

    // Преобразование ключа в бинарный вид
    keyBinary = keyBinary.substr(0, text.size() * 8);  // Обрезка ключа до нужной длины

    // Преобразование текста в бинарный вид
    std::string textBinary = stringToBinary(text);

    // Шифрование
    std::string encryptedBinary = xorOperation(textBinary, keyBinary);
    std::string encryptedText = binaryToString(encryptedBinary);

    std::cout << "Зашифрованный текст: " << encryptedText << std::endl;

    // Расшифровка
    std::string decryptedBinary = xorOperation(encryptedBinary, keyBinary);
    std::string decryptedText = binaryToString(decryptedBinary);

    std::cout << "Расшифрованный текст: " << decryptedText << std::endl;

    return 0;
}

