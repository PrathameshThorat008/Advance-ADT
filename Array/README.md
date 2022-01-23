# Array

An array is defined as the collection of similar type of data items stored at contiguous memory locations

# Initialization

```cpp
    // initilize array
    Array<int> arr;
    // can replace int with your data type
    // it is template
```

# Add / Append

```cpp
arr.add(int el);
// el is element to add

arr.add(int el,int index);
// el is element to add
// index place where top add el
```

# Remove

```cpp
arr.remove();
// remove last element

arr.remove(int index);
// index place wheres element is removed
```

# Update / Replace

```cpp
arr.update(int el, int index);
// el is element after replacement
// index is element which will replace by el
```

# Rotate

```cpp
arr.rotate(int rotations);
// rotates array rotations times
```

# Sorting

```cpp
arr.sort();
// sorts the array in asending
```

# Searching

## Linear Search

```cpp
arr.linearSearch(int el);
// linear searches element el in array
```

## Binary Search

```cpp
arr.binarySearch(int el);
// binary searches element el in array
```

**note** : use if element are are sorted and non repeated

# Joining / Stringify

```cpp
arr.join(string concatinator);
// concatinates elements in array with concatinator
```

# Example Code

```cpp
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
```

# Output

```text
Original Array :
1 2 3 4 5 6 7 8 9 10 11 12

Add 4 to index 0 :
4 1 2 3 4 5 6 7 8 9 10 11 12

Remove Last Element :
4 1 2 3 4 5 6 7 8 9 10 11

Remove Element at index 0 :
1 2 3 4 5 6 7 8 9 10 11

Update 9 to index 4 :
1 2 3 4 9 6 7 8 9 10 11

Rotate Array Thrice :
4 9 6 7 8 9 10 11 1 2 3

Sort The Array :
1 2 3 4 6 7 8 9 9 10 11

Linear Search in Array (9): 7

Binary Search in Array (4): 3

Convert Array to String With Concatinator :
    [ ] : 1 2 3 4 6 7 8 9 9 10 11
    [->] : 1->2->3->4->6->7->8->9->9->10->11
    [+] : 1+2+3+4+6+7+8+9+9+10+11
    [ a ] : 1 a 2 a 3 a 4 a 6 a 7 a 8 a 9 a 9 a 10 a 11
```
