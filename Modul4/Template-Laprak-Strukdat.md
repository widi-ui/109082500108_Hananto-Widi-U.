# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List</h1>
<p align="center">Hananto Widi Utomo -109082500108 </p>

## Dasar Teori

### A. Linked List<br/>
Linked list menghubungkan elemen-elemennya dengan pointer [1]. Dua elemen yang bertetangga secara logis bisa berjauhan di memori, jadi program harus menyimpan alamat simpul pertama untuk mengaksesnya [1]. Array menetapkan ukuran sejak awal, sedangkan linked list menambah atau menghapus elemen tanpa memindahkan elemen lain [2].

#### 1. Simpul (Node)
Simpul memiliki bagian data dan bagian pointer yang menunjuk ke simpul berikutnya [1]. Di C++, programmer menulis simpul sebagai `struct` dan menaruh pointer penghubung di dalamnya [2]. Bagian data bisa memuat beberapa field, misalnya nama dan NPM mahasiswa. Pointer penghubung berjumlah satu per simpul [1].

#### 2. Singly Linked List
Singly linked list adalah tipe linked list paling sederhana. Simpulnya memiliki satu pointer ke simpul berikutnya [1]. Program menelusuri list dalam satu arah, mulai dari simpul pertama [1]. Variabel `First` (atau `Head`) menyimpan alamat simpul pertama dan menjadi titik awal penelusuran. Simpul terakhir berisi pointer `Nil` karena tidak punya simpul sesudahnya [1]. Jika `First` bernilai `Nil`, list kosong [1].

### B. Operasi pada Singly Linked List<br/>

#### 1. Alokasi dan Dealokasi
Untuk membuat simpul, program mengalokasikan memori seukuran simpul, mengisi datanya, lalu mengisi pointer dengan `Nil` [1]. Melepas simpul dari list belum mengembalikan memorinya. Programmer harus mendealokasi simpul itu. Simpul yang lepas tanpa dealokasi menjadi sampah dan terus memakai memori [1].

#### 2. Insert (Penyisipan)
Pada insert di awal, program mengarahkan pointer simpul baru ke `First` lama, lalu memindahkan `First` ke simpul baru [1]. Pada insert setelah simpul tertentu, program menyambungkan simpul baru ke penerus simpul tersebut, lalu menyambungkan simpul tersebut ke simpul baru [1]. Pada insert di akhir, program menelusuri list sampai simpul terakhir dan menyambungkan simpul baru di sana. Jika list kosong, simpul baru menjadi simpul pertama [1].

#### 3. Delete (Penghapusan)
Untuk menghapus simpul, program mengisi pointer simpul pendahulu (predesesor) dengan alamat simpul penerus (suksesor), lalu mendealokasi simpul yang lepas [1]. Pada penghapusan simpul pertama, program memindahkan `First` ke simpul kedua [1]. Lewat penelusuran, program menemukan lokasi simpul yang dihapus maupun lokasi sisipan [1].

#### 4. Penelusuran dan Penghitungan
Penelusuran mengunjungi simpul dari simpul pertama sampai bertemu simpul dengan pointer `Nil` [1]. Menampilkan isi list dan menghitung jumlah simpul memakai pola yang sama.

### C. ADT (Abstract Data Type)<br/>
Praktikum ini membagi ADT singly linked list menjadi tiga file. File header `.h` menyimpan deklarasi tipe dan prosedur. File `.cpp` menyimpan implementasi prosedur. File `main.cpp` berisi program utama yang memakai ADT tersebut.


## Guided 

### 1. list.h

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedList {
    address first;
};

// semua function dan procedure yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
File ini adalah header yang mendefinisikan ADT singly linked list untuk data mahasiswa.

`#ifndef LIST_H ... #endif` adalah include guard agar header tidak terbaca dua kali saat dikompilasi. `#define Nil NULL` membuat nama `Nil` sebagai pengganti `NULL`.

Struct `mahasiswa` menyimpan tiga data: `nama`, `nim`, dan `umur`. Struct `node` berisi `isidata` bertipe `dataMahasiswa` dan pointer `next` yang menunjuk node berikutnya. `address` adalah alias dari pointer ke `node`. Struct `linkedList` hanya punya satu anggota, yaitu `first` yang menunjuk node pertama.

Bagian bawah file berisi deklarasi semua fungsi dan prosedur yang diimplementasikan di `list.cpp`.

