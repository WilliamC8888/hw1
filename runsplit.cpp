#include <iostream>
#include "split.h"
#include <cstddef>

using namespace std;

void printList(Node* head){
    while(head){
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<"nullptr"<<endl;
}
Node* createList(int list[], int size){
    Node* head = new Node(list[0],NULL);
    Node* tail = head;

    for(int i=1;i<size;i++){
        tail->next = new Node(list[i],NULL);
        tail = tail->next;

    }
    return head;
}



int main(){
    int vals[]={1,2,3,4,5,6};

    Node* in = createList(vals, 6);

    cout<<"Original List: ";
    printList(in);

    Node* odds = NULL;
    Node* evens= NULL;

    split(in, odds, evens);


    printList(in);
    printList(odds);
    printList(evens);

}