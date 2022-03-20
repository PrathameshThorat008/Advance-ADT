# Linked List

Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

# Initialization

```cpp
// initilize Stack
Stack<int> st;
// can replace int with your data type
// it is template

Stack<int> st(data);
// data is first node

Stack<int> st = st2 + st3;
// st2 and st3 are other Stacks
```

# Push

```cpp
st.push(int el);
st << el;
st += el;
// el is element to insert

st.push(st2);
st << st2;
st += st2;
// st2 is another stack
```

# Pop

```cpp
st.pop();
// remove last element
```

# Get Element

```cpp
int el = st[position];
el = st.pos(position);

// position starts from 1
```

# Joining / Stringify

```cpp
st.join(string concatinator);
// concatinates elements in Stack with concatinator
```

# Concatinate

```cpp
st + st2
// concatinates elements in st and st2 with concatinator
```

# Example Code

```cpp
#include <iostream>
#include "Stack.hpp"
using namespace std;

int main()
{
    // initilize st
    Stack<int> st;

    // add element to last last index
    for (int i = 1; i <= 12; i++)
        st.push(i);

    cout << "Original st : \n"
         << st.join("->") << endl;

    // delete specific index element
    st.pop();
    cout << "Remove Element top element : \n"
         << st.join("->") << endl;

    cout << "Convert st to String With Concatinator : " << endl;
    cout << "[ ] : " << st.join(" ") << endl;
    cout << "[->] : " << st.join("->") << endl;
    cout << "[+] : " << st.join("+") << endl;
    cout << "[ a ] : " << st.join(" a ") << endl;

    // initilize Stack 2
    Stack<int> st2;

    // add element to last last index
    for (int i = 13; i <= 20; i++)
        st2.push(i);

    cout << "2nd Stack : \n"
         << st2.join("->") << endl;

    cout << "Concatinated Stack : \n"
         << (st + st2).join("->") << endl;

    // initilize Stack 3
    Stack<int> st3 = st + st2;
    cout << "3rd Stack [new concatinated] : \n"
         << st3.join("->") << endl;

    st3 += st;
    cout << "3rd Stack [appended] : \n"
         << st3.join("<-") << endl;

    return 0;
}
```

# Output

```text
Original st :
12->11->10->9->8->7->6->5->4->3->2->1

Remove Element top element :
11->10->9->8->7->6->5->4->3->2->1

Convert st to String With Concatinator :
     [ ] : 11 10 9 8 7 6 5 4 3 2 1
     [->] : 11->10->9->8->7->6->5->4->3->2->1
     [+] : 11+10+9+8+7+6+5+4+3+2+1
     [ a ] : 11 a 10 a 9 a 8 a 7 a 6 a 5 a 4 a 3 a 2 a 1

2nd Stack :
20->19->18->17->16->15->14->13

Concatinated Stack :
20->19->18->17->16->15->14->13->11->10->9->8->7->6->5->4->3->2->1

3rd Stack [new concatinated] :
20->19->18->17->16->15->14->13->11->10->9->8->7->6->5->4->3->2->1

3rd Stack [appended] :
11<-10<-9<-8<-7<-6<-5<-4<-3<-2<-1<-20<-19<-18<-17<-16<-15<-14<-13<-11<-10<-9<-8<-7<-6<-5<-4<-3<-2<-1
```
