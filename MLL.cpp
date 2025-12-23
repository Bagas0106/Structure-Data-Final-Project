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
void addDaerah(listProvinsi &L, adrDaerah p){
    adrDaerah q = nullptr;
    adrProvinsi miko = L.first;
    if (miko->firstDaerah == nullptr){
        miko->firstDaerah = p;
    } else {
        q = miko->firstDaerah;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = p;
        p->prev = q;
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
            cout << "[DAERAH DITEMUKAN!]" << nama << "Diprovinsi " << p->info.namaProvinsi << endl;
            cout << "Masukan Nama Daerah Baru: ";
            cin >> newname;

            d->info.namaDaerah = newname;
            cout << "[DATA BERHASIL DIUBAH!]" << endl;
            return;
        }
        d = d->next
    }
    p = p->next;

    cout << "Maaf , data '" << nama << "'Tidak ditemukan di provinsi maupun didaerah manapun." << endl;

} /*Search provinsi dulu, kalau null lanjut ke search Daerah*/
void deleteData(listProvinsi &L, string nama){
    
}
bool isPoor(adrProvinsi p){

}