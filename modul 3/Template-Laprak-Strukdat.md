# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Hananto Widi Utomo - 109082500108 </p>

## Dasar Teori

### A. Abstract Data Type (ADT)<br/>
ADT dan array menjadi dasar untuk memahami cara menyimpan dan mengakses data dalam struktur data [3]. ADT adalah model matematika dari objek data yang melengkapi tipe data dengan fungsi-fungsi yang bekerja pada data tersebut [1]. Operasi terhadap data termuat dalam spesifikasi ADT, sehingga ADT mencakup lebih dari cara data disusun [1].

#### 1. Konsep ADT
Pemrogram mendefinisikan ADT sendiri untuk memudahkan pemrograman dan untuk menampung tipe data yang tidak disediakan bahasa pemrograman [1]. ADT muncul dari kebutuhan memisahkan struktur penyimpanan dari perilaku tipe data, seperti pada stack dan queue. Perubahan implementasi ADT tidak mengubah program yang memakainya selama antarmuka (interface) ADT tetap sama [1]. Struktur data menunjukkan cara data diorganisasi, sedangkan ADT mengemas struktur data beserta operasi yang bisa dilakukan terhadapnya [1].

#### 2. Struct sebagai Tipe Bentukan
Struct adalah tipe data bentukan yang menghimpun beberapa variabel berkaitan dalam satu nama [1]. Elemen array bertipe sama, sedangkan anggota struct boleh bertipe berbeda, bahkan berupa array atau struct lain [1]. Di C++, struct mewakili record, yaitu rekaman yang tersusun dari satu atau lebih field [2]. Pemrogram mengakses field lewat operator titik, misalnya `m.nim` [1][2].

#### 3. Pemisahan File dan Pengiriman Parameter
Pembuat dan pengguna ADT menyepakati antarmuka ADT, lalu mengerjakan bagian masing-masing secara terpisah [1]. C++ mendukung pemisahan ini karena fungsi bisa dideklarasikan langsung di program atau dipisah ke dalam header file [2]. Fungsi wajib mengembalikan nilai, sedangkan prosedur boleh tidak mengembalikan nilai [2].

Cara pengiriman parameter menentukan nasib variabel asli. Pada pengiriman by value, fungsi menerima salinan nilai, sehingga perubahan di dalam fungsi tidak mengubah variabel asli. Pada pengiriman by reference, fungsi menerima alamat data, sehingga perubahan di dalam fungsi mengubah variabel asli di program pemanggil [1]. Parameter berupa array dikirim secara by reference [1].

### B. Array dan Pointer<br/>

#### 1. Array Satu dan Dua Dimensi
Array adalah himpunan elemen yang terurut dan homogen, yaitu semua elemennya bertipe sama [1]. Array satu dimensi mewakili vektor, dan array dua dimensi mewakili matriks atau tabel [2]. Array dua dimensi memakai dua indeks, indeks pertama untuk baris dan indeks kedua untuk kolom [1]. Bentuk deklarasinya `tipe_data nama_array[baris][kolom]` [2], dan perulangan bersarang memproses seluruh elemennya [2].

#### 2. Array of Struct
Array dapat menyimpan elemen bertipe struct [2]. Deklarasi `Mahasiswa m[100];` membentuk array berisi 100 variabel bertipe struct `Mahasiswa` [1].

#### 3. Pointer
Pointer adalah variabel penunjuk yang berisi alamat memori, bukan nilai data [1]. Operator `&` di depan variabel menghasilkan alamatnya, dan operator `*` di depan pointer mengambil nilai yang tersimpan di alamat yang ditunjuk [1]. Tipe pointer harus sama dengan tipe data yang ditunjuk, jadi pointer bertipe float menunjuk alamat yang berisi nilai float [1].


## Guided 

### 1. mahasiswa.h

```C++
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
```
File ini adalah header ADT mahasiswa. Baris `#ifndef MAHASISWA_H`, `#define MAHASISWA_H`, dan `#endif` membentuk header guard, supaya compiler tidak membaca isi file dua kali saat beberapa file meng-include-nya.

