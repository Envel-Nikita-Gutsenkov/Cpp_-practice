#include <stdlib.h>
#include <stdio.h>

int main() {

    // создание структур

    // входная структура
    struct strictinput {
        int prodkode; // код предприятия
        int itemkode; // код изделия
        float q1; // размеры поставок в 1 квартале
        float q2; // размеры поставок в 2 квартале
        float q3; // размеры поставок в 3 квартале
        float q4; // размеры поставок в 4 квартале
    };
    strictinput dbinput[100]; // массив структур
    // выходная структура
    struct strictoutput {
        int prodkode; // код предприятия
        int itemkode; // код изделия
        float syear; // размер поставок за год
    };
    strictoutput dboutput[100]; // массив структур

    // ввод данных

    int i, stringcount;

    printf("Введите количество добавляемых записей\n");
    scanf("%i", &stringcount);

    for (i = 0; i < stringcount; i++) {
        printf("ВВОДИМ СТРОКУ %i\n", i + 1);
        printf("Введите код предприятия\n");
        scanf("%i", &dbinput[i].prodkode);
        printf("Введите код изделия\n");
        scanf("%i", &dbinput[i].itemkode);
        printf("Введите размеры поставок в 1 квартале\n");
        scanf("%f", &dbinput[i].q1);
        printf("Введите размеры поставок в 2 квартале\n");
        scanf("%f", &dbinput[i].q2);
        printf("Введите размеры поставок в 3 квартале\n");
        scanf("%f", &dbinput[i].q3);
        printf("Введите размеры поставок в 4 квартале\n");
        scanf("%f", &dbinput[i].q4);
    }

    // вывод исходных данных

    printf("\nВведенная таблица");
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("| Код предприятия | Код изделия | 1 квартал  | 2 квартал  | 3 квартал  | 4 квартал  |\n");
    for (i = 0; i < stringcount; i++)
        printf("|      %10i | %10i  | %10.2f | %10.2f | %10.2f | %10.2f |\n", dbinput[i].prodkode, dbinput[i].itemkode,
               dbinput[i].q1, dbinput[i].q2, dbinput[i].q3, dbinput[i].q4);
    printf("-------------------------------------------------------------------------------------");

    // подготовка вывод данных по задаче

    int outputcount = 0, j;
    bool temp, temp1;

    // составление выходного массива
    for (i = 0; i < stringcount; i++) {
        // сортировка в порядке убывания
        temp1 = false;
        for (j = 0; j < i; j++) { // проверяем все строки до текущей
            if (dbinput[i].prodkode > dbinput[j].prodkode) { // если предыдущая строка меньше
                // назначаем новые значения предыдущая строка
                dboutput[j].prodkode = dbinput[i].prodkode;
                dboutput[j].itemkode = dbinput[i].itemkode;
                dboutput[j].syear = dbinput[i].q1 + dbinput[i].q2 + dbinput[i].q3 + dbinput[i].q4;
                // назначаем значения новой строки с предыдущая строка
                dboutput[i].prodkode = dbinput[j].prodkode;
                dboutput[i].itemkode = dbinput[j].itemkode;
                dboutput[i].syear = dbinput[j].q1 + dbinput[j].q2 + dbinput[j].q3 + dbinput[j].q4;
                // метка, что действие выполнено
                temp1 = true;
            }
        }
        if (!temp1) { // если предыдущая строка больше (метка false)
            // назначаем значения текущей строки без изменений
            dboutput[i].prodkode = dbinput[i].prodkode;
            dboutput[i].itemkode = dbinput[i].itemkode;
            dboutput[i].syear = dbinput[i].q1 + dbinput[i].q2 + dbinput[i].q3 + dbinput[i].q4;
        }
    }

    /* подсчет Количество разных изделий, поставляемых предприятиями
       это нахождение количества уникальных элементов
       перебираем все строки */
    for (i = 0; i < stringcount; i++) {
        temp = false; // сброс индикатора
        for (j = 0; j < i; j++) { // проверяем все строки до текущей
            if (dboutput[i].itemkode == dboutput[j].itemkode) // если рассматриваемый элемент совпадает
                temp = true; // означает что число совпало с каким-то предыдущим элементов
        }
        if (!temp) // если до этого элемента такого же не было
            outputcount += 1; // +1 к ответу
    }

    // вывод данных по задаче

    printf("\n\nРезультат в порядке убывания кода предприятия\n");
    printf("-----------------------------------------------------------\n");
    printf("| Код предприятия | Код изделия | Размер поставок за год  |\n");
    for (i = 0; i < stringcount; i++)
        printf("|      %10i | %10i  | %20.2f    |\n", dboutput[i].prodkode, dboutput[i].itemkode, dboutput[i].syear);
    printf("-----------------------------------------------------------\n");
    printf("Количество разных изделий, поставляемых предприятиями: %i", outputcount);
    printf("\n-----------------------------------------------------------");

}
