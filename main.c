// include header
#include "Header.h"

int main() {
    // Deklarasi variabel
    int size, *data, *backupData; // Ukuran data dan pointer untuk data serta cadangan
    clock_t start, end;           // Variabel untuk mengukur waktu eksekusi
    double cpu_time_used;         // Variabel untuk menyimpan hasil waktu eksekusi
    int dataChoice;               // Pilihan jenis data

    while (dataChoice != 3) {
        // Menampilkan menu untuk memilih jenis data
        printf("Masukkan data yang ingin diurutkan:\n");
        printf("1. Sorting Angka (data_angka.txt)\n");
        printf("2. Sorting Kata (data_kata.txt)\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &dataChoice);

        if (dataChoice == 3) {
            printf("Program keluar. Terima kasih!\n");
            break;
        }

        // Memilih file berdasarkan jenis data
        const char *filename = (dataChoice == 1) ? "data_angka.txt" : "data_kata.txt";

        // Menampilkan menu untuk memilih jumlah data
        printf("\nMasukkan jumlah data yang ingin diurutkan:\n");
        printf("1. 10,000\n");
        printf("2. 50,000\n");
        printf("3. 100,000\n");
        printf("4. 250,000\n");
        printf("5. 500,000\n");
        printf("6. 1,000,000\n");
        printf("7. 1,500,000\n");
        printf("8. 2,000,000\n");
        printf("Pilihan Anda: ");
        int choice;
        scanf("%d", &choice);

        // Validasi pilihan ukuran data menggunakan do-while
        do {
            switch (choice) {
            case 1:
                size = 10000;
                break; // Pilihan ukuran 10,000
            case 2:
                size = 50000;
                break; // Pilihan ukuran 50,000
            case 3:
                size = 100000;
                break; // Pilihan ukuran 100,000
            case 4:
                size = 250000;
                break; // Pilihan ukuran 250,000
            case 5:
                size = 500000;
                break; // Pilihan ukuran 500,000
            case 6:
                size = 1000000;
                break; // Pilihan ukuran 1,000,000
            case 7:
                size = 1500000;
                break; // Pilihan ukuran 1,500,000
            case 8:
                size = 2000000;
                break; // Pilihan ukuran 2,000,000
            default:
                // Jika pilihan tidak valid, pengguna diminta untuk mencoba lagi
                printf("Pilihan tidak valid, silakan coba lagi\n");
                continue;
            }
        } while (choice < 1 || choice > 8);

        printf("Anda memilih ukuran data: %d\n", size);

        // Jika pengguna memilih sorting angka
        if (dataChoice == 1){
            int *data = (int *)malloc(size * sizeof(int));
            int *backupData = (int *)malloc(size * sizeof(int));
            if (!data || !backupData){
                perror("Gagal mengalokasikan memori");
                return 1;
            }

            // Membaca data dari file
            if (!readDataFromFile(filename, data, size)){
                free(data);       // Membebaskan memori
                free(backupData); // Membebaskan memori cadangan
                return 1;         // Keluar program jika pembacaan file gagal
            }

            // Membuat cadangan data untuk memulihkan kondisi asli sebelum setiap algoritma sorting
            for (int i = 0; i < size; i++){
                backupData[i] = data[i];
            }

            // Menjalankan Bubble Sort
            for (int i = 0; i < size; i++)
                data[i] = backupData[i];
            start = clock();
            bubbleSort(data, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Bubble Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Selection Sort
            for (int i = 0; i < size; i++)
                data[i] = backupData[i];
            start = clock();
            selectionSort(data, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Selection Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Insertion Sort
            for (int i = 0; i < size; i++)
                data[i] = backupData[i];
            start = clock();
            insertionSort(data, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Insertion Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Merge Sort
            for (int i = 0; i < size; i++)
                data[i] = backupData[i];
            start = clock();
            mergeSort(data, 0, size - 1);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Merge Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Quick Sort
            for (int i = 0; i < size; i++)
                data[i] = backupData[i];
            start = clock();
            quickSort(data, 0, size - 1);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Quick Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Shell Sort
            for (int i = 0; i < size; i++)
                data[i] = backupData[i];
            start = clock();
            shellSort(data, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Shell Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Membebaskan memori setelah selesai
            free(data);
            free(backupData);

        } else if (dataChoice == 2) {
            char (*words)[26] = (char (*)[26])malloc(size * sizeof(char[26]));
            char (*backupWords)[26] = (char (*)[26])malloc(size * sizeof(char[26]));
            if (!words || !backupWords) {
                perror("Gagal mengalokasikan memori");
                return 1;
            }

            // Membaca data kata dari file
            if (!readWordsFromFile(filename, words, size)) {
                free(words);
                free(backupWords);
                return 1;
            }

            // Backup data kata
            for (int i = 0; i < size; i++) {
                strcpy(backupWords[i], words[i]);
            }
            
            // Bubble Sort untuk kata
            for (int i = 0; i < size; i++) 
                strcpy(words[i], backupWords[i]);
            start = clock();
            bubbleSortStr(words, size); // Gunakan fungsi sorting khusus untuk string
            end = clock();
            printMemoryUsage(); // Cetak penggunaan memori setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Bubble Sort selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Selection Sort
            for (int i = 0; i < size; i++)
                strcpy(words[i], backupWords[i]);
            start = clock();
            selectionSortStr(words, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Selection Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Insertion Sort
            for (int i = 0; i < size; i++)
                strcpy(words[i], backupWords[i]);
            start = clock();
            insertionSortStr(words, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Insertion Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Merge Sort
            for (int i = 0; i < size; i++)
                strcpy(words[i], backupWords[i]);
            start = clock();
            mergeSortStr(words, 0, size - 1);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Merge Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Quick Sort
            for (int i = 0; i < size; i++)
                strcpy(words[i], backupWords[i]);        
            start = clock();
            quickSortStr(words, 0, size - 1);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Quick Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            // Menjalankan Shell Sort
            for (int i = 0; i < size; i++)
                strcpy(words[i], backupWords[i]);        
            start = clock();
            shellSortStr(words, size);
            end = clock();
            printMemoryUsage(); // Setelah algoritma dijalankan
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Shell Sort : selesai dalam %.5f detik.\n\n", cpu_time_used);

            free(words);
            free(backupWords);
        }
    }
    printf("\n");
    return 0;
}