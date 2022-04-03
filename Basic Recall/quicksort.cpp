#include <iostream>
#include <vector>
using namespace std;

void printNums(vector<float> numbers)
{
  for (auto num : numbers)
  {
    cout << " " << num; 
  }
  cout << endl;
}

int findMedianOfThree(vector<float> &numbers, int head, int tail, int mid)
{
  if (numbers[mid] < numbers[head]) swap(numbers[mid], numbers[head]);
  if (numbers[tail] < numbers[head]) swap(numbers[tail], numbers[head]);
  if (numbers[mid] < numbers[tail]) swap(numbers[mid], numbers[tail]);
  return tail;
}

int findPivotIndex(vector<float> &numbers, int head, int tail)
{
  int medianOfThree = findMedianOfThree(numbers, head, tail, (head + tail) / 2);
  float pivot = numbers[medianOfThree];
  int p = head;

  for (int i = head; i < tail; i++)
  {
    if (numbers[i] <= pivot)
    {
      swap(numbers[p], numbers[i]);
      p++;
    }
  }
  swap(numbers[medianOfThree],numbers[p]);

  return p;
}

void quickSort(vector<float> &numbers, int head, int tail)
{
  if (head < tail)
  {
    int pivotIndex = findPivotIndex(numbers, head, tail);
    quickSort(numbers, head, pivotIndex - 1);
    quickSort(numbers, pivotIndex + 1, tail);
  }
}

int main()
{
  vector<float> numbers = {9, 77, 65, 443, -98, -34, 54, 2234, -9.2283, 9.223, 9.22456, -988, 334, 334.1};

  cout << "Before sort:";
  printNums(numbers);

  quickSort(numbers, 0, numbers.size() - 1);

  cout << "After sort:";
  printNums(numbers);

  return 0;
}