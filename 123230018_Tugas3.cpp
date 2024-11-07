#include <bits/stdc++.h>
#define MAX 30
using namespace std;


struct Buku {
    string namaBuku;
    string penulis;
    Buku* next;
};

Buku* top = NULL;
Buku* awal = NULL;
Buku* akhir = NULL;

int countBuku(); 

void buatStack() {
    top = NULL;
    awal = NULL;
    akhir = NULL;
}

bool StackKosong() {
    return top == NULL;
}

void pushBuku(string namaBuku, string penulis) {
    Buku* newBuku = new Buku();
    newBuku->namaBuku = namaBuku;
    newBuku->penulis = penulis;
    newBuku->next = NULL;

    if (StackKosong()) {
        awal = akhir = top = newBuku;
    } else {
        newBuku->next = awal;
        awal = newBuku;
        top = awal;
    }
    cout << "Buku berhasil ditambahkan.\n";
}

void popBuku() {
    if (StackKosong()) {
        cout << "Tidak Ada Buku Kawan!\n";
        return;
    }
    Buku* hapus = awal;
    awal = awal->next;
    top = awal;
    cout << "Data Buku yang Berhasil Diambil:\n Nama Buku: " << hapus->namaBuku 
         << "\n Nama Penulis: " << hapus->penulis << "\n";
    delete hapus;
}

void daftarBuku() {
    if (StackKosong()) {
        cout << "Stack Kosong\n";
    } else {
        cout << "+=========================+\n";
        cout << "|       Daftar Buku       |\n";
        cout << "+=========================+\n";
        Buku* temp = top;
        while (temp != NULL) {
            cout << "[" << temp->namaBuku << ", " << temp->penulis << "]\n";
            temp = temp->next;
        }
        cout << "Jumlah Buku: " << countBuku() << "\n";
    }
}

void hapusStack() {
    while (!StackKosong()) {
        popBuku();
    }
    cout << "[SEMUA BUKU TELAH DIHAPUS]\n";
}

void editBuku(string bukuLama) {
    Buku* temp = top;
    while (temp != NULL) {
        if (temp->namaBuku == bukuLama) {
            cout << "Edit Data Buku:\n";
            cout << "Judul Buku Lama: " << temp->namaBuku << "\n";
            cout << "Penulis Lama: " << temp->penulis << "\n";
            cout << "Judul Buku Baru: ";
            getline(cin, temp->namaBuku);
            cout << "Penulis Baru: ";
            getline(cin, temp->penulis);
            cout << "[DATA BUKU DIPERBARUI]\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Judul buku tidak ditemukan.\n";
}

int countBuku() {
    int count = 0;
    Buku* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice;
    string namaBuku, penulis;

    do {
        cout << "+=========================+\n";
        cout << "|       DAFTAR MENU       |\n";
        cout << "+=========================+\n";
        cout << "|1. Taruh Buku            |\n";
        cout << "|2. Ambil Buku            |\n";
        cout << "|3. Daftar Buku           |\n";
        cout << "|4. Buang Semua Buku      |\n";
        cout << "|5. Edit Data Buku        |\n";
        cout << "|6. Keluar                |\n";
        cout << "+=========================+\n";
        cout << "Pilih Menu: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int jumlah;
                cout << "Jumlah Buku yang akan dimasukkan: ";
                cin >> jumlah;
                cin.ignore();

                if (countBuku() + jumlah > MAX) { 
                    cout << "Error: Jumlah buku yang dimasukkan akan melebihi batas maksimal (" << MAX << ").\n";
                    break;
                }
                for (int i = 0; i < jumlah; i++) {
                    cout << "Judul Buku: ";
                    getline(cin, namaBuku);
                    cout << "Penulis: ";
                    getline(cin, penulis);
                    pushBuku(namaBuku, penulis);
                }
                break;
            }
            case 2: {
                popBuku();
                break;
            }
            case 3:
                daftarBuku();
                break;
            case 4:
                hapusStack();
                break;
            case 5: {
                cout << "Masukkan Judul Buku yang ingin diedit: ";
                getline(cin, namaBuku);
                editBuku(namaBuku);
                break;
            }
            case 6:
                cout << "Terima Kasih! Sampai Jumpa Lagi :)\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);
    return 0;
}