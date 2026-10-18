# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List</h1>
<p align="center">Hananto Widi Utomo - 109082500108 </p>

## Dasar Teori

### A. Linked List<br/>
Linked list atau senarai berkait adalah struktur data yang menyimpan kumpulan data secara sekuensial, saling bersambungan, dan dinamis [1]. Linked list tersusun dari sejumlah node yang dihubungkan secara linier dengan bantuan pointer [1]. Pada single linked list, hanya ada satu pointer yang menghubungkan setiap node [1].

#### 1. Node dan Pointer
Setiap node berbentuk `struct` dan memiliki dua bagian. Bagian pertama, medan informasi, menyimpan data. Bagian kedua, medan penyambung (link field), menyimpan alamat node berikutnya [1]. Anggota sebuah struct boleh bertipe struct lain [1], sehingga data satu mahasiswa dapat disimpan sebagai struct di dalam node. Pointer menyimpan alamat memori, bukan nilai data, dan bernilai null bila tidak menunjuk ke mana pun [1]. Node terakhir ditandai dengan medan penyambung yang bernilai null [1].

#### 2. Pointer Awal
Sebuah pointer awal menunjuk ke node pertama list. Dengan pointer ini saja, program dapat membaca semua informasi yang tersimpan di list [1]. List kosong ditandai dengan pointer awal bernilai null [1].

#### 3. Keunggulan terhadap Array
Linked list lebih efisien untuk penyisipan dan penghapusan, dan memakai alokasi penyimpanan dinamis yang dialokasikan saat runtime [1]. Array memiliki batas alokasi memori yang bersifat statis [1].

### B. Operasi pada Singly Linked List<br/>
Operasi dasar pada linked list meliputi menambah node, menghapus node, mencari informasi, dan mencetak node [1]. Membentuk linked list tunggal membutuhkan deklarasi tipe node, deklarasi pointer penunjuk awal, pembentukan node baru, dan pengaitan node baru ke list [1].

#### 1. Menambah Node
Penambahan di depan mengisi `next` node baru dengan alamat node pertama, lalu mengarahkan pointer awal ke node baru [1]. Penambahan di belakang menguji dulu apakah list kosong. Bila kosong, pointer awal diarahkan ke node baru. Bila tidak, program menelusuri list sampai node yang `next`-nya null, lalu mengaitkan node baru di sana [1]. Penambahan di tengah berarti penyisipan pada posisi tertentu, dengan node baru mengambil `next` dari node sebelumnya dan node sebelumnya menunjuk ke node baru [1].

#### 2. Menghapus Node
Penghapusan node pertama menampung node awal di pointer sementara, mengarahkan pointer awal ke node berikutnya, lalu menghapus node yang ditampung [1]. Penghapusan node terakhir menelusuri list sampai node yang `next`-nya null, kemudian menghapusnya dan mengisi `next` node sebelumnya dengan null [1]. Penghapusan node di tengah mengisi `next` node sebelumnya dengan `next` node yang dihapus, lalu menghapus node tersebut [1].

#### 3. Pemisahan File dan Prosedur
ADT dibagi menjadi file header yang berisi tipe dan prototype, file implementasi yang berisi isi fungsi, dan program utama [2]. Prosedur boleh tidak mengembalikan nilai, sedangkan fungsi wajib mengembalikan nilai [2]. Parameter yang nilainya harus berubah di program pemanggil dikirim secara by reference [1].


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
File ini adalah header ADT linked list. Baris `#ifndef LIST_H`, `#define LIST_H`, dan `#endif` membentuk header guard, sedangkan `#define Nil NULL` memberi nama `Nil` untuk pointer kosong.

`struct mahasiswa` menyimpan data `nama`, `nim`, dan `umur`, lalu `typedef` memberinya nama `dataMahasiswa`. `struct node` punya dua field, yaitu `isidata` bertipe `dataMahasiswa` dan `next` bertipe `address`, yaitu pointer ke node berikutnya. `struct linkedList` hanya berisi pointer `first` yang menunjuk node pertama. Bagian bawah file memuat prototype semua fungsi dan prosedur, tanpa isinya.

Header ini berisi tipe data dan daftar operasi ADT linked list, tanpa isi fungsi.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan
       isi data sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev sudah dialokasikan
       F.S. menempatkan elemen setelah node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen pada akhir list */
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
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
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
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
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
    /* I.S. list tidak kosong, nodePrev adalah alamat salah satu elemen list
       F.S. node setelah nodePrev dihapus dari list */
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
    /* I.S. mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info pada list */
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
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */
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
    /* I.S. list sudah ada
       F.S. menghapus semua node di dalam list */
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
File ini berisi isi dari prototype di `list.h`, jadi ia meng-include `"list.h"`.

