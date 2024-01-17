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

    split(in, odds, evens);
}

void addnode(Node*& llist, Node*& in)
{

    if (llist->next == nullptr) {
        llist->next = in;
        in = in->next;
        llist->next->next = nullptr;
    } else {
        addnode(llist->next, in);
    }
}
/* If you needed a helper function, write it here */
