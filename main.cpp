#include "mll.h"
#include <iostream>
#include <cstdlib>
#include <iomanip> // Library untuk mengatur format angka
#include <windows.h>

using namespace std;

int main(){
    //deklarasi
    int masukkan = 1;
    int i;
    int i2;
    listProvinsi L;
    string masukkanString;

    //deklarasi provinsi
    string namaProvinsi;
    string ibuKota; //nampilin data ibuKota
    string zonaWaktu;
    float pertumbuhanEkonomi;

    //deklarasi daerah
    string namaDaerah;
    string tipeWilayah;
    int populasi; // belum diset (set di main panggil totalPopulasi)
    float gajiRataRata; // belum diset (set di main panggil gajiRataRata)
    int luasWilayah; //cek kepadatan penduduk
    int populasiDewasa;
    int populasiAnak;
    int pendapatan4juta;
    int pendapatan3juta;
    int pendapatan2juta;
    int pendapatan1juta;
    int isPenuh;

    createListProvinsi(L);
    // masukkan data
    infoP infoProvinsi;
    infoD infoDaerah;
    adrProvinsi p;
    adrDaerah d;
    for (i=1; i<= 38; i++){
        cin >> infoProvinsi.namaProvinsi;
        cin >> infoProvinsi.ibuKota;
        cin >> infoProvinsi.zonaWaktu;
        cin >> infoProvinsi.pertumbuhanEkonomi;
        p = createElmProvinsi(infoProvinsi);
        for (i2 = 1; i2 <= 5; i2++){
            populasi = 0;
            gajiRataRata = 0;
            isPenuh = 0;
            cin >> infoDaerah.namaDaerah;
            cin >> infoDaerah.tipeWilayah;
            cin >> infoDaerah.luasWilayah;
            cin >> infoDaerah.populasiDewasa;
            cin >> infoDaerah.populasiAnak;
            cin >> infoDaerah.pendapatan1juta;
            cin >> infoDaerah.pendapatan2juta;
            cin >> infoDaerah.pendapatan3juta;
            cin >> infoDaerah.pendapatan4juta;
            d = createElmDaerah(infoDaerah);
            d->info.populasi = totalPopulasi(d);
            d->info.gajiRataRata = gajiratarata(d);
            d->info.isPenuh = ispenuh(d);
            addDaerah(p , d);
        }
        addProvinsi(L, p);
    }


    while (masukkan != 0){
        menu();
        cout << "Masukkan angka: ";
        cin >> masukkan;
        switch(masukkan){
            case 1:
                printDaerahAll(L);
                break;
            case 2:
                cout << "Masukkan Nama Provinsi : ";
                cin >> infoProvinsi.namaProvinsi;
                p = searchProvinsi(L, infoProvinsi.namaProvinsi);
                if (p != nullptr){
                    cout << "Provinsi Sudah ada" << endl;
                } else {
                    cout << "Masukkan Nama Ibukota : ";
                    cin >> infoProvinsi.ibuKota;
                    cout << "Masukkan Nama Zona Waktu : ";
                    cin >> infoProvinsi.zonaWaktu;
                    cout << "Masukkan Pertumbuhan Ekonomi (%) : ";
                    cin >> infoProvinsi.pertumbuhanEkonomi;
                    p = createElmProvinsi(infoProvinsi);
                    addProvinsi(L, p);
                }
                break;
            case 3:
                cout << "Masukan Provinsi yang ingin dimasukin      : ";
                cin >> masukkanString;
                p = searchProvinsi(L, masukkanString);
                populasi = 0;
                gajiRataRata = 0;
                isPenuh = 0;
                cout << "Masukkan Data" << endl;
                cout << "Masukkan Nama Daerah                       :";
                cin >> infoDaerah.namaDaerah;
                cout << "Masukkan Tipe Wilayah                      :";
                cin >> infoDaerah.tipeWilayah;
                cout << "Masukkan Luas Wilayah                      :";
                cin >> infoDaerah.luasWilayah;
                cout << "Masukkan Populasi Dewasa                   :";
                cin >> infoDaerah.populasiDewasa;
                cout << "Masukkan Populasi Anak                     :";
                cin >> infoDaerah.populasiAnak;
                cout << "Masukkan Banyak Orang berpendapatan 1 juta :";
                cin >> infoDaerah.pendapatan1juta;
                cout << "Masukkan Banyak Orang berpendapatan 2 juta :";
                cin >> infoDaerah.pendapatan2juta;
                cout << "Masukkan Banyak Orang berpendapatan 3 juta :";
                cin >> infoDaerah.pendapatan3juta;
                cout << "Masukkan Banyak Orang berpendapatan 4 juta :";
                cin >> infoDaerah.pendapatan4juta;
                d = createElmDaerah(infoDaerah);
                d->info.populasi = totalPopulasi(d);
                d->info.gajiRataRata = gajiratarata(d);
                d->info.isPenuh = ispenuh(d);
                addDaerah(p , d);
                break;
            case 4:
                printProvinsi(L);
                cout << "Masukan Provinsi yang ingin dicari      : ";
                cin >> masukkanString;
                p = searchProvinsi(L, masukkanString);
                if (p == nullptr){
                    cout << "Provinsi Tidak Ditemukan" << endl;
                } else {
                    printSatuProvinsi(p);
                }
                break;
            case 5:
                printDaerahAll(L);
                cout << "Masukan Daerah yang ingin dicari : ";
                cin >> masukkanString;
                d = searchDaerah(L, masukkanString);
                if (d == nullptr){
                    cout << "Daerah Tidak Ditemukan! " << endl;
                } else {
                    cout << "Nama Daerah    :" << d->info.namaDaerah << endl;
                    cout << "Tipe Daerah    :" << d->info.tipeWilayah << endl;
                    cout << "Tipe Dewasa    :" << d->info.populasiDewasa << endl;
                    cout << "Tipe Anak      :" << d->info.populasiAnak << endl;
                    cout << "Populasi       :" << d->info.populasi << endl;
                    cout << "Luas Wilayah   :" << d->info.luasWilayah << endl;
                    cout << "Gaji Rata Rata :" << fixed << setprecision(0) << d->info.gajiRataRata << endl;
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
                }
                cout << endl;
                break;
            case 6:
                cout << "Sebelum Di Sort: " << endl;
                printProvinsi(L);
                sortAscending(L);
                cout << "Sesudah Di Sort: " << endl;
                printProvinsi(L);
                break;
            case 7:
                cout << "Sebelum Di Sort: " << endl;
                printProvinsi(L);
                sortDescending(L);
                cout << "Sesudah Di Sort: " << endl;
                printProvinsi(L);
                break;
            case 8:
                cout << "Masukan Nama yang ingin diubah      : ";
                cin >> masukkanString;
                editData(L, masukkanString);
                printDaerahAll(L);
                break;
            case 9:
                cout << "Masukkan Nama yang ingin dihapus : " << endl;
                cin >> masukkanString;
                deleteData(L, masukkanString);
                break;
            case 10:
                cout << "Masukkan Provinsi yang ingin dilihat : ";
                cin >> masukkanString;
                p = searchProvinsi(L, masukkanString);
                printPoor(p->firstDaerah);
                break;
            case 11:
                cout << "Masukkan Provinsi yang ingin Urutkan : ";
                cin >> masukkanString;
                p = searchProvinsi(L, masukkanString);
                sortByPendapatan(p);
                printPoor(p->firstDaerah);
                break;
            case 12:
                cout << "Masukkan Provinsi yang ingin dilihat : ";
                cin >> masukkanString;
                p = searchProvinsi(L, masukkanString);
                printKepadatan(p->firstDaerah);
                break;
            case 13:
                cout << "Masukkan Kota yang ingin Diberi Program Pemerintah : ";
                cin >> masukkanString;
                d = searchDaerah(L, masukkanString);
                programPemerintah(d);
                d->info.gajiRataRata = gajiratarata(d);
                cout << "Nama Daerah    :" << d->info.namaDaerah << endl;
                cout << "Tipe Daerah    :" << d->info.tipeWilayah << endl;
                cout << "Tipe Dewasa    :" << d->info.populasiDewasa << endl;
                cout << "Tipe Anak      :" << d->info.populasiAnak << endl;
                cout << "Populasi       :" << d->info.populasi << endl;
                cout << "Luas Wilayah   :" << d->info.luasWilayah << endl;
                cout << "Gaji Rata Rata :" << fixed << setprecision(0) << d->info.gajiRataRata << endl;
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
                break;
            case 0:
                cout << "Terimakasih" << endl;
                break;
            default:
                cout << "Pilihat Tidak Valid! Harap perhatikan Menu" << endl;
        }
        if (masukkan != 0){
            cout << "\n";
            system("pause"); // Tahan layar sebelum clear Screen
        }
    }

    return 0;
}

