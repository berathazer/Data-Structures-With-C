#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    char isim[20];
    char soyisim[20];
    char numara[20];
    struct dugum *gosterici;

};
int i = 0;
void strkopyala(char *kelime1,char *kelime2)
{
    while((*kelime1=*kelime2)!= NULL)
    {
        kelime1++;
        kelime2++;

    }
}

struct dugum *ilk = NULL;
struct dugum *gecici = NULL;


void basaEkle(char isim[20],char soyisim[20],char numara[20])
{
    struct dugum *eklenecek;
    eklenecek = (struct dugum*)malloc (sizeof(struct dugum));
    strkopyala(eklenecek->isim,isim);
    strkopyala(eklenecek->soyisim,soyisim);
    strkopyala(eklenecek->numara,numara);
    eklenecek->gosterici =ilk;
    ilk = eklenecek;


}

void listele()
{
    gecici = ilk;
    int i = 1;
    while(gecici != NULL)
    {

        printf("%d. kisinin Adi:%s   Soyadi:%s   Numarasi=%s\n",i,gecici->isim,gecici->soyisim,gecici->numara);
        i++;
        gecici = gecici->gosterici;

    }

}
struct dugum *gecici_sonraki = NULL;
struct dugum *gecici_onceki = NULL;

void NumarayaSirala()
{
    gecici =ilk;
    while(gecici ->gosterici != NULL)
    {

        if (gecici->numara > gecici->gosterici->numara)
        {

           if(gecici == ilk )
            {
                printf("1.degisime girdi");
                gecici_sonraki = gecici->gosterici;
                gecici->gosterici = gecici->gosterici->gosterici;
                gecici_sonraki->gosterici = gecici;
                gecici_onceki = gecici_sonraki;
                ilk = gecici_sonraki;
            }
            else
            {

                gecici_sonraki =gecici->gosterici;
                gecici->gosterici = gecici->gosterici->gosterici;
                gecici_sonraki->gosterici = gecici;
                gecici_onceki->gosterici = gecici_sonraki;
                gecici=ilk;


            }

        }
        else
        {
            gecici_onceki =gecici;
            gecici =gecici->gosterici;
            gecici_sonraki = gecici->gosterici;

        }

    }


}

void SoyismeSirala()
{
    gecici =ilk;
    while(gecici->gosterici != NULL)
    {

        if (gecici->soyisim[0] >= gecici->gosterici->soyisim[0])
        {

           if(gecici == ilk )
            {
                gecici_sonraki = gecici->gosterici;
                gecici->gosterici = gecici->gosterici->gosterici;
                gecici_sonraki->gosterici = gecici;
                gecici_onceki = gecici_sonraki;
                ilk = gecici_sonraki;
            }
            else
            {

                gecici_sonraki =gecici->gosterici;
                gecici->gosterici = gecici->gosterici->gosterici;
                gecici_sonraki->gosterici = gecici;
                gecici_onceki->gosterici = gecici_sonraki;
                gecici=ilk;


            }

        }
        else
        {
            gecici_onceki =gecici;
            gecici =gecici->gosterici;
            gecici_sonraki = gecici->gosterici;

        }

    }


}

int main()
{
    char isim[20];
    char soyisim[20];
    char numara[20];
    int durum = 1;

    while(durum)
    {
        int secim;
        printf("\nYapmak istediginiz islemi seciniz.\n");
        printf("1-Basa Ekleme\n2-Listeleme\n3-Numaraya gore sirala\n4-Soy isme gore sirala\nSecim:");
        scanf("%d",&secim);



        switch(secim)
        {
        case 1:
            printf("Ad:");
            scanf("%s",&isim);

            printf("Soyad:");
            scanf("%s",&soyisim);

            printf("Numara:");
            scanf("%s",&numara);

            basaEkle(isim,soyisim,numara);
            break;

        case 2:
            listele();
            break;


        case 3:

            NumarayaSirala();
            break;

        case 4:
            SoyismeSirala();
            break;

        default:
            printf("Yanlis numara girdiniz. Tekrar girin\n");
            break;



        }




    }
    return 0;
}

