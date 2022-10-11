// test case :  5 2 7 8 2 10 20 3 101 0 102 4 103 25 4 0 45 3 5

/*
Linked list is a linear data structure which does not have contgious memory locations. They are linked using pointers. It is a collection of nodes. A node can n number of data fields and a reference link to the next node in the list.
 */

// Singly linked list
// Singly linked liist allows only forward traversal of the list. It is useful for bit integer calculations
#include <iostream>
using namespace std;
class node
{
public:
    // creating components of the node
    int data;   // store the value
    node *link; // to store the address of the next node

    // constructor (to be created when the object is created)
    node(int data)
    {
        this->data = data;
        this->link = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        // freeing the memory (if the object is created by using new or the constructor uses new to allocate memory which resides in the heap memory or the free store, the destructor should use delete to free the memory.)
        if (this->link != NULL)
        {
            delete link;
            this->link = NULL;
        }
        cout << "the value of the deleted node is: " << value << endl;
    }
};

// function to insert the node at the start of the linked list
void insert_at_head(node *&head, int value) // head taken by reference so that the node is inserted into the original linked list andnot into a copy of the linked list
{
    // create new node
    node *temp = new node(value);
    temp->link = head; // linking the new node to the start of the list
    head = temp;       // updating the head to point to the new start of the list
}

// function to insert the node at the end of the linked list
void insert_at_tail(node *&tail, int value) // tail taken by reference to insert the node at the end of the origiinal list
{
    // creating the new node
    node *temp = new node(value);
    tail->link = temp; // linking the last node to the new node
    tail = temp;       // updating the tail to point to the newly inserted node at the end of the list
    // tail = tail->link; is an alternative to tail = temp;
}

// function to insert the node at the given position (in the middle) of the linked list
void insert_at_pos(node *&head, node *&tail, int value, int pos)
{
    // inserting at the start
    if (pos <= 1)
    {
        insert_at_head(head, value);
        return;
    }

    // inserting in the middle
    node *ptr = head;                 // assigning a pointer to the start of the list;
    for (int i = 1; i < pos - 1; i++) // traversing till the (pos - 1)th node
    {
        if (ptr->link != NULL)
            ptr = ptr->link;
        else if (ptr->link == NULL) // the pointer has reached the last element of the list so insert at the end
        {
            insert_at_tail(tail, value);
            return;
        }
    }
    node *temp = new node(value); // creating the new node
    temp->link = ptr->link;       // linking the new node
    ptr->link = temp;             // inserting the node into the list
}

// function to delete a node by position
void deletenodebypos(node *&head, node *&tail, int pos)
{
    // deletion from the beginning
    if (pos <= 1)
    {
        node *temp = head;
        head = head->link;
        temp->link = NULL; // freeing the memory of the deleted node
        delete temp;
    }
    // deletion from position
    else
    {
        node *ptr = head; // current pointer
        node *pre = NULL; // previous pointer
        for (int i = 1; i < pos; i++)
        {
            if (ptr->link == NULL && i < pos) // the pointer ptr has reached the end of the list and i is still less than the position (meaning the position given is grater than the size of the linked list) in this case delete the last element of the list
            {
                cout << "the position is greater than the size of the linked list hence deleting the last node of the list." << endl;
                pre->link = NULL; // pre is the new end of the linked list
                tail = pre;       // setting the tail to the new end of the linked list
                ptr->link = NULL; // freeing the memory before deleting the node
                delete ptr;
                return;
            }
            pre = ptr;
            ptr = ptr->link;
        }
        // ptr is at the location the node has to be deleted
        pre->link = ptr->link; // joining previous to the next of the node to be deleted (current node)
        if (ptr->link == NULL) // if the last element of the list is being deleted
        {
            tail = pre; // setting the tail to the new end of the list
            delete ptr; // ptr-> link is already null as it is the last element of the list
            return;
        }
        ptr->link = NULL; // freeing the memory before deleting the node
        delete ptr;
    }
}

// function to print the values of the singly linked list (traversing the linked list)
void print_list(node *&head, node *tail)
{
    cout << "---------------------------------" << endl;
    cout << "printing the values in the list: ";
    node *ptr = head;   // making a pointer pointing to the start of the list
    while (ptr != NULL) // till the poiinter doesnt reach the end of the list
    {
        cout << ptr->data << " "; // printing the data of the current node
        ptr = ptr->link;          // going to the next node
    }
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "the head is at element: " << head->data << endl;
    cout << "the tail is at element: " << tail->data << endl;
    cout << "---------------------------------" << endl;
}

int main()
{
    // creating the node
    int value = 0;
    cout << "enter the value of the node: ";
    cin >> value;
    node *node1 = new node(value);
    // creating a head pointer pointing to the start of the list
    node *head = node1;
    // also creating tail pointer to carry along to the end of the list to insert at tail
    node *tail = node1;
    // a node is now created with the value given by the user and the link pointing to null
    // printing the data in the node
    cout << "data of new node: " << node1->data << endl;
    cout << "link of the new node(null) : " << node1->link << endl;
    cout << endl;

    // !!INSERTION OF ELEMENTS!!
    // inserting n nodes into the list (inseting at head)
    int n = 0;
    cout << "enter the number of nodes to be added to the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value in the beginning of the linked list: ";
        cin >> tempvalue;
        insert_at_head(head, tempvalue);
    }
    cout << endl;

    // printing the values in the list
    print_list(head, tail); // the values will be printes in the reverse order of insertion as they were inserted at the start of the list

    cout << endl;
    // inserting n nodes to a list (inserting at tail)
    n = 0;
    cout << "enter the number of nodes to be added to the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to be inserted at the end of the linked list: ";
        cin >> tempvalue;
        insert_at_tail(tail, tempvalue);
        cout << endl;
    }
    // printing the values in the list
    print_list(head, tail); // the new values will be printed in the order they were inserted at the values were inserted at the end of the list

    cout << endl;
    // inserting n nodes at the given positions (inserting in the middle of the list)
    n = 0;
    cout << "enter the number of nodes to be added to the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        int pos = 0;
        cout << "enter the value of the node to be inserted in the list: ";
        cin >> tempvalue;
        cout << "enter the position where the node should be inserted: ";
        cin >> pos;
        insert_at_pos(head, tail, tempvalue, pos);
        cout << endl;
    }
    // printing the values in the list
    print_list(head, tail);

    cout << endl;

    // !!DELETION OF ELEMENTS!!
    // deleting by position
    n = 0;
    cout << "enter the number of elements to be deleted from the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        cout << "enter the position to delete the elements from: ";
        cin >> pos;
        deletenodebypos(head, tail, pos);
        print_list(head, tail);
    }
    return 0;
}