#include <iostream>
#include <iomanip>
using namespace std;

struct User {
    string nama;
    string nim;
};
  
struct Skincare {
    string merk;
    int stok;
};

int main() {

    User user = {"Dava_imoet", "100"};
    string inputNama, inputNim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "===== LOGIN GUDANG SKINCARE =====\n";
        cout << "Namanya Siapa ? : ";
        cin >> inputNama;
        cout << "Nim nya berapa ? : ";
        cin >> inputNim;
    
        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "\nLogin berhasil!\n";
            break;
        } else {
            cout << "Login gagal!\n";
            percobaan++;
        }
    }

    if (percobaan == 3) {
        cout << "\nAnda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    Skincare lemari[100];

    lemari[0] = {"Glad2Glow", 39};
    lemari[1] = {"The Originote", 40};
    lemari[2] = {"Skintific", 37};
    lemari[3] = {"Wardah", 28};
    lemari[4] = {"Implora", 28};
    lemari[5] = {"Nuface", 26};
    lemari[6] = {"Scarlett", 35};
    lemari[7] = {"Emina", 12};
    lemari[8] = {"Azarine", 33};
    lemari[9] = {"Facetology", 31};
    lemari[10] = {"Npure", 42};

    int jumlah = 11;
    int pilihan;

    do {
        cout << "\n===== SISTEM GUDANG SKINCARE =====\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Lihat Paket Skincare\n";
        cout << "3. Menambah Stok Produk\n";
        cout << "4. Mengurangi Stok Produk\n";
        cout << "5. Hapus Merek Skincare\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {

            cout << "\nMasukkan Merk Skincare: ";
            cin >> lemari[jumlah].merk;

            cout << "Masukkan Stok Produk: ";
            cin >> lemari[jumlah].stok;

            jumlah++;

            cout << "Produk berhasil ditambahkan.\n";
        }

        else if (pilihan == 2) {

            cout << "\n=====================================\n";
            cout << "       DAFTAR MERK SKINCARE\n";
            cout << "=====================================\n";

            cout << left << setw(10) << "No"
                 << setw(15) << "Merk"
                 << setw(10) << "Stok" << endl;

            cout << "-------------------------------------\n";

            for (int i = 0; i < jumlah; i++) {

                cout << left << setw(10) << i + 1
                     << setw(15) << lemari[i].merk
                     << setw(10) << lemari[i].stok << endl;
            }

            cout << "=====================================\n";
        }

        else if (pilihan == 3) {

            int nomor, tambah;

            cout << "Pilih nomor produk: ";
            cin >> nomor;

            if (nomor > 0 && nomor <= jumlah) {

                cout << "Masukkan jumlah stok yang ditambahkan: ";
                cin >> tambah;

                lemari[nomor - 1].stok += tambah;

                cout << "Stok berhasil ditambahkan.\n";

            } else {

                cout << "Nomor produk tidak valid.\n";

            }
        }

        else if (pilihan == 4) {

            int nomor, kurang;

            cout << "Pilih nomor produk: ";
            cin >> nomor;

            if (nomor > 0 && nomor <= jumlah) {

                cout << "Masukkan jumlah stok yang dikurangi: ";
                cin >> kurang;

                if (kurang <= lemari[nomor - 1].stok) {

                    lemari[nomor - 1].stok -= kurang;

                    cout << "Stok berhasil dikurangi.\n";

                } else {

                    cout << "Stok tidak mencukupi.\n";

                }

            } else {

                cout << "Nomor produk tidak valid.\n";

            }
        }

        else if (pilihan == 5) {

            int hapus;

            cout << "Masukkan nomor produk yang ingin dihapus: ";
            cin >> hapus;

            if (hapus > 0 && hapus <= jumlah) {

                for (int i = hapus - 1; i < jumlah - 1; i++) {
                    lemari[i] = lemari[i + 1];
                }

                jumlah--;

                cout << "Produk berhasil dihapus.\n";

            } else {

                cout << "Nomor produk tidak valid.\n";

            }
        }

    } while (pilihan != 6);

    cout << "\nTerima kasih telah menggunakan sistem.\n";

    return 0;
}