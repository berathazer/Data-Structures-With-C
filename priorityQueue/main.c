#include <stdio.h>
#include <stdlib.h>

struct kuyruk
{
    int fiyat;
    int oteleme;
    struct kuyruk *sonraki;

};
struct kuyruk *ilk = NULL;
struct kuyruk *gecici = NULL;
struct kuyruk *gecici_sonraki = NULL;
struct kuyruk *gecici_onceki = NULL;
struct kuyruk *temp = NULL;
struct kuyruk *gezici = NULL;
struct kuyruk *temponceki = NULL;
int topfiyat;



void siparis_ekle(int fiyat)
{
    struct kuyruk *eklenecek = (struct kuyruk *)malloc(sizeof(struct kuyruk));
    eklenecek->fiyat = fiyat;

    temp =ilk;
    gecici = ilk;

    if(ilk == NULL)
    {
        ilk = eklenecek;
        ilk->sonraki = NULL;
        ilk->oteleme = 0;
        topfiyat = fiyat;
    }
    else if(ilk->sonraki == NULL)
    {
        if(eklenecek->fiyat > ilk->fiyat)
        {
            ilk->sonraki = eklenecek;
            eklenecek->sonraki = NULL;
            eklenecek->oteleme = 0;
            ilk->oteleme++;
            topfiyat = eklenecek->fiyat;

        }
        else
        {
            eklenecek->sonraki = ilk;
            eklenecek->oteleme = 0;
            ilk = eklenecek;
        }
    }
    else
    {

        while(gecici->sonraki != NULL)
        {
            gecici_onceki = gecici;

            if(eklenecek->fiyat <= gecici->fiyat)
            {
                eklenecek->sonraki = ilk;
                ilk = eklenecek;
                gecici = gecici->sonraki;
                break;
            }

            if(eklenecek->fiyat > gecici->fiyat && eklenecek->fiyat <= gecici->sonraki->fiyat)
            {
                eklenecek->sonraki = gecici->sonraki;
                gecici->sonraki = eklenecek;

                while(temp->sonraki != eklenecek)
                {
                    temp->oteleme++;
                    temp = temp->sonraki;
                }
                temp->oteleme++;
                gecici = gecici->sonraki;

                break;
            }
            temp= ilk;
            while(temp->sonraki != NULL)
            {
                temp = temp->sonraki;
            }

            if (eklenecek->fiyat > temp->fiyat)
            {
                temp->sonraki = eklenecek;
                eklenecek->sonraki = NULL;
                topfiyat = eklenecek->fiyat;
                gezici = ilk;
                while(gezici->sonraki != eklenecek)
                {
                    gezici->oteleme++;
                    gezici =gezici->sonraki;
                }
                gezici->oteleme++;
                gecici = gecici->sonraki;

                break;

            }
            temp = ilk;

            gecici =gecici->sonraki;
        }
    }
}


void siparisi_al()
{
    gecici = ilk;
    temp = ilk;
    int maxoteleme =0;
    int sayac = 0;
    temponceki = ilk;
    gezici = ilk;
    if(gecici != NULL)
    {
        while(temp->sonraki != NULL)
        {
            if(temp->oteleme >= maxoteleme)
            {
                maxoteleme =temp->oteleme;
            }
            temp = temp->sonraki;
        }
    }

    temp = ilk;

    if(gecici == NULL)
    {
        printf("Siparis yok");
    }
    else if(gecici->sonraki ==NULL)
    {
        printf("%d fiyatli siparis alindi\n",gecici->fiyat);
        free(gecici);
        ilk = NULL;
    }

    else
    {
        gecici = ilk;
        while(gecici->sonraki != NULL)
        {
            if(maxoteleme < 3)
            {

                while(gezici->sonraki != NULL)
                {
                    gecici_onceki = gezici;
                    gezici = gezici->sonraki;
                }
                gecici_onceki->sonraki = NULL;
                printf("%d fiyatli siparis alindi",gezici->fiyat);
                free(gezici);
                break;

            }
            else if(gecici->oteleme >=3)
            {

                temp = gecici->sonraki;
                while(temp->sonraki != NULL)
                {

                    if(temp->oteleme >= gecici->oteleme)
                    {

                        while(temponceki->sonraki != temp)
                        {

                            temponceki = temponceki->sonraki;
                        }
                        temponceki->sonraki = temp->sonraki;
                        printf("%d fiyatli siparis alindi\n",temp->fiyat);
                        free(temp);
                        sayac = 1;
                        break;
                    }
                    temp = temp->sonraki;
                }
                temp =ilk;
                if(sayac ==0)
                {
                    if(gecici ==ilk)
                    {
                        ilk = ilk->sonraki;
                        printf("%d fiyatli siparis alindi",gecici->fiyat);
                        free(gecici);
                        break;
                    }
                    else
                    {
                        while(gecici_onceki->sonraki != gecici)
                        {
                            gecici_onceki = gecici_onceki->sonraki;
                        }
                        gecici_onceki->sonraki = gecici->sonraki;
                        printf("%d fiyatli siparis alindi",gecici->fiyat);
                        free(gecici);
                        break;
                    }
                }
                break;
            }

            gecici =gecici->sonraki;
        }

    }

}


void otelemeyazdir()
{
    gecici = ilk;
    while(gecici != NULL)
    {
        printf("%d fiyatli siparisin otelemesi:%d\n",gecici->fiyat,gecici->oteleme);
        gecici = gecici->sonraki;
    }
    printf("\n");
}




void listele()
{
    printf("\n");
    gecici =ilk;
    if(gecici == NULL)
    {
        printf("eleman yok");
    }
    else
    {
        while(gecici->sonraki != NULL)
        {
            printf("%d->",gecici->fiyat);
            gecici =gecici->sonraki;
        }
        printf("%d",gecici->fiyat);
    }
    printf("\n");
}



int main()
{
    int fiyat;
    int secim;
    while(1)
    {
        printf("\n1-Siparis ekle\n2-Siparisi al\n3-Siparisleri listele\n4-Oteleme listesi\n0-Cikis\nSecim:");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            printf("Siparisiniz fiyatini giriniz:");
            scanf("%d",&fiyat);
            siparis_ekle(fiyat);
            system("cls");
            listele();
            break;

        case 2:
            siparisi_al();
            listele();
            break;

        case 3:
            listele();
            break;

        case 4:
            otelemeyazdir();
            break;

        case 0:
            return 0;
            break;

        }
    }
    return 0;
}
