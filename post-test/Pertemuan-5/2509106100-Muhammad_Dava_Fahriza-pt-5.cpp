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

bool login(User *akun, string *nama, string *nim) {
    return akun->nama == *nama && akun->nim == *nim;
}

void lihatProduk(Skincare *lemari, int jumlah) {
    cout << "\n=====================================\n";
    cout << "       DAFTAR MERK SKINCARE\n";
    cout << "=====================================\n";

    cout << left << setw(10) << "No"
         << setw(15) << "Merk"
         << setw(10) << "Stok" << endl;

    cout << "-------------------------------------\n";

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(10) << i + 1
             << setw(15) << (lemari + i)->merk
             << setw(10) << (lemari + i)->stok << endl;
    }

    cout << "=====================================\n";
}

void tambahProduk(Skincare *lemari, int *jumlah) {
    cout << "\nMasukkan Merk Skincare: ";
    cin >> (lemari + *jumlah)->merk;

    cout << "mau masukan produk apa niehh: ";
    cin >> (lemari + *jumlah)->stok;

    (*jumlah)++;

    cout << "Produk udah di tambahkan yaww.\n";
}

void tambahStok(Skincare *lemari, int jumlah) {
    int nomor, tambah;

    cout << "Pilih nomor produk: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= jumlah) {
        cout << "mau nambah berapa stok niehh: ";
        cin >> tambah;

        (lemari + nomor - 1)->stok += tambah;

        cout << "Stok udah di tambahkan yaww.\n";
    } else {
        cout << "Nomor produk tidak valid.\n";
    }
}

void kurangiStok(Skincare *lemari, int jumlah) {
    int nomor, kurang;

    cout << "Pilih nomor produk : ";
    cin >> nomor;

    if (nomor > 0 && nomor <= jumlah) {
        cout << "Mau kurangi brp stok niehh: ";
        cin >> kurang;

        if (kurang <= (lemari + nomor - 1)->stok) {
            (lemari + nomor - 1)->stok -= kurang;
            cout << "Stok udah di kurangin yaww.\n";
        } else {
            cout << "Stok tidak mencukupi.\n";
        }
    } else {
        cout << "Nomor produk tidak valid.\n";
    }
}

void hapusProduk(Skincare *lemari, int *jumlah) {
    int hapus;

    cout << "Masukkan nomor produk yang ingin dihapus: ";
    cin >> hapus;

    if (hapus > 0 && hapus <= *jumlah) {
        for (int i = hapus - 1; i < *jumlah - 1; i++) {
            *(lemari + i) = *(lemari + i + 1);
        }

        (*jumlah)--;

        cout << "Produk udah di hapus yaww.\n";
    } else {
        cout << "Nomor produk tidak valid.\n";
    }
}

int totalStokRekursif(Skincare *lemari, int n) {
    if (n == 0)
        return 0;

    return (lemari + n - 1)->stok + totalStokRekursif(lemari, n - 1);
}

void sortingMerkDescending(Skincare *lemari, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((lemari + j)->merk < (lemari + j + 1)->merk) {
                Skincare temp = *(lemari + j);
                *(lemari + j) = *(lemari + j + 1);
                *(lemari + j + 1) = temp;
            }
        }
    }
    cout << "udah terurut ya mulai dari huruf z.\n";
}

void sortingStokAscending(Skincare *lemari, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((lemari + j)->stok > (lemari + j + 1)->stok) {
                Skincare temp = *(lemari + j);
                *(lemari + j) = *(lemari + j + 1);
                *(lemari + j + 1) = temp;
            }
        }
    }
    cout << "Stok yang mau habis udh di urutkan yaww.\n";
}

void sortingMerkAscending(Skincare *lemari, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((lemari + j)->merk > (lemari + j + 1)->merk) {
                Skincare temp = *(lemari + j);
                *(lemari + j) = *(lemari + j + 1);
                *(lemari + j + 1) = temp;
            }
        }
    }
    cout << "udah terurut ya mulai dari huruf A.\n";
}

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

        if (login(&user, &inputNama, &inputNim)) {
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

    Skincare lemari[100] = {
        {"Glad2Glow", 39},
        {"TheOriginote", 40},
        {"Skintific", 37},
        {"Wardah", 28},
        {"Implora", 28},
        {"Nuface", 26},
        {"Scarlett", 35},
        {"Emina", 12},
        {"Azarine", 33},
        {"Facetology", 31},
        {"Npure", 42}
    };

    int jumlah = 11;
    int pilihan;

    do {
        cout << "\n===== SISTEM GUDANG SKINCARE =====\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Lihat Paket Skincare\n";
        cout << "3. Menambah Stok Produk\n";
        cout << "4. Mengurangi Stok Produk\n";
        cout << "5. Hapus Merek Skincare\n";
        cout << "6. Urutakn merek skincare mulai dari huruf Z\n";
        cout << "7. Urutkan jumlah sotok yang mau habis\n";
        cout << "8. Urutakn merek skincare mulai dari huruf A\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambahProduk(lemari, &jumlah);
        }
        else if (pilihan == 2) {
            lihatProduk(lemari, jumlah);
            cout << "Total semua stok (rekursif): "
                 << totalStokRekursif(lemari, jumlah) << endl;
        }
        else if (pilihan == 3) {
            tambahStok(lemari, jumlah);
        }
        else if (pilihan == 4) {
            kurangiStok(lemari, jumlah);
        }
        else if (pilihan == 5) {
            hapusProduk(lemari, &jumlah);
        }
        else if (pilihan == 6) {
            sortingMerkDescending(lemari, jumlah);
        }
        else if (pilihan == 7) {
            sortingStokAscending(lemari, jumlah);
        }
        else if (pilihan == 8) {
            sortingMerkAscending(lemari, jumlah);
        }

    } while (pilihan != 9);

    cout << "\nmakasihhh yaaa udah pakai sistem akuuu lopyuuu.\n";

    return 0;
}