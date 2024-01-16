/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include"iostream"
using namespace std;

/* Add a prototype for a helper function here if you need */
void addnode(Node*& llist, Node*& in);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
    if (in == nullptr) {
      return;
    }


    while(in != nullptr) {

        if(in -> value % 2 == 0) {
            if(evens == nullptr) {
                evens = in;
                in = in -> next;
                evens->next = nullptr;
            } else{
                addnode(evens, in);
            }

        } else {
            if(odds == nullptr) {
                odds = in;
                in = in->next;
                odds->next = nullptr;
            } else{
                addnode(odds, in);
            }
        }
    }
}

void addnode(Node*& llist, Node*& in)
{
    Node* curr = llist;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = in;
    in = in->next;
    curr->next->next = nullptr;
}
/* If you needed a helper function, write it here */
