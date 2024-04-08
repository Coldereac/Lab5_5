#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>
#include <string.h>

#define SIZE 100

/*
*Завдання 5. Речення користувача, введене з клавіатури, складається зі слів, які
можуть містити дійсні додатні числа. Напишіть програму, яка знаходить
мінімальне з цих чисел.
*/
float find_min(const char* str); // фукнція знаходження мінімального дійсного числа у реченні. На вхід подається речення.
//Якщо чисел там нема, то повертає значення FLT_MAX


int main() {
    char sentence[SIZE]; // Масив для речення

    // Введення речення
    printf("Don't type something like 2.2.2...\nEnter sentence: ");
    gets(sentence);
    sentence[strlen(sentence)] = '\0';

    //знаходження мінімального числа
    float min = find_min(sentence);

    // Виведення результату
    if (min == FLT_MAX) {
        printf("No numbers.\n");
    }else if(min == -1){
        puts("You typed number like 2.2.2...");
    }
    else {
        printf("Minimal number: %.5f\n", min);
    }
    return 0;
}

float find_min(const char* str) {
    float min = FLT_MAX; // Мінімальне значення
    // Змінна для зберігання числа
    char num_temp[20];
    // Обробка речення
    int stop;
    for (int i = 0, j; str[i] != '\0'; i++) {
        // Перевірка, чи є символ цифрою
        if (isdigit(str[i])) {
            // Зчитування числа
            stop = 0;
            j = 0;
            while (isdigit(str[i]) || (str[i] == '.' && isdigit(str[i+1]) && !stop) ) {
                num_temp[j] = str[i];
                if(num_temp[j] == '.') stop = 1;
                j++;
                i++;
            }
            float num = atof(num_temp);
            // Оновлення мінімального значення
            if (num < min) {
                min = num;
            }
        }
    }
    if(stop){
        min = -1;
    }
    return min;
}