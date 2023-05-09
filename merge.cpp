// https://www.geeksforgeeks.org/merge-sort/?ref=gcse
class MergeSort : public SortingAlgorithm
{
  // Merges two subarrays of array[].
  // First subarray is arr[begin..mid]
  // Second subarray is arr[mid+1..size]
private:
  void merge(int array[], int const left, int const mid,
             int const right)
  {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
      leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
      rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0,    // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
      if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
      {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
      }
      else
      {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
      }
      indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
      indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
      indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
  }

  void mergeSort(int array[], int start, int end)
  {
    if (start >= end)
      return; // Returns recursively

    int mid = start + (end - start) / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, mid, end);
  }

public:
  void sort(int array[], int size)
  {
    mergeSort(array, 0, size - 1);
  }
};