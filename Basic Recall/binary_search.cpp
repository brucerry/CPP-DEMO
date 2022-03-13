#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(double num, vector<double> dictionary, int head, int tail)
{
  if (head > tail) return -1;

  int mid = head + (tail - head) / 2;

  if (num == dictionary[mid]) return mid;
  if (num < dictionary[mid]) return binarySearch(num, dictionary, head, mid - 1);
  return binarySearch(num, dictionary, mid + 1, tail);
}

int main()
{
  vector<double> dictionary {-92.3, 33, 35.456, 2, 11, -9.333, 5};
  sort(dictionary.begin(), dictionary.end());

  vector<double> numToBeFound {1, 22, 333, 33, -92.25, -92.3, 12, 121, 11, 5, -9.33, -9.333, -9.334};

  for (auto num : numToBeFound)
  {
    int idx = binarySearch(num, dictionary, 0, dictionary.size() - 1);
    if (idx == -1)
    {
      cout << num << " is not found" << endl;
    }
    else
    {
      cout << num << " is in index " << idx << endl;
    }
  }

  return 0;
}
