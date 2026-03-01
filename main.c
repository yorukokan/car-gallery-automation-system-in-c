#include <stdio.h>
#include <stdlib.h>

/* Ad         : Okan
   Soyad      : Yoruk */

// --> ARAC GALERISI FIRMASI OTOMASYONU <--

struct Araba // Araba Icin Gerekli Olan Struct Yapisi Kuruluyor .
{
    char marka[20];
    char model[20];
    char renk[20];
    int yil;
    long int fiyat;
};

struct Firma // Firma Icin Gerekli Olan Struct Yapisi Kuruluyor .
{
    char firmaAdi[50];
    char sehir[20];
    int arabaSayisi;
    struct Araba *arabalar;
};
// --> Fonksiyon Tanimlamalari Yapiliyor .
int menu();                                                             // --> Menu Fonksiyonu Ekranini Kullanmayi Sagliyor .
void aracKayitEkle(struct Firma *firma, int n);                         // 1 - Arac Kaydini Yapmayi Sagliyor .
void aracKaydiListele(struct Firma *firma, int n);                      // 2 - Arac Kayitlarini Listelemeyi Sagliyor .
void aracKaydiSil(struct Firma *firma, int arabaninNumarasi);           // 3 - Arac Kayitlarini Silmeyi Sagliyor .
void aracKaydiGuncelle(struct Firma *firma, int arabaninNumarasi);      // 4 - Arac Kayitlarini Guncellemeyi Sagliyor .
void aracFiyatAraligi(struct Firma *firma, int minFiyat, int maxFiyat); // 5 - Belirli Fiyat Araliginda Arabalari Ekrana Getiriyor .
void arabaBulma(struct Firma *firma, char *arananMarka);                // 6 - Ayni Markaya Sahip Arabalari Bulmayi Sagliyor .

int main()
{
    int secim;
    int n = 1;

    printf("Arac Satis Otomasyonuna Hosgeldiniz ... \n\n"); // Bilgilendirme Yapiliyor .
    printf("Oncelikle Firmanizin Adini ve Bulundugunuz Sehri Giriniz . \n");

    struct Firma *firma = malloc(n * sizeof(struct Firma)); // Gerekli Olan Bellek Alani Aliniyor .

    if (firma == NULL) // Gerekli Bellek Ayirilamaz Ise Uyari Bilgilendirmesi Yapiliyor .
    {
        printf("Gerekli Olan Bellek Ayirilamadi ! \n");
        exit(0);
    }
    else
        printf("Firma Adi : ");
    scanf("%s", &firma->firmaAdi);
    printf("Sehir     : ");
    scanf("%s", &firma->sehir);
    printf("\n----------------------------------------------------------------- \n"); // Firma Olusturuluyor . Bilgilendirme Yapiliyor .
    printf("\n%s Adli Firmaniz Olusturuldu . \n", firma->firmaAdi);
    printf("%s Bolgesinde Hizmet Vermeye Basliyabilirsiniz . \n\n", firma->sehir);
    printf("Simdi Firmanin Ana Menusune Gecebiliriz . \n");
    printf("Burada Gozuken Fonksiyonlar ile Istediklerinizi Yapabilirsiniz . \n\n");
    printf("----------------------------------------------------------------- \n");

    secim = menu();
    // Yapilmak Istenen Islemlerin Menusu Ekrana Getiriliyor .
    while (secim != 0) // Gerekli Fonksiyonlar Cagirilarak Islemler Tamamlaniyor .
    {
        if (secim == 1)
        {
            system("cls"); // Ekrani Temizlemek Icin Kullaniyoruz .
            aracKayitEkle(firma, n);
        }
        else if (secim == 2)
        {
            system("cls"); // Ekrani Temizlemek Icin Kullaniyoruz .
            aracKaydiListele(firma, n);
        }
        else if (secim == 3)
        {
            int arabaninNumarasi;
            system("cls"); // Ekrani Temizlemek Icin Kullaniyoruz .
            printf("Arac Kaydi Silme Islemine Hosgeldiniz . \n");
            printf("\nSilinecek Arabanin Numarasini Giriniz : "); // Silinecek Araba Numarasi Aliniyor .
            scanf("%d", &arabaninNumarasi);
            aracKaydiSil(firma, arabaninNumarasi);
        }
        else if (secim == 4)
        {
            int arabaninNumarasi;
            system("cls");                                             // Ekrani Temizlemek Icin Kullaniyoruz .
            printf("Arac Kaydi Guncelleme Islemine Hosgeldiniz . \n"); // Guncellenecek Araba Numarasi Aliniyor .
            printf("\nGuncellenecek Arabanin Numarasini Giriniz : ");
            scanf("%d", &arabaninNumarasi);
            aracKaydiGuncelle(firma, arabaninNumarasi);
        }
        else if (secim == 5)
        {
            int minFiyat, maxFiyat;
            system("cls"); // Ekrani Temizlemek Icin Kullaniyoruz .
            printf("Fiyat Araliginda Arama Bulma Islemine Hosgeldiniz . \n");
            printf("Fiyat Araligini Giriniz : \n"); // Fiyat Araligi Aliniyor ( Maximum ve Minimum Fiyat Bilgisi Aliniyor . ) .
            printf("Minimum Fiyat : ");
            scanf("%d", &minFiyat);
            printf("Maximum Fiyat : ");
            scanf("%d", &maxFiyat);
            aracFiyatAraligi(firma, minFiyat, maxFiyat);
        }
        else if (secim == 6)
        {
            char arananMarka[20];
            system("cls"); // Ekrani Temizlemek Icin Kullaniyoruz .
            printf("Markaya Gore Araba Arama Yapma Islemine Hosgeldiniz . \n");
            printf("Aranan Araba Markasi : "); // Aranan Arabanin Markasi Aliniyor .
            scanf("%s", arananMarka);
            arabaBulma(firma, arananMarka);
        }
        else
        {
            printf("\nHatali Secim Yaptiniz !\n"); // Hatali Secim Bildiriliyor . Ana Menuye Donuluyor .
            printf("Lutfen Belirtilen Secimlerden Birini Yapin ! \n");
        }
        secim = menu();
    }
    printf("\nOtomasyondan Cikiliyor ... \n"); // Otomasyondan Cikis Yapiliyor .
    printf("Iyi Gunler Dileriz ... \n");
    free(firma); // Bellekte Tutulan Yer Serbest Birakiliyor .
    return 0;
}