`struct mahasiswa` punya tiga field: `nim` bertipe `int`, serta `nilai` dan `nilai2` bertipe `float`. Di bawahnya ada dua prototype. `inputMhs` memakai parameter reference (`&m`), jadi data yang diinput mengisi variabel di `main()`. `rata2` menerima `mahasiswa` dan mengembalikan `float`.

Header ini berisi tipe data dan daftar operasi ADT, tanpa isi fungsi.

### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim =";
    cin >> (m).nim;
    cout << "input nilai =";
    cin >> (m).nilai;
    cout << "input nilai2 =";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai+m.nilai2)/2;
}
```
File ini berisi isi dari prototype di `mahasiswa.h`, jadi ia meng-include `"mahasiswa.h"`.

Prosedur `inputMhs` meminta pengguna mengisi NIM, nilai, dan nilai2, lalu menyimpannya ke `m.nim`, `m.nilai`, dan `m.nilai2`. Parameter reference membawa perubahan itu ke variabel asli di `main()`.

Fungsi `rata2` menjumlahkan `nilai` dan `nilai2`, lalu membaginya dengan 2. Karena kedua nilai bertipe `float`, hasil baginya berbentuk desimal.

File implementasi berisi cara kerja operasi yang dideklarasikan di header.

### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;

}
```
`main.cpp` memakai ADT yang sudah dibuat. Variabel `mhs` bertipe `mahasiswa`. `inputMhs(mhs)` mengisi datanya dari keyboard, lalu `rata2(mhs)` menghitung rata-rata dua nilai yang diinput. Program utama tidak perlu mengetahui isi fungsi, ia memanggilnya.

Program utama jadi pendek karena memanggil operasi yang sudah tersedia di ADT.

## Unguided 

### 1. (Buatlah ADT mahasiswa dalam array maksimal 10 data dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir dihitung dengan fungsi: 0.3 * uts + 0.4 * uas + 0.3 * tugas)

**soal1.h**
```C++
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
```

**soal1.cpp**
```C++
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
```

**main_soal1.cpp**
```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/widi-ui/109082500108_Hananto-Widi-U./blob/main/modul%203/Output/Output3.1.png?raw=true)

penjelasan unguided 1
Soal pertama meminta ADT `mahasiswa` dalam tiga file: `soal1.h` berisi struct dan prototype, `soal1.cpp` berisi isi fungsi, dan `main_soal1.cpp` berisi program utama. Struct `mahasiswa` punya field `nama`, `nim`, `uts`, `uas`, `tugas`, dan `nilaiAkhir`. Konstanta `MAKS = 10` membatasi jumlah data di array.

Fungsi `hitungNilaiAkhir` memberi bobot 30% untuk UTS, 40% untuk UAS, dan 30% untuk tugas. Prosedur `inputMhs` memakai parameter reference, jadi data yang diinput masuk ke elemen array di `main()`, lalu prosedur memanggil `hitungNilaiAkhir` untuk mengisi `nilaiAkhir`. Perintah `cin.ignore()` membuang karakter enter yang tersisa sebelum `getline`, sehingga nama berspasi terbaca utuh.

Di `main()`, `do-while` membatasi jumlah mahasiswa antara 1 dan 10. Perulangan `for` pertama mengisi data tiap mahasiswa, dan perulangan `for` kedua menampilkan seluruh data beserta nilai akhir.

Soal ini melatih pembuatan ADT dengan struct, pembagian file `.h`, `.cpp`, dan `main`, serta array of struct.

### 2. (Buatlah ADT pelajaran dengan field namaMapel dan kodeMapel, lengkap dengan file header, file implementasi, dan main, lalu tampilkan datanya)

**soal2.h**
```C++
#ifndef SOAL2_H_INCLUDED
#define SOAL2_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif 
```

**soal2.cpp**
```C++
#include <iostream>
#include "soal2.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

