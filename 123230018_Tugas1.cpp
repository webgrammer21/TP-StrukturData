#include <iostream>
#include <string>

using namespace std;

struct Pegawai {
    string nPegawai;
    int gaji;
    Pegawai* next;
};

Pegawai* buatNode(string nPegawai, int gaji) {
    Pegawai* newNode = new Pegawai;
    newNode->nPegawai = nPegawai;
    newNode->gaji = gaji;
    newNode->next = nullptr;
    return newNode;
}

void sisipDepan(Pegawai*& head, string nPegawai, int gaji) {
    Pegawai* newNode = buatNode(nPegawai, gaji);
    newNode->next = head;
    head = newNode;
}

void sisipTengah(Pegawai*& head, string nPegawai, int gaji) {
    if (head == nullptr) {
        sisipDepan(head, nPegawai, gaji);
        return;
    }
    Pegawai* temp = head;
    while (temp->next != nullptr && temp->next->gaji > gaji) {
        temp = temp->next;
    }
    Pegawai* newNode = buatNode(nPegawai, gaji);
    newNode->next = temp->next;
    temp->next = newNode;
}

void sisipBelakang(Pegawai*& head, string nPegawai, int gaji) {
    if (head == nullptr) {
        sisipDepan(head, nPegawai, gaji);
        return;
    }
    Pegawai* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Pegawai* newNode = buatNode(nPegawai, gaji);
    temp->next = newNode;
}

void hapusData(Pegawai*& head, string nPegawai) {
    if (head == nullptr) {
        cout << "Data kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    if (head->nPegawai == nPegawai) {
        Pegawai* temp = head;
        head = head->next;
        delete temp;
        cout << "Pegawai dengan nama " << nPegawai << " telah dihapus." << endl;
        return;
    }

    Pegawai* temp = head;
    while (temp->next != nullptr && temp->next->nPegawai != nPegawai) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Pegawai* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "Pegawai dengan nama " << nPegawai << " telah dihapus." << endl;
    } else {
        cout << "Nama yang anda masukkan tidak ada dalam data yang dimasukkan." << endl;
        cout << "=============================================================" << endl;
    }
}

void tampilkanData(Pegawai* head) {
    if (head == nullptr) {
        cout << "Tidak ada data pegawai." << endl;
        return;
    }
    Pegawai* temp = head;
    while (temp != nullptr) {
        cout << "Nama pegawai: " << temp->nPegawai << endl;
        cout << "Gaji pegawai: Rp. " << temp->gaji << endl;
        cout << "===============================" << endl;
        temp = temp->next;
    }
}

int main() {
    Pegawai* head = nullptr;
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
                cin.ignore();

                cout << "=============================" << endl;

                cout << "+==========================+" << endl;                
                cout << "|        TAMBAH DATA       |" << endl;
                cout << "+==========================+" << endl; 
                cout << "|1. SISIP DEPAN            |" << endl;
                cout << "|2. SISIP TENGAH           |" << endl;
                cout << "|3. SISIP BELAKANG         |" << endl;
                cout << "+==========================+" << endl; 
                cout << "Masukkan pilihan anda (1-3): ";
                int sisipPilihan;
                cin >> sisipPilihan;

                switch (sisipPilihan) {
                    case 1:
                        sisipDepan(head, nama, gaji);
                        break;
                    case 2:
                        sisipTengah(head, nama, gaji);
                        break;
                    case 3:
                        sisipBelakang(head, nama, gaji);
                        break;
                    default:
                        cout << "Pilihan sisip tidak valid." << endl;
                }

                cout << "Data berhasil disimpan." << endl;
                break;
            }
            case 2: {
                cout << "+==========================+" << endl; 
                cout << "|        HAPUS DATA        |" << endl;
                cout << "+==========================+" << endl; 
                cout << "Masukkan nama pegawai yang akan dihapus: ";
                string nama;
                cin.ignore();
                getline(cin, nama);

                hapusData(head, nama);
                break;
            }
            case 3:
                cout << "+==========================+" << endl; 
                cout << "|      TAMPILAN DATA       |" << endl;
                cout << "+==========================+" << endl; 
                tampilkanData(head);
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
        cout << "Kembali ke menu ? (y/n) : ";
        cin >> back;
        cout << endl;

    } while (back == 'y' || back == 'Y');

    return 0;
}