// |--> Ana Menu Fonksiyonu .
int menu()
{
    int fonksiyonSecim;

    printf("\n------------------------------- \n");
    printf("|-->       ANA  MENU       <--| \n"); // Ana Menu Hakkinda Bilgi Veriliyor .
    printf("------------------------------- \n");
    printf("1- Arac Kayit Ekleme                    .\n");
    printf("2- Arac Kaydi Listeleme                 .\n");
    printf("3- Arac Kaydi Silme                     .\n");
    printf("4- Arac Kaydi Guncelleme                .\n");
    printf("5- Belirli Fiyat Araliginda Araba Bulma .\n");
    printf("6- Markaya Gore Arac Listeleme          .\n");
    printf("0- Cikis . \n");

    printf("Secim Yapiniz : "); // Secim Yaptiriliyor . Secilen Fonksiyonu Geri Donduruyor .
    scanf("%d", &fonksiyonSecim);

    return fonksiyonSecim;
}

// 1. --> Arac Kaydi Ekleme Fonksiyonu .
void aracKayitEkle(struct Firma *firma, int n)
{
    int arabaSayisi;
    int i;
    printf("Arac Kaydi Ekleme Islemine Hosgeldiniz . \n");
    printf("UYARI --> Arac Kayit Islemi Basta Yapilmalidir . \n");
    printf("      --> Sonradan Arac Eklemek Eski Araclari Silmektedir . \n");
    printf("\nFirmaniza Kac Tane Araba Eklemek Istiyorsunuz ? : "); // Kayit Yapilacak Araba Sayisi Aliniyor .
    scanf("%d", &arabaSayisi);

    firma->arabalar = malloc(arabaSayisi * sizeof(struct Araba)); // Arabalar Icin Bellekte Yer Ayiriliyor .
                                                                  /* Arac Kaydi Ekleme Islemi En Basta Yapiliyor.
                                                                     Sonradan Arac Eklemek Istedim ama Tam Olarak Yapamadim .
                                                                     Realloc ile Yapmaya Calistigimda Calisti Fakat return Hatasini Bulamadim .
                                                                     Bu Yuzden Sadece Basta Araba Ekleyebiliyoruz .
                                                                     Sonradan Eklemek Istersek Bastan Baslamamiz Gerekiyor . */

    if (firma->arabalar == NULL) // Gerekli Bellek Ayirilamaz Ise Uyari Bilgilendirmesi Yapiliyor .
    {
        printf("Gerekli Olan Bellek Ayirilamadi ! \n");
        exit(0);
    }

    for (i = 0; i < arabaSayisi; i++)
    {
        printf("\n%d. Arabanin Bilgilerini Giriniz : \n", i + 1); // Araba Icin Istenilen Bilgiler Aliniyor .
        printf("Araba Markasi    : ");
        scanf("%s", &firma->arabalar[i].marka);
        printf("Araba Modeli     : ");
        scanf("%s", &firma->arabalar[i].model);
        printf("Araba Rengi      : ");
        scanf("%s", &firma->arabalar[i].renk);
        printf("Araba Uretim Yili: ");
        scanf("%d", &firma->arabalar[i].yil);
        printf("Araba Fiyati     : ");
        scanf("%ld", &firma->arabalar[i].fiyat);
        printf("\n");
    }
    printf("Araba Kayit Islemi Basariyla Tamamlandi . \n\n"); // Islem Tamamlaniyor ve Ana Menuye Yonlendiriliyor .
    firma->arabaSayisi = arabaSayisi;                         // Arac Sayisini Tutuyor ve Dýger Arabalar Arasinda Gecmeyi Sagliyor .
    printf("Ana Menuye Yonlendiriliyorsunuz ... \n\n");
}

