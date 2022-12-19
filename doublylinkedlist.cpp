#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
void printList(Node *head)
{
    Node *n = head;
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
void insertBeginning(Node *head)
{
    int x;
    cout << "Enter the element to insert at beginning : ";
    cin >> x;
    Node *temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;
    head = temp;

    printList(head);
}
void insertPosition(Node *head)
{
    int x;
    int pos;
    cout << "Enter the element to be inserted : ";
    cin >> x;
    cout << "Enter the position : ";
    cin >> pos;
    Node *n = head;
    for (int i = 0; i < pos; i++)
    {
        n = n->next;
    }
    Node *nyu = new Node();
    Node *temp = n->prev;
    nyu->data = x;
    nyu->next = n;
    nyu->prev = temp;
    temp->next = nyu;
    n->prev = nyu;
    printList(head);
}
void insertEnd(Node *head)
{
    int x;
    Node *n = head;
    Node *last = new Node();

    cout << "Enter the element to insert at end : ";
    cin >> x;
    last->data = x;
    last->next = NULL;
    Node *temp = NULL;
    while (n != NULL)
    {
        temp = n;
        n = n->next;
    }
    last->prev = temp;
    temp->next = last;
    printList(head);
}
void deleteBeginning(Node *head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    printList(head);
}
void deletePosition(Node *head)
{
    int pos;
    cout << "Enter the position : ";

    cin >> pos;
    Node *n = head;
    for (int i = 0; i < pos; i++)
    {
        n = n->next;
    }
    Node *rev = n->prev;
    rev->next = n->next;
    n->next->prev = rev;
    free(n);
    printList(head);
}
void deleteEnd(Node *head)
{
    Node *n = head;
    Node *rev = NULL;
    while (n != NULL)
    {
        rev = n;
        n = n->next;
    }
    rev->prev->next = NULL;
    free(rev);
    printList(head);
}
Node *searchElement(Node *head)
{
    int x;
    cout << "Enter the element to search for : ";
    cin >> x;
    Node *n = head;
    while (n->data != x && n->next != NULL)
    {
        n = n->next;
    }
    return n;
}
void concatenate(Node *head, Node *head2)
{
    Node *n = head;
    Node *temp = NULL;
    while (n != NULL)
    {
        temp = n;
        n = n->next;
    }
    temp->next = head2;
    head2->prev = temp;
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
    head->data = 1;
    head->prev = NULL;
    head->next = second;
    second->data = 2;
    second->prev = head;
    second->next = third;
    third->data = 3;
    third->prev = second;
    third->next = fourth;

    fourth->data = 4;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->prev = fourth;
    fifth->next = NULL;

    // linked list 2
    Node *list1 = new Node();
    Node *list2 = new Node();
    Node *list3 = new Node();

    list1->data = 6;
    list1->prev = NULL;
    list1->next = list2;

    list2->data = 7;
    list2->prev = list1;
    list2->next = list3;

    list3->data = 8;
    list3->prev = list2;
    list3->next = NULL;

    printList(head);
    int choice = 1;
    while (choice != 0)
    {
        cout << "1. Insert an element x at the beginning of the doubly linked list "<<endl;
        cout << "2. Insert an element x at ith position in the doubly linked list "<<endl;
        cout<< "3. Insert an element x at the end of doubly linked list "<<endl;
        cout<< "4. Remove an element from the beginning of the doubly linked list "<<endl;
        cout<< "5. Remove an element from ith position in the doubly linked list."<<endl;
        cout<< "6. Remove an element from the end of the doubly linked list "<<endl;
        cout<< "7. Search for an element x in the doubly linked list and return its pointer "<<endl;
        cout << "8. Concatenate two doubly linked lists" << endl;
        cout << "Enter 0 to Exit " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertBeginning(head);
            break;
        case 2:
            insertPosition(head);
            break;
        case 3:
            insertEnd(head);
            break;
        case 4:
            deleteBeginning(head);
            break;
        case 5:
            deletePosition(head);
            break;
        case 6:
            deleteEnd(head);
            break;
        case 7:
        {
            Node *ans = searchElement(head);
            cout << "Element found at pointer ; " << ans << endl;
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
