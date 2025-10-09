#include <iostream>#include <iostream>
#include <string>
using namespace std;

int main() {
    const int HARI = 14; 
    string produk[HARI] = {
        "Apel", "Pisang", "Leci", "Jeruk", "Anggur", "Kelengkeng", "Mangga",
        "Jeruk", "Melon", "Pisang", "Mangga", "Apel", "Jeruk", "Anggur" };
    string target;
    int counter = 0;

    cout << "Daftar Produk Buah Segar : " << endl;
    cout << "Apel      " "\t" "Pisang    " "\t" "Leci          " "\t" "Jeruk     " << endl;
    cout << "Anggur    \t" "Kelengkeng\t" "Mangga    \t" "Melon     \t" << endl;
    cout << "Masukkan nama produk yang ingin dihitung restocknya : ";
    cin >> target;

    cout << "Produk " << target << " Selalu direstock pada ";
    bool restock = false;

    for (int i = 0; i < HARI; i++) {
        if (produk[i] == target) {
            counter++;
            restock = true;
            cout << "hari ke-" << (i + 1) << " ";
        }
    }

    if (counter > 0) {
        cout << "\nProduk \"" << target << "\" restock sebanyak " << counter << " kali dalam 2 minggu." << endl;
    } else {
        cout << "\nProduk \"" << target << "\" tidak dilakukan restock sama sekali dalam 2 minggu." << endl;
    }

    return 0;
}
}
