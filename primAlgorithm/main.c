#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SONSUZ 100000
int dizi [5][5];


void matrisOku()
{
    int i = 0 ;
    FILE *fp = fopen("matris.txt","r");
    while(fscanf(fp,"%d %d %d %d %d",
                 &dizi[i][0],
                 &dizi[i][1],
                 &dizi[i][2],
                 &dizi[i][3],
                 &dizi[i][4]
                ) != EOF)
    {
        i++;
    }
}


void yazdir()
{
    int i,j;

    for(i = 0 ; i<5 ; i++)
    {
        for(j = 0 ; j<5 ; j++)
        {
            printf("%d   ",dizi[i][j]);
        }
        printf("\n");
    }
}

int ShortestPath(int key[],bool visited[]){

    int min = SONSUZ;

    int i,minIndex;

    for(i = 0 ; i<5 ; i++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Prims(){

    int key[5];
    int parent[5];
    bool visited[5];

    for(int i = 0 ; i<5 ; i++){
        visited[i] = false;
        key[i] = SONSUZ;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0 ; i<5 ; i++){
        int min = ShortestPath(key,visited);
        visited[min] = true;

        for(int j = 0 ; j<5 ; j++){
            if(dizi[min][j] && visited[j] == false && dizi[min][j] < key[j]){
                key[j] = dizi[min][j];
                parent[j] = min;
            }
        }
    }
    printMST(parent);
}

void printMST(int parent[]){
    for(int i = 1 ; i<5 ; i++){
        printf("%d - %d => %d\n",parent[i],i,dizi[i][parent[i]]);
    }
}

int main()
{
    matrisOku();
    //yazdir();
    Prims();
    return 0;
}
