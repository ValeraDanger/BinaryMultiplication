#include "BinMult.h"
#include <stdlib.h>
#include <math.h>

int bin2dec(char* num) {
    return strtol(num, NULL, 2);
}

int deg(int base, unsigned int deg) {  //интовое возведение в степень, чтобы избежать неточностей в округлении флотовой версии
    if (base == 0) return 0;

    int result = 1;
    for (int i = 0; i < deg; i++) {
        result *= base;
    }

    return result;
}

char* dec2bin(int num) {
    if (num == 0) {
        char* result = (char*)calloc(2, sizeof(char));
        result[0] = '0';
        return result;
    };
        
    char reverseBinaryNum[32]; //так как число 32 битное

    int i = 0;
    while (num > 0) {
        reverseBinaryNum[i] = '0' + num % 2;
        i++;
        num /= 2;
    }
    reverseBinaryNum[i] = '\0';

    char* result = (char*)calloc(i+1, sizeof(char));
    result[i] = '\0';
    int j = 0;
    for (i -= 1; i >= 0; i--) {
        result[j] = reverseBinaryNum[i];
        j++;
    }

    return result;
}

char* mult(char* str1, char* str2) {
    int num1 = bin2dec(str1);
    int num2 = bin2dec(str2);

    int mult = num1 * num2;

    return dec2bin(mult);
}
