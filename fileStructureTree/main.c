#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agac
{
    char dizi[20];
    struct agac *cocuk;
    struct agac *kardes;
    int tabsayisi;

};

struct dugum
{
    char deger[20];
    struct dugum *sonraki;
    int tsayisi;
};


struct dugum *gecici = NULL;
struct dugum *bas = NULL;
struct dugum *gdeger = NULL;
struct dugum *kontrol = NULL;

int sayac =0;





struct agac *kokolustur(char dizi[],int tabsayisi)
{
    struct agac *kok = (struct agac*)malloc(sizeof(struct agac));
    kok->cocuk = NULL;
    kok->kardes = NULL;
    kok->tabsayisi = tabsayisi;
    strcpy(kok->dizi,dizi);
    return kok;
}


void yolu_goster(struct agac *kok,char dizi[])
{
    if(kok != NULL)
    {
        if(!strcmp(kok->dizi,dizi))
        {
            ara(dizi,kok->tabsayisi);
            printf("\n\n");
        }
        yolu_goster(kok->cocuk,dizi);
        yolu_goster(kok->kardes,dizi);
    }
}


void listele(struct agac *kok)
{
    if(kok!=NULL)
    {
        for(int i = 1 ; i<kok->tabsayisi+1 ; i++)
        {
            printf("\t");
        }
        printf("%s\n\n",kok->dizi);
        listele(kok->cocuk);
        listele(kok->kardes);
    }

}


void ara(char dizi[],int tsayisi)
{
    int i =1;
    gecici = bas;
    printf("%s:/",bas->deger);

    for(i; i<tsayisi;)
    {
        if(gecici->tsayisi == i)
        {
            gdeger = gecici;
        }
        gecici = gecici->sonraki;

        if(!strcmp(gecici->deger,dizi))
        {
            kontrol = gecici;
            printf("%s/",gdeger->deger);
            gecici = bas;
            i++;
        }
    }
    printf("%s ",dizi);
}


void sonaekle(char dizi[],int tabsayisi)
{
    struct dugum *eklenecek = (struct dugum*)malloc(sizeof(struct dugum));
    eklenecek->sonraki = NULL;
    eklenecek->tsayisi = tabsayisi;
    strcpy(eklenecek->deger,dizi);

    gecici = bas;
    if(bas== NULL)
    {
        bas = eklenecek;
        bas->sonraki = NULL;
        bas->tsayisi = tabsayisi;
        strcpy(bas->deger,dizi);
    }
    else if(bas->sonraki ==NULL)
    {
        bas->sonraki = eklenecek;
    }
    else
    {
        while(gecici->sonraki != NULL)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = eklenecek;
    }
}


struct agac *gezin(struct agac *kok)
{
    if(kok != NULL)
    {
        sonaekle(kok->dizi,kok->tabsayisi);
        gezin(kok->cocuk);
        gezin(kok->kardes);
    }
}


struct agac *ekle(struct agac *kok,int tabsayisi,char dizi[])
{
    if(kok != NULL)
    {
        if(tabsayisi == kok->tabsayisi+1)
        {
            if(kok->kardes == NULL)
            {
                kok->cocuk = ekle(kok->cocuk,tabsayisi,dizi);
            }
            else
            {
                ekle(kok->kardes,tabsayisi,dizi);
            }
        }
        else if(tabsayisi == kok->tabsayisi)
        {
            kok->kardes = ekle(kok->kardes,tabsayisi,dizi);
        }
        else
        {
            if(kok->kardes == NULL)
            {
                ekle(kok->cocuk,tabsayisi,dizi);
            }
            else
            {
                ekle(kok->kardes,tabsayisi,dizi);
            }
        }
    }
    else
    {
        kok = kokolustur(dizi,tabsayisi);
    }
    return kok;
}


int elemansay(struct agac *kok)
{
    if(kok != NULL)
    {
        return 1+elemansay(kok->kardes)+elemansay(kok->cocuk);
    }
}

int main()
{
    struct agac *root = NULL;


    root = kokolustur("C",0);

    ekle(root,1,"Kullanicilar");
    ekle(root,2,"BeratHazer");
    ekle(root,3,"Eclipse");
    ekle(root,2,"Ortak");
    ekle(root,3,"Ortak Muzikler");
    ekle(root,1,"Program Files");
    ekle(root,2,"Intel");
    ekle(root,3,"Wifi");
    ekle(root,1,"Riot Games");
    ekle(root,2,"League Of Legends");
    ekle(root,3,"Aram");
    ekle(root,1,"Windows");



    gezin(root);



    yolu_goster(root,"Kullanicilar");
    yolu_goster(root,"Berat");
    yolu_goster(root,"Eclipse");
    yolu_goster(root,"Ortak");
    yolu_goster(root,"Ortak Muzikler");
    yolu_goster(root,"Program Files");
    yolu_goster(root,"Intel");
    yolu_goster(root,"Wifi");
    yolu_goster(root,"Riot Games");
    yolu_goster(root,"League Of Legends");
    yolu_goster(root,"Aram");
    yolu_goster(root,"Windows");

    return 0;
}
