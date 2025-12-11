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
void addProvinsi(listProvinsi &L, adrProvinsi p);
void addDaerah(listProvinsi &L, adrDaerah p);