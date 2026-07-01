#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    int ogrencino;
    char ilkad[20];
    char soyad[20];
    int vizenot;
    int finalnot;
    float ortalama;
    };

int main(){
    int menusecim = 0;
    int silinenno = 0;
    struct Ogrenci sinif[100];
    int kayitliogrenci = 0;

    FILE *fpointer = fopen("liste.txt", "r");

    if (fpointer == NULL) {
        printf("Hata: Dosya bulunamadı!\n");
    }
    else{
    while (kayitliogrenci < 100 && fscanf(fpointer, "%d", &sinif[kayitliogrenci].ogrencino) != EOF) {
        fscanf(fpointer, "%19s", sinif[kayitliogrenci].ilkad);
        fscanf(fpointer, "%19s", sinif[kayitliogrenci].soyad);
        fscanf(fpointer, "%d", &sinif[kayitliogrenci].vizenot);
        fscanf(fpointer, "%d", &sinif[kayitliogrenci].finalnot);
        kayitliogrenci++;

    }
        fclose(fpointer);}



    while (menusecim != 5){
printf("Öğrenci bilgi sistemine hoş geldiniz! Lütfen yapmak istediğiniz işlemi seçiniz.\n");
printf("1. Yeni öğrenci ekle\n");
printf("2. Tüm öğrencileri listele\n");
printf("3. Öğrenci silme\n");
printf("4. Verileri kaydet\n");
printf("5. Çıkış yap\n");
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
    int cift_kayit = 0;
    for (int n = 0;  n < kayitliogrenci; n++){
        if (sinif[kayitliogrenci].ogrencino == sinif[n].ogrencino){
            printf("Bu numara zaten kayıtlı!\n");
            cift_kayit++;
            while (getchar() != '\n');
            sinif[kayitliogrenci].ogrencino = 0;
            break;
        }
}

if(cift_kayit > 0){
    continue;
}

    printf("Öğrenci ilk adını giriniz:\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(sinif[kayitliogrenci].ilkad, 20, stdin);
    printf("Öğrenci soy adını giriniz:\n");
    fgets(sinif[kayitliogrenci].soyad, 20, stdin);
    printf("Öğrencinin vize notunu giriniz:");
    if (scanf("%d", &sinif[kayitliogrenci].vizenot) != 1) {
    printf("Geçersiz not!\n");
    while (getchar() != '\n');
    continue;
}
    printf("Öğrencinin final notunu giriniz:");
    if (scanf("%d", &sinif[kayitliogrenci].finalnot) != 1) {
    printf("Geçersiz not!\n");
    while (getchar() != '\n');
    continue;
}
    kayitliogrenci = kayitliogrenci + 1;
    printf("Öğrenci başarıyla kaydedildi!\n");
    continue;
}
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
        printf("Öğrenci vize not: %d\n", sinif[i].vizenot);
        printf("Öğrenci final not: %d\n", sinif[i].finalnot);
        printf("Öğrenci ortalama not: %.2f\n", (sinif[i].finalnot * 0.4) + (sinif[i].vizenot * 0.6));
        printf("----------------------------------------------\n");

    }
    continue;
}

else if (menusecim == 3){
    if (kayitliogrenci == 0){
        printf("Daha hiçbir öğrenci kaydedilmedi!\n");
        continue;
    }
    printf("Silmek istediğiniz öğrencinin numarasını yazınız:");
if (scanf("%d", &silinenno) != 1) {
    printf("Lütfen geçerli bir öğrenci numarası giriniz!\n");
    while (getchar() != '\n');
    silinenno = 0;
    continue;
}   
    int bulundu = 0;
    for (int f = 0;  f < kayitliogrenci; f++){
        if (silinenno == sinif[f].ogrencino){
            for (int c = f; c < kayitliogrenci - 1; c++){
                sinif[c] = sinif[c + 1];
            }
                kayitliogrenci--;
                bulundu++;
                printf("Silme basarili!\n");
                break;
        }

    }
        if (bulundu == 0){
        printf("Öğrenci numarası bulunamadı!\n");
        continue;
        }

}

    else if(menusecim == 4){
        FILE *fpointer = fopen("liste.txt", "w");

    if (fpointer == NULL) {
        printf("Hata: Dosya açılamadı!\n");
        return 1;
    }
    else{
        for(int h = 0; h < kayitliogrenci; h++){
        fprintf(fpointer, "%d\n", sinif[h].ogrencino);
        fprintf(fpointer, "%s\n", sinif[h].ilkad);
        fprintf(fpointer, "%s\n", sinif[h].soyad);
        fprintf(fpointer, "%d\n", sinif[h].vizenot);
        fprintf(fpointer, "%d\n", sinif[h].finalnot);
        }
    }
    fclose(fpointer);
    printf("Dosya başarıyla yazıldı.\n");
    continue;
    }


else if (menusecim == 5){
    printf("Programdan çıkılıyor!\n");
        FILE *fpointer = fopen("liste.txt", "w");

    if (fpointer == NULL) {
        printf("Hata: Dosya açılamadı!\n");
        return 1;
    }
    else{
        for(int h = 0; h < kayitliogrenci; h++){
        fprintf(fpointer, "%d\n", sinif[h].ogrencino);
        fprintf(fpointer, "%s\n", sinif[h].ilkad);
        fprintf(fpointer, "%s\n", sinif[h].soyad);
        fprintf(fpointer, "%d\n", sinif[h].vizenot);
        fprintf(fpointer, "%d\n", sinif[h].finalnot);
        }
    fclose(fpointer);
    return 0;
}
}

else {
    printf("Geçerisiz girdi!");
    continue;
}

    }
}
