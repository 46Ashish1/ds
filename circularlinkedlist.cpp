#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *head)
{
    Node *n = head;
    while (n->next != head)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << n->data << endl;
}
void insertFront(Node *head)
{
    Node *n = head;
    int x;
    cout << "Enter the value to be inserted at front : ";
    cin >> x;
    Node *nyu = new Node();
    while (n->next != head)
    {
        n = n->next;
    }
    nyu->data = x;
    nyu->next = head;
    head = nyu;
    n->next = nyu;
    printList(head);
}
void insertAfter(Node *head)
{
    Node *n = head;
    int x, y;
    cout << "Enter the element to be inserted : ";
    cin >> x;
    cout << "Enter the y : ";
    cin >> y;
    while (n->data != y)
    {
        n = n->next;
    }
    Node *nyu = new Node();
    nyu->data = x;
    nyu->next = n->next;
    n->next = nyu;
    printList(head);
}
void insertBack(Node *head)
{
    int x;
    cout << "Enter the value to insert at the end : ";
    cin >> x;
    Node *n = head;
    while (n->next != head)
    {
        n = n->next;
    }
    Node *nyu = new Node();
    nyu->data = x;
    nyu->next = head;
    n->next = nyu;

    printList(head);
}
void removeBack(Node *head)
{
    Node *prev = NULL;
    Node *n = head;
    while (n->next != head)
    {
        prev = n;
        n = n->next;
    }
    prev->next = head;
    free(n);
    printList(head);
}
void removeFront(Node *head)
{
    Node *n = head;
    Node *temp = head;
    while (n->next != head)
    {
        n = n->next;
    }
    n->next = head->next;
    head = head->next;
    free(temp);
    printList(head);
}
void removeElement(Node *head)
{
    int x;
    cout << "Enter the element to remove : ";
    cin >> x;
    Node *n = head;
    Node *prev = NULL;
    while (n->data != x)
    {
        prev = n;
        n = n->next;
    }
    prev->next = n->next;
    free(n);
    printList(head);
}
Node *searchElement(Node *head)
{
    Node *n = head;
    int x;
    cout << "Enter the element to search for : ";
    cin >> x;
    while (n->data != x)
    {
        n = n->next;
    }
    return n;
}
void concatenate(Node *head, Node *head2)
{
    Node *n = head;
    while (n->next != head)
    {
        n = n->next;
    }
    n->next = head2;
    Node *o = head2;
    while (o->next != head2)
    {
        o = o->next;
    }
    o->next = head;
    printList(head);
}
int main()
{
    // linked list 1
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    head->data =
        1;
    head->next = second;
    second->data =
        2;
    second->next = third;
    third->data =
        3;
    third->next = fourth;

    fourth->data =
        4;
    fourth->next = fifth;
    fifth->data =
        5;
    fifth->next = head;

    // linked list 2
    Node *list1 = new Node();
    Node *list2 = new Node();
    Node *list3 = new Node();

    list1->data =
        6;
    list1->next = list2;

    list2->data =
        7;
    list2->next = list3;

    list3->data =
        8;
    list3->next = list1;

    printList(head);
    int choice = 1;
    while (choice != 0)
    {
        cout << "1. Insert an element x at the front of the cicularly linked list "<<endl;
            cout << "2. Insert an element x after an element y in the circularly linked list "<<endl;
            cout<< "3. Insert an element x at the back of circular linked list "<<endl;
            cout << "4. Remove an element from back of the cicularly linked list "<<endl;
            cout<< "5. Remove an element from front of the cicularly linked list."<<endl;
                cout << "6. Remove x from the circularly linked list" << endl;
        cout << "7. Search for an element x in the cicularly linked list andreturn its pointer "<<endl;
                   cout  << "8. Concatenate two circularly linked lists" << endl;
        cout << "Enter 0 to Exit " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertFront(head);
            break;
        case 2:
            insertAfter(head);
            break;
        case 3:
            insertBack(head);
            break;
        case 4:
            removeBack(head);
            break;
        case 5:
            removeFront(head);
            break;
        case 6:
            removeElement(head);
            break;
        case 7:
        {
            Node *ans = searchElement(head);
            cout << "Element found at : " << ans << endl;
            break;
        }
        case 8:
        {
            concatenate(head, list1);
            break;
        }
        }
    }
    return 0;
}