// 2. --> Arac Kayitlarini Listeleme Fonksiyonu .
void aracKaydiListele(struct Firma *firma, int n)
{
    int i;
    printf("____________________________________________________________ \n");
    printf("--          |       Firmanizdaki Arabalar      |          -- \n"); // Araclarin Kaydi Listeleniyor .
    printf("____________________________________________________________ \n");
    for (i = 0; i < (firma->arabaSayisi); i++)
    {
        printf("--| %d. Arac Bilgileri : \n", i + 1); // Arac Bilgileri Ekrana Yaziliyor .
        printf("________________________ \n");
        printf("--| Marka       : %s\n", firma->arabalar[i].marka);
        printf("--| Model       : %s\n", firma->arabalar[i].model);
        printf("--| Renk        : %s\n", firma->arabalar[i].renk);
        printf("--| Uretim Yili : %d\n", firma->arabalar[i].yil);
        printf("--| Fiyat       : %ld\n", firma->arabalar[i].fiyat);
        printf("________________________ \n");
        printf("\n");
    }
    printf("Firmanizdaki Arabalar Listelendi . \n"); // Islem Tamamlaniyor ve Ana Menuye Yonlendiriliyor .
    printf("Ana Menuye Yonlendiriliyorsunuz ... \n");
}

// 3. --> Arac Kayitlarini Silme Fonksiyonu .
void aracKaydiSil(struct Firma *firma, int arabaninNumarasi)
{
    int i;
    if (arabaninNumarasi < 1 || arabaninNumarasi > (firma->arabaSayisi)) // Silinecek Araba Numarasini Kontrol Ediliyor .
    {
        printf("\nGecersiz Araba Numarasi Girdiniz ! \n");
        printf("Ana Menuye Yonlendiriliyorsunuz ... \n\n");
        return;
    }

    for (i = arabaninNumarasi - 1; i < (firma->arabaSayisi - 1); i++) // Arac Silindiginde Bir Sonraki Arabayi Oncekine Kaydiriliyor .
    {                                                                 // Bu Sayede Arada Bosluklar Kalmiyor .
        firma->arabalar[i] = firma->arabalar[i + 1];
    }

    firma->arabaSayisi--; // Araba Sayisi 1 Azaltiliyor .
    printf("\nAraba Kaydi Basariyla Silindi . \n");
    printf("Ana Menuye Yonlendiriliyorsunuz ... \n"); // Islem Tamamlaniyor ve Ana Menuye Yonlendiriliyor .
}

// 4. --> Arac Kayitlarini Guncelleme Fonksiyonu .
void aracKaydiGuncelle(struct Firma *firma, int arabaninNumarasi)
{
    int guncellemeSecim;

    if (arabaninNumarasi < 1 || arabaninNumarasi > (firma->arabaSayisi)) // Guncellenecek Arabanin Numarasi Kontrol Ediliyor .
    {
        printf("Gecersiz Araba Numarasi Girdiniz! \n");
        printf("Ana Menuye Yonlendiriliyorsunuz ... \n\n");
        return;
    }

    do
    {
        printf("\nGuncellenecek Arac Bilgileri: \n"); // Secilen Numaraya Gore Arac Bilgileri Ekrana Getiriliyor .
        printf("Marka: %s\n", firma->arabalar[arabaninNumarasi - 1].marka);
        printf("Model: %s\n", firma->arabalar[arabaninNumarasi - 1].model);
        printf("Renk: %s\n", firma->arabalar[arabaninNumarasi - 1].renk);
        printf("Uretim Yili: %d\n", firma->arabalar[arabaninNumarasi - 1].yil);
        printf("Fiyat: %d\n", firma->arabalar[arabaninNumarasi - 1].fiyat);

        printf("\nHangi Ozelliklerini Guncellemek Istersiniz ? \n"); // Hangi Bilgilerin Guncellenecegi Soruluyor .
        printf("1 - Marka .\n");
        printf("2 - Model .\n");
        printf("3 - Renk .\n");
        printf("4 - Uretim Yili .\n");
        printf("5 - Fiyat .\n");
        printf("0 - Cikis .\n"); // Islemden Cikis Yapiliyor .
        printf("Secim Yapiniz: ");
        scanf("%d", &guncellemeSecim); // Guncelleme Secimi Giriliyor .

        switch (guncellemeSecim) // Switch Case ile Gerekli Yer Guncelleniyor .
        {
        case 1:
            printf("Yeni Marka : ");
            scanf("%s", firma->arabalar[arabaninNumarasi - 1].marka);
            break;
        case 2:
            printf("Yeni Model : ");
            scanf("%s", firma->arabalar[arabaninNumarasi - 1].model);
            break;
        case 3:
            printf("Yeni Renk : ");
            scanf("%s", firma->arabalar[arabaninNumarasi - 1].renk);
            break;
        case 4:
            printf("Yeni Uretim Yili : ");
            scanf("%d", &firma->arabalar[arabaninNumarasi - 1].yil);
            break;
        case 5:
            printf("Yeni Fiyat : ");
            scanf("%ld", &firma->arabalar[arabaninNumarasi - 1].fiyat);
            break;
        case 0:
            printf("Guncelleme Tamamlandi . \n");
            printf("Ana Menuye Yonlendiriliyorsunuz ... \n"); // Islem Tamamlaniyor ve Ana Menuye Yonlendiriliyor .
            break;
        default:
            printf("Gecersiz Secim ! \n");
            printf("Lutfen Belirtilen Secimlerden Birini Yapin ! \n");
            break;
        }
    } while (guncellemeSecim != 0);
    system("cls"); // Ekrani Temizlemek Icin Kullaniyoruz .
}

