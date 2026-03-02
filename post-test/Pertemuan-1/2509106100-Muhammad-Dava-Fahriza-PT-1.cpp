#include <iostream>
using namespace std;

int main() {
    string nama, pass;
    int salah = 0;

    cout << "=================================\n";
    cout << "         SISTEM LOGIN            \n";
    cout << "=================================\n";

    while (salah < 3) {
        cout << "\nNamanya siapa ya?        : ";
        cin >> nama;
        cout << "Password 3 digit NIM kamu : ";
        cin >> pass;

        if (nama == "Dava_imut" && pass == "100") {
            cout << "\nLogin berhasil! Selamat datang \n";
            break;
        } else {
            salah++;
            cout << "Login salah! Sisa kesempatan: "
                 << 3 - salah << "\n";
        }
    }

    if (salah == 3) {
        cout << "\nAnda gagal login 3 kali.\n";
        cout << "Program berhenti.\n";
        return 0;
    }

    int pilih;

    do {
        cout << "\n=================================\n";
        cout << "        MENU KONVERSI WAKTU      \n";
        cout << "=================================\n";
        cout << "1. Jam    -> Menit & Detik\n";
        cout << "2. Menit  -> Jam & Detik\n";
        cout << "3. Detik  -> Jam & Menit\n";
        cout << "4. Keluar\n";
        cout << "---------------------------------\n";
        cout << "Pilih menu (1-4) : ";
        cin >> pilih;

        if (pilih == 1) {
            int jam;
            cout << "\nMasukkan jumlah jam : ";
            cin >> jam;

            cout << "\nHasil Konversi:\n";
            cout << jam << " jam = "
                 << jam * 60 << " menit dan "
                 << jam * 3600 << " detik\n";
        }

        else if (pilih == 2) {
            int menit;
            cout << "\nMasukkan jumlah menit : ";
            cin >> menit;

            cout << "\nHasil Konversi:\n";
            cout << menit << " menit = "
                 << menit / 60 << " jam dan "
                 << menit * 60 << " detik\n";
        }

        else if (pilih == 3) {
            int detik;
            cout << "\nMasukkan jumlah detik : ";
            cin >> detik;

            cout << "\nHasil Konversi:\n";
            cout << detik << " detik = "
                 << detik / 3600 << " jam dan "
                 << detik / 60 << " menit\n";
        }

        else if (pilih == 4) {
            cout << "\nTerima kasih telah menggunakan program ini \n";
        }

        else {
            cout << "\nPilihan tidak tersedia!\n";
        }

    } while (pilih != 4);

    return 0;
}