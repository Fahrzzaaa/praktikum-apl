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
    if (*jumlah >= 100) {
        cout << "Kapasitas penuh!\n";
        return;
    }

    cout << "Masukkan Merk Skincare: ";
    cin >> (lemari + *jumlah)->merk;

    cout << "Masukkan jumlah stok: ";
    cin >> (lemari + *jumlah)->stok;

    (*jumlah)++;
    cout << "Produk berhasil ditambahkan.\n";
}

void tambahStok(Skincare *lemari, int jumlah) {
    int nomor, tambah;

    cout << "Pilih nomor produk: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= jumlah) {
        cout << "Tambah stok: ";
        cin >> tambah;
        (lemari + nomor - 1)->stok += tambah;
        cout << "Stok berhasil ditambahkan.\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

void kurangiStok(Skincare *lemari, int jumlah) {
    int nomor, kurang;

    cout << "Pilih nomor produk: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= jumlah) {
        cout << "Kurangi stok: ";
        cin >> kurang;

        if (kurang <= (lemari + nomor - 1)->stok) {
            (lemari + nomor - 1)->stok -= kurang;
            cout << "Stok berhasil dikurangi.\n";
        } else {
            cout << "Stok tidak cukup.\n";
        }
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

void hapusProduk(Skincare *lemari, int *jumlah) {
    int hapus;

    cout << "Masukkan nomor produk: ";
    cin >> hapus;

    if (hapus > 0 && hapus <= *jumlah) {
        for (int i = hapus - 1; i < *jumlah - 1; i++) {
            *(lemari + i) = *(lemari + i + 1);
        }
        (*jumlah)--;
        cout << "Produk berhasil dihapus.\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

int totalStokRekursif(Skincare *lemari, int n) {
    if (n == 0) return 0;
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
    cout << "udah urut yaww.\n";
}

void sortingStokAscending(Skincare *lemari, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if ((lemari + j)->stok < (lemari + minIndex)->stok) {
                minIndex = j;
            }
        }
        Skincare temp = *(lemari + i);
        *(lemari + i) = *(lemari + minIndex);
        *(lemari + minIndex) = temp;
    }
    cout << "Stok kecil ke besar.\n";
}

void merge(Skincare *lemari, int left, int mid, int right) {
    Skincare L[100], R[100];
    int n1 = mid - left + 1;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) L[i] = lemari[left + i];
    for (int j = 0; j < n2; j++) R[j] = lemari[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].merk <= R[j].merk) lemari[k++] = L[i++];
        else lemari[k++] = R[j++];
    }

    while (i < n1) lemari[k++] = L[i++];
    while (j < n2) lemari[k++] = R[j++];
}

void mergeSort(Skincare *lemari, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(lemari, left, mid);
        mergeSort(lemari, mid + 1, right);
        merge(lemari, left, mid, right);
    }
}

void sortingMerkAscending(Skincare *lemari, int jumlah) {
    mergeSort(lemari, 0, jumlah - 1);
    cout << "udah urut yaww.\n";
}

void linearSearchMerk(Skincare *lemari, int jumlah, string cari) {
    for (int i = 0; i < jumlah; i++) {
        if ((lemari + i)->merk == cari) {
            cout << "Ditemukan di posisi ke-" << i + 1 << endl;
            cout << "Merk: " << (lemari + i)->merk << endl;
            cout << "Stok: " << (lemari + i)->stok << endl;
            return;
        }
    }
    cout << "Produk tidak ditemukan.\n";
}

int binarySearchStok(Skincare *lemari, int jumlah, int cari) {
    int kiri = 0, kanan = jumlah - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if ((lemari + tengah)->stok == cari) return tengah;
        else if ((lemari + tengah)->stok < cari) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}

int main() {
    User user = {"Dava_imoet", "100"};
    string inputNama, inputNim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\n===== LOGIN =====\n";
        cout << "Nama nya siapa yaaaa : ";
        cin >> inputNama;
        cout << "3 angka di blakang nim berapa  : ";
        cin >> inputNim;

        if (login(&user, &inputNama, &inputNim)) {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login gagal yaww!\n";
            cout << "Sisa percobaan: " << 3 - percobaan - 1 << endl;
        }
        percobaan++;
    }

    if (percobaan == 3) return 0;

    Skincare lemari[100] = {
        {"Glad2Glow",39},{"TheOriginote",40},{"Skintific",37},
        {"Wardah",28},{"Implora",28},{"Nuface",26},
        {"Scarlett",35},{"Emina",12},{"Azarine",33},
        {"Facetology",31},{"Npure",42}
    };

    int jumlah = 11, pilihan;

    do {
        cout << "\n=========================================\n";
        cout << "         MENU UTAMA GUDANG SKINCARE\n";
        cout << "=========================================\n";

        cout << left << setw(5) << "No" << "Fitur\n";
        cout << "-----------------------------------------\n";

        cout << setw(5) << "1"  << "Tambah Produk\n";
        cout << setw(5) << "2"  << "Lihat Produk\n";
        cout << setw(5) << "3"  << "Tambah Stok\n";
        cout << setw(5) << "4"  << "Kurangi Stok\n";
        cout << setw(5) << "5"  << "Hapus Produk\n";
        cout << setw(5) << "6"  << "urutkan Merk (Z-A)\n";
        cout << setw(5) << "7"  << "urutkan stok yang mau habis\n";
        cout << setw(5) << "8"  << "urutkan Merk (A-Z)\n";
        cout << setw(5) << "9"  << "Cari Merk\n";
        cout << setw(5) << "10" << "Cari Stok\n";
        cout << setw(5) << "11" << "Keluar\n";

        cout << "=========================================\n";
        cout << "Pilih menu (1-11): ";
        cin >> pilihan;

        if (pilihan == 1) tambahProduk(lemari, &jumlah);
        else if (pilihan == 2) {
            lihatProduk(lemari, jumlah);
            cout << "Total stok: " << totalStokRekursif(lemari, jumlah) << endl;
        }
        else if (pilihan == 3) tambahStok(lemari, jumlah);
        else if (pilihan == 4) kurangiStok(lemari, jumlah);
        else if (pilihan == 5) hapusProduk(lemari, &jumlah);
        else if (pilihan == 6) sortingMerkDescending(lemari, jumlah);
        else if (pilihan == 7) sortingStokAscending(lemari, jumlah);
        else if (pilihan == 8) sortingMerkAscending(lemari, jumlah);
        else if (pilihan == 9) {
            string cari;
            cout << "Cari merk skincare: ";
            cin >> cari;
            linearSearchMerk(lemari, jumlah, cari);
        }
        else if (pilihan == 10) {
            int cari;
            cout << "Cari stok skincare: ";
            cin >> cari;
            sortingStokAscending(lemari, jumlah);
            int hasil = binarySearchStok(lemari, jumlah, cari);

            if (hasil != -1)
                cout << "Ditemukan: " << (lemari + hasil)->merk << " - " << (lemari + hasil)->stok << endl;
            else
                cout << "Tidak ditemukan.\n";
        }

    } while (pilihan != 11);

    cout << "Terima kasih udah pakai program aku, kasi nilai 100 yahh.\n";
}

