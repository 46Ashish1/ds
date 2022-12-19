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
    void enqueue_front(int x)
    {
        if (front == NULL && rear == NULL)
        {
            Node *nyu = new Node();
            nyu->data = x;
            nyu->next = NULL;
            front = nyu;
            rear = nyu;
        }
        else
        {
            Node *nyu = new Node();
            nyu->data = x;
            nyu->next = front;
            front = nyu;
        }
    }
    void enqueue_rear(int x)
    {
        if (front == NULL && rear == NULL)
        {
            Node *nyu = new Node();
            nyu->data = x;
            nyu->next = NULL;
            front = nyu;
            rear = nyu;
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
    void dequeue_front()
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
    void dequeue_rear()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            Node *n = front;
            Node *prev = NULL;
            while (n != rear)
            {
                prev = n;
                n = n->next;
            }
            Node *temp = rear;
            rear = prev;
            rear->next = NULL;
            free(temp);
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
        cout << endl;
    }
};
int main()
{
    Queue q = Queue();
    int choice;
    do
    {
        cout << "1. Push from front into Queue " << endl;
        cout << "2. Push from Back into Queue" << endl;
        cout << "3. Pop from front of Queue" << endl;
        cout << "4. Pop from Back of Queue" << endl;
        cout << "5. Display the Queue" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter the value : ";
            cin >> x;
            q.enqueue_front(x);
            break;

        case 2:
            int y;
            cout << "Enter the value : ";
            cin >> y;
            q.enqueue_rear(y);
            break;
        case 3:
            q.dequeue_front();
            break;
        case 4:
            q.dequeue_rear();
            break;
        case 5:
            q.display();
            break;
        }
    } while (choice != 0);
    return 0;
}
