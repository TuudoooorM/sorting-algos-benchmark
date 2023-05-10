class SortingAlgorithm
{
public:
  virtual void sort(int array[], int size) = 0;
};

void swap(int &a, int &b)
{
  int aux = a;
  a = b;
  b = aux;
}

void swap(float &a, float &b)
{
  float aux = a;
  a = b;
  b = aux;
}

double getTimeTaken(timespec &start, timespec &end)
{
  double time_taken;
  time_taken = (end.tv_sec - start.tv_sec) * 1e9;
  time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  return time_taken;
}

double runBenchmark(SortingAlgorithm &algorithm, int array[], int arrayBase[], int size)
{
  timespec start, end;
  std::copy(arrayBase, arrayBase + size, array);

  clock_gettime(CLOCK_MONOTONIC, &start);
  algorithm.sort(array, size);
  clock_gettime(CLOCK_MONOTONIC, &end);

  return getTimeTaken(start, end);
}

void showResults(double meanTimesTaken[], std::string algorithmNames[])
{
  std::cout << std::endl
            << std::endl;

  for (int algorithmIndex = 0; algorithmIndex < 9; algorithmIndex++)
  {
    std::cout << algorithmNames[algorithmIndex] << ": " << std::fixed << meanTimesTaken[algorithmIndex] << std::setprecision(9) << " seconds\n";
  }

  std::cout << std::endl
            << std::endl;
}