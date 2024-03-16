/*
 * @author Ganang Setyo Hadi
 * NPM 2208107010052
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

/*
 * FUNCTION: generateRandomNumbers
 *
 * DESCRIPTION:
 * Fungsi ini mengisi array dengan bilangan acak menggunakan fungsi rand().
 *
 * PARAMETERS:
 * array  = Array yang akan diisi dengan bilangan acak.
 * size   = Ukuran array yang akan diisi.
 * seed   = Seed untuk fungsi srand().
 *
 * ALGORITHM:
 * - Menggunakan fungsi srand() untuk mengatur seed generator bilangan acak berdasarkan nilai seed.
 * - Loop dari i = 0 hingga size - 1.
 *   - Setiap iterasi, array[i] diisi dengan bilangan acak menggunakan fungsi rand().
 */

void generateRandomNumbers(int array[], int size, int seed)
{
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}

/*
 * FUNCTION: bubbleSort
 *
 * DESCRIPTION:
 * Fungsi ini mengurutkan array menggunakan algoritma Bubble Sort.
 *
 * PARAMETERS:
 * array = Array yang akan diurutkan.
 * size  = Ukuran array.
 *
 * ALGORITHM:
 * - Loop dari i = 0 hingga size - 2 (inklusif).
 *   - Di dalam loop i, loop dari j = 0 hingga size - i - 2 (inklusif).
 *     - Bandingkan array[j] dengan array[j + 1].
 *     - Jika array[j] > array[j + 1], tukar nilai keduanya.
 * - Setelah loop selesai, array akan terurut secara ascending.
 */

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/*
 * FUNCTION: selectionSort
 *
 * DESCRIPTION:
 * Fungsi ini mengurutkan array menggunakan algoritma Selection Sort.
 *
 * PARAMETERS:
 * array = Array yang akan diurutkan.
 * size  = Ukuran array.
 *
 * ALGORITHM:
 * - Loop dari i = 0 hingga size - 2 (inklusif).
 *   - Di dalam loop i, cari indeks nilai minimum di antara array[i] hingga array[size - 1].
 *     - Simpan indeks nilai minimum pada min_index.
 *   - Tukar nilai array[i] dengan nilai minimum yang ditemukan.
 * - Setelah loop selesai, array akan terurut secara ascending.
 */

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

/*
 * FUNCTION: insertionSort
 *
 * DESCRIPTION:
 * Fungsi ini mengurutkan array menggunakan algoritma Insertion Sort.
 *
 * PARAMETERS:
 * array = Array yang akan diurutkan.
 * size  = Ukuran array.
 *
 * ALGORITHM:
 * - Loop dari i = 1 hingga size - 1 (inklusif).
 *   - Simpan array[i] pada key.
 *   - Tentukan j = i - 1.
 *   - Selama j >= 0 dan array[j] > key, lakukan:
 *     - Geser array[j] ke posisi array[j + 1].
 *     - Kurangi nilai j.
 *   - Tempatkan key pada posisi array[j + 1].
 * - Setelah loop selesai, array akan terurut secara ascending.
 */

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

/*
 * FUNCTION: saveToFile
 *
 * DESCRIPTION:
 * Fungsi ini menyimpan array ke dalam file teks.
 *
 * PARAMETERS:
 * filename   = Nama file tujuan.
 * array      = Array yang akan disimpan.
 * size       = Ukuran array.
 * type       = Jenis array ("unsorted" untuk array sebelum diurutkan, "sorted" untuk array setelah diurutkan).
 * sort_type  = Jenis pengurutan yang digunakan.
 *
 * ALGORITHM:
 * - Buka file dengan mode "a" (append).
 * - Jika file gagal dibuka, tampilkan pesan kesalahan dan kembalikan.
 * - Jika jenis array adalah "unsorted", tulis informasi ukuran array dan jenis pengurutan ke file.
 * - Jika jenis array adalah "sorted", tulis informasi jenis array ke file.
 * - Tulis elemen-elemen array ke file.
 * - Tutup file.
 */

void saveToFile(char *filename, int array[], int size, char *type, char *sort_type)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    if (type == "unsorted")
    {
        fprintf(file, "Ukuran angka %d\n", size);
        fprintf(file, "%s:\n", sort_type);
        fprintf(file, "Angka Tidak Terurut : ");
    }
    else if (type == "sorted")
    {
        fprintf(file, "Angka Terurut : ");
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", array[i]);
    }
    fprintf(file, "\n");

    fclose(file);
}

