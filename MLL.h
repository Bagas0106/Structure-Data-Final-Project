#include <iostream>
using namespace std;

struct infoProvinsi {
    string namaProvinsi;
    string ibuKota;
};

struct infoDaerah {
    string NamaDaerah;
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

