#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

struct Ogrenci {
    int ogrencino;
    char ilkad[20];
    char soyad[20];
    };

int main(){
    int menusecim = 0;
    struct Ogrenci sinif[100];
    int kayitliogrenci = 0;

    while (menusecim != 3){
printf("Öğrenci bilgi sistemine hoş geldiniz! Lütfen yapmak istediğiniz işlemi seçiniz.\n");
printf("1. Yeni öğrenci ekle\n");
printf("2. Tüm öğrencileri listele\n");
printf("3. Çıkış yap\n");
if (scanf("%d", &menusecim) != 1) {
    printf("Lütfen geçerli bir menü numarası giriniz!\n");
    while (getchar() != '\n');
    menusecim = 0;
    continue;}

if (menusecim == 1){
    printf("Öğrenci numarası giriniz:");
    scanf("%d", &sinif[kayitliogrenci].ogrencino);
    printf("Öğrenci ilk adını giriniz:");
    scanf("%s", sinif[kayitliogrenci].ilkad);
    printf("Öğrenci soy adını giriniz:");
    scanf("%s", sinif[kayitliogrenci].soyad);
    kayitliogrenci = kayitliogrenci + 1;
    printf("Öğrenci başarıyla kaydedildi!\n");
    continue;
}
else if (menusecim == 2){
    if (kayitliogrenci == 0){
        printf("Henüz bir öğrenci kaydedilmedi!");
        continue;
    }
    for (int i = 0; i < kayitliogrenci; i++) {
        printf("Öğrenci no: %d\n", sinif[i].ogrencino);
        printf("Öğrenci adı: %s\n", sinif[i].ilkad);
        printf("Öğrenci soy ad: %s\n", sinif[i].soyad);

    }
    continue;
}
else if (menusecim == 3){
    printf("Programdan çıkılıyor!\n");
    return 0;
}

else {
    printf("Geçerisiz girdi!");
    continue;
}

    }
}
