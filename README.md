# BinaryMultiplication
Тестовое задание для летней школы

## Описание
Реализация задания содержит три файла:
- `BinMult.h` - заголовочный файл для модуля,
- `BinMult.c` - файл с реализацией функций,
- `Source.c` - основной файл проекта. Содержит тесты функции,

Модуль содержит:
- основную функцию вида `char* mult(char* str1, char* str2)`. Принимает на вход две строки из 0 и 1, перемножает их по правилам двоичного умножения и возвращает результирующую строку как число в двоичном виде.
- служебные функции вида:
  - `int bin2dec(char* num)` - перевод строки из 0 и 1 в десятичное число типа int,
  - `int deg(int base, unsigned int deg)` - возведение знакового целого числа типа int в беззнаковую степень типа unsigned int,
  - `char* dec2bin(int num)` - перевод десятичного числа типа int в строку из 0 и 1. **Функция выделяет память под возвращаемый результат динамически. Требуется освобождение памяти после вызова этой функции и функции `mult`, использующей ее.**

## Результаты тесирования функции `mult`
- Test passed: 0 * 0 = 0
- Test passed: 1 * 1 = 1
- Test passed: 101 * 10 = 1010
- Test passed: 111 * 111 = 110001
- Test passed: 1001 * 11 = 11011
- Test passed: 1100 * 1010 = 1111000
- Test passed: 1111 * 1111 = 11100001
- Test passed: 101010101010 * 110110110110 = 100100100011011011011100
- Test passed: 0 * 1101 = 0
- Test passed: 1101 * 0 = 0
- Test passed: 01011 * 1101 = 10001111
- Test passed: 101 * 0111 = 100011
- Test passed: 01011 * 01101 = 10001111


[![C CI](https://github.com/ValeraDanger/BinaryMultiplication/actions/workflows/c-ci.yml/badge.svg)](https://github.com/ValeraDanger/BinaryMultiplication/actions/workflows/c-ci.yml)
