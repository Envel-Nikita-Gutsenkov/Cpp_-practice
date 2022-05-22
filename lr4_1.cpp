#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include <windows.h>

/*
 * ГУЦЕНКОВ НИКИТА
 * ВАРИАНТ 4
 */

#define n 1000
const int NAME = 20;
const int l=80;

struct olymp
{
    char str[l];
    int  ozu;
};

int main()
{
    int i=0;
    struct olymp notes[20];
    struct olymp notes_tmp;

    char  str[n];
    FILE *f_in;
    FILE *f_out;
    f_in = fopen("note.txt","r");
    f_out = fopen("noteNew.txt","w+a");
    if(f_in!=NULL)
    {
        printf("файл note.txt открыт\n");
        puts("\n");
        while(fgets(str,l,f_in))
        {
            puts("считана строка: ");
            puts(str);
            puts ("\n");
            strcpy(notes[i].str,str);
            notes[i].ozu = atoi(&str[48]);
            i++;
        }
        printf("считывание завершено\n");
    }
    else
    {
        printf("не удалось создать или открыть файл\n");
        return 1;
    }
    fclose(f_in);
    for(int b = 1; b < i; ++b)
    {
        for(int r = 0; r < i-b; r++)
        {
            if(notes[r].ozu < notes[r+1].ozu)
            {
                notes_tmp = notes[r];
                notes[r] = notes[r+1];
                notes[r+1] = notes_tmp;
            }
        }
    }

    for (int z=0; z<i; z++)
    {
        if(notes[z].ozu >=40)
        {
            fputs(notes[z].str, f_out);
        }
    }
    fclose(f_out);
    fflush(stdin);
    getchar();
    return 0;
}
