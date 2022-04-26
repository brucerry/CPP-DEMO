// https://leetcode.com/problems/guess-number-higher-or-lower/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

// time: O(log(n)) base-3
// space: O(1)
class TernarySearch {
public:
  int guessNumber(int n) {
    int low = 1;
    int high = n;
    while (low <= high) {
      int mid1 = low + (high - low) / 2;
      int mid2 = high - (high - low) / 2;
      int result1 = guess(mid1);
      int result2 = guess(mid2);
      if (result1 == 0) return mid1;
      if (result2 == 0) return mid2;
      if (result1 == -1) high = mid1 - 1;
      else if (result2 == 1) low = mid2 + 1;
      else {
        low = mid1 + 1;
        high = mid2 - 1;
      }
    }
    return -1;
  }
};

// time: O(log(n)) base-2
// space: O(1)
class BinarySearch {
public:
  int guessNumber(int n) {
    int low = 1;
    int high = n;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int result = guess(mid);
      if (result == -1) high = mid - 1;
      else if (result == 1) low = mid + 1;
      else return mid;
    }
    return -1;
  }
};