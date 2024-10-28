
#include "List.h"
using namespace std;
class myList : public List {
public:
    
    myList(int s = 100) : List(s) {}
    myList(const myList& other) : List(other) {}
    ~myList() {}

    
    void addElementAtFirstIndex(int value) override {
        if (currentsize >= maxsize) return;
        for (int i = currentsize; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        currentsize++;
    }

  
    void addElementAtLastIndex(int value) override {
        if (currentsize >= maxsize) return;
        arr[currentsize++] = value;
    }

   
    int removeElementFromEnd() override {
        if (currentsize <= 0) return -1;
        return arr[--currentsize];
    }

  
    void removeElementFromStart() override {
        if (currentsize <= 0) return;
        for (int i = 0; i < currentsize - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        currentsize--;
    }

    
    bool empty() const {
        return currentsize == 0;
    }

  
    bool full() const {
        return currentsize == maxsize;
    }

    int size() const {
        return currentsize;
    }

  
    bool insertAt(int index, int value) {
        if (index < 0 || index > currentsize || currentsize >= maxsize) return false;
        for (int i = currentsize; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        currentsize++;
        return true;
    }

    
    int last() const {
        if (currentsize <= 0) return -1;
        return arr[currentsize - 1];
    }

  
    bool search(int value) const {
        for (int i = 0; i < currentsize; i++) {
            if (arr[i] == value) return true;
        }
        return false;
    }
};
