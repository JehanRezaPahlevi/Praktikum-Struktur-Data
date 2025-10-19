#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    long long nim;  
    string nama;
    Mahasiswa* left;
    Mahasiswa* right;

    Mahasiswa(long long n, string nm) : nim(n), nama(nm), left(nullptr), right(nullptr) {}
};

Mahasiswa* insertMahasiswa(Mahasiswa* root, long long nim, string nama) {
    if (!root) return new Mahasiswa(nim, nama);
    if (nim < root->nim)
        root->left = insertMahasiswa(root->left, nim, nama);
    else if (nim > root->nim)
        root->right = insertMahasiswa(root->right, nim, nama);
    return root;
}

Mahasiswa* searchMahasiswa(Mahasiswa* root, long long nim) {
    if (!root || root->nim == nim)
        return root;
    if (nim < root->nim)
        return searchMahasiswa(root->left, nim);
    return searchMahasiswa(root->right, nim);
}

void inorder(Mahasiswa* root) {
    if (!root) return;
    inorder(root->left);
    cout << "NIM: " << root->nim << " | Nama: " << root->nama << endl;
    inorder(root->right);
}

long long findMin(Mahasiswa* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->nim;
}

long long findMax(Mahasiswa* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->nim;
}

int countMahasiswa(Mahasiswa* root) {
    if (!root) return 0;
    return 1 + countMahasiswa(root->left) + countMahasiswa(root->right);
}

int main() {
    Mahasiswa* root = nullptr;
    int pilihan;
    long long nim;
    string nama;

    do {
        cout << "\n=== SISTEM DATA MAHASISWA (BST) ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Tampilkan Semua Data (Inorder)\n";
        cout << "4. NIM Terkecil\n";
        cout << "5. NIM Terbesar\n";
        cout << "6. Total Mahasiswa\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan NIM  : "; cin >> nim;
            cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama);
            root = insertMahasiswa(root, nim, nama);
            cout << "Data berhasil ditambahkan!\n";
            break;
        case 2:
            cout << "Masukkan NIM yang dicari: "; cin >> nim;
            {
                Mahasiswa* mhs = searchMahasiswa(root, nim);
                if (mhs)
                    cout << "Ditemukan! Nama: " << mhs->nama << endl;
                else
                    cout << "Data tidak ditemukan!\n";
            }
            break;
        case 3:
            cout << "\nData Mahasiswa (urut berdasarkan NIM):\n";
            inorder(root);
            break;
        case 4:
            cout << "NIM terkecil: " << findMin(root) << endl;
            break;
        case 5:
            cout << "NIM terbesar: " << findMax(root) << endl;
            break;
        case 6:
            cout << "Total Mahasiswa: " << countMahasiswa(root) << endl;
            break;
        }
    } while (pilihan != 7);

    cout << "Terima kasih!\n";
    return 0;
}