**main_soal2.cpp**
```C++
#include <iostream>
#include "soal2.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/widi-ui/109082500108_Hananto-Widi-U./blob/main/modul%203/Output/output3.2.png?raw=true)

penjelasan unguided 2
Soal kedua meminta ADT `pelajaran` dalam tiga file, yaitu `soal2.h`, `soal2.cpp`, dan `main_soal2.cpp`. Struct `pelajaran` punya dua field, `namaMapel` dan `kodeMapel`.

Fungsi `create_pelajaran` berperan sebagai konstruktor. Ia menerima nama dan kode, menyimpannya ke variabel `p`, lalu mengembalikan `p` sebagai nilai bertipe `pelajaran`. Prosedur `tampil_pelajaran` menampilkan kedua field ke layar.

Di `main()`, nama "Struktur Data" dan kode "STD" masuk ke `create_pelajaran`, lalu `tampil_pelajaran` menampilkan hasilnya.

Soal ini melatih konsep konstruktor pada ADT, yaitu fungsi yang membentuk nilai bertipe ADT dari data masukan.

### 3. (Buatlah dua array dua dimensi integer berukuran 3x3 dan dua pointer integer. Buat fungsi untuk menampilkan isi array, fungsi untuk menukar isi array pada posisi tertentu, dan fungsi untuk menukar isi dua variabel yang ditunjuk oleh pointer)

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "=== Array A ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B ===" << endl;
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2) : ";
    cin >> baris >> kolom;

    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        tukarPosisi(A, B, baris, kolom);
        cout << "\n=== Setelah ditukar pada posisi ["
             << baris << "][" << kolom << "] ===" << endl;
        cout << "Array A :" << endl;
        tampilArray(A);
        cout << "\nArray B :" << endl;
        tampilArray(B);
    } else {
        cout << "Posisi tidak valid!" << endl;
    }

    cout << "\n=== Pointer ===" << endl;
    cout << "Sebelum : x = " << x << ", y = " << y << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah : x = " << x << ", y = " << y << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/widi-ui/109082500108_Hananto-Widi-U./blob/main/modul%203/Output/output3.3.png?raw=true)

penjelasan unguided 3
Soal ketiga memakai dua array dua dimensi `A` dan `B` berukuran 3×3, serta dua pointer `p1` dan `p2` yang menunjuk ke variabel `x` dan `y`.

Fungsi `tampilArray` menampilkan isi array dengan dua perulangan bersarang, perulangan luar untuk baris dan perulangan dalam untuk kolom. Fungsi `tukarPosisi` menukar elemen `A` dan `B` pada baris dan kolom yang dipilih pengguna: `A[baris][kolom]` disimpan ke `temp`, diisi dengan `B[baris][kolom]`, lalu `B[baris][kolom]` diisi dengan `temp`. Array dikirim ke fungsi secara by reference, jadi perubahan terjadi di array asli pada `main()`. Sebelum menukar, program mengecek apakah baris dan kolom berada di antara 0 dan 2. Kalau tidak, program menampilkan "Posisi tidak valid!".

Fungsi `tukarPointer` menukar isi variabel yang ditunjuk pointer dengan operator `*`. Awalnya `x = 10` dan `y = 20`, setelah ditukar `x = 20` dan `y = 10`.

Soal ini melatih array dua dimensi sebagai parameter fungsi dan pointer untuk menukar isi variabel.

## Kesimpulan
Praktikum Modul 3 membangun ADT dari `struct` dan operasi yang mengolahnya, lalu memecahnya menjadi file header, file implementasi, dan program utama. Guided memakai ADT `mahasiswa` yang menyimpan NIM dan dua nilai, dengan prosedur `inputMhs` berparameter reference dan fungsi `rata2`. Unguided memakai ADT `mahasiswa` dalam array maksimal 10 elemen dengan nilai akhir berbobot, ADT `pelajaran` dengan konstruktor `create_pelajaran`, serta array dua dimensi 3×3 dan pointer untuk menukar isi data lewat fungsi.


## Referensi
[1] Triase. (2020). Struktur Data: Diktat Edisi Revisi. Medan: Fakultas Sains dan Teknologi, Universitas Islam Negeri Sumatera Utara. Diakses pada 12 Oktober 2026 melalui http://repository.uinsu.ac.id/9717/.
<br>[2] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: UMSIDA Press. Diakses pada 12 Oktober 2026 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Rahman, S., Hartono, Joni, Dafitri, H., Tanjung, J. P., & Chiuloto, K. (2025). Struktur Data dan Algoritma: Pendekatan Visual dan Praktis dalam C++. Medan: Universitas Medan Area Press. Diakses pada 12 Oktober 2026 melalui https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf.
