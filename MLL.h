#include <iostream>
using namespace std;

struct infoProvinsi {
    string namaProvinsi;
    string ibuKota;
    string zonaWaktu
};

struct infoDaerah {
    string namaDaerah;
    int populasi;
    int gajiRataRata;
    int luasWilayah;
    string tipeWilayah
    string kodeBPS
};

typedef struct provinsi *adrProvinsi;
typedef struct daerah *adrDaerah;

struct provinsi {
    adrProvinsi next;
    adrProvinsi prev;
    adrDaerah firstDaerah;
    infoProvinsi infoP;
};

struct daerah {
    adrDaerah next;
    adrDaerah prev;
    infoDaerah infoD;
};

struct listProvinsi {
    adrProvinsi first;
    adrProvinsi last;
};


void createListProvinsi(listProvinsi &L);
bool isEmptyProvinsi(listProvinsi L);
bool isEmptyDaerah(adrProvinsi p);
void addProvinsi(listProvinsi &L, adrProvinsi p);
void addDaerah(listProvinsi &L, adrDaerah p);
adrProvinsi createElmProvinsi(string namaProvinsi, string Ibukota);
adrDaerah createElmDaerah()
