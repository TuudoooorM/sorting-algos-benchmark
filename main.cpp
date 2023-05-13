#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>

#include "utils.cpp"

#include "bubble.cpp"
#include "insertion.cpp"
#include "bucket.cpp"
#include "counting.cpp"
#include "heap.cpp"
#include "merge.cpp"
#include "quick.cpp"
#include "radix.cpp"
#include "shell.cpp"

std::string algorithmNames[9] = {
    "Bubble Sort",
    "Bucket Sort",
    "Counting Sort",
    "Heap Sort",
    "Insertion Sort",
    "Merge Sort",
    "Quick Sort",
    "Radix Sort",
    "Shell Sort"};

enum SortingAlgorithms
{
  eBubble,
  eBucket,
  eCounting,
  eHeap,
  eInsertion,
  eMerge,
  eQuick,
  eRadix,
  eShell
};

int main()
{
  srand(time(NULL));
  int iterationCount;
  int size;
  while (true)
  {
    std::cout << "Input the size of the array: ";
    std::cin >> size;
    std::cout << "Input how many times to run the benchmarks: ";
    std::cin >> iterationCount;

    if (size > 1'000'000 || size < 0)
    {
      std::cout << "Size should be within [0, 1.000.000]\n";
      continue;
    }

    BubbleSort bubble;
    BucketSort bucket;
    CountingSort counting;
    HeapSort heap;
    InsertionSort insertion;
    MergeSort merge;
    QuickSort quick;
    RadixSort radix;
    ShellSort shell;

    SortingAlgorithm *algorithms[9] = {&bubble, &bucket, &counting, &heap, &insertion, &merge, &quick, &radix, &shell};
    double meanTimesTaken[9] = {0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};

    int *arrayBase = new int[size], *array = new int[size];
    std::generate(arrayBase, arrayBase + size, std::rand);

    // std::cout << "Running benchmarks...\n";
    for (int i = 0; i < iterationCount; i++)
    {
      std::random_shuffle(array, array + size);
      // std::cout << i << ". Running algorithm ";
      for (int algorithmIndex = 0; algorithmIndex < 9; algorithmIndex++)
      {
        if (size >= 100'000 && algorithmIndex == eBubble || size >= 1'000'000 && algorithmIndex == eCounting)
          continue;

        std::cout << algorithmNames[algorithmIndex] << " | ";
        meanTimesTaken[algorithmIndex] += runBenchmark(*algorithms[algorithmIndex], array, arrayBase, size);

        for (int j = 0; j < size - 1; j++)
          if (array[j] > array[j + 1])
          {
            std::cout << "\n\nalgorithm " << algorithmNames[algorithmIndex] << " did not correctly sort the array.\n\n";
            return 0;
          }
      }

      // std::cout << std::endl;
    }

    for (int i = 0; i < 9; i++)
      meanTimesTaken[i] /= static_cast<double>(iterationCount);

    showResults(meanTimesTaken, algorithmNames);
    delete[] array;
    delete[] arrayBase;
  }
}

// timing: https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/