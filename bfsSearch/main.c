#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dizi[6][6];

bool ziyaret[6];

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;  // kuyruðun baþý
struct node *rear = NULL;   // kuyruðun sonu

struct node * dugumOlustur(int data){
    struct node *eklenecek = (struct node *) malloc(sizeof(struct node));
    eklenecek->next = NULL;
    eklenecek->data = data;
    return eklenecek;
};

void enQueue(int data){
    struct node *yeniDugum = dugumOlustur(data);

    if(front == NULL){
        front = yeniDugum;
        rear = yeniDugum;
    }
    else{
        rear->next = yeniDugum;
        rear = yeniDugum;

    }
}

void deQueue(){
    if(front == NULL){
        return;
    }
    if(front->next == NULL){
        front = NULL;
        rear = NULL;
    }else{
        struct node* temp = front->next;
        free(front);
        front = temp;

    }
}

bool bosMu(){
    if(front == NULL){
        return true;
    }else{
        return false;
    }
}



void BFS(int root){
    int i;
    for(i = 0 ; i<6 ; i++){
        ziyaret[i] = false;
    }

    ziyaret[root] = true;
    enQueue(root);

    while(!bosMu()){
        root = front->data;
        printf("%d ",root);
        deQueue();
        for(int i = 0 ; i<6 ; i++){
            if(ziyaret[i] == false && dizi[root][i] == 1){
                ziyaret[i] = true;
                enQueue(i);
            }
        }
    }
}


void matrisOku(){
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

void yazdir(){
    int i,j;

    for(i = 0 ; i<6 ; i++){
        for(j = 0 ; j<6 ; j++){
            printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    matrisOku();
    yazdir();
    printf("\n");
    BFS(5);
    return 0;
}
