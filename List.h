
#include <iostream>
using namespace std;

class List {
protected:
    int* arr;
    int maxsize;
    int currentsize;

public:
    
    List(int s = 100) : maxsize(s), currentsize(0) {
        arr = new int[maxsize];
    }

    
    List(const List& other) : maxsize(other.maxsize), currentsize(other.currentsize) {
        arr = new int[maxsize];
        for (int i = 0; i < currentsize; ++i) {
            arr[i] = other.arr[i];
        }
    }

    virtual ~List() {
        delete[] arr;
    }

    virtual void addElementAtFirstIndex(int value) = 0;
    virtual void addElementAtLastIndex(int value) = 0;
    virtual int removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};
