#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

void insertion(int []);
void tampil (int []);

int main()
{
    int A[] = {5, 4, 3, 2, 1};

    printf("Sebelum diurutkan : ");
    tampil(A);
    insertion(A);
    printf("Setelah diurutkan : ");
    tampil(A);
    return 0;
}

void tampil(int x[])
{
    int i;

    for(i=0; i<MAKS; i++)
        printf("%d ", x[i]);
    puts("");
}

void insertion(int x[])
{
    int i, j, key;

    for(i=1;i<MAKS;i++)
    {
        key=x[i];
        j=i-1;
        while(j>=0 && x[j]>key)
        {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
    }
}
