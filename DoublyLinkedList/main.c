#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int veri;
    struct dugum *sonraki;
    struct dugum *onceki;

};

struct dugum *ilk = NULL;
struct dugum *gecici = NULL;
struct dugum *gecici_sonraki = NULL;
struct dugum *gecici_onceki = NULL;


void basaEkle(int sayi)
{
    struct dugum *eklenecek = (struct dugum*)malloc(sizeof(struct dugum));
    eklenecek->veri = sayi;


    if (ilk==NULL)
    {
        ilk=eklenecek;
        ilk->sonraki = ilk;
        ilk->onceki = ilk;
    }
    else
    {
        if(ilk->sonraki == ilk )
        {
            ilk->sonraki = eklenecek;
            ilk->onceki = eklenecek;
            eklenecek->sonraki = ilk;
            eklenecek->onceki = ilk;
            ilk = eklenecek;
        }
        else
        {
            gecici = ilk;
            while(gecici->sonraki != ilk)
            {
                gecici = gecici->sonraki;
            }

            gecici->sonraki = eklenecek;
            ilk->onceki = eklenecek;
            eklenecek->sonraki = ilk;
            eklenecek->onceki = gecici;
            ilk = eklenecek;

        }
    }
}

void sonaEkle(int sayi)
{
    struct dugum *eklenecek = (struct dugum*)malloc(sizeof(struct dugum));
    eklenecek->veri = sayi;
    if(ilk == NULL)
    {
        ilk = eklenecek;
        ilk->sonraki = ilk;
        ilk->onceki = ilk;

        //basaEkle(sayi);
    }
    else
    {
        if(ilk->sonraki ==ilk)
        {
            ilk->sonraki = eklenecek;
            ilk->onceki = eklenecek;
            eklenecek->sonraki = ilk;
            eklenecek->onceki = ilk;

        }
        else
        {
            gecici = ilk;
            while(gecici->sonraki !=ilk)
            {
                gecici = gecici->sonraki;
            }
            gecici->sonraki = eklenecek;
            eklenecek->onceki = gecici;
            eklenecek->sonraki = ilk;
            ilk->onceki = eklenecek;

        }
    }

}

void bastanSil()
{
    gecici = ilk;
    if(ilk ==NULL)
    {
        printf("eleman yok");
    }
    else
    {
        if(ilk->sonraki == ilk)
        {
            free(ilk);
            ilk = NULL;
        }
        else
        {
            while(gecici->sonraki != ilk)
            {
                gecici = gecici->sonraki;
            }
            gecici_sonraki = ilk->sonraki;
            free(ilk);
            gecici_sonraki->onceki =gecici;
            gecici->sonraki = gecici_sonraki;
            ilk = gecici_sonraki;

        }
    }
}

void sondanSil()
{
    gecici = ilk;

    if(ilk == NULL)
    {
        printf("silinecek eleman bulunamadi");
    }
    else
    {
        if(ilk->sonraki == ilk)
        {
            free(ilk);
            ilk = NULL;
        }
        else
        {
            while(gecici->sonraki != ilk)
            {
                gecici_onceki = gecici;
                gecici = gecici->sonraki;
            }
            gecici_onceki->sonraki = ilk;
            ilk->onceki = gecici_onceki;
            free(gecici);

        }
    }
}

void listele()
{
    system("cls");
    if(ilk ==NULL)
        printf("ELEMAN YOK !!!");
    else
    {
        gecici = ilk;
        while(gecici->sonraki != ilk)
        {
            printf("%d -> ",gecici->veri);
            gecici = gecici->sonraki;
        }
        printf("%d",gecici->veri);

    }

}


int main()
{
    while (1)
    {
        int secim;
        int sayi;
        printf("\n1-Basa Ekle\n2-Sona Ekle\n3-Bastan Sil\n4-Sondan Sil\n5-Listele\n0-Cikis\n");
        printf("Yapmak istediginiz islemi secin:");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:

            printf("Eklemek istediginiz sayiyi girin:");
            scanf("%d",&sayi);
            basaEkle(sayi);
            listele();
            break;

        case 2:
            printf("Eklemek istediginiz sayiyi girin:");
            scanf("%d",&sayi);
            sonaEkle(sayi);
            listele();
            break;

        case 3:
            bastanSil();
            listele();
            break;

        case 4:
            sondanSil();
            listele();
            break;

        case 5:
            listele();
            break;

        case 0:
            return 0;

        default:
            printf("\nYanlis secim.\n");

        }
    }
    return 0;
}
