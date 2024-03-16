# Evaluasi Kinerja Algoritma Pengurutan

Repository ini berisi kode C untuk mengevaluasi kinerja tiga algoritma pengurutan: Bubble Sort, Selection Sort, dan Insertion Sort. Kode tersebut menghasilkan angka acak, mengurutkannya menggunakan setiap algoritma, mengukur waktu eksekusi, dan menyimpan hasilnya ke dalam file teks.

## Cara Menjalankan Kode

1. Pastikan Anda telah menginstal compiler C pada sistem Anda.
2. Clone repositori ini atau unduh file `2208107010052_Simple_Sorting.c`.
3. Kompilasi kode menggunakan perintah berikut:

   ```bash
   gcc 2208107010052_Simple_Sorting.c -o sorting_algorithms
   ```

4. Jalankan executable yang telah dikompilasi:

   ```bash
   ./sorting_algorithms
   ```

## Fungsi-fungsi

### `generateRandomNumbers`

Fungsi ini mengisi sebuah array dengan angka acak menggunakan fungsi `rand()`.

Parameter:

- `array`: Array yang akan diisi dengan angka acak.
- `size`: Ukuran dari array yang akan diisi.
- `seed`: Seed untuk fungsi `srand()`.

### `bubbleSort`

Fungsi ini mengurutkan sebuah array menggunakan algoritma Bubble Sort.

Parameter:

- `array`: Array yang akan diurutkan.
- `size`: Ukuran array.

### `selectionSort`

Fungsi ini mengurutkan sebuah array menggunakan algoritma Selection Sort.

Parameter:

- `array`: Array yang akan diurutkan.
- `size`: Ukuran array.

### `insertionSort`

Fungsi ini mengurutkan sebuah array menggunakan algoritma Insertion Sort.

Parameter:

- `array`: Array yang akan diurutkan.
- `size`: Ukuran array.

### `saveToFile`

Fungsi ini menyimpan sebuah array ke dalam file teks.

Parameter:

- `filename`: Nama file tujuan.
- `array`: Array yang akan disimpan.
- `size`: Ukuran array.
- `type`: Tipe array ("unsorted" untuk sebelum pengurutan, "sorted" untuk setelah pengurutan).
- `sort_type`: Algoritma pengurutan yang digunakan.

## Fungsi Utama

Fungsi `main` digunakan untuk menguji kinerja dari algoritma pengurutan. Ini mengevaluasi waktu eksekusi dari setiap algoritma untuk ukuran array mulai dari 100,000 hingga 1,000,000 dengan peningkatan sebesar 100,000.

## Lisensi

Kode dalam repository ini dilisensikan di bawah [MIT License](LICENSE).
