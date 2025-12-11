#include <iostream>
using namespace std;

struct infoProvinsi {
    string namaProvinsi;
    string ibuKota;
    string zonaWaktu
};

struct infoDaerah {
    string namaDaerah;
    string tipeWilayah;
    int populasi;
    int gajiRataRata;
    int luasWilayah;
    string kodeBPS;
};

typedef struct provinsi *adrProvinsi;
typedef struct daerah *adrDaerah;
typedef struct infoProvinsi infoP;
typedef struct infoDaerah infoD;

struct provinsi {
    adrProvinsi next;
    adrProvinsi prev;
    adrDaerah firstDaerah;
    infoProvinsi info;
};

struct daerah {
    adrDaerah next;
    adrDaerah prev;
    infoDaerah info;
};

struct listProvinsi {
    adrProvinsi first;
    adrProvinsi last;
};


void createListProvinsi(listProvinsi &L);
bool isEmptyProvinsi(listProvinsi L);
bool isEmptyDaerah(adrProvinsi p);
adrProvinsi createElmProvinsi(infoP p);
adrDaerah createElmDaerah(infoD p);
void addProvinsi(listProvinsi &L, adrProvinsi p);
void addDaerah(listProvinsi &L, adrDaerah p);
bool isPoor(listProvinsi L);
