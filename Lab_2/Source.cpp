#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
int mas[1000000];
int size = 1000000;

int compare(const void* x1, const void* x2)   
{
    return (*(int*)x1 - *(int*)x2);            
}

void shell(int* items, int count)
{
    clock_t start, end;
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
    start = clock();
    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
    end = clock();
    double time = difftime(end, start) / CLOCKS_PER_SEC;
    printf(" Время затраченное на сортировку Шелла  составило - %f секунд", time);
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];
    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}
void main() {
    setlocale(LC_ALL, "Russian");
    //for (int i = 0; i < 100000; i++) {
    //    mas[i] = rand() % 100;
    //}
    ////
    mas[0] = 1;
    for (int i = 0; i < 1000000; i++) {
        mas[i] = mas[i] + 1;
    }
    ////
    //mas[0] = 10000000;
    //for (int i = 0; i < 1000000; i++) {
    //    mas[i] = mas[i] - 1;
    //}
    ////
    //mas[0] = 1;
    //for (int i = 0; i < 500000; i++) {
    //    mas[i] = mas[i] - 1;
    //}
    //for (int i = 500000; i < 1000000; i++) {
    //    mas[i] = mas[i] - 1;
    //}
    ////
   /* shell(mas, size);*/
    /*clock_t start, end;
    start = clock();
    qs(mas, 0, size - 1);
    end = clock();
    double time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("\n Время затраченное на быструю сортировку составило - %f секунд", time);*/
    
    clock_t start, end;
    start = clock();
    qsort(mas, 1000000, sizeof(int), compare);      
    end = clock();
    double time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("\n Время затраченное на быструю сортировку c помощью стандартной библиотеки   составило  - %f секунд", time);
}
