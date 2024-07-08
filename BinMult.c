#include "BinMult.h"
#include <string.h>
#include <stdlib.h>

char* shift(char* num, int count) {
	int result_size = strlen(num) + count + 1;
	int len_num = strlen(num);
	char* result = (char*)malloc(result_size);  //создаем буфер для всей строки + количетсво символов смещения + 1 символ конца строки
	strcpy(result, num);

	for (int i = 0; i < count; i++) {
		result[strlen(num) + i] = '0';
	}

	result[result_size - 1] = '\0';

	return result;
}

char* add(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    // Определяем максимальную длину
    int maxLen = lenA > lenB ? lenA : lenB;

    // Выделяем память для результата
    // +2: один для возможного переноса и один для завершающего нуля
    char* result = (char*)calloc(maxLen + 2, sizeof(char));

    //result[maxLen + 1] = '\0'; // Завершающий ноль

    int carry = 0; // Перенос
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen;

    // Складываем числа
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 2;
        result[k] = (sum % 2) + '0';
        k--;
    }

    
    if (result[0] == 0) {
        char* formated_result = (char*)calloc(maxLen + 1, sizeof(char));    // Если в начале строки был ноль, то переноса не было, а щначит ноль нужно удалить
        strcpy(formated_result, result + 1);                  //Адрес указателя result сместим на единицу, чтобы откинуть ведущий ноль
        free(result);

        return formated_result;
    }

    return result;
}

char* mult(char* num1, char* num2) {
	int result_size = strlen(num1) + strlen(num2) + 1; //максимальная длина буфера. При двоичном умножении она равна сумме длин множителей
	int len_num1 = strlen(num1);
	int len_num2 = strlen(num2);

	char* result = (char*)calloc(result_size, sizeof(char));

    for (int i = 0; i < result_size - 1; i++) {     
        result[i] = '0';
    }

	for (int i = 0; i < len_num2; i++) {        //Проходим каждую цифру второго числа с конца

        if (num2[ (len_num2 - 1) - i] == '1') {               //Если очередная цифра - единица, то смещаем первое число на позицию этой цифры во втором числе и прибавляем его к result.
            char* tmp_shift = shift(num1, i);
            char* tmp_result = add(result, tmp_shift);      //Фактически получили умножение столбиком

            free(tmp_shift);
            free(result);
            result = tmp_result;
        }

        else if (num2[(len_num2 - 1) - i] == '0') {
            continue;
        }

        else {
            exit(2);        //Если очередная цифра не ноль или единица - что-то пошло не так. Завершим программу с кодом 2.
        }
	}

    //Теперь удалим ведущие нули, если такие имеются
    int zeroes_count = 0;
    for (int i = 0; result[i] == '0'; i++) {
        zeroes_count++;
    }

    if (zeroes_count == result_size - 1) {  //Возможна ситуация, когда число целиком состоит из нулей. В таком случае, оставим в числе один ноль, уменьшив размер zeroes_count на единицу.
        zeroes_count = result_size - 2;
    }

    if (zeroes_count > 0) {
        char* tmp_result = (char*)calloc(result_size - zeroes_count, sizeof(char));
        strcpy(tmp_result, result + zeroes_count);    //Адрес указателя result сместим на zeroes_count, чтобы откинуть ведущие ноли
        free(result);
        result = tmp_result;
    }
    return result;
}