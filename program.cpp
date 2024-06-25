#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

// Структура для хранения текста и ключа
struct Data {
    std::string text;
    std::string encryptedText;
    std::string key;
};

// Функция для преобразования строки в двоичный вид
std::string stringToBinary(const std::string& text) {
    std::string binaryString;
    for (char c : text) {
        for (int i = 7; i >= 0; --i) {
            binaryString += ((c >> i) & 1) ? '1' : '0';
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
            c = (c << 1) | (binary[i + j] - '0');
        }
        text += c;
    }
    return text;
}

// Функция для выполнения побитовой операции XOR
std::string xorOperation(const std::string& textBinary, const std::string& keyBinary) {
    std::string result;
    for (size_t i = 0; i < textBinary.size(); ++i) {
        result += (textBinary[i] == keyBinary[i]) ? '0' : '1';
    }
    return result;
}

// Функция для генерации гаммы
std::string generateKey(const std::string& text, int keyLength) {
    std::string key;
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < keyLength; ++i) {
        key += text[rand() % text.size()];
    }
    return key;
}

// Функция для чтения текста из файла
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        exit(1);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

// Функция для записи текста и ключа в файл
void writeFile(const std::string& filename, const Data& data) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        exit(1);
    }
    file << "Изначальный текст: " << data.text << "\n";
    file << "Зашифрованный текст: " << data.encryptedText << "\n";
    file << "\nГамма: " << data.key;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод текста
    std::string inputFilename, outputFilename;
    std::cout << "Введите имя файла для чтения текста: ";
    std::cin >> inputFilename;
    std::cin.ignore(); // Игнорируем оставшийся символ новой строки

    std::string text = readFile(inputFilename);

    // Ввод гаммы
    std::string key;
    int keyLength = 0;

    std::cout << "\nВведите длину будущей гаммы.\nПРИМЕЧАНИЕ: длина гаммы должна превышать длину текста.\n";
    while (keyLength < text.size()) {
        std::cout << "\nДлина текста: " << text.size();

        std::cout << "\nДлина гаммы: ";
        std::cin >> keyLength;
    }

    key = generateKey(text, keyLength);

    // Преобразование ключа в бинарный вид
    std::string keyBinary = stringToBinary(key).substr(0, text.size() * 8);

    // Преобразование текста в бинарный вид
    std::string textBinary = stringToBinary(text);

    // Шифрование
    std::string encryptedBinary = xorOperation(textBinary, keyBinary);
    std::string encryptedText = binaryToString(encryptedBinary);

    // Запись зашифрованного текста и гаммы в файл
    Data data = { text, encryptedText, key };
    std::cout << "\nВведите имя файла для сохранения зашифрованного текста и гаммы: ";
    std::cin >> outputFilename;
    writeFile(outputFilename, data);

    std::cout << "Зашифрованный текст и гамма были сохранены в файле " << outputFilename << std::endl;

    return 0;
}
