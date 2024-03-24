#include <stdio.h>

//mendeklarasikan sebuah struct yang bertipe integer
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

int isTahunKabisat(int tahun) { //deklarasi fungsi
    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) { //digunakan untuk menentukan apakah tahun tersebut adalah tahun kabisat atau tidak
        return 1; //jika memenuhi salah satu dari kondisi, fungsi akan mengembalikan nilai 1, menandakan bahwa tahun tersebut adalah tahun kabisat
    }
    return 0; //jika tidak memenuhi kedua kondisi, maka fungsi akan mengembalikan nilai 0, menandakan bahwa tahun tersebut bukanlah tahun kabisat
}

struct Tanggal hitungTanggalBerikutnya(struct Tanggal tanggalSekarang) { //deklarasi fungsi
    int jumlahHariDalamBulan[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //untuk menyimpan jumlah hari setiap bulan
    
    if (tanggalSekarang.bulan == 2 && isTahunKabisat(tanggalSekarang.tahun)) { //digunakan untuk mengecek apakah bulan saat ini adalah februari dan tahun nya adalah tahun kabisat
        jumlahHariDalamBulan[2] = 29; //jika benar maka jumlah hari dalam bulan ferbuari menjadi 29
    }
    
    tanggalSekarang.hari++; //hari dalam 'tanggalSekarang' ditambah satu sehingga menghasilkan tanggal berikutnya
    
    if (tanggalSekarang.hari > jumlahHariDalamBulan[tanggalSekarang.bulan]) { //untuk memeriksa apakah nilai 'hari' dalam 'tanggalSekarang' lebih besar dari jumlah hari dalam bulan yang sedang diproses
        tanggalSekarang.hari = 1; //jika hari dalam 'tanggalSekarang' melebihi jumlah hari dalam bulan, maka atur kembali nilai 'hari' menjadi 1
        tanggalSekarang.bulan++; //mengatur tanggal kembali menjadi 1, nilai bulan dalam 'tanggalSekarang' ditingkatkan satu
        
        if (tanggalSekarang.bulan > 12) { //untuk memeriksa apakah nilai bulan 12 sudah melebihi 12, yang menandakan bahwa kita sudah mencapai bulan desember dan perlu beralih ke tahun berikutnya
            tanggalSekarang.bulan = 1; //jika nilai bulan melebihi 12, maka kita atur kembali nilai bulan menjadi 1, menandakan bahwa sudah memasuki bulan pertama dalam tahun baru
            tanggalSekarang.tahun++; //menaikkan nilai tahun dalam 'tanggalSekarang', menandakan bahwa sudah memasuki tahun berikutnya setelah melewati bulan desember
        }
    }
    
    return tanggalSekarang; //untuk mengembalikan nilai dari variabel 'tanggalSekarang' setelah proses perhitungan tanggal berikutnya selesai dilakukan
}

int main() {
    struct Tanggal tanggalSekarang, tanggalBerikutnya; //untuk menyimpan tanggal yang dimasukkan dan menyimpan tanggal berikutnya yang dihitung oleh program
    
    printf("Masukkan tanggal : "); //perintah untuk memasukkan tanggal
    scanf("%d/%d/%d", &tanggalSekarang.hari, &tanggalSekarang.bulan, &tanggalSekarang.tahun); //berfungsi untuk untuk membaca input dari pengguna berupa tanggal yang dimasukkan dalam format "hari/bulan/tahun", lalu menyimpan nilainya ke dalam variabel 'tanggalSekarang'
    
    tanggalBerikutnya = hitungTanggalBerikutnya(tanggalSekarang); //berfungsi menghitung tanggal berikutnya berdasarkan tanggal yang dimasukkan
    
    printf("Tanggal berikutnya : %d/%d/%d\n", tanggalBerikutnya.hari, tanggalBerikutnya.bulan, tanggalBerikutnya.tahun); //untuk mengoutputkan tanggal berikutnya yang telah dihitung oleh program
    
    return 0; //program selesai
}
