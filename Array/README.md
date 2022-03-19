# Array

An array is defined as the collection of similar type of data items stored at contiguous memory locations

# Initialization

```cpp
// initilize array
Array<int> arr;
// can replace int with your data type
// it is template

Array<int> arr = arr2;
// or

Array<int> arr = arr2 + arr3;
// arr2 and arr3 are other arrays
```

# Add / Append

```cpp
arr.add(int el);
arr << el;
// el is element to add

arr.add(int el,int index);
// el is element to add
// index place where top add el

arr += arr2;
// append arr2 to arr
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
arr[index] = el;
// el is element after replacement
// index is element which will replace by el
```

# Get Element

```cpp
int el = arr[index];
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

# Concatinate

```cpp
arr + arr2
// concatinates elements in arr and arr2 with concatinator
```

# Mapping

```cpp
arr.map(T (*callback)(T));
arr.map(T (*callback)(T, int));
arr.map(T (*callback)(T, int, Array<T> *));

// return new Array<T> object with values returned by function

// example function
int twice(int el)
{
     return el * 2;
}

arr.map(twice);

```

# Example Code

```cpp
#include <iostream>
#include "Array.hpp"
using namespace std;

int twice(int el)
{
     return el * 2;
}

int main()
{
     // initilize array
     Array<int> arr;

     // add element to last last index
     for (int i = 1; i <= 12; i++)
          // arr << i;
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
     //     arr[4] = 9;
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

     // initilize array 2
     Array<int> arr2;

     // add element to last last index
     for (int i = 13; i <= 20; i++)
          // arr << i;
          arr2.add(i);

     cout << "2nd Array : \n"
          << arr2.join(" ") << endl;

     // New Array with Map Method
     cout << "Arr * 2 with map method : \n"
          << arr.map(twice).join(" ") << endl;

     // initilize array 3
     Array<int> arr3 = (arr + arr2);
     cout << "3rd Array [new concatinated] : \n"
          << arr3.join(" ") << endl;

     arr3 += arr;
     cout << "3rd Array [appended] : \n"
          << arr3.join(" ") << endl;

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

2nd Array :
13 14 15 16 17 18 19 20

Arr * 2 with map method :
2 4 6 8 12 14 16 18 18 20 22

3rd Array [new concatinated] :
1 2 3 4 6 7 8 9 9 10 11 13 14 15 16 17 18 19 20

3rd Array [appended] :
1 2 3 4 6 7 8 9 9 10 11 13 14 15 16 17 18 19 20 1 2 3 4 6 7 8 9 9 10 11
```
