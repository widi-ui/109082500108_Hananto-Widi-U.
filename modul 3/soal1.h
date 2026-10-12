#ifndef SOAL1_H_INCLUDED
#define SOAL1_H_INCLUDED

#include <string>
using namespace std;

const int MAKS = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(mahasiswa m);

void inputMhs(mahasiswa &m);

void tampilMhs(mahasiswa m);

#endif 