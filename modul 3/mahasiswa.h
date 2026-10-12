#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    int nim;
    float nilai;
    float nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif