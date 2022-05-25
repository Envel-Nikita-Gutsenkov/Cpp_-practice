#include <stdio.h>
#include <stdlib.h>

int main() {
    int count, i, positive = 0;
    float temp, percent;
    char s[40];
    // открываем файл для чтения и записи
    FILE *f1 = fopen("chisla.txt", "r+a");

    if (!f1) {
        printf("ОШИБКА ЧТЕНИЯ");
    } else {
        printf("Все содержимое файла:\n");
        // выводим все
        while (fgets(s, 40, f1))
            puts(s);
        // возврат в начало файла
        rewind(f1);
        // получаем число в первой строке
        fscanf(f1, "%d", &count);
        // получаем все числа во второй строке
        for (i = 0; i < count; i++) {
            fscanf(f1, "%f", &temp);
            // считаем количество положительных
            if (temp > 0)
                positive++;
        }
        // процент положительных чисел
        percent = positive * 100 / count;

        // запись в файл
        fprintf(f1, "\n%.2f", percent);

        printf("\nПроцент положительных чисел %.2f", percent);

        fclose(f1);
        getchar();
        exit(0);
    }
}