/*
 * FUNCTION: main
 *
 * DESCRIPTION:
 * Fungsi utama untuk menguji performa dari algoritma sorting (Bubble Sort, Selection Sort, Insertion Sort).
 * Algoritma sorting diuji untuk ukuran array mulai dari 100,000 hingga 1,000,000 dengan penambahan 100,000 setiap iterasi.
 * Waktu eksekusi dari setiap algoritma sorting dicatat dan ditampilkan.
 * Selain itu, hasil array sebelum dan setelah diurutkan disimpan ke dalam file "numbers.txt".
 *
 * ALGORITHM:
 * - Inisialisasi array numbers dengan ukuran MAX_SIZE.
 * - Tetapkan ukuran awal array (size) ke 100,000.
 * - Loop untuk setiap algoritma sorting (Bubble Sort, Selection Sort, Insertion Sort):
 *     - Cetak header untuk jenis algoritma, jumlah bilangan, dan waktu eksekusi.
 *     - Mengukur waktu eksekusi dengan clock sebelum dan setelah pengurutan.
 *     - Tampilkan waktu eksekusi dalam milidetik.
 *     - Simpan array (sebelum dan sesudah diurutkan) ke dalam file "numbers.txt".
 *     - Lakukan pengujian untuk ukuran array dari 100,000 hingga 1,000,000 dengan penambahan 100,000 setiap iterasi:
 *         - Buat array baru untuk setiap iterasi.
 *         - Ulangi langkah-langkah di atas untuk array yang baru.
 * - Kembalikan 0.
 */
int main()
{
    int numbers[MAX_SIZE];
    int size = 100000;
    int seed = time(NULL); // Menggunakan waktu saat ini sebagai seed untuk pembuatan angka acak

    // Membuat angka acak sekali di awal
    generateRandomNumbers(numbers, MAX_SIZE, seed);

    printf("----------------------------------------------------------------------------------\n");
    printf("||Jenis Algoritma\t|| Jumlah Bilangan\t|| Waktu Eksekusi (ms)\t\t||\n");
    printf("----------------------------------------------------------------------------------\n");

    for (int i = 0; i < 10; i++) // 10 iterasi untuk menguji dari 100,000 hingga 1,000,000 dengan penambahan 100,000 setiap iterasi
    {
        clock_t start, end;
        double cpu_time_used;

        // Melakukan pengujian untuk Bubble Sort
        start = clock();
        bubbleSort(numbers, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        if (size == 100000)
        {
            printf("||Bubble Sort\t\t|| %d\t\t|| %.2f\t\t\t||\n", size, cpu_time_used);
            printf("||                      ----------------------------------------------------------\n");
        }
        else if (size == 1000000)
        {
            printf("||                      || %d\t\t|| %.2f\t\t\t||\n", size, cpu_time_used);
            printf("----------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("||                      || %d\t\t|| %.2f\t\t\t||\n", size, cpu_time_used);
            printf("||                      ----------------------------------------------------------\n");
        }

        saveToFile("numbers.txt", numbers, size, "unsorted", "Bubble Sort");
        saveToFile("numbers.txt", numbers, size, "sorted", "Bubble Sort");

        size += 100000; // Meningkatkan ukuran array untuk iterasi selanjutnya
    }

    // Mengatur ulang ukuran array ke nilai awal
    size = 100000;
    for (int i = 0; i < 10; i++)
    {
        clock_t start, end;
        double cpu_time_used;

        // Melakukan pengujian untuk Selection Sort
        start = clock();
        selectionSort(numbers, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        if (size == 100000)
        {
            printf("||Selection Sort        || %d\t\t|| %.2f\t\t\t||\n", size, cpu_time_used);
            printf("||                      ----------------------------------------------------------\n");
        }
        else if (size == 1000000)
        {
            printf("||                      || %d\t\t|| %.2f\t\t\t||\n", size, cpu_time_used);
            printf("----------------------------------------------------------------------------------\n");
        }

        else
        {
            printf("||                      || %d\t\t|| %.2f\t\t\t||\n", size, cpu_time_used);
            printf("||                      ----------------------------------------------------------\n");
        }

        saveToFile("numbers.txt", numbers, size, "unsorted", "Selection Sort");
        saveToFile("numbers.txt", numbers, size, "sorted", "Selection Sort");

        size += 100000;
    }

    // Mengatur ulang ukuran array ke nilai awal
    size = 100000;
    for (int i = 0; i < 10; i++)
    {
        clock_t start, end;
        double cpu_time_used;

        // Melakukan pengujian untuk Insertion Sort
        start = clock();
        insertionSort(numbers, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        if (size == 100000)
        {
            printf("||Insertion Sort        || %d\t\t|| %.2f\t\t\t\t||\n", size, cpu_time_used);
            printf("||                      ----------------------------------------------------------\n");
        }
        else if (size == 1000000)
        {
            printf("||                      || %d\t\t|| %.2f\t\t\t\t||\n", size, cpu_time_used);
            printf("----------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("||                      || %d\t\t|| %.2f\t\t\t\t||\n", size, cpu_time_used);
            printf("||                      ----------------------------------------------------------\n");
        }

        saveToFile("numbers.txt", numbers, size, "unsorted", "Insertion Sort");
        saveToFile("numbers.txt", numbers, size, "sorted", "Insertion Sort");

        size += 100000;
    }
    return 0;
}
