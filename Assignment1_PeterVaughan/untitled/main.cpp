#include <iostream>
#include "List.cpp"
using namespace std;

int main()
{
    //printf("true: %d, false: %d\n", true, false);
    //printf("NULL: %d, nullptr: %d, 0: %d\n", NULL, nullptr, 0);
    //printf("NULL: %d, nullptr: %p, 0: %d\n", NULL, nullptr, 0);

    List list;

    //append
    list.append(78);
    list.append(5);
    cout << list.first->data << endl;
    cout << list.last->data << endl << endl;

    //prepend
    list.prepend(13);
    cout << list.first->data << endl << endl;

    list.prepend(55);
    cout << list.first->data << endl << endl;

    //size return
    cout << list.size() << endl << endl;

    //error-handling (not needed but to showcase this)
    Node* result = list.index(-1);
    if (result) {
        cout << result->data << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
    //head
    cout << list.index(0)->data << endl;

    //middle info 
    cout << list.index(1)->data << endl;
    cout << list.index(2)->data << endl;
    
    //tail
    cout << list.index(3)->data << endl << endl;

    //pop - remove last element
    list.pop();
    //head
    cout << list.index(0)->data << endl;
    cout << list.index(1)->data << endl;
    //tail
    cout << list.index(2)->data << endl << endl;

    //contains value: 0 is false, 1 is true
    bool story = list.contains(999);
    cout <<  story << endl;
    story = list.contains(55);
    cout <<  story << endl << endl;

    //Find value - return number or nil
    int find = list.find(78);
    if (find >= 0) {
        cout << "Index: "<< find << endl;
    }
    else
        cout << "nil" << endl;

    find = list.find(999999);
    if (find >= 0) {
        cout << "Number: "<< find << endl << endl;
    }
    else
        cout << "nil" << endl;

    return 0;
}
