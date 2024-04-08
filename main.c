#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>

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
    printf("Enter sentence: ");
    gets(sentence);

    //знаходження мінімального числа
    float min = find_min(sentence);

    // Виведення результату
    if (min == FLT_MAX) {
        printf("No numbers.\n");
    } else {
        printf("Minimal number: %.8f\n", min);
    }
    return 0;
}

float find_min(const char* str) {
    float min = FLT_MAX; // Мінімальне значення
    // Змінна для зберігання числа
    char num_temp[20];
    // Обробка речення
    for (int i = 0, j; str[i] != '\0'; i++) {
        // Перевірка, чи є символ цифрою
        if (isdigit(str[i])) {
            // Зчитування числа
            j = 0;
            int found_dot = 0;
            while (isdigit(str[i]) || (str[i] == '.' && isdigit(str[i+1])) ) {
                num_temp[j] = str[i];
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
    return min;
}