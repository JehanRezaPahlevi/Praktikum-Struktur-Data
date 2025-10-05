#include <iostream>
#include <string>
using namespace std;

int main() {
    const int HARI = 14; 
    string produk[HARI] = {
        "Apel", "Pisang", "Apel", "Jeruk", "Apel", "Pisang", "Mangga",
        "Jeruk", "Apel", "Pisang", "Mangga", "Apel", "Jeruk", "Pisang" };
    string target;
    int counter = 0;

    cout << "Masukkan nama produk yang ingin dihitung restocknya : ";
    cin >> target;

    cout << "\nHari-hari produk \"" << target << "\" dilakukan restock: ";
    bool restock = false;

    for (int i = 0; i < HARI; i++) {
        if (produk[i] == target) {
            counter++;
            restock = true;
            cout << "Hari-" << (i + 1) << " ";
        }
    }

    if (counter > 0) {
        cout << "\n\nProduk \"" << target << "\" restock sebanyak " << counter << " kali dalam 2 minggu." << endl;
    } else {
        cout << "\nProduk \"" << target << "\" tidak dilakukan restock sama sekali dalam 2 minggu." << endl;
    }

    return 0;
}