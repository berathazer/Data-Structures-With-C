#include <stdio.h>
#include <stdlib.h>

struct agac
{
    int veri;
    struct agac *sag;
    struct agac *sol;

};

struct agac *gecici=  NULL;
struct agac *gecici_sonraki = NULL;


int max_value;
int min_value;
int right_dept =0;
int left_dept =0;
int count =0; // dugum sayisi;



struct agac *kokolustur(int veri)
{
    struct agac *kok = (struct agac *)malloc(sizeof(struct agac));
    kok->veri = veri;
    kok->sag = NULL;
    kok->sol = NULL;

    return kok;
}

struct agac *elemanekle(struct agac *kok,int veri)
{
    if(kok != NULL)
    {
        if(kok->veri > veri)
        {
            kok->sol = elemanekle(kok->sol,veri);
        }
        if(kok->veri < veri)
        {
            kok->sag = elemanekle(kok->sag,veri);
        }
    }
    else
    {
        kok = kokolustur(veri);
    }
    return kok;
}


void preorder(struct agac *kok)
{
    if(kok != NULL)
    {
        printf("%d  ",kok->veri);
        preorder(kok->sol);
        preorder(kok->sag);
    }
}


void inorder(struct agac *kok)
{
    if(kok!=NULL)
    {
        inorder(kok->sol);
        printf("%d  ",kok->veri);
        inorder(kok->sag);
    }
}


void postorder(struct agac *kok)
{
    if(kok!=NULL)
    {
        postorder(kok->sol);
        postorder(kok->sag);
        count++;
        printf("%d  ",kok->veri);
    }
}


void maxdeger(struct agac *kok)
{

    if(kok != NULL)
    {
        maxdeger(kok->sag);
        right_dept++;
        if(kok->sag== NULL &&kok->sol == NULL)
        {
            max_value = kok->veri;
        }

    }

}


void mindeger(struct agac *kok)
{
    if(kok != NULL)
    {
        mindeger(kok->sol);
        left_dept++;
        if(kok->sol == NULL  && kok->sag == NULL)
        {
            min_value = kok->veri;
        }
    }
}

int sagmin(struct agac *kok)
{
    while(kok->sol != NULL)
    {
        kok = kok->sol;
    }
    return kok->veri;
}

int solmax(struct agac *kok)
{
    while(kok->sag != NULL)
    {
        kok = kok->sag;
    }
    return kok->veri;

}

void arama(struct agac *kok,int veri)
{
    if(kok != NULL)
    {
        if(veri>kok->veri)
        {
            arama(kok->sag,veri);
        }
        if(veri<kok->veri)
        {
            arama(kok->sol,veri);
        }
        if(kok->veri == veri)
        {
            printf("\nAranan eleman :%d\n",kok->veri);
        }
    }
    else
    {
        printf("\nAranan eleman bulunamadi.\n");
    }
}

struct agac *silme(struct agac *kok,int veri)
{
    if(kok == NULL)
    {
        free(kok);
        return NULL;
    }
    if(kok->veri == veri)
    {
        if(kok->sag == NULL && kok->sol == NULL)
        {
            free(kok);
            return NULL;
        }
        if(kok->sag != NULL)
        {
            kok->veri = sagmin(kok->sag);
            kok->sag = silme(kok->sag,sagmin(kok->sag));
            return kok;
        }
        kok->veri = solmax(kok);
        kok->sol = silme(kok->sol,sagmin(kok->sol));
        return kok;
    }
    if(kok->veri < veri)
    {
        kok->sag = silme(kok->sag,veri);
        return kok;
    }
    else
    {
        kok->sol = silme(kok->sol,veri);
        return kok;
    }
}

int sayac =0;





void elemansay(struct agac *kok)   //eleman sayisi rekursif
{
    if(kok != NULL)
    {
        sayac++;
        elemansay(kok->sol);
        elemansay(kok->sag);
    }
}



int elemantopla(struct agac *kok)    //elemanlarin toplami rekursif
{
    if(kok == NULL)
    {
        return 0;
    }
    else
    {
        return kok->veri+elemantopla(kok->sol)+elemantopla(kok->sag);
    }
}







int main()
{
    struct agac *kok = NULL;
    struct agac *temp = NULL;
    kok = kokolustur(10);

    elemanekle(kok,8);
    elemanekle(kok,7);
    elemanekle(kok,6);
    elemanekle(kok,4);
    elemanekle(kok,5);


    printf("preorder:  ");
    preorder(kok);
    printf("\n------------------------------------------\n");
    printf("inorder:   ");
    inorder(kok);
    printf("\n------------------------------------------\n");
    printf("postorder: ");
    postorder(kok);


    maxdeger(kok);
    mindeger(kok);

    printf("\n max deger :%d\n",max_value);
    printf("\n min deger :%d\n",min_value);
    printf("\n sag derinlik: %d",right_dept);
    printf("\n sol derinlik: %d",left_dept);
    printf("\n dugum sayisi: %d\n",count);

    inorder(kok);
    printf("\n");
    arama(kok,11);
       printf("\n");

    printf("toplam31:%d ",elemantopla(kok));
       printf("\n");
       silme(kok,15);
printf("toplam31:%d ",elemantopla(kok));
/*

    silme(kok,15);
    inorder(kok);
printf("\n");
    silme(kok,10);
    inorder(kok);
printf("\n");
    silme(kok,20);
    inorder(kok);
printf("\n");
    silme(kok,18);
    inorder(kok);
printf("\n");
    silme(kok,12);
    inorder(kok);
printf("\n");
    silme(kok,11);
    inorder(kok);
printf("\n");
    silme(kok,25);
    inorder(kok);
    silme(kok,25);
*/
    printf("\n\n");
    elemansay(kok);
    printf("eleman sayisi: %d\n",sayac);


    printf("\nsilindikten sonra :  ");
    inorder(kok);
    printf("\n\n");
    preorder(kok);

    return 0;
}
