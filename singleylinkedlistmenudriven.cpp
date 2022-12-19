#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void printList(Node *n)
{
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
    cout << "Enter the value to insert at beginning : ";

    cin >> x;
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    printList(head);
}
void insertPosition(Node *head)
{
    int x;
    int pos;
    cout << "Enter the element to be inserted ; ";
    cin >> x;
    cout << "Enter the position to insert in : ";
    cin >> pos;
    Node *nyu = new Node();
    nyu->data = x;
    Node *n = head;
    Node *temp = NULL;
    for (int i = 0; i < pos; i++)
    {
        temp = n;
        n = n->next;
    }
    nyu->next = n;
    temp->next = nyu;
    printList(head);
}
void deleteBeginning(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    printList(head);
}
void deletePosition(Node *head)
{
    int pos;
    cout << "Enter the positon to delete from : ";
    cin >> pos;
    Node *n = head;
    Node *prev = NULL;
    for (int i = 0; i < pos; i++)
    {
        prev = n;
        n = n->next;
    }
    Node *temp = n;
    prev->next = temp->next;
    free(temp);
    printList(head);
}
Node *searchElement(Node *head)
{
    int x;
    cout << "Enter the element to find for : ";

    cin >> x;
    Node *n = head;
    while (n->data != x)
    {
        n = n->next;
    }
    return n;
}
void concatenate(Node *head, Node *head2)
{
    Node *n = head;
    Node *prev = NULL;
    while (n != NULL)
    {
        prev = n;
        n = n->next;
    }
    prev->next = head2;
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
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = NULL;

    // linked list 2
    Node *list1 = new Node();
    Node *list2 = new Node();
    Node *list3 = new Node();

    list1->data = 6;

    list1->next = list2;

    list2->data = 7;
    list2->next = list3;

    list3->data = 8;
    list3->next = NULL;

    printList(head);
    int choice = 1;
    while (choice != 0)
    {
        cout << "1. Insert an element x at the beginning of the singly linked list "<<endl;
        cout<< "2. Insert an element x at ith position in the singly linked list "<<endl;
        cout<< "3. Remove an element from the beginning of the singly linked list "<<endl;
        cout<< "4. Remove an element from ith position in the singly linked list."<<endl;
        cout<< "5. Search for an element x in the singly linked list and return its pointer "<<endl;
        cout<< "6. Concatenate two singly linked lists" << endl;
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
            deleteBeginning(head);
            break;
        case 4:
            deletePosition(head);
            break;
        case 5:
        {
            Node *ans = searchElement(head);
            cout << "Element found at : " << ans << endl;
            break;
        }
        case 6:
        {
            concatenate(head, list1);
            break;
        }
        default:
        {
            cout << "Enter valid option : " << endl;
            break;
        }
        }
    }
    return 0;
}
