#include "MLL.h"
#include <iostream>

using namespace std;

void createListProvinsi(listProvinsi &L){
    L.first = nullptr;
    L.last = nullptr;
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
void addDaerah(adrProvinsi p, adrDaerah d){
    adrDaerah q = p->firstDaerah;
    if (q == nullptr){
        q = d;
    }else {
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = d;
    }
}

adrDaerah searchIbuKota(adrProvinsi p, string ibuKota){
    if (p == nullptr){
        return nullptr;
    }
    adrDaerah temp = p->firstDaerah;
    while (temp != nullptr){
        if (temp->info.namaDaerah == ibuKota){
            return temp;
        }
    }
    return nullptr;
}
void printProvinsi(listProvinsi L){
    adrProvinsi p = L.first;
    while (p != nullptr){
        cout << p->info.namaProvinsi;
        if (p->next != nullptr){
            cout << ", ";
        }
        p = p->next;
    }
    cout << endl;
}
void printDaerahAll(listProvinsi L){
    adrProvinsi p;
    adrDaerah q;
    if (L.first == nullptr){
        cout << "Tidak ada data";
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
    adrProvinsi p;
    if (L.first == nullptr){
        cout << "Kosong";
    } else {
        p = L.first;
        while (p != nullptr){
            if (p->info.namaProvinsi == provinsi){
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
}
adrDaerah searchDaerah(listProvinsi L, string daerah){
    adrProvinsi p;
    adrDaerah q;
    if (L.first == nullptr){
        cout << "Provinsi kosong";
    } else {
        p = L.first;
        while (p != nullptr){
            
            p = p->next;
        }
        return nullptr;
    }
}
void sortAscending(listProvinsi &L){
    if (L.first == nullptr || L.first->next == nullptr){
        return;
    }

    bool tukar = true;
    adrProvinsi ptr;
    adrProvinsi lptr = nullptr;

    while (tukar){
        tukar = false;
        ptr = L.first;

        while (ptr->next != lptr){
            if (ptr->info.namaProvinsi > ptr->next->info.namaProvinsi){
                string tempp = ptr->info.namaProvinsi;
                ptr->info.ibuKota = ptr->next->info.namaProvinsi;
                ptr->next->info.namaProvinsi = tempp;

                adrDaerah tempd = ptr->firstDaerah;
                ptr->firstDaerah = ptr->next->firstDaerah;
                ptr->next->firstDaerah = tempd;

                tukar = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
}
void sortDescending(listProvinsi &L){
    if (L.first == nullptr || L.first->next == nullptr){
        return;
    }

    bool tukar = true;
    adrProvinsi ptr;
    adrProvinsi lptr = nullptr;

    while (tukar){
        tukar = false;
        ptr = L.first;

        while (ptr->next != lptr){
            if (ptr->info.namaProvinsi < ptr->next->info.namaProvinsi){

                string tempp = ptr->info.namaProvinsi;
                ptr->info.namaProvinsi = ptr->next->info.namaProvinsi;
                ptr->next->info.namaProvinsi = tempp;

                adrDaerah tempd = ptr->firstDaerah;
                ptr->firstDaerah = ptr->next->firstDaerah;
                ptr->next->firstDaerah = tempd;

                tukar = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
}
void deleteAllChild(adrProvinsi p){
    adrDaerah q;
    if (p->firstDaerah != nullptr){
        q = p->firstDaerah;
        while (q != nullptr){
            while  (q->next != nullptr){
                q = q->next;
            }
            q->next->prev = nullptr;
            q->next = nullptr;
        }
    }
}
void editData(listProvinsi &L, string nama){
    string newname;
    
    adrProvinsi p = L.first;
    while (p != nullptr){
        if (p->info.namaProvinsi == nama){
            cout << "[PROVINSI DITEMUKAN!]" << nama << endl;
            cout << "Masukan Nama Provinsi baru: ";
            cin >> newname;

            p->info.namaProvinsi = newname;
            cout << "[DATA BERHASIL DIUBAH!]" << endl;
            return;
        }
        p = p->next;
    }

    p = L.first;
    while (p != nullptr){
        adrDaerah d = p->firstDaerah;

        while(d != nullptr){
            if (d->info.namaDaerah == nama){
                cout << "[DAERAH DITEMUKAN!]" << nama << "Diprovinsi " << p->info.namaProvinsi << endl;
                cout << "Masukan Nama Daerah Baru: ";
                cin >> newname;

                d->info.namaDaerah = newname;
                cout << "[DATA BERHASIL DIUBAH!]" << endl;
                return;
            }
            d = d->next;
        }
        p = p->next;
    }

    cout << "Maaf , data '" << nama << "'Tidak ditemukan di provinsi maupun didaerah manapun." << endl;

} /*Search provinsi dulu, kalau null lanjut ke search Daerah*/
void deleteData(listProvinsi &L, string nama){
    adrProvinsi p = L.first;
    while (p != nullptr){
        if (p->info.namaProvinsi == nama){
            p->next->prev = p->prev;
            p->prev->next = p->next;
            p->next = nullptr;
            p->prev = nullptr;
            deleteAllChild(p);
            return;
        }
        p = p->next;
    }
    p = L.first;
    while (p != nullptr){
        adrDaerah d = p->firstDaerah;

        while(d != nullptr){
            if (d->info.namaDaerah == nama){
                d->next->prev = d->prev;
                d->prev->next = d->next;
                d->next = nullptr;
                d->prev = nullptr;
                cout << "[DATA BERHASIL DIHAPUS!]" << endl;
                return;
            }
            d = d->next;
        }
        p = p->next;
    }
    cout << "Maaf , data '" << nama << "'Tidak ditemukan di provinsi maupun didaerah manapun." << endl;
}
int totalPopulasi(adrDaerah d){
    return d->info.populasiDewasa + d->info.populasiAnak;
}
int isPenuh(adrDaerah d){
    int kepadatanPenduduk = 0;
    kepadatanPenduduk = totalPopulasi(d) / d->info.luasWilayah;
    if (kepadatanPenduduk <= 50){
        return 1;
    } else if ((kepadatanPenduduk > 50) && (kepadatanPenduduk <= 250)){
        return 2;
    } else if ((kepadatanPenduduk > 250) && (kepadatanPenduduk <= 500)){
        return 3;
    } else if ((kepadatanPenduduk > 500) && (kepadatanPenduduk <= 1000)){
        return 4;
    } else {
        return 5;
    }
}
float gajiRataRata(adrDaerah d){ 
    int totalGaji = 0;
    float gajiRataRata = 0;
    totalGaji = (d->info.pendapatan4juta * 4000000) + (d->info.pendapatan3juta * 3000000) + (d->info.pendapatan2juta * 2000000) + (d->info.pendapatan1juta * 1000000);
    gajiRataRata = float(totalGaji) / d->info.populasiDewasa;
    return gajiRataRata;
}
bool isPoor(adrDaerah d){
    return gajiRataRata(d) < 3000000;
}