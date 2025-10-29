#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Barang {
    int kode;
    string nama;
    int stok;
    Barang* next;
};

void initTable(Barang* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

int hashFunction(int kode) {
    return kode % SIZE;
}

void tambahBarang(Barang* table[], int kode, string nama, int stok) {
    int index = hashFunction(kode);
    Barang* cur = table[index];
    while (cur != nullptr) {
        if (cur->kode == kode) {
            cur->stok += stok;
            cout << "Stok barang dengan kode " << kode << " telah diperbarui!\n";
            return;
        }
        cur = cur->next;
    }
    Barang* baru = new Barang;
    baru->kode = kode;
    baru->nama = nama;
    baru->stok = stok;
    baru->next = table[index];
    table[index] = baru;
    cout << "Barang berhasil ditambahkan!\n";
}

void hapusBarang(Barang* table[], int kode) {
    int index = hashFunction(kode);
    Barang* cur = table[index];
    Barang* prev = nullptr;
    while (cur != nullptr) {
        if (cur->kode == kode) {
            if (prev == nullptr)
                table[index] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
            cout << "Barang dengan kode " << kode << " telah dihapus.\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Barang dengan kode " << kode << " tidak ditemukan.\n";
}

void cariBarang(Barang* table[], int kode) {
    int index = hashFunction(kode);
    Barang* cur = table[index];
    while (cur != nullptr) {
        if (cur->kode == kode) {
            cout << "\nBarang ditemukan!\n";
            cout << "Kode  : " << cur->kode << endl;
            cout << "Nama  : " << cur->nama << endl;
            cout << "Stok  : " << cur->stok << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Barang dengan kode " << kode << " tidak ditemukan.\n";
}

void tampilkanBarang(Barang* table[]) {
    cout << "\n=== Daftar Barang di Toko ===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "] ";
        Barang* tmp = table[i];
        if (tmp == nullptr) {
            cout << "Kosong\n";
            continue;
        }
        while (tmp != nullptr) {
            cout << "(" << tmp->kode << " | " << tmp->nama << " | Stok: " << tmp->stok << ") -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Barang* table[SIZE];
    initTable(table);
    int pilihan;
    do {
        cout << "\n=== MENU MANAJEMEN TOKO ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Cari Barang\n";
        cout << "4. Tampilkan Semua Barang\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        if (pilihan == 1) {
            int kode, stok;
            string nama;
            cout << "Masukkan kode barang : ";
            cin >> kode;
            cout << "Masukkan nama barang : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan jumlah stok : ";
            cin >> stok;
            tambahBarang(table, kode, nama, stok);
        } else if (pilihan == 2) {
            int kode;
            cout << "Masukkan kode barang yang akan dihapus: ";
            cin >> kode;
            hapusBarang(table, kode);
        } else if (pilihan == 3) {
            int kode;
            cout << "Masukkan kode barang yang dicari: ";
            cin >> kode;
            cariBarang(table, kode);
        } else if (pilihan == 4) {
            tampilkanBarang(table);
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan sistem Manajemen Toko!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    return 0;
}
