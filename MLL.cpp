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
        d->prev = q;
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
        temp = temp->next;
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
    adrProvinsi p = L.first;
    while (p != nullptr){
        adrDaerah d = p->firstDaerah;
        while (d != nullptr){
            if (d->info.namaDaerah == daerah){
                return d;
            }
            d = d->next;
        }
        p = p->next;
    }
    return nullptr;
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

void menu(){
    cout << "============================================================";
    cout << "1.Tambah Provinsi                                           ";
    cout << "2.Tambah Daerah                                             ";
    cout << "3.Mencari nama IbuKota berdasarkan Nama Kota                ";
    cout << "4.Mengurutkan ascending berdasarkan Alphabet                ";
    cout << "5.Mengurutkan decending berdasarkan Alphabet                 ";
    cout << "6.Edit data                                                 ";
    cout << "7.Delete Data                                               ";
    cout << "8.exit                                                      ";

}
void programPemerintah(adrDaerah d){
    cout << "Pemerintah membuka lowongan kerja (19 juta) di bidang Industrialisasi & Investasi Sektor Teknologi" << endl;
    int temp;
    if (isPoor(d)){
        temp = d->info.pendapatan1juta;
        d->info.pendapatan1juta = d->info.pendapatan1juta - temp;
        d->info.pendapatan2juta += temp;
    }
    if (isPoor(d)){
        cout << "Program Pemerintah belum berhasil, Pemerintah berusaha memberikan pendidikan lebih tinggi buat masyarakat yang sebelumnya berpendapat 1 juta" << endl;
        d->info.pendapatan2juta = d->info.pendapatan2juta - temp;
        d->info.pendapatan3juta += temp;
    }
    if (isPoor(d)){
        cout << "Program Pemerintah masih belum berhasil juga. Pemerintah memutuskan untuk memberikan pendidikan tinggi buat masyarakat berpenghasilan 2 juta" << endl;
        temp = d->info.pendapatan2juta;
        d->info.pendapatan2juta = d->info.pendapatan2juta - temp;
        d->info.pendapatan3juta += temp;
    } else {
        cout << "Masyarakat tidak bisa diselamatan" << endl;
    }
}

void sortByPendapatan(adrProvinsi p) {
    if (p == nullptr || p->firstDaerah == nullptr) {
        cout << "Tidak ada data daerah untuk diurutkan." << endl;
        return;
    }

    bool tukar;
    adrDaerah d;
    adrDaerah last = nullptr;

    while (tukar) {
        tukar = false;
        d = p->firstDaerah;

        while (d->next != last) {
            if (gajiRataRata(d) < gajiRataRata(d->next)) {

                infoD tempInfo = d->info;
                d->info = d->next->info;
                d->next->info = tempInfo;

                tukar = true;
            }
            d = d->next;
        }
        last = d;
    }

    cout << "Daerah di " << p->info.namaProvinsi << " berhasil diurutkan berdasarkan pendapatan tertinggi." << endl;
}

