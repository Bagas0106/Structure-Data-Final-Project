#include "MLL.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void tampilkanMenu() {
    cout << "\n============================================================" << endl;
    cout << "     SISTEM INFORMASI STATISTIK EKONOMI PROVINSI           " << endl;
    cout << "============================================================" << endl;
    cout << "1. Tambah Provinsi" << endl;
    cout << "2. Tambah Daerah (ke Provinsi tertentu)" << endl;
    cout << "3. Tampilkan Semua Data (Provinsi & Daerah)" << endl;
    cout << "4. Urutkan Provinsi (A-Z)" << endl;
    cout << "5. Urutkan Provinsi (Z-A)" << endl;
    cout << "6. Urutkan Daerah Berdasarkan Pendapatan (Terbesar)" << endl;
    cout << "7. Jalankan Program Pemerintah (Naikkan Pendapatan)" << endl;
    cout << "8. Cari Ibu Kota" << endl;
    cout << "9. Edit Data" << endl;
    cout << "10. Hapus Data" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    listProvinsi L;
    createListProvinsi(L);

    int pilihan;
    string namaP, namaD, cari;
    adrProvinsi p;
    adrDaerah d;

    loadDummyData(L);

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer setelah input angka

        switch (pilihan) {
            case 1: {
                infoP ip;
                cout << "Nama Provinsi: "; getline(cin, ip.namaProvinsi);
                cout << "Ibu Kota: "; getline(cin, ip.ibuKota);
                cout << "Zona Waktu (WIB/WITA/WIT): "; getline(cin, ip.zonaWaktu);
                cout << "Pertumbuhan Ekonomi (%): "; cin >> ip.pertumbuhanEkonomi;
                addProvinsi(L, createElmProvinsi(ip));
                cout << "[Berhasil Menambahkan Provinsi]" << endl;
                break;
            }

            case 2: {
                cout << "Masukkan Nama Provinsi tujuan: "; getline(cin, namaP);
                p = searchProvinsi(L, namaP);
                if (p != nullptr) {
                    infoD id;
                    cout << "Nama Daerah: "; getline(cin, id.namaDaerah);
                    cout << "Tipe (Kota/Kabupaten): "; getline(cin, id.tipeWilayah);
                    cout << "Luas Wilayah (km2): "; cin >> id.luasWilayah;
                    cout << "Populasi Anak: "; cin >> id.populasiAnak;
                    cout << "Populasi Dewasa: "; cin >> id.populasiDewasa;
                    cout << "Jumlah Pendapatan 1jt: "; cin >> id.pendapatan1juta;
                    cout << "Jumlah Pendapatan 2jt: "; cin >> id.pendapatan2juta;
                    cout << "Jumlah Pendapatan 3jt: "; cin >> id.pendapatan3juta;
                    cout << "Jumlah Pendapatan 4jt: "; cin >> id.pendapatan4juta;
                    addDaerah(p, createElmDaerah(id));
                    cout << "[Berhasil Menambahkan Daerah]" << endl;
                } else {
                    cout << "Provinsi tidak ditemukan!" << endl;
                }
                break;
            }

            case 3:
                cout << "\n--- DATA SELURUH PROVINSI & DAERAH ---" << endl;
                p = L.first;
                while (p != nullptr) {
                    cout << "\nPROVINSI: " << p->info.namaProvinsi << " (Ibu Kota: " << p->info.ibuKota << ")" << endl;
                    d = p->firstDaerah;
                    if (d == nullptr) {
                        cout << "  [Belum ada data daerah]" << endl;
                    } else {
                        while (d != nullptr) {
                            cout << "  > " << d->info.namaDaerah << " | Rata-rata Gaji: Rp"
                                 << fixed << setprecision(0) << gajiRataRata(d)
                                 << " | Status: " << (isPoor(d) ? "MISKIN" : "SEJAHTERA") << endl;
                            d = d->next;
                        }
                    }
                    p = p->next;
                }
                break;

            case 4:
                sortAscending(L);
                cout << "[Provinsi diurutkan A-Z]" << endl;
                break;

            case 5:
                sortDescending(L);
                cout << "[Provinsi diurutkan Z-A]" << endl;
                break;

            case 6:
                cout << "Masukkan Nama Provinsi: "; getline(cin, namaP);
                p = searchProvinsi(L, namaP);
                if (p != nullptr) {
                    sortByPendapatan(p);
                    printDaerah(p);
                } else {
                    cout << "Provinsi tidak ditemukan!" << endl;
                }
                break;

            case 7:
                cout << "Masukkan Nama Daerah yang ingin dibantu: "; getline(cin, namaD);
                d = searchDaerah(L, namaD);
                if (d != nullptr) {
                    cout << "Kondisi Sebelum Program: Rp" << gajiRataRata(d) << " (" << (isPoor(d) ? "MISKIN" : "SEJAHTERA") << ")" << endl;
                    programPemerintah(d);
                    cout << "Kondisi Sesudah Program: Rp" << gajiRataRata(d) << " (" << (isPoor(d) ? "MISKIN" : "SEJAHTERA") << ")" << endl;
                } else {
                    cout << "Daerah tidak ditemukan!" << endl;
                }
                break;

            case 8:
                cout << "Cari Ibu Kota dari Provinsi: "; getline(cin, namaP);
                p = searchProvinsi(L, namaP);
                if (p != nullptr) {
                    cout << "Ibu Kota " << namaP << " adalah: " << p->info.ibuKota << endl;
                }
                break;

            case 9:
                cout << "Masukkan Nama (Provinsi/Daerah) yang ingin diedit: "; getline(cin, cari);
                editData(L, cari);
                break;

            case 10:
                cout << "Masukkan Nama (Provinsi/Daerah) yang ingin dihapus: "; getline(cin, cari);
                deleteData(L, cari);
                break;

            case 0:
                cout << "Keluar dari program..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
