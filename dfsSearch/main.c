#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int dizi[6][6];
bool ziyaret[6];

void matrisOku()
{
    int i = 0 ;
    FILE *fp = fopen("matris.txt","r");
    while(fscanf(fp,"%d %d %d %d %d %d",
                 &dizi[i][0],
                 &dizi[i][1],
                 &dizi[i][2],
                 &dizi[i][3],
                 &dizi[i][4],
                 &dizi[i][5]
                ) != EOF)
    {
        i++;
    }
}

void yazdir()
{
    int i,j;

    for(i = 0 ; i<6 ; i++)
    {
        for(j = 0 ; j<6 ; j++)
        {
            printf("%d   ",dizi[i][j]);
        }
        printf("\n");
    }
}

int minBulma(int root){
    int minDeger = 10000;
    int minIndis = 0;
    for(int i = 0 ; i<6 ; i++){
        if(dizi[root][i] < minDeger && ziyaret[i] == false &&  dizi[root][i] != -1){
            minDeger = dizi[root][i];
            minIndis = i;
        }
    }
    return minIndis;

}


bool DFS(int root)
{
    ziyaret[root] = true;
    printf("%d ",root);

    for(int i = 0 ; i < 6 ; i++)
    {
        int minIndis = minBulma(root);
        if(dizi[root][i] != -1 && ziyaret[i] == false)
        {
            DFS(minIndis);
        }
    }
}


int main()
{
    matrisOku();
    for(int i = 0 ; i< 6 ; i++)
    {
        ziyaret[i] = false;
    }
    yazdir();
    printf("\n");
    DFS(5);
    return 0;
}
