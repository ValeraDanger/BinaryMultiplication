#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BinMult.h"

void runTest(const char* binary1, const char* binary2, const char* expected) {
    char* result = mult(binary1, binary2);
    if (strcmp(result, expected) == 0) {
        printf("Test passed: %s * %s = %s\n", binary1, binary2, result);
    }
    else {
        printf("Test failed: %s * %s = %s (expected: %s)\n", binary1, binary2, result, expected);
        exit(1);
    }
    free(result);  // Функция mult выделяет память для результата, и мы должны её освободить
}

int main() {
    // Тесты
    runTest("0", "0", "0");
    runTest("1", "1", "1");
    runTest("101", "10", "101");
    runTest("111", "111", "110001");
    runTest("1001", "11", "11011");
    runTest("1100", "1010", "1111000");
    runTest("1111", "1111", "11100001");

    // Тесты с большими числами
    runTest("101010101010", "110110110110", "100100100011011011011100");

    // Тесты с одним числом равным нулю
    runTest("0", "1101", "0");
    runTest("1101", "0", "0");

    // Тесты с одним числом с ведущим нулем
    runTest("01011", "1101", "10001111");
    runTest("101", "0111", "100011");

    // Тесты с двумя числами с ведущим нулем
    runTest("01011", "01101", "10001111");
  

    return 0;
}