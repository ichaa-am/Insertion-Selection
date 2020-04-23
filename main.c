#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAKS 5

void insertion(int *, int);
void selection(int *, int);
int menu();

int main()
{
    int angka[MAKS];
    int tampung[MAKS];
    int pilih, mode, n;
    puts("Menu Sorting Int\n");
    printf("Masukkan jumlah data : ");
    scanf("%d", &n);
    random(angka,n);
    printf("Kondisi array awal: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", angka[i]);
    }
    backup(MAKS,angka,tampung);
    do
    {
        backup(MAKS,tampung,angka);
        printf("\n\nKondisi array awal: ");
        for(int i=0; i<n; i++)
        {
            printf("%d ", angka[i]);
        }
        printf("\n\nMenu Sorting\n");
        printf("1. Insertion\n");
        printf("2. Selection\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilih);
        switch(pilih)
        {
        case 1 :
            mode = menu();
            insertion(angka, mode);
            break;

        case 2 :
            mode = menu();
            selection(angka, mode);
            break;

        case 3 :
            exit(0);
            break;
        }
    }
    while(1);
    return 0;
}

void backup(int batas, int A[], int temp[])
{
    int i;
    for(i=0; i<batas; i++)
        temp[i] = A[i];
}

void random(int A[], int n)
{
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++)
        A[i] = rand()/1000;
}

int menu()
{
    int pilih;
    printf("\nMode Urut\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilih);
    return pilih;
}

void insertion(int angka[], int mode)
{
    for(int i=1; i<MAKS; i++)
    {
        for(int j=i; j>0 && angka[j]<angka[j-1]; j--)
        {
            int temp=angka[j-1];
            angka[j-1]=angka[j];
            angka[j]=temp;
        }
    }
    printf("\nSetelah diurutkan: ");
    if(mode==1)
    {
        for(int i=0; i<MAKS; i++)
        {
            printf("%d ", angka[i]);
        }
    }
    else if(mode==2)
    {
        for(int i=MAKS-1; i>=0; i--)
        {
            printf("%d ", angka[i]);
        }
    }
}

void selection(int angka[], int mode)
{
    int i,j, min;
    for(i=0; i<MAKS-1; i++)
    {
        min = i;
        j = i+1;
        while(j<MAKS)
        {
            if(angka[j] < angka[min])
                min = j;
            j++;
        }
        int temp = angka[i];
        angka[i] = angka[min];
        angka[min] = temp;
    }

    printf("\nSetelah diurutkan: ");
    if(mode==1)
    {
        for(int i=0; i<MAKS; i++)
        {
            printf("%d ", angka[i]);
        }
    }
    else if(mode==2)
    {
        for(int i=MAKS-1; i>=0; i--)
        {
            printf("%d ", angka[i]);
        }
    }
}
