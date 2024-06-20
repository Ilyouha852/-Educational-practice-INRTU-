Данная программа была создана в качестве задания для прохождения учебной технологической практики.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Назначение программы: Шифрование текста методом гаммирования.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Суть шифрвования методом гаммирования: Используется цифровое представление текстовой информации, при котором символы текста заменяют некоторыми цифровыми эквивалентами или представляют в виде двоичного кода. 
В этом случае, при шифровании, символы шифруемого текста последовательно складывают с символами некоторой специальной последовательности (ключом), называемой гаммой.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Принцип работы программы:
1) Пользователь вводит с клавиатуры в интерфейс программы (консоль) текст, который нужно зашифровать.
2) Пользователь вводит с клавиатуры в интерфейс программы (консоль) гамму, с помощью которой будет шифроваться текст.
3) Программа преобразует текст в двоичное представление.
4) Программа преобразует ключ в двоичное представление.
5) Программа шифрует текст посредством сложения его двоичного преобразования с двоичным преобразованием ключа через операцию "Исключающее ИЛИ (XOR)".
6) Программа выводит на экран зашифрованный текст.
7) Программа расшифровывает текст посредством повторного сложения его двоичного преобразования с двоичным преобразованием ключа через операцию "Исключающее ИЛИ (XOR)".
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------