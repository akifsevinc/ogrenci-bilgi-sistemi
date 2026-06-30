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
    int silinenno = 0;
    struct Ogrenci sinif[100];
    int kayitliogrenci = 0;

    while (menusecim != 4){
printf("Öğrenci bilgi sistemine hoş geldiniz! Lütfen yapmak istediğiniz işlemi seçiniz.\n");
printf("1. Yeni öğrenci ekle\n");
printf("2. Tüm öğrencileri listele\n");
printf("3. Öğrenci silme\n");
printf("4. Çıkış yap\n");
if (scanf("%d", &menusecim) != 1) {
    printf("Lütfen geçerli bir menü numarası giriniz!\n");
    while (getchar() != '\n');
    menusecim = 0;
    continue;}

if (menusecim == 1){

    if (kayitliogrenci == 100){
        printf("Öğrenci limiti doldu!");
        continue;
    }
    else{
    printf("Öğrenci numarası giriniz:");
    if (scanf("%d", &sinif[kayitliogrenci].ogrencino) != 1) {
    printf("Lütfen geçerli bir öğrenci numarası giriniz!\n");
    while (getchar() != '\n');
    sinif[kayitliogrenci].ogrencino = 0;
    continue;}
    printf("Öğrenci ilk adını giriniz:\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(sinif[kayitliogrenci].ilkad, 20, stdin);
    printf("Öğrenci soy adını giriniz:\n");
    scanf("%s", sinif[kayitliogrenci].soyad);
    kayitliogrenci = kayitliogrenci + 1;
    printf("Öğrenci başarıyla kaydedildi!\n");
    continue;}
}
else if (menusecim == 2){
    if (kayitliogrenci == 0){
        printf("Henüz bir öğrenci kaydedilmedi!");
        continue;
    }
    for (int i = 0; i < kayitliogrenci; i++) {
        printf("----------------------------------------------\n");
        printf("Öğrenci no: %d\n", sinif[i].ogrencino);
        printf("Öğrenci adı: %s\n", sinif[i].ilkad);
        printf("Öğrenci soy ad: %s\n", sinif[i].soyad);
        printf("----------------------------------------------\n");

    }
    continue;
}

else if (menusecim == 3){
    if (kayitliogrenci == 0){
        printf("Daha hiçbir öğrenci kaydedilmedi!");
        continue;
    }
    printf("Silmek istediğiniz öğrencinin numarasını yazınız:");
if (scanf("%d", &silinenno) != 1) {
    printf("Lütfen geçerli bir öğrenci numarası giriniz!\n");
    while (getchar() != '\n');
    silinenno = 0;
    continue;
}   
    for (int f = 0;  f < kayitliogrenci; f++){
        if (silinenno == sinif[f].ogrencino){
            for (int c = f; c < kayitliogrenci - 1; c++){
                sinif[c] = sinif[c + 1];
            }
                kayitliogrenci--;
                printf("Silme basarili!\n");
                break;
        }
    }

}

else if (menusecim == 4){
    printf("Programdan çıkılıyor!\n");
    return 0;
}

else {
    printf("Geçerisiz girdi!");
    continue;
}

    }
}