void loadDummyData(listProvinsi &L) {
    adrProvinsi p;
    infoP ip;
    infoD id;

    // --- 1. DKI JAKARTA (6 Daerah) ---
    ip = {"DKI Jakarta", "Jakarta Pusat", "WIB", 4.8};
    p = createElmProvinsi(ip); addProvinsi(L, p);
    addDaerah(p, createElmDaerah({"Jakarta Pusat", "Kota", 0, 0, 48, 100, 200, 300, 400, 50, 50}));
    addDaerah(p, createElmDaerah({"Jakarta Utara", "Kota", 0, 0, 146, 200, 300, 400, 100, 100, 100}));
    addDaerah(p, createElmDaerah({"Jakarta Timur", "Kota", 0, 0, 188, 300, 400, 300, 200, 150, 150}));
    addDaerah(p, createElmDaerah({"Jakarta Selatan", "Kota", 0, 0, 141, 150, 200, 500, 600, 80, 80}));
    addDaerah(p, createElmDaerah({"Jakarta Barat", "Kota", 0, 0, 129, 250, 350, 450, 150, 120, 120}));
    addDaerah(p, createElmDaerah({"Kepulauan Seribu", "Kabupaten", 0, 0, 8, 50, 50, 30, 20, 40, 40}));

    // --- 2. JAWA BARAT (10 Daerah) ---
    ip = {"Jawa Barat", "Bandung", "WIB", 5.4};
    p = createElmProvinsi(ip); addProvinsi(L, p);
    addDaerah(p, createElmDaerah({"Bandung", "Kota", 0, 0, 167, 400, 150, 150, 200, 100, 100}));
    addDaerah(p, createElmDaerah({"Bekasi", "Kota", 0, 0, 210, 600, 100, 100, 300, 400, 150}));
    addDaerah(p, createElmDaerah({"Depok", "Kota", 0, 0, 200, 500, 120, 130, 250, 200, 100}));
    addDaerah(p, createElmDaerah({"Bogor", "Kota", 0, 0, 118, 450, 150, 150, 200, 100, 120}));
    addDaerah(p, createElmDaerah({"Sukabumi", "Kabupaten", 0, 0, 4145, 800, 400, 200, 100, 50, 300}));
    addDaerah(p, createElmDaerah({"Cianjur", "Kabupaten", 0, 0, 3840, 750, 500, 150, 50, 50, 350}));
    addDaerah(p, createElmDaerah({"Karawang", "Kabupaten", 0, 0, 1652, 700, 100, 100, 400, 300, 200}));
    addDaerah(p, createElmDaerah({"Cirebon", "Kota", 0, 0, 37, 300, 100, 100, 150, 50, 50}));
    addDaerah(p, createElmDaerah({"Garut", "Kabupaten", 0, 0, 3074, 900, 600, 200, 50, 50, 400}));
    addDaerah(p, createElmDaerah({"Tasikmalaya", "Kota", 0, 0, 171, 400, 200, 150, 50, 0, 150}));

    // --- 3. JAWA TENGAH (10 Daerah) ---
    ip = {"Jawa Tengah", "Semarang", "WIB", 5.1};
    p = createElmProvinsi(ip); addProvinsi(L, p);
    addDaerah(p, createElmDaerah({"Semarang", "Kota", 0, 0, 373, 600, 100, 200, 300, 200, 150}));
    addDaerah(p, createElmDaerah({"Surakarta", "Kota", 0, 0, 44, 400, 50, 150, 200, 100, 100}));
    addDaerah(p, createElmDaerah({"Magelang", "Kota", 0, 0, 18, 150, 30, 50, 70, 50, 40}));
    addDaerah(p, createElmDaerah({"Salatiga", "Kota", 0, 0, 56, 180, 20, 60, 100, 50, 50}));
    addDaerah(p, createElmDaerah({"Pekalongan", "Kota", 0, 0, 45, 250, 80, 120, 100, 20, 60}));
    addDaerah(p, createElmDaerah({"Tegal", "Kota", 0, 0, 38, 200, 70, 130, 80, 20, 50}));
    addDaerah(p, createElmDaerah({"Banyumas", "Kabupaten", 0, 0, 1327, 850, 400, 300, 100, 50, 300}));
    addDaerah(p, createElmDaerah({"Cilacap", "Kabupaten", 0, 0, 2142, 900, 300, 300, 200, 100, 400}));
    addDaerah(p, createElmDaerah({"Brebes", "Kabupaten", 0, 0, 1769, 1000, 600, 300, 100, 0, 500}));
    addDaerah(p, createElmDaerah({"Kudus", "Kabupaten", 0, 0, 425, 450, 50, 100, 200, 200, 100}));

    // --- 4. JAWA TIMUR (10 Daerah) ---
    ip = {"Jawa Timur", "Surabaya", "WIB", 5.2};
    p = createElmProvinsi(ip); addProvinsi(L, p);
    addDaerah(p, createElmDaerah({"Surabaya", "Kota", 0, 0, 350, 900, 50, 150, 400, 500, 200}));
    addDaerah(p, createElmDaerah({"Malang", "Kota", 0, 0, 110, 500, 50, 100, 300, 150, 100}));
    addDaerah(p, createElmDaerah({"Batu", "Kota", 0, 0, 199, 200, 20, 80, 100, 50, 40}));
    addDaerah(p, createElmDaerah({"Kediri", "Kota", 0, 0, 63, 250, 30, 70, 150, 100, 60}));
    addDaerah(p, createElmDaerah({"Madiun", "Kota", 0, 0, 33, 180, 20, 60, 100, 50, 40}));
    addDaerah(p, createElmDaerah({"Blitar", "Kota", 0, 0, 32, 160, 30, 70, 60, 40, 40}));
    addDaerah(p, createElmDaerah({"Mojokerto", "Kota", 0, 0, 16, 140, 20, 50, 70, 30, 30}));
    addDaerah(p, createElmDaerah({"Pasuruan", "Kota", 0, 0, 36, 180, 40, 80, 60, 20, 50}));
    addDaerah(p, createElmDaerah({"Probolinggo", "Kota", 0, 0, 56, 200, 60, 100, 40, 20, 60}));
    addDaerah(p, createElmDaerah({"Sidoarjo", "Kabupaten", 0, 0, 714, 800, 100, 200, 300, 300, 200}));

    // --- 5. BALI (5 Daerah) ---
    ip = {"Bali", "Denpasar", "WITA", 5.0};
    p = createElmProvinsi(ip); addProvinsi(L, p);
    addDaerah(p, createElmDaerah({"Denpasar", "Kota", 0, 0, 127, 500, 20, 80, 250, 250, 100}));
    addDaerah(p, createElmDaerah({"Badung", "Kabupaten", 0, 0, 418, 450, 10, 50, 200, 300, 100}));
    addDaerah(p, createElmDaerah({"Gianyar", "Kabupaten", 0, 0, 368, 400, 50, 100, 150, 150, 120}));
    addDaerah(p, createElmDaerah({"Tabanan", "Kabupaten", 0, 0, 839, 350, 100, 150, 100, 50, 150}));
    addDaerah(p, createElmDaerah({"Buleleng", "Kabupaten", 0, 0, 1365, 500, 200, 200, 100, 50, 250}));

    // --- 6. PAPUA (9 Daerah) ---
    ip = {"Papua", "Jayapura", "WIT", 2.5};
    p = createElmProvinsi(ip); addProvinsi(L, p);
    addDaerah(p, createElmDaerah({"Jayapura", "Kota", 0, 0, 940, 400, 150, 150, 100, 50, 100}));
    addDaerah(p, createElmDaerah({"Mimika", "Kabupaten", 0, 0, 21693, 600, 100, 100, 200, 300, 200}));
    addDaerah(p, createElmDaerah({"Merauke", "Kabupaten", 0, 0, 44071, 350, 200, 100, 50, 50, 150}));
    addDaerah(p, createElmDaerah({"Biak Numfor", "Kabupaten", 0, 0, 2602, 300, 200, 100, 20, 10, 120}));
    addDaerah(p, createElmDaerah({"Jayawijaya", "Kabupaten", 0, 0, 7030, 450, 350, 100, 20, 10, 200}));
    addDaerah(p, createElmDaerah({"Nabire", "Kabupaten", 0, 0, 11112, 320, 200, 100, 30, 10, 150}));
    addDaerah(p, createElmDaerah({"Keerom", "Kabupaten", 0, 0, 8390, 250, 180, 50, 20, 0, 100}));
    addDaerah(p, createElmDaerah({"Sarmi", "Kabupaten", 0, 0, 17742, 150, 100, 40, 10, 0, 80}));
    addDaerah(p, createElmDaerah({"Waropen", "Kabupaten", 0, 0, 10977, 120, 100, 20, 0, 0, 60}));

    cout << "--- [SYSTEM] 50 Data Daerah Berhasil Dimuat! ---" << endl;
}
