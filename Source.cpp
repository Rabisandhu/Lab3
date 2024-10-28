#include <iostream>
#include "custom.h"

using namespace std;

int main() {
   
    CustomList list(10);

 
    list.addElementAtLastIndex(5);
    list.addElementAtLastIndex(3);
    list.addElementAtLastIndex(7);
    list.addElementAtLastIndex(2);
    list.addElementAtLastIndex(11);

    cout << "List after adding elements: ";
    for (int i = 0; i < list.size(); ++i) {
        cout << list.removeElementFromEnd() << " ";
    }
    cout << endl;

    
    int primeSum = list.sum_ofPrime();
    cout << "Sum of prime numbers in the list: " << primeSum << endl;

    int secondMaxEven = list.secondMaxEven();
    cout << "Second maximum even number: " << secondMaxEven << endl;

    int secondMinOdd = list.secondMinOdd();
    cout << "Second minimum odd number: " << secondMinOdd << endl;

    cout << (list.empty() ? "List is empty." : "List is not empty.") << endl;

    return 0;
}
