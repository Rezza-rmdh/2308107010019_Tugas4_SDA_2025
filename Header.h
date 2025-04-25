// include library yang diperlukan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

// Fungsi untuk mendapatkan informasi penggunaan memori
void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        printf("Penggunaan Memori (Working Set Size): %ld KB\n", memInfo.WorkingSetSize / 1024);
    } else {
        printf("Gagal mendapatkan informasi penggunaan memori.\n");
    }
}

// Function to read number data from a file
int readDataFromFile(const char *filename, int *data, int size) {
  FILE *file = fopen(filename, "r");
  if (!file) {
      perror("Failed to open file");
      return 0;
  }

  for (int i = 0; i < size; i++) {
      if (fscanf(file, "%d", &data[i]) != 1) {
          printf("Error reading data from file\n");
          fclose(file);
          return 0;
      }
  }
  fclose(file);
  return 1;
}

// Function to read word data from a file
int readWordsFromFile(const char *filename, char words[][26], int size) {
  FILE *file = fopen(filename, "r"); // Membuka file dalam mode baca
  if (!file) {
      perror("Gagal membuka file");
      return 0; // Jika gagal membuka file, return 0
  }

  for (int i = 0; i < size; i++) {
      if (fscanf(file, "%s", words[i]) != 1) { // Membaca kata per baris
          printf("Error membaca kata dari file\n");
          fclose(file); // Tutup file jika terjadi kesalahan
          return 0;
      }
  }

  fclose(file); // Tutup file setelah selesai
  return 1; // Return 1 jika berhasil
}

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to swap strings
void swapStr(char *a, char *b) {
  char *temp = (char *)malloc((strlen(a) + 1) * sizeof(char)); // Alokasi buffer dinamis
  if (temp == NULL) {
    perror("Gagal mengalokasikan memori");
    return;
  }
  strcpy(temp, a); // Salin string `a` ke buffer
  strcpy(a, b);    // Salin string `b` ke string `a`
  strcpy(b, temp); // Salin string dari buffer ke string `b`
  free(temp);      // Bebaskan memori setelah digunakan
}

// perform the bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
    
    // check if swapping occurs  
    int swapped = 0;
    
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two array elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        
        swapped = 1;
      }
    }
    
    // no swapping means the array is already sorted
    // so no need for further comparison
    if (swapped == 0) {
      break;
    }
    
  }
}

// Selection Sort in C
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

// Insertion sort in C
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Merge sort in C
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int *L = (int *)malloc(n1 * sizeof(int));
  int *M = (int *)malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}


// Quick sort in C
// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Shell Sort in C programming
// Shell sort
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Bubble Sort untuk string
void bubbleSortStr(char words[][26], int size) {
  for (int step = 0; step < size - 1; ++step) {
    int swapped = 0;
    for (int i = 0; i < size - step - 1; ++i) {
      // Gunakan strcmp untuk membandingkan dua string
      if (strcmp(words[i], words[i + 1]) > 0) {
        // Tukar jika string tidak berurutan
        char temp[26];
        strcpy(temp, words[i]);
        strcpy(words[i], words[i + 1]);
        strcpy(words[i + 1], temp);
        swapped = 1;
      }
    }
    if (swapped == 0) {
      break;
    }
  }
}

// Selection Sort untuk string
void selectionSortStr(char words[][26], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      // Gunakan strcmp untuk menemukan string terkecil
      if (strcmp(words[i], words[min_idx]) < 0) {
        min_idx = i;
      }
    }
    // Tukar string
    char temp[26];
    strcpy(temp, words[min_idx]);
    strcpy(words[min_idx], words[step]);
    strcpy(words[step], temp);
  }
}

// Insertion Sort untuk string
void insertionSortStr(char words[][26], int size) {
  for (int step = 1; step < size; step++) {
    char key[26];
    strcpy(key, words[step]);
    int j = step - 1;
    // Pindahkan elemen yang lebih besar dari key ke satu posisi ke depan
    while (j >= 0 && strcmp(key, words[j]) < 0) {
      strcpy(words[j + 1], words[j]);
      j--;
    }
    strcpy(words[j + 1], key);
  }
}

#include <stdlib.h>
#include <string.h>

// Fungsi Merge untuk string
void mergeStr(char words[][26], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Alokasi memori untuk array L dan R
    char **L = (char **)malloc(n1 * sizeof(char *));
    char **R = (char **)malloc(n2 * sizeof(char *));
    for (int i = 0; i < n1; i++) {
        L[i] = (char *)malloc(26 * sizeof(char));
        strcpy(L[i], words[l + i]);
    }
    for (int j = 0; j < n2; j++) {
        R[j] = (char *)malloc(26 * sizeof(char));
        strcpy(R[j], words[m + 1 + j]);
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(words[k], L[i]);
            i++;
        } else {
            strcpy(words[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(words[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(words[k], R[j]);
        j++;
        k++;
    }

    // Bebaskan memori yang dialokasikan
    for (int i = 0; i < n1; i++) {
        free(L[i]);
    }
    free(L);
    for (int j = 0; j < n2; j++) {
        free(R[j]);
    }
    free(R);
}

// Merge Sort untuk string
void mergeSortStr(char words[][26], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortStr(words, l, m);
        mergeSortStr(words, m + 1, r);
        mergeStr(words, l, m, r);
    }
}

// Fungsi Partition untuk string
int partitionStr(char words[][26], int low, int high) {
  char pivot[26];
  strcpy(pivot, words[high]);
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (strcmp(words[j], pivot) <= 0) {
      i++;
      char temp[26];
      strcpy(temp, words[i]);
      strcpy(words[i], words[j]);
      strcpy(words[j], temp);
    }
  }

  char temp[26];
  strcpy(temp, words[i + 1]);
  strcpy(words[i + 1], words[high]);
  strcpy(words[high], temp);

  return (i + 1);
}

// Quick Sort untuk string
void quickSortStr(char words[][26], int low, int high) {
  if (low < high) {
    int pi = partitionStr(words, low, high);
    quickSortStr(words, low, pi - 1);
    quickSortStr(words, pi + 1, high);
  }
}

// Shell Sort untuk string
void shellSortStr(char words[][26], int size) {
  for (int interval = size / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < size; i++) {
      char temp[26];
      strcpy(temp, words[i]);
      int j;
      for (j = i; j >= interval && strcmp(words[j - interval], temp) > 0; j -= interval) {
        strcpy(words[j], words[j - interval]);
      }
      strcpy(words[j], temp);
    }
  }
}