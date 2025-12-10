#include <iostream>
using namespace std;

struct infoProvinsi {
    string namaProvinsi;
    string ibuKota;
};

struct infoDaerah {
    string namaDaerah;
    int populasi;
    int gajiRataRata;
    string wisata;
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

struct ListProvinsi {
    adrProvinsi first;
    adrProvinsi last;
};

