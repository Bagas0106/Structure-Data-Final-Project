#include "MLL.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip> // Library untuk mengatur format angka

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
    adrDaerah q;
    if (p->firstDaerah == nullptr){
        p->firstDaerah = d;
    }else {
        q = p->firstDaerah;
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
    if (p == nullptr){
        cout << "Tidak ada Provinsi" << endl;
    } else {
        while (p != nullptr){
            cout << "Nama Provinsi           : " << p->info.namaProvinsi << endl;
            cout << "Nama Ibukota            : " << p->info.ibuKota << endl;
            cout << "Zona Watu               : " << p->info.zonaWaktu << endl;
            cout << "Pertumbuhan Ekonomi (%) : " << p->info.pertumbuhanEkonomi << endl;
            cout << endl;
            p = p->next;
        }
        cout << endl;
    }
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
            cout << "Provinsi " << p->info.namaProvinsi << endl << endl;
            if (q == nullptr){
                cout << "Tidak ada Daerah" << endl;
            }
            while (q != nullptr){
                cout << "Nama Daerah    :" << q->info.namaDaerah << endl;
                cout << "Tipe Daerah    :" << q->info.tipeWilayah << endl;
                cout << "Tipe Dewasa    :" << q->info.populasiDewasa << endl;
                cout << "Tipe Anak      :" << q->info.populasiAnak << endl;
                cout << "Populasi       :" << q->info.populasi << endl;
                cout << "Luas Wilayah   :" << q->info.luasWilayah << endl;
                cout << "Gaji Rata Rata :" << fixed << setprecision(0) << q->info.gajiRataRata << endl;
                if (q->info.isPenuh == 1){
                    cout << "Kepadatan      : Sangat Rendah" << endl;
                } else if (q->info.isPenuh == 2){
                    cout << "Kepadatan      : Rendah" << endl;
                } else if (q->info.isPenuh == 3){
                    cout << "Kepadatan      : Sedang" << endl;
                } else if (q->info.isPenuh == 4){
                    cout << "Kepadatan      : Padat" << endl;
                } else if (q->info.isPenuh == 5){
                    cout << "Kepadatan      : Sangat Rendah" << endl << endl;
                }
                cout << endl;
                q = q->next;
            }
            p = p->next;
            cout << endl << endl;
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
            cout << "Nama Daerah    :" << q->info.namaDaerah << endl;
            cout << "Tipe Daerah    :" << q->info.tipeWilayah << endl;
            cout << "Tipe Dewasa    :" << q->info.populasiDewasa << endl;
            cout << "Tipe Anak      :" << q->info.populasiAnak << endl;
            cout << "Populasi       :" << q->info.populasi << endl;
            cout << "Luas Wilayah   :" << q->info.luasWilayah << endl;
            cout << "Gaji Rata Rata :" << fixed << setprecision(0) << q->info.gajiRataRata << endl;
            if (q->info.isPenuh == 1){
                cout << "Kepadatan      : Sangat Rendah" << endl;
            } else if (q->info.isPenuh == 2){
                cout << "Kepadatan      : Rendah" << endl;
            } else if (q->info.isPenuh == 3){
                cout << "Kepadatan      : Sedang" << endl;
            } else if (q->info.isPenuh == 4){
                cout << "Kepadatan      : Padat" << endl;
            } else if (q->info.isPenuh == 5){
                cout << "Kepadatan      : Sangat Rendah" << endl;
            }
            cout << endl;
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
                infoP tempp = ptr->info;
                ptr->info = ptr->next->info;
                ptr->next->info = tempp;

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

                infoP tempp = ptr->info;
                ptr->info = ptr->next->info;
                ptr->next->info = tempp;

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
            cout << "[PROVINSI DITEMUKAN!] " << nama <<endl;
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
                cout << "[DAERAH DITEMUKAN!] " << nama << " Diprovinsi " << p->info.namaProvinsi << endl;
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

}
void deleteData(listProvinsi &L, string nama) {
    adrProvinsi p = L.first;
    while (p != nullptr) {
        if (p->info.namaProvinsi == nama) {
            if (p == L.first && p == L.last) {
                L.first = nullptr;
                L.last = nullptr;
            } else if (p == L.first) {
                L.first = p->next;
                L.first->prev = nullptr;
            } else if (p == L.last) {
                L.last = p->prev;
                L.last->next = nullptr;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            p->firstDaerah = nullptr;
            delete p;
            cout << "[PROVINSI BERHASIL DIHAPUS!]" << endl;
            return;
        }
        p = p->next;
    }

    p = L.first;
    while (p != nullptr) {
        adrDaerah d = p->firstDaerah;
        while (d != nullptr) {
            if (d->info.namaDaerah == nama) {
                if (d == p->firstDaerah) {
                    p->firstDaerah = d->next;
                    if (p->firstDaerah != nullptr) p->firstDaerah->prev = nullptr;
                } else {
                    d->prev->next = d->next;
                    if (d->next != nullptr) d->next->prev = d->prev;
                }
                delete d;
                cout << "[DAERAH BERHASIL DIHAPUS!]" << endl;
                return;
            }
            d = d->next;
        }
        p = p->next;
    }
    cout << "Data tidak ditemukan." << endl;
}
int totalPopulasi(adrDaerah d){
    return d->info.populasiDewasa + d->info.populasiAnak;
}
int ispenuh(adrDaerah d){
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
float gajiratarata(adrDaerah d){
    long long totalGaji = 0;
    float gajiRataRata = 0;

    totalGaji = ( (long long)d->info.pendapatan4juta * 4000000LL) + ( (long long)d->info.pendapatan3juta * 3000000LL) + ( (long long)d->info.pendapatan2juta * 2000000LL) + ( (long long)d->info.pendapatan1juta * 1000000LL);

    if (d->info.populasiDewasa > 0) {
        gajiRataRata = (float)totalGaji / d->info.populasiDewasa;
    }
    return gajiRataRata;
}
bool isPoor(adrDaerah d){
    return gajiratarata(d) < 3000000;
}

void menu(){
    clearScreen();
    cout << "============================================================" << endl;
    cout << "         SISTEM INFORMASI STATISTIK EKONOMI PROVINSI        " << endl;
    cout << "============================================================" << endl;
    cout << "1.Tampilkan Data All                                        " << endl;
    cout << "2.Tambah Provinsi                                           " << endl;
    cout << "3.Tambah Daerah                                             " << endl;
    cout << "4.Cari Provinsi                                             " << endl;
    cout << "5.Cari Daerah                                               " << endl;
    cout << "6.Mengurutkan Provinsi ascending berdasarkan Alphabet       " << endl;
    cout << "7.Mengurutkan Provinsi decending berdasarkan Alphabet       " << endl;
    cout << "8.Edit data (Provinsi maupun Daerah)                        " << endl;
    cout << "9.Delete Data                                               " << endl; // Opsi 1 Semua Provinsi, 2 Satu Provinsi, Opsi 3 Ke Menu Utama
    cout << "10.Tampilkan Gaji Rata Rata (Tiap Provinsi)                 " << endl; // Opsi 1 Urutkan Opsi 2 Ke Menu Utama
    cout << "11.Urutkan Kota Berdasarkan Pendapatan                      " << endl;
    cout << "12.Tampilkan Provinsi berdasarkan Kepadatan                 " << endl; // Opsi 1 Sangat Padat, 2 Padat, 3 Sedang, Rendah, Sangat Rendah
    cout << "13.Program Pemerintah (Special Event)                       " << endl;
    cout << "0.exit                                                      " << endl;
    cout << "============================================================" << endl << endl;

}
void programPemerintah(adrDaerah d) {
    if (d == nullptr) return;
    int totalDiBracket;
    int pengangguran;

    cout << "Pemerintah menjalankan program peningkatan ekonomi di " << d->info.namaDaerah << "..." << endl;

    while (isPoor(d)) {
        if (d->info.pendapatan1juta > 0) {
            d->info.pendapatan4juta += d->info.pendapatan1juta;
            d->info.pendapatan1juta = 0;
        } else if (d->info.pendapatan2juta > 0) {
            d->info.pendapatan4juta += d->info.pendapatan2juta;
            d->info.pendapatan2juta = 0;
        } else if (d->info.pendapatan3juta > 0) {
            d->info.pendapatan4juta += d->info.pendapatan3juta;
            d->info.pendapatan3juta = 0;
        } else {
            break;
        }
    }
    d->info.gajiRataRata = gajiratarata(d);

    if (!isPoor(d)) {
        cout << "[BERHASIL] Target tercapai. Gaji rata-rata sekarang: " << fixed << setprecision(0) << d->info.gajiRataRata << endl;
    } else {
        cout << "[GAGAL] Sumber daya tidak cukup untuk mengangkat rata-rata di atas 3 juta." << endl;
        Sleep(1500);
        cout << "UPAYA TERAKHIR: Pemerintah membuka lapangan kerja masif untuk pengangguran (Gaji 2 Juta)..." << endl;

        totalDiBracket = d->info.pendapatan1juta + d->info.pendapatan2juta + d->info.pendapatan3juta + d->info.pendapatan4juta;
        pengangguran = d->info.populasiDewasa - totalDiBracket;

        if (pengangguran > 0) {
            d->info.pendapatan2juta += pengangguran;
            d->info.gajiRataRata = gajiratarata(d);

            if (!isPoor(d)) {
                cout << "[BERHASIL AKHIR] Dengan mempekerjakan " << pengangguran << " pengangguran, target tercapai!" << endl;
            } else {
                cout << "[GAGAL TOTAL] Bahkan setelah mempekerjakan semua orang, rata-rata tetap di bawah 3 juta." << endl;
            }
        } else {
            cout << "Tidak ada pengangguran (semua penduduk dewasa sudah memiliki pekerjaan)." << endl;
            cout << "Namun tetap tida bisa diselamatkan " << endl;
        }
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
            if (gajiratarata(d) < gajiratarata(d->next)) {

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

adrDaerah printPoor(adrDaerah d){
    if (d != nullptr){
        cout << "Nama Kota : " << d->info.namaDaerah << endl;
        cout << "Pendapatan Rata Rata: " << fixed << setprecision(0) << d->info.gajiRataRata << endl << endl;
        return printPoor(d->next);
    } else {
        return nullptr;
    }
}


void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void printSatuProvinsi(adrProvinsi p){
    cout << "Nama Provinsi           : " << p->info.namaProvinsi << endl;
    cout << "Nama Ibu Kota           : " << p->info.ibuKota << endl;
    cout << "Zona Waktu              : " << p->info.zonaWaktu << endl;
    cout << "Pertumbuhan Ekonomi (%) : " << p->info.pertumbuhanEkonomi << endl;
    cout << endl;

    printDaerah(p);
}

adrDaerah printKepadatan(adrDaerah d){
    if (d != nullptr){
        cout << "Nama Kota : " << d->info.namaDaerah << endl;
        if (d->info.isPenuh == 1){
            cout << "Kepadatan      : Sangat Rendah" << endl;
        } else if (d->info.isPenuh == 2){
            cout << "Kepadatan      : Rendah" << endl;
        } else if (d->info.isPenuh == 3){
            cout << "Kepadatan      : Sedang" << endl;
        } else if (d->info.isPenuh == 4){
            cout << "Kepadatan      : Padat" << endl;
        } else if (d->info.isPenuh == 5){
            cout << "Kepadatan      : Sangat Rendah" << endl;
        }
        cout << endl;
        return printKepadatan(d->next);
    } else {
        return nullptr;
    }
}
