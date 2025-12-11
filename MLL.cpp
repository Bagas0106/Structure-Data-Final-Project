#include "MLL.h"
#include <iostream>

using namespace std;

void createListProvinsi(listProvinsi &L){
    L.first = nullptr;
}
bool isEmptyProvinsi(listProvinsi L){
    return L.first == nullptr;
}
bool isEmptyDaerah(adrProvinsi p){
    return p->firstDaerah == nullptr;
}
adrProvinsi createElmProvinsi(infoP p){
    adrProvinsi q = new  provinsi;
    q->info = p;
    q->next = nullptr;
    q->prev = nullptr;
    q->firstDaerah = nullptr;
    return q;
}
adrDaerah createElmDaerah(infoD p){
    adrDaerah q = new daerah;
    q->info = p;
    q->next = nullptr;
    q->prev = nullptr;
    return q;
}
void addProvinsi(listProvinsi &L, adrProvinsi p){
    if (L.first == nullptr){
        L.first = p;
        L.last = p;
    } else if (L.first == L.last){
        L.first->next = p;
        p->prev = L.first;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}
void addDaerah(listProvinsi &L, adrDaerah p){
    adrDaerah q = nullptr;
    if (L->firstDaerah == nullptr){
        L->firstDaerah = p;
    } else {
        q = L->firstDaerah;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
}
bool isPoor(adrProvinsi p){

}
adrDaerah searchIbuKota(adrProvinsi p){

}
void printProvinsi(listProvinsi L){
    adrProvinsi p = L.first;
    while (p != nullptr){
        cout << p->info.namaProvinsi;
        if (p->next != nullptr){
            cout << ", "
        }
        p = p->next;
    }
    cout << endl;
}
void printDaerahAll(listProvinsi L){
    adrProvinsi p;
    adrDaerah q;
    if (L.first == nullptr){
        cout << "Tidak ada data"
    } else {
        p = L.first;
        while (p != nullptr){
            q = p->firstDaerah;
            if (q == nullptr){
                cout << "Tidak ada Daerah" << endl;
            }
            while (q != nullptr){
                cout << q->info.namaDaerah;
                if (q->next != nullptr){
                    cout << ", ";
                }
                q = q->next;
            }
            p = p->next;
        }
    }
    cout << endl;
}
void printDaerah(adrProvinsi p){
    adrDaerah q;
    if(p->firstDaerah == nullptr){
        cout << "Tidak ada Daerah" << endl;
    } else {
        q = p->firstDaerah;
        while (q != nullptr){
            cout << q->info.namaDaerah;
            if (q->next != nullptr){
                cout << ", ";
            }
            q = q->next;
        }
    }
}
adrProvinsi searchProvinsi(listProvinsi L, string provinsi){

}
adrDaerah searchDaerah(listProvinsi L, string daerah){

}
void sortAscending(listProvinsi &L){

}
void sortDescending(listProvinsi &L){

}
void editData(listProvinsi &L, string nama){

} /*Search provinsi dulu, kalau null lanjut ke search Daerah*/
void deleteData(listProvinsi &L, string nama){

}