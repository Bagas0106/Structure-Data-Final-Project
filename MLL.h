#include <iostream>
using namespace std;

struct infoProvinsi {
    string namaProvinsi;
    string ibuKota; //nampilin data ibuKota
    string zonaWaktu;
    float pertumbuhanEkonomi;
};

struct infoDaerah {
    string namaDaerah;
    string tipeWilayah;
    int populasi; // belum diset (set di main panggil gajiRataRata)
    float gajiRataRata; // belum diset (set di main panggil gajiRataRata)
    int luasWilayah; //cek kepadatan penduduk
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
void addDaerah(adrProvinsi p, adrDaerah d);
bool isPoor(adrDaerah d);
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
void deleteAllChild(adrProvinsi p);
int totalPopulasi(adrDaerah d);
int isPenuh(adrDaerah d);  // 1:Sangat rendah, 2:Rendah, 3:Sedang, 4:Padat, 5:Sangat Padat
float gajiRataRata(adrDaerah d);
/*Sort, Searching, Print (Parrent, Child sebuah Provinsi, Child All), Edit, Func Operasi, Delete*/