#include <iostream>
using namespace std;

// Menampilkan isi array 2D 3x3
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Menukar isi array A dan B pada posisi (baris, kolom) tertentu
void tukarPosisi(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

// Menukar isi variabel yang ditunjuk oleh dua pointer
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