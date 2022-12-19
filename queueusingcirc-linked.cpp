#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Queue
{
private:
    Node *front = NULL;
    Node *rear = NULL;

public:
    void enqueue(int x)
    {
        if (front == NULL && rear == NULL)
        {
            Node *nyu = new Node();
            nyu->data = x;
            nyu->next = NULL;
            rear = nyu;
            front = nyu;
        }
        else
        {
            Node *nyu = new Node();
            nyu->data = x;
            nyu->next = NULL;
            rear->next = nyu;
            rear = nyu;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty " << endl;
        }
        else
        {
            Node *n = front;
            front = front->next;
            free(n);
        }
    }
    void display()
    {
        Node *n = front;
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
    }
};
int main()
{
    Queue q = Queue();
    int choice;
    do
    {
        cout << "1. Push into Queue " << endl;
        cout << "2. Pop From Queue" << endl;
        cout << "3. Display the Queue" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter the value : ";
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        }
    } while (choice != 0);
    return 0;
}
