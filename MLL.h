#include <iostream>
using namespace std;

struct infoProvinsi {
    string namaProvinsi;
    string ibuKota;
    string zonaWaktu;
    float pertumbuhanEkonomi;
};

struct infoDaerah {
    string namaDaerah;
    string tipeWilayah;
    int populasi;
    int gajiRataRata;
    int luasWilayah;
    int populasiDewasa;
    int populasiAnak;
    int pendapatan4juta;
    int pendapatan3juta;
    int pendapatan2juta;
    int pendapatan1juta;
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
bool isPoor(adrProvinsi p);
adrDaerah searchIbuKota(adrProvinsi p, string ibuKota);
void printProvinsi(listProvinsi L);
void printDaerahAll(listProvinsi L);
void printDaerah(adrProvinsi p);
adrProvinsi searchProvinsi(listProvinsi L, string provinsi);
adrDaerah searchDaerah(listProvinsi L, string daerah);
void sortAscending(listProvinsi &L);
void sortDescending(listProvinsi &L);
void editData(listProvinsi &L, string nama); /*Search provinsi dulu, kalau null lanjut ke search Daerah*/
void deleteData(listProvinsi &L, string nama);

/*Sort, Searching, Print (Parrent, Child sebuah Provinsi, Child All), Edit, Func Operasi, Delete*/