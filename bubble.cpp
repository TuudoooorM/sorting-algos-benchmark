// https://www.geeksforgeeks.org/bubble-sort-in-cpp/

class BubbleSort : public SortingAlgorithm
{
public:
  void sort(int arr[], int n)
  {
    int i, j;
    for (i = 0; i < n - 1; i++)

      // Last i elements are already
      // in place
      for (j = 0; j < n - i - 1; j++)
        if (arr[j] > arr[j + 1])
          swap(arr[j], arr[j + 1]);
  }
};