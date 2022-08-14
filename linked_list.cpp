#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertAtTail(Node *&head, int n)
{
    Node *newNode = new Node(n);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int n)
{
    Node *newNode = new Node(n);
    newNode->Next = head;
    head = newNode;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    Node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->Next;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
        return -1;
    for (; temp->value != key; count++)
    {
        if (temp->Next == NULL)
            return -1;
        temp = temp->Next;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if (flag == 0)
        cout << "The search value is not yet in the list" << endl;
    else
    {
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
        cout << endl;
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insertByValueUnique(Node *&head, int searchValue, int value)
{
    // S1: Search the position of the searchValue
    int position;
    position = searchByValueUnique(head, searchValue);

    // S2: Insert the value at the position + 1
    insertAtSpecificPosition(head, position + 1, value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
        cout << "There is no value int the Linked List" << endl;
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
            cout << "There is no value int the Linked List" << endl;
        else
            deletionAtHead(head);
    }
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (position <= countLength(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->Next;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "Position out of bounds" << endl;
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    int position = searchByValueUnique(head, value);
    if (position == -1)
        cout << "Value not found in the Linked List" << endl;
    else
        deletionAtSpecificPosition(head, position);
}

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The Linked List is empty" << endl;
        return head;
    }
    Node *next = head->Next;
    while (true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;
        next = next->Next;
    }
    cout << "Linked List is reversed" << endl;
    return prev;
}

int findMid(Node *&head)
{
    if (head == NULL)
        return -1;
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
        {
            cout << " -> ";
        }
        n = n->Next;
    }
    cout << endl
         << endl;
}

int main()
{
    Node *head = NULL;
    int value;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insert at specific position" << endl
         << "Choice 4: Search a value (From Unique List)" << endl
         << "Choice 5: Search a value (From Duplicate List)" << endl
         << "Choice 6: Insertion after a specific value (From Unique List)" << endl
         << "Choice 7: Deletion at head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at a specific position" << endl
         << "Choice 10: Deletion by value (From Unique List)" << endl
         << "Choice 11: Reversal Non Recursive" << endl
         << "Choice 12: Finding Mid (slow fast pointer method" << endl
         << "Choice 0: Exit" << endl;

    cout << "Next Choice: ";
    int choice, position;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            cout << "Enter the desired position: ";
            cin >> position;
            cout << "Enter the Value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;

        case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
                cout << "The number is at Position " << position << endl;
            else
                cout << "The number not yet in the List" << endl;
            break;

        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            // searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
                cout << "The search value is not yet in the list" << endl;
            else
            {
                int size = T.position[0];
                cout << "The value is found at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            break;

        case 6:
            cout << "Enter the value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertByValueUnique(head, searchValue, value);
            break;

        case 7:
            deletionAtHead(head);
            break;

        case 8:
            deletionAtTail(head);
            break;

        case 9:
            if (head == NULL)
            {
                cout << "There is no value in the Linked List" << endl;
                break;
            }
            cout << "Enter the desire position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            cout << endl;
            display(head);
            break;

        case 10:
            cout << "Enter the value to delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;

        case 11:
            head = reverseNonRecursive(head);
            break;

        case 12:

            int mid;
            mid = findMid(head);
            if (mid == -1)
                cout << "Linked List is empty" << endl;
            else
                cout << "Mid is: " << mid << endl;
            break;

        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << "Linked List: ";
    display(head);
    cout << "Length of the List: " << countLength(head) << endl;
    return 0;
}