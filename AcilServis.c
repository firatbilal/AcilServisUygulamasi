#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

// HL7 formatina uygun hasta bilgisi yapisi
typedef struct {
    char kimlik_no[12];   // 11 haneli hasta kimlik numarasi + null karakter
    char ad[50]; // Hasta adi
    int yas; // Hasta yasi
    char cinsiyet[10]; // Cinsiyet
    char hastalik_durumu[100]; // Hastalik durumu
    char oncelik[15]; // Oncelik seviyesi (yesil, sari, kirmizi)
    char recete_no[15]; // Recete numarasi
} Hasta;

Hasta kuyruk[MAX_PATIENTS];
int hasta_sayisi = 0;

// Recete numarasi olusturma fonksiyonu
void receteNoUret(char *no) {
    sprintf(no, "RX-%d", rand() % 10000);
}

// Yeni hasta kaydi ekleme
void hastaEkle() {
    if (hasta_sayisi >= MAX_PATIENTS) {
        printf("Hasta kapasitesi dolu!\n");
        return;
    }

    Hasta yeniHasta;
    printf("Hasta Kimlik No: ");
    scanf("%11s", yeniHasta.kimlik_no);
    getchar();
    printf("Hasta Adi: ");
    fgets(yeniHasta.ad, sizeof(yeniHasta.ad), stdin);
    yeniHasta.ad[strcspn(yeniHasta.ad, "\n")] = 0;
    printf("Yas: ");
    scanf("%d", &yeniHasta.yas);
    getchar();
    printf("Cinsiyet: ");
    fgets(yeniHasta.cinsiyet, sizeof(yeniHasta.cinsiyet), stdin);
    yeniHasta.cinsiyet[strcspn(yeniHasta.cinsiyet, "\n")] = 0;
    printf("Hastalik Durumu: ");
    fgets(yeniHasta.hastalik_durumu, sizeof(yeniHasta.hastalik_durumu), stdin);
    yeniHasta.hastalik_durumu[strcspn(yeniHasta.hastalik_durumu, "\n")] = 0;
    printf("Oncelik (yesil, sari, kirmizi): ");
    fgets(yeniHasta.oncelik, sizeof(yeniHasta.oncelik), stdin);
    yeniHasta.oncelik[strcspn(yeniHasta.oncelik, "\n")] = 0;
    
    receteNoUret(yeniHasta.recete_no);
    kuyruk[hasta_sayisi++] = yeniHasta;
    printf("Hasta basariyla kaydedildi! Recete No: %s\n", yeniHasta.recete_no);
}

// Hasta listesini oncelik sirasina gore gosterme
int oncelikSira(Hasta h1, Hasta h2) {
    // Öncelik sýrasýna göre sýralama yapalým
    // Kýrmýzý > Sarý > Yeþil
    if (strcmp(h1.oncelik, "kirmizi") == 0) return -1;
    if (strcmp(h2.oncelik, "kirmizi") == 0) return 1;
    if (strcmp(h1.oncelik, "sari") == 0) return -1;
    if (strcmp(h2.oncelik, "sari") == 0) return 1;
    return 0; // Yeþil öncelik ayný
}

void hastalariGoster() {
    if (hasta_sayisi == 0) {
        printf("Su anda kayitli hasta yok.\n");
        return;
    }
    // Önceliðe göre sýralama
    qsort(kuyruk, hasta_sayisi, sizeof(Hasta), (int (*)(const void *, const void *)) oncelikSira);

    printf("Kimlik No | Isim | Yas | Cinsiyet | Durum | Oncelik | Recete No\n");
    printf("------------------------------------------------------\n");
    
    // Döngü deðiþkenini dýþarýda tanýmladýk
    int i;
    for (i = 0; i < hasta_sayisi; i++) {
        printf("%s | %s | %d | %s | %s | %s | %s\n", kuyruk[i].kimlik_no, kuyruk[i].ad, kuyruk[i].yas, kuyruk[i].cinsiyet, kuyruk[i].hastalik_durumu, kuyruk[i].oncelik, kuyruk[i].recete_no);
    }
}

// Hasta cikisi
void hastaTaburcu() {
    if (hasta_sayisi == 0) {
        printf("Bekleyen hasta yok.\n");
        return;
    }
    printf("Hasta %s (%s) taburcu edildi.\n", kuyruk[0].ad, kuyruk[0].kimlik_no);
    int i;
    for (i = 0; i < hasta_sayisi - 1; i++) {
        kuyruk[i] = kuyruk[i + 1];
    }
    hasta_sayisi--;
}

int main() {
    int secim;
    while (1) {
        printf("\n1. Hasta Ekle\n2. Hasta Listesi\n3. Hasta Taburcu\n4. Cikis\nSeciminiz: ");
        scanf("%d", &secim);
        getchar();
        switch (secim) {
            case 1:
                hastaEkle();
                break;
            case 2:
                hastalariGoster();
                break;
            case 3:
                hastaTaburcu();
                break;
            case 4:
                printf("Sistemden cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}

