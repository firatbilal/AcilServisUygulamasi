# Acil Servis Uygulamasi

Bu proje, HL7 formatına uygun hasta bilgilerini kaydeden, listeleyen ve hasta taburcu işlemleri gerçekleştiren bir C programıdır. Program, hasta bilgilerini bağlı liste veri yapısında saklar ve hastaların öncelik sırasına göre sıralanmasını sağlar.

## İçindekiler
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Fonksiyonlar](#fonksiyonlar)
- [Katkıda Bulunanlar](#katkıda-bulunanlar)

## Kurulum

1. Bu repoyu klonlayın:
    ```bash
    git clone https://github.com/AcilServisUygulamasi/AcilServis.git
    ```
2. Derleyici ile kodu derleyin:
    ```bash
    gcc -o AcilServis AcilServis.c
    ```

## Kullanım

1. Programı çalıştırın:
    ```bash
    ./AcilServis
    ```
2. Varsayılan olarak hasta kaydı ekleyebilir, listeleyebilir ve hasta taburcu edebilirsiniz. Aşağıdaki seçenekler ile işlemleri gerçekleştirebilirsiniz:

    **`1`**: Yeni hasta kaydı ekler.
    **`2`**: Mevcuthasta listesini öncelik sırasına göre gösterir.
    **`3`**: İlk sıradaki hastayı taburcu eder.
    **`4`**: Programdan çıkış yapar.

## Fonksiyonlar

- **`receteNoUret`**: Yeni bir reçete numarası oluşturur.
- **`hastaEkle`**: Yeni bir hasta kaydı ekler.
- **`oncelikSira`**: Hastaları öncelik sırasına göre sıralar (Kırmızı > Sarı > Yeşil).
- **`hastalariGoster`**: Hasta listesini öncelik sırasına göre ekrana yazdırır.
- **`hastaTaburcu`**: İlk sıradaki hastayı taburcu eder.

## Katkıda Bulunanlar

- [firatbilal](https://github.com/firatbilal)
