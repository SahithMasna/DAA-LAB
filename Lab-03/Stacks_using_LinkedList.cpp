#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void push(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Popped: " << top->data << endl;

    Node *temp = top;
    top = top->next;
    delete temp;
}

void display()
{
    Node *temp = top;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    cout << "Stack: ";
    display();

    pop();

    cout << "After pop: ";
    display();

    return 0;
}