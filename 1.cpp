#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[40], temp1[40];
    int w, h, i, j, temp2;
    double temp, result;
    // открываем файл для чтения
    FILE *f1 = fopen("matr.txt", "r");
    // проверка на ошибки открытия
    if (!f1) {
        printf("ОШИБКА ЧТЕНИЯ");
    } else {
        // выводим содержимов
        printf("Все содержимое файла \n");
        while (fgets(s, 40, f1))
            puts(s);
        // на начало файла
        rewind(f1);

        // в 1 строке надо найти длину и высоту матрицы в виде двух целых чисел
        fscanf(f1, "%d", &temp2);
        w = temp2;
        fscanf(f1, "%d", &temp2);
        h = temp2;

        // столбцы матрицы
        for (i = 0; i < h; i++) {
            // строки
            for (j = 0; j < w; j++) {
                // находим double
                fscanf(f1, "%lf", &temp);
                // если отрицательное, находим сумму этих элементов
                if (temp < 0)
                    result = result + temp;
            }
        }

        printf("Нашли сумму отрицательных элементов матрицы. Она равна %.2f", result);

        // закрываем файл
        fclose(f1);
        getchar();
        exit(0);
    }
}