`isEmpty` mengembalikan `true` bila `first` bernilai `Nil`. `createList` mengisi `first` dengan `Nil` sehingga list kosong. `alokasi` membuat node baru dengan `new`, mengisi `nama`, `nim`, dan `umur` ke `isidata`, lalu mengisi `next` dengan `Nil`. `dealokasi` mengembalikan memori node ke sistem dengan `delete`.

Tiga prosedur insert menempatkan node di tempat berbeda. `insertFirst` mengisi `next` node baru dengan `first` lama, lalu mengarahkan `first` ke node baru. `insertAfter` mengisi `next` node baru dengan `next` milik `Prev`, lalu mengarahkan `next` milik `Prev` ke node baru. `insertLast` menelusuri list sampai node yang `next`-nya `Nil`, lalu mengaitkan node baru di situ, atau langsung mengisi `first` bila list masih kosong.

Tiga prosedur delete melepas node dari list lalu memanggil `dealokasi`. `delFirst` memindahkan `first` ke node berikutnya. `delLast` menelusuri list dengan dua pointer, `nodeHapus` dan `nodePrev`, sampai `nodeHapus` berada di node terakhir, lalu mengisi `next` milik `nodePrev` dengan `Nil`. `delAfter` mengisi `next` milik `nodePrev` dengan `next` node yang dihapus. Ketiganya menampilkan pesan bila list kosong atau node sebelumnya tidak valid.

`printList` menelusuri list dan menampilkan nama, NIM, dan usia tiap node. `nbList` menelusuri list sambil menambah penghitung, lalu mengembalikan jumlah node. `deleteList` menghapus node satu per satu, mengisi `first` dengan `Nil`, dan menampilkan pesan "List sudah terhapus!".

File implementasi berisi cara kerja operasi yang dideklarasikan di header.

### 3. main.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DIHAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
`main.cpp` memakai ADT yang sudah dibuat. Lima node dialokasi dengan data Dhimas, Arvin, Rizal, Satrio, dan Joshua. Urutan insert menentukan isi list. `insertFirst` menaruh Dhimas di depan, `insertLast` menaruh Arvin di belakang, `insertAfter` menyisipkan Rizal setelah Dhimas dan Satrio setelah Rizal, lalu `insertLast` menaruh Joshua di belakang. List menjadi Dhimas, Rizal, Satrio, Arvin, Joshua dengan jumlah node 5.

Tahap delete berjalan berurutan. `delFirst` menghapus Dhimas, `delLast` menghapus Joshua, dan `delAfter` menghapus node setelah Rizal, yaitu Satrio. List tersisa Rizal dan Arvin dengan jumlah node 2. `deleteList` lalu mengosongkan list, sehingga `printList` menampilkan "List kosong." dan `nbList` menghasilkan 0.

Program utama pendek karena memanggil operasi yang sudah tersedia di ADT.

## Unguided 

### 1. (Buatlah ADT Singly Linked List di dalam file Singlylist.h, implementasi prosedur di dalam Singlylist.cpp, lalu buat program utama di dalam main.cpp yang mengalokasi node berisi 2, 0, 8, 12, 9 dengan insertFirst dan menampilkannya dengan printInfo)

**Singlylist.h**
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

// I.S. sembarang
// F.S. list L kosong (First = Nil)
void createList(List &L);

// Fungsi: membuat node baru dengan info x dan next = Nil
address alokasi(infotype x);

// I.S. P terdefinisi
// F.S. node P dihapus dari memori, P = Nil
void dealokasi(address &P);

// I.S. L terdefinisi
// F.S. info semua node tampil di layar dari First sampai node terakhir
void printInfo(List L);

// I.S. L dan P terdefinisi
// F.S. node P menjadi node pertama pada list L
void insertFirst(List &L, address P);

// I.S. L terdefinisi
// F.S. node pertama dilepas dari L dan alamatnya disimpan di P
void deleteFirst(List &L, address &P);

// I.S. L terdefinisi
// F.S. node terakhir dilepas dari L dan alamatnya disimpan di P
void deleteLast(List &L, address &P);

// I.S. Prec terdefinisi
// F.S. node setelah Prec dilepas dan alamatnya disimpan di P
void deleteAfter(address Prec, address &P);

// Fungsi: menghitung jumlah node pada list L
int nbList(List L);

// I.S. L terdefinisi
// F.S. semua node dihapus dari memori, L kosong
void deleteList(List