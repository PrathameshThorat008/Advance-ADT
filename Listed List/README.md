# Linked List

A linked list is a sequence of data structures, which are connected together via links. Linked List is a sequence of links which contains items. Each link contains a connection to another link. Linked list is the second most-used data structure after Array.

# Initialization

```cpp
// initilize LinkedList
LinkedList<int> ll;
// can replace int with your data type
// it is template

LinkedList<int> ll(data);
// data is first node

LinkedList<int> ll = ll2 + ll3;
// ll2 and ll3 are other LinkedLists
```

# Add / Append

```cpp
ll.insert(int el);
// el is element to insert

ll.insert(int el,int index);
// el is element to insert
// index place where top insert el
```

# Remove

```cpp
ll.del();
// remove last element

ll.del(int index);
// index place wheres element is removed
```

# Update / Replace

```cpp
ll.update(int el, int index);
// el is element after replacement
// index is element which will replace by el
```

# Get Element

```cpp
int el = ll[index];
// if index is greater than length
// it returns head node data
```

# Search

This is Linear Search

```cpp
ll.search(int el);
// linear searches element el in LinkedList
```

# Joining / Stringify

```cpp
ll.join(string concatinator);
// concatinates elements in LinkedList with concatinator
```

# Concatinate

```cpp
ll + ll2
// concatinates elements in ll and ll2 with concatinator
```

# Mapping

```cpp
ll.map(T (*callback)(T));
ll.map(T (*callback)(T, int));
ll.map(T (*callback)(T, int, LinkedList<T> *));

// return new LinkedList<T> object with values returned by function

// example function
int twice(int el)
{
     return el * 2;
}

ll.map(twice);

```

# Example Code

```cpp
#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int twice(int el)
{
     return el * 2;
}

int main()
{
     // initilize ll
     LinkedList<int> ll;

     // add element to last last index
     for (int i = 1; i <= 12; i++)
          ll.insert(i);

     cout << "Original ll : \n"
          << ll.join("->") << endl;

     // add element to specific index
     ll.insert_head(5);
     cout << "Add 5 to Head : \n"
          << ll.join("->") << endl;

     // add element to specific index
     ll.insert(4, 2);
     cout << "Add 4 to index 2 : \n"
          << ll.join("->") << endl;

     // delete specific index element
     ll.del(0);
     cout << "Remove Element at index 0 : \n"
          << ll.join("->") << endl;

     // update element at specific index
     ll.update(9, 4);
     //     ll[4] = 9;
     cout << "Update 9 to index 4 : \n"
          << ll.join("->") << endl;

     // Linear search
     cout << "Search in ll (9): " << ll.search(9) << endl;

     cout << "Convert ll to String With Concatinator : " << endl;
     cout << "[ ] : " << ll.join(" ") << endl;
     cout << "[->] : " << ll.join("->") << endl;
     cout << "[+] : " << ll.join("+") << endl;
     cout << "[ a ] : " << ll.join(" a ") << endl;

     // initilize LinkedList 2
     LinkedList<int> ll2;

     // add element to last last index
     for (int i = 13; i <= 20; i++)
          ll2.insert(i);

     cout << "2nd LinkedList : \n"
          << ll2.join("->") << endl;

     cout << "Concatinated LinkedList : \n"
          << (ll + ll2).join("->") << endl;

     // initilize LinkedList 3
     LinkedList<int> ll3 = ll + ll2;
     cout << "3rd LinkedList [new concatinated] : \n"
          << ll3.join("->") << endl;

     ll3 += ll;
     cout << "3rd LinkedList [appended] : \n"
          << ll3.join("->") << endl;

     // New LinkedList with Map Method
     cout << "ll * 2 with map method : \n"
          << ll.map(twice).join("->") << endl;

     return 0;
}
```

# Output

```text
Original ll :
1->2->3->4->5->6->7->8->9->10->11->12

Add 5 to Head :
5->1->2->3->4->5->6->7->8->9->10->11->12

Add 4 to index 2 :
5->1->4->2->3->4->5->6->7->8->9->10->11->12

Remove Element at index 0 :
1->4->2->3->4->5->6->7->8->9->10->11->12

Update 9 to index 4 :
1->4->2->3->4->9->6->7->8->9->10->11->12

Search in ll (9): 5

Convert ll to String With Concatinator :
     [ ] : 1 4 2 3 4 9 6 7 8 9 10 11 12
     [->] : 1->4->2->3->4->9->6->7->8->9->10->11->12
     [+] : 1+4+2+3+4+9+6+7+8+9+10+11+12
     [ a ] : 1 a 4 a 2 a 3 a 4 a 9 a 6 a 7 a 8 a 9 a 10 a 11 a 12

2nd LinkedList :
13->14->15->16->17->18->19->20

Concatinated LinkedList :
1->4->2->3->4->9->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20

3rd LinkedList [new concatinated] :
1->4->2->3->4->9->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20

3rd LinkedList [appended] :
1->4->2->3->4->9->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20->1->4->2->3->4->9->6->7->8->9->10->11->12

ll * 2 with map method :
2->8->4->6->8->18->12->14->16->18->20->22->24
```