Kesimpulan: header ini menetapkan bentuk node, bentuk list, dan daftar operasi untuk linked list mahasiswa.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(linkedList &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
File ini berisi implementasi semua prosedur yang dideklarasikan di `list.h`.

`isEmpty()` mengembalikan `true` jika `first` bernilai `Nil`. `createList()` membuat list kosong dengan mengisi `first` dengan `Nil`.

`alokasi()` membuat node baru dengan `new`, mengisi `nama`, `nim`, dan `umur`, lalu mengatur `next = Nil`. `dealokasi()` mengembalikan memori node ke sistem dengan `delete`.

Untuk insert, `insertFirst()` mengarahkan `next` node baru ke `first` lama lalu memindahkan `first` ke node baru. `insertAfter()` menyisipkan node baru setelah node `Prev`: `next` node baru diarahkan ke `Prev->next`, lalu `Prev->next` diarahkan ke node baru. `insertLast()` menelusuri list sampai node terakhir (yang `next`-nya `Nil`), lalu menyambungkan node baru di sana. Jika list kosong, node baru langsung menjadi `first`.

Untuk delete, `delFirst()` memajukan `first` ke node kedua, lalu menghapus node lama. `delLast()` menelusuri list sambil mencatat node sebelumnya (`nodePrev`), lalu memutus node terakhir dan menghapusnya. Kasus list dengan satu node ditangani terpisah. `delAfter()` menghapus node setelah `nodePrev` dengan cara menyambungkan `nodePrev->next` ke node sesudahnya sebelum node tersebut dihapus.

`printList()` menelusuri list dari `first` dan menampilkan nama, NIM, dan usia tiap node. `nbList()` menghitung jumlah node dengan menelusuri list. `deleteList()` menghapus semua node satu per satu, lalu mengatur `first = Nil`.

Kesimpulan: file ini mengimplementasikan pembuatan, penyisipan, penghapusan, penampilan, dan penghitungan node, dengan `new` dan `delete` sebagai pengelola memori.


## Unguided 

### 1. (Buatlah ADT Singly Linked List pada file Singlylist.h, implementasi prosedurnya pada Singlylist.cpp, dan program utama pada main.cpp. Tampilkan isi list setelah lima node ditambahkan dengan insertFirst)

**Singlylist1.h**
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

**Singlylist1.cpp**
```C++
#include "Singlylist1.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

**main1.cpp**
```C++
#include "Singlylist1.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/widi-ui/109082500108_Hananto-Widi-U./blob/main/Modul4/Output/output1.png?raw=true)

penjelasan unguided 1
Pada soal pertama, dibuat ADT singly linked list dengan data bertipe `int`. Struct `ElmList` menyimpan `info` dan `next`, sedangkan struct `List` menyimpan pointer `First` ke node pertama.

Program utama membuat list kosong dengan `createList()`, lalu membuat lima node dengan `alokasi()` yang berisi 2, 0, 8, 12, dan 9. Setiap node dimasukkan dengan `insertFirst()`, yaitu di awal list. Karena selalu masuk di depan, node yang dimasukkan paling akhir menjadi node pertama. Isi list berubah seperti ini:

```
2
0 2
8 0 2
12 8 0 2
9 12 8 0 2
```

Hasil akhirnya, saat `printInfo()` dipanggil, list tampil dengan urutan 9 12 8 0 2.

Kesimpulan: soal ini melatih pembuatan ADT singly linked list, alokasi node, dan penyisipan di awal list dengan `insertFirst()`.

### 2. (Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().)

**Singlylist2.h**
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

**Singlylist2.cpp**
```C++
#include "Singlylist2.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

**main2.cpp**
```C++
#include "Singlylist2.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, P = Nil;
    createList(L);

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    deleteFirst(L, P);      
    dealokasi(P);

    deleteLast(L, P);       
    dealokasi(P);

    deleteAfter(L, P4, P);  
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    cout << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/widi-ui/109082500108_Hananto-Widi-U./blob/main/Modul4/Output/output2.png?raw=true)

penjelasan unguided 2
Pada soal kedua, list dari soal pertama (9 12 8 0 2) ditambah prosedur penghapusan. Prosedur `deleteFirst()`, `deleteLast()`, dan `deleteAfter()` hanya melepas node dari list lalu mengembalikan alamatnya lewat parameter `P`. Setelah itu node dihapus dari memori dengan `dealokasi()`.

Urutan prosesnya:

```
Awal               : 9 12 8 0 2
deleteFirst        : 12 8 0 2     (node 9 dihapus)
deleteLast         : 12 8 0       (node 2 dihapus)
deleteAfter(P4)    : 12 0         (node 8 dihapus)
```

`P4` menunjuk node 12, jadi `deleteAfter(L, P4, P)` menghapus node yang berada tepat setelahnya, yaitu node 8. Setelah itu `printInfo()` menampilkan `12 0` dan `nbList()` menghitung jumlah node, yaitu 2.

Terakhir, `deleteList()` menghapus seluruh node dengan memanggil `deleteFirst()` dan `dealokasi()` berulang sampai `First` bernilai `Nil`. Setelahnya `nbList()` mengembalikan 0, yang menandakan list sudah kosong.

Kesimpulan: soal ini melatih penghapusan node di awal, di akhir, dan setelah node tertentu, penghitungan jumlah node, dan pengosongan list dengan dealokasi memori.

## Kesimpulan
Praktikum Modul 4 memperlihatkan cara kerja singly linked list. Node menyimpan data dan pointer `next`, sedangkan `First` menunjuk node pertama. Operasi insert (`insertFirst`, `insertAfter`, `insertLast`) dan delete (`deleteFirst`, `deleteLast`, `deleteAfter`) mengatur ulang pointer. `alokasi` membuat node dengan `new`, dan `dealokasi` mengembalikan memorinya dengan `delete`. Pada latihan, lima kali `insertFirst` menghasilkan list 9 12 8 0 2. Penghapusan node 9, 2, dan 8 menyisakan list 12 0 dengan 2 node, lalu `deleteList` mengosongkan list sampai jumlah node 0. Pemisahan kode ke file `.h`, `.cpp`, dan `main.cpp` membuat program terstruktur.


## Referensi
[1] Erzed, N. (tanpa tahun). Modul Struktur Data: Linked List (Modul VII & VIII). Jakarta: Universitas Esa Unggul. Diakses pada 18 Oktober 2026 melalui https://lms-paralel.esaunggul.ac.id/mod/resource/view.php?id=117155.
<br>[2] Fitra, M. R. A., Effendi, A. A. S., & Ramadhani, F. (2025). Implementasi Python dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 pada Universitas Negeri Medan Menggunakan Struktur Data Linked List. JATI (Jurnal Mahasiswa Teknik Informatika), 9(1), 51–58. Diakses pada 18 Oktober 2026 melalui https://ejournal.itn.ac.id/jati/article/download/12164/6831.
