#include <iostream>
#include "Array.hpp"
using namespace std;

int main()
{
    // initilize array
    Array<int> arr;

    // add element to last last index
    for (int i = 1; i <= 12; i++)
        arr.add(i);
    cout << "Original Array : \n"
         << arr.join(" ") << endl;

    // add element to specific index
    arr.add(4, 0);
    cout << "Add 4 to index 0 : \n"
         << arr.join(" ") << endl;

    // delete last element
    arr.remove();
    cout << "Remove Last Element : \n"
         << arr.join(" ") << endl;

    // delete specific index element
    arr.remove(0);
    cout << "Remove Element at index 0 : \n"
         << arr.join(" ") << endl;

    // update element at specific index
    arr.update(9, 4);
    cout << "Update 9 to index 4 : \n"
         << arr.join(" ") << endl;

    // rorate array by left
    arr.rotate(3);
    cout << "Rotate Array Thrice : \n"
         << arr.join(" ") << endl;

    // to sort array
    arr.sort();
    cout << "Sort The Array : \n"
         << arr.join(" ") << endl;

    // Linear search
    cout << "Linear Search in Array (9): " << arr.linearSearch(9) << endl;

    // Binary search
    cout << "Binary Search in Array (4): " << arr.binarySearch(4) << endl;

    cout << "Convert Array to String With Concatinator : " << endl;
    cout << "[ ] : " << arr.join(" ") << endl;
    cout << "[->] : " << arr.join("->") << endl;
    cout << "[+] : " << arr.join("+") << endl;
    cout << "[ a ] : " << arr.join(" a ") << endl;
    return 0;
}