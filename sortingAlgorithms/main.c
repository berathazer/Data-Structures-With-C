#include <stdio.h>
#include <stdlib.h>
int dizi[] = {0,25,2,10,45,9,7,78,40,31};
int dizi2[] = {0,1,2,3,4,5,6,7,8,10};
int kopya[10];
int boyut = sizeof(dizi)/sizeof(dizi[0]);

void insertion_sort(int dizi[],int boyut)
{
    int i,j;
    for(i = 1 ; i<boyut ; i++)
    {
        int temp = dizi[i];
        j = i-1;
        while(dizi[j]>temp)
        {
            dizi[j+1] = dizi[j];
            j--;
        }
        dizi[j+1] = temp;
    }
}

void bubble_sort(int dizi[],int boyut)
{
    int i,j;
    for(i = 0 ; i< boyut ; i++)
    {
        for(j = 1 ; j<boyut-1-i ; j++)
        {
            if(dizi[j]>dizi[j+1])
            {
                int temp = dizi[j+1];
                dizi[j+1] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
}

void selection_sort(int dizi[],int boyut)
{
    int i,j,minindex;
    for(i = 0 ; i<boyut ; i++)
    {
        minindex = i;
        for(j = i ; j<boyut ; j++)
        {
            if(dizi[j] < dizi[minindex])
                minindex = j;
        }
        int temp = dizi[i];
        dizi[i] = dizi[minindex];
        dizi[minindex] = temp;
    }
}

// 7,25,2,10,45,9,7,78,40,31

void birlestir(int bas,int orta,int son)
{
    int i,j,k;
    for(i = bas ; i <=son ; i++)
    {
        kopya[i] = dizi[i];
    }
    i = bas;
    j = orta+1;
    k = bas;
    while(i<=orta && j<=son)
    {
        if(kopya[i] <= kopya[j])
        {
            dizi[k++] = kopya[i++];
        }
        else
        {
            dizi[k++] = kopya[j++];
        }
    }

    while (i<=orta)
    {
        dizi[k++] = kopya[i++];
    }
}

void merge_sort(int bas,int son)
{
    if(bas < son)
    {
        int orta = (bas+son)/2;
        merge_sort(bas,orta);
        merge_sort(orta+1,son);
        birlestir(bas,orta,son);

    }

}

void bin_search(int dizi[],int bas,int son,int aranan )
{
    int orta = dizi[(bas+son)/2];
    if(aranan < orta)
        bas++;
    else if(aranan > orta)
        son--;
    else
        printf("Aranan eleman bulundu: %d\n",dizi[orta]);
}
int recursive_bin(int dizi[],int bas,int son,int aranan)
{
    if(son>=bas)
    {
        int orta = dizi[(bas+son)/2];

        if(aranan == orta)
            return orta;
        if(aranan<orta)
            return recursive_bin(dizi,bas,orta-1,aranan);
        if(aranan>orta)
            return recursive_bin(dizi,orta+1,son,aranan);
    }
    else
        return -1;
}

int main()
{
    printf("Siralanmamis Dizi:  ");
    for(int i =0  ; i<boyut ; i++)
    {
        printf("%d ",dizi[i]);
    }
    printf("\n\n");


    //insertion_sort(dizi,boyut);
    //bubble_sort(dizi,boyut);
    //selection_sort(dizi,boyut);
    merge_sort(0,9);

    printf("Siralanmis Dizi:  ");
    for(int i =0  ; i<boyut ; i++)
    {
        printf("%d ",dizi[i]);
    }
    printf("\n\n");

    bin_search(dizi,0,boyut-1,10);

    int sayi = recursive_bin(dizi2,0,boyut-1,8);
    if(sayi == -1)
        printf("aranan sayi bulunamadi\n");
    else
        printf("Aranan Sayi : %d\n",sayi);



    return 0;
}
