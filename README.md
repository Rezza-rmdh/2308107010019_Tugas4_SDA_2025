# 2308107010019_Tugas4_SDA_2025

Nama : Rezza Ramadhana
NPM : 2308107010019

Kode ini adalah implementasi program untuk mengukur kinerja berbagai algoritma sorting, seperti Bubble Sort, Selection Sort, dan
lainnya, pada data angka atau kata dengan ukuran yang bervariasi. Program dimulai dengan mendeklarasikan variabel untuk menyimpan
ukuran data, tipe data (angka/kata), waktu eksekusi, serta cadangan data. Dalam perulangan utama, pengguna diberikan pilihan jenis data
(angka atau kata) dan ukuran data yang ingin diurutkan. Berdasarkan pilihan, program membaca data dari file yang relevan. Setelah data
diimpor, data utama disimpan sebagai cadangan agar setiap algoritma dapat dijalankan pada kondisi data yang sama.

Selanjutnya, program menjalankan masing-masing algoritma sorting, dimulai dengan mengembalikan data ke kondisi aslinya dari cadangan
sebelum setiap algoritma dijalankan. Waktu eksekusi untuk setiap algoritma dihitung menggunakan fungsi clock() dan hasilnya dicetak
dalam format detik. Jika pengguna memilih data berupa kata, kode menggunakan array 2D untuk menyimpan string, dan algoritma sorting
menyesuaikan dengan operasi string. Setelah semua algoritma selesai dijalankan, memori yang digunakan dibebaskan dengan fungsi free().
Program ini juga memiliki opsi untuk keluar dari menu jika pengguna memilihnya, memastikan penggunaan memori yang efisien dan operasi
yang sesuai dengan input pengguna.
