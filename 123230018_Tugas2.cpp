#include <iostream>
#include <string>

using namespace std;

struct Pegawai {
    string nPegawai;
    int gaji;
};

struct node {
    Pegawai pgw;
    node* next;
};

node* awal = NULL;
node* akhir = NULL;

bool listKosong() {
    return (awal == NULL);
}

void sisipnode(Pegawai pgw) {
    node* nb = new node();
    nb->pgw = pgw;
    nb->next = NULL;

    if (listKosong()) {
        awal = nb;
        akhir = nb;
    } else if (pgw.gaji < awal->pgw.gaji) {
        nb->next = awal;
        awal = nb;
    } else {
        node* bantu = awal;
        while (bantu->next != NULL && pgw.gaji >= bantu->next->pgw.gaji) {
            bantu = bantu->next;
        }
        nb->next = bantu->next;
        bantu->next = nb;

        if (nb->next == NULL) {
            akhir = nb;
        }
    }
}

void hapusnode(string nama) {
    if (listKosong()) {
        cout << "Tidak ada data." << endl;
        return;
    }

    node* bantu = awal;
    node* hapus = NULL;

    if (awal->pgw.nPegawai == nama) {
        hapus = awal;
        awal = awal->next;
        delete hapus;
        return;
    }

    while (bantu->next != NULL && bantu->next->pgw.nPegawai != nama) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "Node dengan nama " << nama << " tidak ditemukan." << endl;
        return;
    }

    hapus = bantu->next;
    bantu->next = hapus->next;

    if (hapus == akhir) {
        akhir = bantu;
    }

    delete hapus;
}

void tampilkanData() {
    if (listKosong()) {
        cout << "Tidak ada data pegawai." << endl;
        return;
    }

    node* temp = awal;
    while (temp != NULL) {
        cout << "Nama pegawai: " << temp->pgw.nPegawai << endl;
        cout << "Gaji pegawai: Rp. " << temp->pgw.gaji << endl;
        cout << "===============================" << endl;
        temp = temp->next;
    }
}

int main() {
    char back;

    do {
        cout << "+==========================+" << endl;        
        cout << "|        MENU UTAMA        |" << endl;
        cout << "+==========================+" << endl; 
        cout << "|1. TAMBAH DATA            |" << endl;
        cout << "|2. HAPUS DATA             |" << endl;
        cout << "|3. TAMPILAN DATA          |" << endl;
        cout << "|4. EXIT                   |" << endl;
        cout << "+==========================+" << endl; 
        cout << "Masukkan pilihan anda (1-4): ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "Masukkan nama pegawai: ";
                string nama;
                cin.ignore();
                getline(cin, nama);

                cout << "Masukkan gaji pegawai: Rp. ";
                int gaji;
                cin >> gaji;

                Pegawai pgw = {nama, gaji};
                sisipnode(pgw);
                cout << "Data berhasil disimpan." << endl;
                break;
            }
            case 2: {
                cout << "Masukkan nama pegawai yang akan dihapus: ";
                string nama;
                cin.ignore();
                getline(cin, nama);

                hapusnode(nama);
                break;
            }
            case 3:
                tampilkanData();
                break;
            case 4:
                cout << "=============================" << endl;
                cout << "|       Terima kasih!       |" << endl;
                cout << "|Untuk Anda Yang Selalu Ada!|" << endl;
                cout << "=============================" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << endl;
        cout << "Kembali ke menu? (y/n): ";
        cin >> back;
        cout << endl;

    } while (back == 'y' || back == 'Y');

    return 0;
}
