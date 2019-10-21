#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

node *top = nullptr;

//// create a new node structure with value and return it
node* getNode(int val)
{
    node *newNode = new node;               // new - memory allocation
    newNode -> value = val;
    newNode -> next = NULL;

    return newNode;
}

//// insert a new node into the stack - push
void push(int value)
{
    node *newNode = getNode(value);         // create a newNode

    // if there is no node, then assign top to the very first node
    if(!top)
        top = newNode;

    // inserting the new node into the stack
    else
    {
        newNode -> next = top;
        top = newNode;
    }
}

int pop()
{
    // check underflow error
    if(!top)
    {
        cout << "Underflow error";
    }
    else
    {
        // to free the current top node, assign top to a temporary pointer
        node *temp = top;
        top = top->next;        // set top pointer to the next node in the stack
        delete temp;            // free(delete) temp node
    }
    return 0;
}

//// print the stack
void print()
{
    node *ptr = top;
    while(ptr)
    {
        cout << ptr->value << " ";
        ptr = ptr -> next;
    }
    ptr->value ;

}

int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    push(4);
    push(5);
    push(8);
    push(9);
    push(12);
    push(53);
    pop();
    pop();
    print();
}
