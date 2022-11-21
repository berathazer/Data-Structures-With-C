#include<stdio.h>
#include<stdlib.h>
#define line 8
#define boyut 6


struct node
{
    int data;
    struct node *next;
};



struct node *first = NULL;
struct node *temp = NULL;
struct node *last = NULL;
struct node *head = NULL;

int deger=0;
void ekle(int adder)
{
    struct node *add = (struct node*)malloc (sizeof(struct node));
    add->data = adder;
    add->next = NULL;
    temp = first;
    if(temp == NULL)
    {
        first = add;
        last = add;
    }
    else if(temp->next == NULL)
    {
        first->next  = add;
        last = add;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = add;
        last = add;
    }
}



void terscevir(struct node *ilk)   // recursive reverse linked list function
{

    if(ilk->next->next != NULL){

        terscevir(ilk->next);

        ilk->next->next = ilk;
        ilk->next = NULL;

    }else{

        head = ilk->next;

        ilk->next->next = ilk;
        ilk->next = NULL;

        return 0;

    }

}



void yazdir(struct node *first)
{
    temp = first;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
     printf("%d->",temp->data);
}





int main()
{
    ekle(1);
    ekle(2);
    ekle(3);
    ekle(4);
    ekle(10);
    ekle(8);
    ekle(0);

    printf("Before Reverse: ");
    yazdir(first);



    terscevir(first);  // recursive reverse function
    printf("\nAfter Reverse: ");
    yazdir(head);

    printf("\n");
    //yazdir(first);





}








/*

int sayac=1;
int onceki=0;
int sonraki=1;
int gecici;
int sayi=1;
void fibonacci(int x){

    if(x>=2)
    {
        sayac++;
        fibonacci(x-1);
        sayi = onceki+sonraki;
        onceki = sonraki;
        sonraki = sayi;

    }
    printf("%d->",sayi);
}





int main()
{
    fibonacci(555);  //recursive fibonacci function
}






int fak = 1;
void faktoriyel(int x)
{
if(x>1)
 {
     faktoriyel(x-1);
     fak = fak*x;
 }

 printf("%d->",fak);
 printf("%d\n",x);
}

int main()
{

    faktoriyel(5);   recursive factorial function

    return 0;
}
*/



