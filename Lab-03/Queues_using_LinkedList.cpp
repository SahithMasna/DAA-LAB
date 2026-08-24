#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Deleted: " << front->data << endl;

    Node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display()
{
    Node *temp = front;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue: ";
    display();

    dequeue();

    cout << "After dequeue: ";
    display();

    return 0;
}