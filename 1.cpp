#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[40], temp1[40];
    int w, h, i, j, count;
    double temp2, result;
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
        // узнаем размер матрицы, он не больше 9х9 (если больше, надо дописать программу с поиском пробела), читаем 1 строку
        fgets(s, 40, f1);

        // в 1 строке надо найти длину и высоту матрицы в виде двух целых чисел
        i = 0;
        // пока не конец строки
        while (s[i] != '\n') {
            // найти пробел
            if (s[i] == ' ') {
                // находим длина
                strncpy(temp1, s, i);
                w = atof(temp1);
                // находим высота (+2 т.к. число после пробела)
                strncpy(temp1, s + 2, i);
                h = atof(temp1);
            }
            i++;
        }

        //
        for(i = 0; i < h; i++)
        {
            for (j = 0 ; j < w; j++)
            {
                fscanf(f1,"%lf",&temp2);
                if (temp2 < 0)
                    result = result + temp2;
                printf("%.2f ",temp2);
            }
            printf("\n");
        }

        printf("Нашли сумму отрицательных элементов матрицы. Она равна %.2f", result);

        // закрываем файл
        fclose(f1);
        getchar();
        exit(0);
    }
}
