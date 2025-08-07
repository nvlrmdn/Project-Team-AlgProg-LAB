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
    if (fp == NULL) {
        return;
    }

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
    FILE *history = fopen("history.txt", "a");

    printf("\n Input Buku Baru \n");

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

    fprintf(history, "Buku: %s | Jenis: %s | Harga: %d\n",
            nama[jumlah], jenis[jumlah], harga[jumlah]);

    fclose(fp);
    fclose(history);

    jumlah++;
    printf("Buku Berhasil Ditambahkan\n");
}

void viewHistory() {
    FILE *history = fopen("history.txt", "r");

    printf("\n History Penjualan \n");

    if (history == NULL) {
        printf("Belum ada history penjualan.\n");
        return;
    }

    char line[256];
    int i = 1;
    while (fgets(line, sizeof(line), history)) {
        printf("%d. %s", i++, line);
    }

    fclose(history);
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