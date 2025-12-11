#include "MLL.h"

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