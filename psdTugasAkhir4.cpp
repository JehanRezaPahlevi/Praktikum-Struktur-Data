#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100;
string antrian[MAXN];
int frontIdx = -1, rearIdx = -1;

bool isEmpty() {
    return frontIdx == -1;
}

bool isFull() {
    return (rearIdx + 1) % MAXN == frontIdx;
}

void tambahPasien(string nama) {
    if (isFull()) {
        cout << "Antrian penuh! Mohon menunggu pasien lain selesai.\n";
        return;
    }
    if (isEmpty()) {
        frontIdx = rearIdx = 0;
    } else {
        rearIdx = (rearIdx + 1) % MAXN;
    }
    antrian[rearIdx] = nama;
    cout << "Pasien " << nama << " berhasil ditambahkan ke antrian.\n";
}

void layaniPasien() {
    if (isEmpty()) {
        cout << "Tidak ada pasien dalam antrian.\n";
        return;
    }
    cout << "Pasien " << antrian[frontIdx] << " sedang dilayani...\n";
    if (frontIdx == rearIdx) {
        frontIdx = rearIdx = -1;
    } else {
        frontIdx = (frontIdx + 1) % MAXN;
    }
}

void pasienBerikutnya() {
    if (isEmpty()) {
        cout << "Belum ada pasien dalam antrian.\n";
        return;
    }
    cout << "Pasien berikutnya: " << antrian[frontIdx] << '\n';
}

void tampilkanAntrian() {
    if (isEmpty()) {
        cout << "Belum ada pasien dalam antrian.\n";
        return;
    }
    cout << "\nDaftar pasien dalam antrian (dari depan ke belakang):\n";
    int i = frontIdx;
    int nomor = 1;
    while (true) {
        cout << nomor++ << ". " << antrian[i] << '\n';
        if (i == rearIdx) break;
        i = (i + 1) % MAXN;
    }
}

int main() {
    int pilih;
    string nama;

    do {
        cout << "\n=== SISTEM ANTRIAN PASIEN RUMAH SAKIT ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Layani Pasien\n";
        cout << "3. Lihat Pasien Berikutnya\n";
        cout << "4. Tampilkan Semua Pasien\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore(); 

        switch (pilih) {
            case 1:
                cout << "Nama pasien: ";
                getline(cin, nama);
                tambahPasien(nama);
                break;
            case 2:
                layaniPasien();
                break;
            case 3:
                pasienBerikutnya();
                break;
            case 4:
                tampilkanAntrian();
                break;
            case 5:
                cout << "Sistem antrian ditutup.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 5);

    return 0;
}