// 5. --> Fiyat Araligina Gore Araba Listeleme Fonksiyonu .
void aracFiyatAraligi(struct Firma *firma, int minFiyat, int maxFiyat)
{
    int i;
    int bulunanAraba = 0;

    printf("\nFiyat Araliginda Olan Arabalarin Listesi : \n");
    printf("-------------------------------------------- \n");

    for (i = 0; i < (firma->arabaSayisi); ++i)
    {
        if ((firma->arabalar[i].fiyat) >= minFiyat && (firma->arabalar[i].fiyat) <= maxFiyat) // Belirlenen Fiyat Araliginda Araba Var ise Ekrana Yazdiriliyor .
        {
            printf("%d. Araba Bilgileri : \n", i + 1);
            printf("------------------------- \n");
            printf("Araba Markasi : %s\n", firma->arabalar[i].marka);
            printf("Araba Modeli  : %s\n", firma->arabalar[i].model);
            printf("Araba Rengi   : %s\n", firma->arabalar[i].renk);
            printf("Araba Uretim Yili : %d\n", firma->arabalar[i].yil);
            printf("Araba Fiyati  : %ld\n", firma->arabalar[i].fiyat);
            printf("------------------------- \n");
            bulunanAraba++;
        }
    }

    if (bulunanAraba == 0) // Fiyat Araliginda Araba Yok ise Bu Kisma Geciliyor .
    {
        printf("\nBelirtilen Fiyat Araliginda Araba Bulunamadi . \n\n");
    }

    printf("Fiyat Araligindaki Arabalari Bulma Islemi Tamamlandi . \n"); // Islem Tamamlaniyor ve Ana Menuye Yonlendiriliyor .
    printf("Ana Menuye Yonlendiriliyorsunuz ... \n");
}

// 6. --> Ayni Marka Araba Bulma Fonksiyonu .
void arabaBulma(struct Firma *firma, char *arananMarka)
{
    int i;
    int ayniMarkaAraba = 0;

    printf("\n%s Marka Arabalarin Listesi : \n", arananMarka);
    printf("-------------------------------------- \n");

    for (i = 0; i < (firma->arabaSayisi); ++i)
    {
        if (strcmp(firma->arabalar[i].marka, arananMarka) == 0) // Ayni Marka Araba Var ise Listeleniyor .
        {
            printf("%d. Araba Bilgileri : \n", i + 1);
            printf("------------------------- \n");
            printf("Araba Markasi : %s\n", firma->arabalar[i].marka);
            printf("Araba Modeli  : %s\n", firma->arabalar[i].model);
            printf("Araba Rengi   : %s\n", firma->arabalar[i].renk);
            printf("Araba Uretim Yili : %d\n", firma->arabalar[i].yil);
            printf("Araba Fiyati  : %ld\n", firma->arabalar[i].fiyat);
            printf("------------------------- \n");
            ayniMarkaAraba++;
        }
    }
    if (ayniMarkaAraba == 0) // Ayni Marka Araba Yok ise Bilgilendirme Yapiliyor .
    {
        printf("\n%s Marka Araba Bulunamadi . \n", arananMarka);
    }
    printf("Araba Bulma Islemi Tamamlandi . \n"); // Islem Tamamlaniyor ve Ana Menuye Yonlendiriliyor .
    printf("Ana Menuye Yonlendiriliyorsunuz ... \n");
}
