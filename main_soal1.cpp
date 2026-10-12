#include <iostream>
#include "soal1.h"
using namespace std;

int main() {
    mahasiswa data[MAKS];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAKS << ") : ";
        cin >> n;
    } while (n < 1 || n > MAKS);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMhs(data[i]);
    }

    cout << "\n===== DATA MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        tampilMhs(data[i]);
    }
    return 0;
}