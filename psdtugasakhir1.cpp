#include <iostream>
using namespace std;

int main() {
    string kodeAwal = "08140625";        
    string koleksiSim[100];   

    for (int i = 0; i < 100; i++) {
        int nomorBelakang = i + 1;
        string digitEmpat = "";

        if (nomorBelakang < 10) 
            digitEmpat = "000" + to_string(nomorBelakang);   
        else if (nomorBelakang < 100) 
            digitEmpat = "00" + to_string(nomorBelakang);   
        else if (nomorBelakang < 1000) 
            digitEmpat = "0" + to_string(nomorBelakang);   
        else 
            digitEmpat = to_string(nomorBelakang);      

        koleksiSim[i] = kodeAwal + digitEmpat;
    }

   for (int i = 0; i < 100; i++) {
    cout << koleksiSim[i] << "\t";   
    if ((i + 1) % 10 == 0) {       
        cout << endl;
    }
}

    return 0;
}
