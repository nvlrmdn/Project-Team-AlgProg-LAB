#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char kode[100][10];
char nama[100][50];
char jenis[100][30];
int harga[100];
int jumlah = 0;

void loadData() {
    FILE *fp = fopen("databuku.txt", "r");

    while (fscanf(fp, "%[^,],%[^,],%[^,],%d\n",
                  kode[jumlah],
                  nama[jumlah],
                  jenis[jumlah],
                  &harga[jumlah]) != EOF) {
        jumlah++;
    }

    fclose(fp);
}

void viewBuku() {
    printf("\n Daftar Buku \n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. Kode: %s | Nama: %s | Jenis: %s | Harga: %d\n",
               i + 1, kode[i], nama[i], jenis[i], harga[i]);
    }
}

void inputBuku() {
    FILE *fp = fopen("databuku.txt", "a");

    printf("Masukkan Kode Buku: ");
    scanf("%s", kode[jumlah]);
    printf("Masukkan Nama Buku: ");
    scanf(" %[^\n]", nama[jumlah]);
    printf("Masukkan Jenis Buku: ");
    scanf(" %[^\n]", jenis[jumlah]);
    printf("Masukkan Harga Buku: ");
    scanf("%d", &harga[jumlah]);

    fprintf(fp, "%s,%s,%s,%d\n",
            kode[jumlah], nama[jumlah], jenis[jumlah], harga[jumlah]);

    fclose(fp);

    jumlah++;
    printf("Buku Berhasil Ditambahkan\n");
}

void viewHistory() {
    printf("\n History Penjualan \n");
    if (jumlah == 0) {
        printf("Belum ada Buku.\n");
    } else {
        for (int i = 0; i < jumlah; i++) {
            printf("%d. Buku: %s | Jenis: %s | Harga: %d\n",
                   i + 1, nama[i], jenis[i], harga[i]);
        }
    }
}

int main() {
    int pilihan;

    loadData();

    while (1) {
        printf("\n MENU \n");
        printf("1. Input Buku\n");
        printf("2. View History\n");
        printf("3. View Buku\n");
        printf("4. Keluar\n");
        printf("Pilih (1/2/3/4): ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            inputBuku();
        } else if (pilihan == 2) {
            viewHistory();
        } else if (pilihan == 3) {
            viewBuku();
        } else if (pilihan == 4) {
            break;
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}