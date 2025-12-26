#include "mll.h"
#include <iostream>
#include <cstdlib>
#include <iomanip> // Library untuk mengatur format angka

using namespace std;

int main(){
    //deklarasi
    int masukkan = 1;
    int i;
    int i2;
    listProvinsi L;

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
        cout << endl;
        switch(masukkan){
            case 1:
                printDaerahAll(L);
                break;
            case 2:
                cout << "Masukkan Nama Provinsi :";
                cin >> infoProvinsi.namaProvinsi;
                cout << "Masukkan Nama Ibukota :";
                cin >> infoProvinsi.ibuKota;
                cout << "Masukkan Nama Ibukota :";
                cin >> infoProvinsi.zonaWaktu;
                cin >> infoProvinsi.pertumbuhanEkonomi;
                p = createElmProvinsi(infoProvinsi);
                addProvinsi(L, p);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
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

