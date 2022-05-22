#include <stdio.h>
#include <string.h>

/*
 * ГУЦЕНКОВ НИКИТА
 * ВАРИАНТ 4
 */

int entering(struct films *arr, int kol, int m, int k, int id);
void all_printing(struct films *arr, int m);
void chg_udk(struct films *arr, int m);
int data_delete(struct films *arr, int m);
void data_printing(struct films *arr, int m);
int id_delete(struct films *arr, int m);
void write_bin(struct films *arr, FILE *fb, int &a);
int searchandrun(struct films *arr, FILE *fb, int m);
void destroy();
void createbackup(struct films *arr, FILE *fb, int &a);

struct times {
    int hours;
    int minutes;
};

struct data {
    int day;
    int month;
    int year;
    int releaseyear;
};

struct films {
    int ID;
    char name[25];
    char udk[10];
    struct data datas;
    struct times time;
    char type[20];
    char producer[30];
};

int main() {
    int kol = 100, g = 0;
    films *arr = new films[kol];
    int k = 0, m = 0, num, id = 1;
    bool flag = true;
    FILE *File;
    while (flag) {
        printf("МЕНЮ:\n");
        printf("1. Создавать бинарный файл.\n");
        printf("2. Добавлять запись в конец файла.\n");
        printf("3. Добавлять запись по номеру.\n");
        printf("4. Выводить на экран все записи в виде таблицы.\n");
        printf("5. Удалять запись по номеру.\n");
        printf("6. Основные функции.\n");
        printf("7. Удалять весь файл.\n");
        printf("8. Копировать данные из файла в резервный файл.\n");
        printf("Выбор пункта: ");
        scanf("%d", &num);
        printf("\n");
        switch (num) {
            case 1:
                write_bin(arr, File, m);
                break;

            case 2:
                m = entering(arr, kol, m, k, id);
                id++;
                k++;
                break;

            case 3:
                m = entering(arr, kol, m, k, id);
                id++;
                k++;
                break;

            case 4:
                all_printing(arr, m);
                break;

            case 5:
                m = id_delete(arr, m);
                k--;
                break;

            case 6:
                searchandrun(arr, File, m);
                break;

            case 7:
                destroy();
                break;

            case 8:
                createbackup(arr, File, m);
                break;

            default:
                printf("EXIT...\n\n");
                flag=false;
                return (0);
        }
    }
}

int searchandrun(struct films *arr, FILE *fb, int m) {
        int num;
        bool flag = true;
        while (flag) {
            printf("Основные функции:\n");
            printf("1. Удалить все записи о фильмах с заданным годом выпуска.\n");
            printf("2. Для заданного фильма заменить УДК кассеты.\n");
            printf("3. Вывести все сведения о фильмах заданного производителя.\n");
            printf("Выбор пункта: ");
            scanf("%d", &num);
            printf("\n");
            switch (num) {
                case 1:
                    data_delete(arr, m);
                    break;

                case 2:
                    chg_udk(arr, m);
                    break;

                case 3:
                    data_printing(arr, m);
                    break;

                default:
                    printf("ERROR\n\n");
                    return m;
            }
        }
}

int entering(struct films *arr, int kol, int m, int k, int id) {
    if (m != kol) {
        m++;
        arr[k].ID = id;

        printf("УДК кассеты:\n");
        fflush(stdin);
        arr[k].udk[0] = 0;
        gets(arr[k].udk);

        printf("Название фильма:\n");
        fflush(stdin);
        arr[k].name[0] = 0;
        gets(arr[k].name);

        printf("Жанр (комедия, триллер и т.д.):\n");
        fflush(stdin);
        arr[k].type[0] = 0;
        gets(arr[k].type);

        printf("Производитель:\n");
        fflush(stdin);
        arr[k].producer[0] = 0;
        gets(arr[k].producer);

        printf("Год выпуска:\n");
        fflush(stdin);
        scanf("%d", &arr[k].datas.releaseyear);

        printf("Дата проката:\n");
        fflush(stdin);
        scanf("%d.%d.%d", &arr[k].datas.day, &arr[k].datas.month, &arr[k].datas.year);

        printf("Время проката:\n");
        fflush(stdin);
        scanf("%d.%d", &arr[k].time.hours, &arr[k].time.minutes);

        printf("\n");

    } else printf("ERROR.\n\n");
    return m;
}

