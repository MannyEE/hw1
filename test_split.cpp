/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "iostream"

using namespace std;

int main(int argc, char* argv[])
{
    
    Node* head = new Node(0, nullptr);
    Node* curr = head;

    for(int i = 1; i < 10; i++) {
        curr -> next = new Node(i, nullptr);
        curr = curr->next;
    }

    Node* even = nullptr;
    Node* odd = nullptr;

    split(head, odd, even);


    if (head == nullptr) {
        cout << "Head is null!" << endl;
    }

    Node* evencounter = even;
    while(evencounter != nullptr){
        cout << evencounter->value << " ";
        evencounter = evencounter->next;
    }

    cout << "\n";


    Node* oddcounter = odd;
    while(oddcounter != nullptr){
        cout << oddcounter->value << " ";
        oddcounter = oddcounter->next;
    }

    
    return 0;

}
