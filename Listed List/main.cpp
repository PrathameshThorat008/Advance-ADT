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