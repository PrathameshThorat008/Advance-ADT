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