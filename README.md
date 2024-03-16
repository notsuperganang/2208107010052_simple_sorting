# Sorting Algorithms Performance Evaluation

This repository contains C code to evaluate the performance of three sorting algorithms: Bubble Sort, Selection Sort, and Insertion Sort. The code generates random numbers, sorts them using each algorithm, measures execution time, and saves the results to a text file.

## How to Run the Code

1. Ensure you have a C compiler installed on your system.
2. Clone this repository or download the `sorting_algorithms.c` file.
3. Compile the code using the following command:

   ```bash
   gcc sorting_algorithms.c -o sorting_algorithms
   ```

4. Run the compiled executable:

   ```bash
   ./sorting_algorithms
   ```

## Functions

### `generateRandomNumbers`

This function fills an array with random numbers using the `rand()` function.

Parameters:

- `array`: Array to be filled with random numbers.
- `size`: Size of the array to be filled.
- `seed`: Seed for the `srand()` function.

### `bubbleSort`

This function sorts an array using the Bubble Sort algorithm.

Parameters:

- `array`: Array to be sorted.
- `size`: Size of the array.

### `selectionSort`

This function sorts an array using the Selection Sort algorithm.

Parameters:

- `array`: Array to be sorted.
- `size`: Size of the array.

### `insertionSort`

This function sorts an array using the Insertion Sort algorithm.

Parameters:

- `array`: Array to be sorted.
- `size`: Size of the array.

### `saveToFile`

This function saves an array to a text file.

Parameters:

- `filename`: Destination file name.
- `array`: Array to be saved.
- `size`: Size of the array.
- `type`: Type of the array ("unsorted" for before sorting, "sorted" for after sorting).
- `sort_type`: Sorting algorithm used.

## Main Function

The `main` function is used to test the performance of the sorting algorithms. It evaluates the execution time of each algorithm for array sizes ranging from 100,000 to 1,000,000 with increments of 100,000.
