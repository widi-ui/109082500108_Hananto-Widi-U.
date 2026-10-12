#include <iostream>
#include "soal1.h"
using namespace std;

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void inputMhs(mahasiswa &m) {
    cout << "Nama   : ";
    cin.ignore();
    getline(cin, m.nama);
    cout << "NIM    : ";
    cin >> m.nim;
    cout << "UTS    : ";
    cin >> m.uts;
    cout << "UAS    : ";
    cin >> m.uas;
    cout << "Tugas  : ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

void tampilMhs(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}