void all_printing(struct films *arr, int m) {
    if (m != 0) {
        for (int i = 0; i < m; i++) {
            printf("%d)\n", i + 1);
            printf("ID: %d\n", arr[i].ID);
            printf("УДК кассеты: %s\n", arr[i].udk);
            printf("Название фильма: %s\n", arr[i].name);
            printf("Жанр (комедия, триллер и т.д.): %s\n", arr[i].type);
            printf("Производитель: %s\n", arr[i].producer);
            printf("Год выпуска: %04d\n", arr[i].datas.releaseyear);
            printf("Дата проката: %02d.%02d.%02d\n", arr[i].datas.day, arr[i].datas.month, arr[i].datas.year);
            printf("Время проката: %02d.%02d\n", arr[i].time.hours, arr[i].time.minutes);
            printf("\n\n");
        }
    } else
        printf("ФАЙЛ ПУСТ.\n\n");
}

void chg_udk(struct films *arr, int m) {
    int i = 0;
    bool find = true;
    char new_udk[10];
    char find_name[25];
    if (m != 0) {
        printf("Для заданного фильма заменить УДК кассеты. NAME:\n");
        scanf("%s", &find_name);
        while (find && i < m) {
            if (strcmp(find_name, arr[i].name) == 0) {
                printf("UDK:\n");
                scanf("%s", &new_udk);
                arr[i].udk[0] = 0;
                strcat(arr[i].udk, new_udk);
                find = false;
            }
            i++;
        }
        if (find)
            printf("ERROR.\n\n");
        else printf("DONE.\n\n");
    } else
        printf("ERROR.\n\n");
}

int data_delete(struct films *arr, int m) {
    int kol = 0;
    struct data data1;
    if (m != 0) {
        printf("Удалить все записи о фильмах с заданным годом выпуска:\n");
        scanf("%04d", &data1.year);
        for (int i = 0; i < m; i++) {
            if (arr[i].datas.releaseyear == data1.year) {
                kol++;
                for (int k = i; k < m - 1; k++)
                    arr[k] = arr[k + 1];
                m--;
                i--;
            }
        }
        if (kol == 0) printf("ERROR.\n\n");
        else printf("DONE.\n\n");
    } else
        printf("ERROR.\n\n");
    return m;
}

int id_delete(struct films *arr, int m) {
    int kol = 0, id;
    if (m != 0) {
        printf("Удалить номер:\n");
        scanf("%d", &id);
        for (int i = 0; i < m; i++) {
            if (id == arr[i].ID) {
                kol++;
                for (int k = i; k < m - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                m--;
                i--;
            }
        }
        if (kol == 0) printf("ERROR.\n\n");
        else printf("DONE.\n\n");
    } else
        printf("ERROR.\n\n");
    return m;
}

void data_printing(struct films *arr, int m) {
    int kol = 0;
    char prod[20];
    if (m != 0) {
        printf("Вывести все сведения о фильмах заданного производителя:\n");
        scanf("%s", &prod);
        for (int i = 0; i < m; i++) {
            if (strcmp(prod, arr[i].producer) == 0) {
                kol++;
                printf("\n");
                printf("ID: %d\n", arr[i].ID);
                printf("УДК кассеты: %s\n", arr[i].udk);
                printf("Название фильма: %s\n", arr[i].name);
                printf("Жанр (комедия, триллер и т.д.): %s\n", arr[i].type);
                printf("Производитель: %s\n", arr[i].producer);
                printf("Год выпуска: %04d\n", arr[i].datas.releaseyear);
                printf("Дата проката: %02d.%02d.%02d\n", arr[i].datas.day, arr[i].datas.month, arr[i].datas.year);
                printf("Время проката: %02d.%02d\n", arr[i].time.hours, arr[i].time.minutes);
                printf("\n\n");
            }
        }
        if (kol == 0) printf("ERROR.\n\n");
    } else
        printf("ФАЙЛ ПУСТ.\n\n");
}

void createbackup(struct films *arr, FILE *fb, int &a) {
    int i;
    fb = fopen("backup.bin", "w+b");

    fwrite(&a, sizeof(int), 1, fb);
    for (i = 0; i < a; i++)
        fwrite(&arr[i], sizeof(struct films), 1, fb);
    printf("DONE\n\n");
    fclose(fb);
}

void write_bin(struct films *arr, FILE *fb, int &a) {
    int i;
    fb = fopen("binfile.bin", "w+b");
    fwrite(&a, sizeof(int), 1, fb);
    for (i = 0; i < a; i++)
        fwrite(&arr[i], sizeof(struct films), 1, fb);
    printf("DONE\n\n");
    fclose(fb);
}

void destroy() {
    remove("binfile.bin");
    printf("DESTROYED\n\n");
}
