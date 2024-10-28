
#include "myList.h"
using namespace std;
class CustomList : public myList {
public:
    
    CustomList(int s = 100) : myList(s) {}
    CustomList(const CustomList& other) : myList(other) {}
    ~CustomList() {}

   
    int sum_ofPrime() const {
        int sum = 0;
        for (int i = 0; i < currentsize; ++i) {
            if (isPrime(arr[i])) sum += arr[i];
        }
        return sum;
    }

    
    int secondMaxEven() const {
        int maxEven = -1, secondMaxEven = -1;
        for (int i = 0; i < currentsize; ++i) {
            if (arr[i] % 2 == 0) {
                if (arr[i] > maxEven) {
                    secondMaxEven = maxEven;
                    maxEven = arr[i];
                }
                else if (arr[i] > secondMaxEven && arr[i] != maxEven) {
                    secondMaxEven = arr[i];
                }
            }
        }
        return secondMaxEven;
    }

   
    int secondMinOdd() const {
        int minOdd = INT_MAX, secondMinOdd = INT_MAX;
        for (int i = 0; i < currentsize; ++i) {
            if (arr[i] % 2 != 0) {
                if (arr[i] < minOdd) {
                    secondMinOdd = minOdd;
                    minOdd = arr[i];
                }
                else if (arr[i] < secondMinOdd && arr[i] != minOdd) {
                    secondMinOdd = arr[i];
                }
            }
        }
        return (secondMinOdd == INT_MAX) ? -1 : secondMinOdd;
    }

  
    void printDuplicates() const {
        for (int i = 0; i < currentsize; ++i) {
            bool duplicateFound = false;
            for (int j = 0; j < i; ++j) {
                if (arr[i] == arr[j]) {
                    duplicateFound = true;
                    break;
                }
            }
            if (duplicateFound) {
                cout << arr[i] << " appears multiple times.\n";
            }
        }
    }

    void rotateClockwise(int r) {
        int mid = currentsize / 2;
        r %= mid;
        if (r == 0) return;

  
        for (int i = 0; i < r; ++i) {
            int last = arr[mid - 1];
            for (int j = mid - 1; j > 0; --j) {
                arr[j] = arr[j - 1];
            }
            arr[0] = last;
        }

        for (int i = 0; i < r; ++i) {
            int last = arr[currentsize - 1];
            for (int j = currentsize - 1; j > mid; --j) {
                arr[j] = arr[j - 1];
            }
            arr[mid] = last;
        }
    }

    void rotateAnticlockwise(int rt) {
        int mid = currentsize / 2;
        rt %= mid;
        if (rt == 0) return;

        for (int i = 0; i < rt; ++i) {
            int first = arr[0];
            for (int j = 0; j < mid - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            arr[mid - 1] = first;
        }

        for (int i = 0; i < rt; ++i) {
            int first = arr[mid];
            for (int j = mid; j < currentsize - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            arr[currentsize - 1] = first;
        }
    }

private:
    bool isPrime(int num) const {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
};
