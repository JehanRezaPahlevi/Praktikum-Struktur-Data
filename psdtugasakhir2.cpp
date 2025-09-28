#include <iostream>
using namespace std;

void tukarString(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    string buku[100];

    cout << "Masukkan jumlah buku: ";
    cin >> n;
    cin.ignore();

    cout << "Masukkan judul buku:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, buku[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (buku[j] > buku[j + 1]) {
                tukarString(buku[j], buku[j + 1]);
            }
        }
    }

    cout << "\nDaftar Buku Setelah Diurutkan (A - Z)" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << buku[i] << endl;
    }

    return 0;
}