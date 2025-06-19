#include <bits/stdc++.h>
using namespace std;

const int EMPTY = 0;
const int DELETE = -1;
const float LOAD = 0.75; // ngưỡng tải

struct Entry {
    int Maso;
    Entry() {
        Maso = EMPTY;
    }
};

struct HashTable {
    int M, n;
    vector<Entry> table;

    HashTable(int size) {
        M = size;
        n = 0;
        table.resize(M);
    }
};

// Hàm insert (thăm dò tuyến tính)
bool insert(HashTable& ht, Entry x) {
    if (ht.n >= int(ht.M * LOAD)) return false; // Bảng đầy

    int key = x.Maso;
    for (int i = 0; i < ht.M; i++) {
        int idx = (key % ht.M + i) % ht.M;
        if (ht.table[idx].Maso == EMPTY || ht.table[idx].Maso == DELETE) {
            ht.table[idx] = x;
            ht.n++;
            return true;
        }
        if (ht.table[idx].Maso == key) return false; // Không chèn trùng
    }
    return false; // Không chèn được
}

// Hàm remove
bool remove(HashTable& ht, int maso) {
    int key = maso;
    for (int i = 0; i < ht.M; i++) {
        int idx = (key % ht.M + i) % ht.M;
        if (ht.table[idx].Maso == EMPTY) return false; // không tìm thấy
        if (ht.table[idx].Maso == maso) {
            ht.table[idx].Maso = DELETE;
            ht.n--;
            return true;
        }
    }
    return false;
}

// Hàm in bảng băm
void printTable(const HashTable& ht) {
    for (int i = 0; i < ht.M; i++) {
        cout << "[" << i << "]: ";
        if (ht.table[i].Maso == EMPTY)
            cout << "EMPTY";
        else if (ht.table[i].Maso == DELETE)
            cout << "DELETE";
        else
            cout << ht.table[i].Maso;
        cout << endl;
    }
}
