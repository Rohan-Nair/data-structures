// delete node by value in singly linked list is remaining

// test case :  5 2 7 8 2 10 20 3 101 0 102 4 103 25 4 0 45 3 5

/*
Linked list is a linear data structure which does not have contgious memory locations. They are linked using pointers. It is a collection of nodes. A node can n number of data fields and a reference link to the next node in the list.
 */

/*
// Singly linked list
// Singly linked liist allows only forward traversal of the list. It is useful for bit integer calculations
*/
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

// function to detect a loop in a LL
bool LLhasloop(node *head)
{
    // if the list is empty
    if (head == NULL)
        return head;
    map<node *, int> mp; // to check reoccurence
    node *ptr = head;

    while (ptr != NULL)
    {
        if (mp.find(ptr) != mp.end())
            return true; // the element is already present in the map hence it has been visited hence a loop is present
        // if its not in the map then add it to the map
        mp[ptr] = true;
        ptr = ptr->link;
    }
    return false;
}

int main()
{

    // creating the node
    int value = 0;
    cout << "enter the value of the node: ";
    cin >> value;
    node *node1 = new node(value);
    // creating a head pointer pointing to the start of the list
    node *head = node1; // if there is no node made before creating the head then point the head to null;
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

    // to check if the list has a loop or not
    
    return 0;
}

// -------------------------END OF SINGLY LINKED LIST--------------------------------------

/*
// Doubly Linked List
// A doubly linked list comtains a minimum of three fields : previous_link, forward_link, data. The previous link points to the previous node in the linked list. the rest of the fields work the same as singly linked list. Doubly linked list supports forward and backward traversal. Backwared traversal is carried out using the previous_link pointer. A head and tail pointer is always maintained pointing to the start and end of the doubly linked list respoectively. The start and end of the DLL both point to NULL.
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link; // pointer to point to the forward node
    node *prev; // pointer to point to the previous node

    // constructor
    node(int data)
    {
        this->data = data;
        this->link = NULL;
        this->prev = NULL;
    }
};

// function to print the elements of the list
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

// function to get the length of the DLL
int getLength(node *head, node *tail)
{
    int len = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->link;
    }
    return len;
}

// function to insert the value at the start of the DLL
void insert_at_head(node *&head, node *&tail, int value) // IMP-> Passing head and tail by reference
{
    // creating the node to be inserted
    node *temp = new node(value);
    // inserting the node
    temp->link = head; // joining the new node to the start of the list
    head->prev = temp; // joining the prev of the head to the new node
    head = temp;       // updating the head to the new start of the DLL
}

// function to insert the elements at the end of the DLL
void insert_at_tail(node *&head, node *&tail, int value)
{
    // creating the node
    node *temp = new node(value);
    // inserting the node
    temp->prev = tail; // connecting the prev of the node to the end of the list
    tail->link = temp; // connecting the end of the list to the new node
    tail = temp;       // updating the tail to the new end of the list
}

// function to isert a the element at any position
void insert_at_pos(node *&head, node *&tail, int value, int pos)
{
    // inserting at the start
    if (pos <= 1)
    {
        insert_at_head(head, tail, value);
        return;
    }

    // inserting in the middle
    node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (ptr->link != NULL)
            ptr = ptr->link;
        else if (ptr->link == NULL)
        {
            // the pointer has reached the last element of the list hence inserting element at the end of the list
            insert_at_tail(head, tail, value);
            return;
        }
    }

    // the pointer has reached the position to insert the element
    node *temp = new node(value); // creating the new node
    // modifying connections
    temp->link = ptr->link;
    ptr->link->prev = temp;
    ptr->link = temp;
    temp->prev = ptr;
}
int main()
{
    int value = 0;
    cout << "enter the value for the node: ";
    cin >> value;
    node *node1 = new node(value);

    // creating the head pointer pointing to the first node of the list. (head will point to null if there is no node already present in the list)
    // ERROR: head will point to null but while calling the inser functions the head
    node *head = node1;
    // creating the tail pointer also pointing to the first node of the list (same for tail)
    node *tail = node1;

    cout << "the length of the linked list is :" << getLength(head, tail) << endl; // the length cannot be foudn by subtracting the tail from the head like in an array as the memory locations are not contigious in a linked list

    // inserting n nodes into the linked list
    int n = 0;
    cout << "enter the number of nodes to be inserted into the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to add at the start of the list: ";
        cin >> tempvalue;
        insert_at_head(head, tail, tempvalue);
    }
    print_list(head, tail);

    cout << endl;
    n = 0;
    cout << "enter the number of nodes to be inserted at the end of the list: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to add to the end of the list: ";
        cin >> tempvalue;
        insert_at_tail(head, tail, tempvalue);
    }
    print_list(head, tail);

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
    // printing the elemments of the list
    print_list(head, tail);
    return 0;
}
*/

// ------------------------CORRECTION (for doubly linked list)----------------------------
/*
// if there is no element present in the list and the head adn tail point to null
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link; // pointer to point to the forward node
    node *prev; // pointer to point to the previous node

    // constructor
    node(int data)
    {
        this->data = data;
        this->link = NULL;
        this->prev = NULL;
    }
};

// function to print the elements of the list
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

// function to get the length of the DLL
int getLength(node *head, node *tail)
{
    int len = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->link;
    }
    return len;
}

// function to insert the value at the start of the DLL
void insert_at_head(node *&head, node *&tail, int value) // IMP-> Passing head and tail by reference
{
    // if the list is empty
    if (head == NULL)
    {
        // list is empty
        node *temp = new node(value); // creating the node
        head = temp;                  // making the new node which is the first node as head
        tail = temp;                  // making the first node also as tail
        return;
    }
    // creating the node to be inserted
    node *temp = new node(value);
    // inserting the node
    temp->link = head; // joining the new node to the start of the list
    head->prev = temp; // joining the prev of the head to the new node
    head = temp;       // updating the head to the new start of the DLL
}

// function to insert the elements at the end of the DLL
void insert_at_tail(node *&head, node *&tail, int value)
{
    // if the list is empty
    if (head == NULL)
    {
        node *temp = new node(value); // creating the new node
        head = temp;                  // making the new node which is the first node as head
        tail = temp;                  // making the first node also as tail
        return;
    }
    // creating the node
    node *temp = new node(value);
    // inserting the node
    temp->prev = tail; // connecting the prev of the node to the end of the list
    tail->link = temp; // connecting the end of the list to the new node
    tail = temp;       // updating the tail to the new end of the list
}

// function to isert a the element at any position
void insert_at_pos(node *&head, node *&tail, int value, int pos)
{
    // inserting at the start
    if (pos <= 1)
    {
        insert_at_head(head, tail, value);
        return;
    }

    // inserting in the middle
    node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (ptr->link != NULL)
            ptr = ptr->link;
        else if (ptr->link == NULL)
        {
            // the pointer has reached the last element of the list hence inserting element at the end of the list
            insert_at_tail(head, tail, value);
            return;
        }
    }
    // the pointer has reached the position to insert the element
    node *temp = new node(value); // creating the new node
    // modifying connections
    temp->link = ptr->link;
    ptr->link->prev = temp;
    ptr->link = temp;
    temp->prev = ptr;
}
int main()
{
    // creating the head pointer pointing to the first node of the list. (head will point to null if there is no node already present in the list)
    // ERROR: head will point to null but while calling the inser functions the head
    node *head = NULL;
    // creating the tail pointer also pointing to the first node of the list (same for tail)
    node *tail = NULL;

    // inserting n nodes into the linked list
    int n = 0;
    cout << "enter the number of nodes to be inserted into the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to add at the start of the list: ";
        cin >> tempvalue;
        insert_at_head(head, tail, tempvalue);
    }
    print_list(head, tail);

    cout << endl;
    n = 0;
    cout << "enter the number of nodes to be inserted at the end of the list: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to add to the end of the list: ";
        cin >> tempvalue;
        insert_at_tail(head, tail, tempvalue);
    }
    print_list(head, tail);

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
        print_list(head, tail);
    }
    // printing the elemments of the list
    print_list(head, tail);
    return 0;
}
*/

/*
// ------------------------CORRECTION (for singly linked list)----------------------------
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
void insert_at_head(node *&head, node *&tail, int value) // head taken by reference so that the node is inserted into the original linked list andnot into a copy of the linked list
{
    // if the list is empty
    if (head == NULL)
    {
        // list is empty
        node *temp = new node(value);
        head = temp; // updating the head to point to the new start of the list
        tail = temp; // updating the tail to point to the new end (start and end is same since there is only one node present in the list)
        return;
    }
    // list is not empty
    // create new node
    node *temp = new node(value);
    temp->link = head; // linking the new node to the start of the list
    head = temp;       // updating the head to point to the new start of the list
}

// function to insert the node at the end of the linked list
void insert_at_tail(node *&head, node *&tail, int value) // tail taken by reference to insert the node at the end of the origiinal list
{
    // if the list is empty
    if (tail == NULL)
    {
        // list is empty
        node *temp = new node(value);
        tail = temp; // updating the tail to point to the only element in the list
        head = temp; // updating the head to point to the only element in the list
    }
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
        insert_at_head(head, tail, value);
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
            insert_at_tail(head, tail, value);
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
    // if the list is empty
    if (head == NULL)
    {
        // list is empty
        cout << "the list is empty" << endl;
        return;
    }
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
    // creating a head pointer pointing to the start of the list
    node *head = NULL; // if there is no node made before creating the head then point the head to null;
    // also creating tail pointer to carry along to the end of the list to insert at tail
    node *tail = NULL;

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
        insert_at_head(head, tail, tempvalue);
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
        insert_at_tail(head, tail, tempvalue);
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
*/

/*
// -------------------DOUBLY CONTINUE---------------------------
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link; // pointer to point to the forward node
    node *prev; // pointer to point to the previous node

    // constructor
    node(int data)
    {
        this->data = data;
        this->link = NULL;
        this->prev = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        if (this->link != NULL)
        {
            delete link;
            link = NULL;
        }
        cout << "the value of the delete node is: " << value << endl;
    }
};

// function to print the elements of the list
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

// function to get the length of the DLL
int getLength(node *head, node *tail)
{
    int len = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->link;
    }
    return len;
}

// function to insert the value at the start of the DLL
void insert_at_head(node *&head, node *&tail, int value) // IMP-> Passing head and tail by reference
{
    // if the list is empty
    if (head == NULL)
    {
        // list is empty
        node *temp = new node(value); // creating the node
        head = temp;                  // making the new node which is the first node as head
        tail = temp;                  // making the first node also as tail
        return;
    }
    // creating the node to be inserted
    node *temp = new node(value);
    // inserting the node
    temp->link = head; // joining the new node to the start of the list
    head->prev = temp; // joining the prev of the head to the new node
    head = temp;       // updating the head to the new start of the DLL
}

// function to insert the elements at the end of the DLL
void insert_at_tail(node *&head, node *&tail, int value)
{
    // if the list is empty
    if (head == NULL)
    {
        node *temp = new node(value); // creating the new node
        head = temp;                  // making the new node which is the first node as head
        tail = temp;                  // making the first node also as tail
        return;
    }
    // creating the node
    node *temp = new node(value);
    // inserting the node
    temp->prev = tail; // connecting the prev of the node to the end of the list
    tail->link = temp; // connecting the end of the list to the new node
    tail = temp;       // updating the tail to the new end of the list
}

// function to isert a the element at any position
void insert_at_pos(node *&head, node *&tail, int value, int pos)
{
    // inserting at the start
    if (pos <= 1)
    {
        insert_at_head(head, tail, value);
        return;
    }

    // inserting in the middle
    node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (ptr->link != NULL)
            ptr = ptr->link;
        else if (ptr->link == NULL)
        {
            // the pointer has reached the last element of the list hence inserting element at the end of the list
            insert_at_tail(head, tail, value);
            return;
        }
    }
    if (ptr->link == NULL)
    {
        insert_at_tail(head, tail, value);
        return;
    }
    // the pointer has reached the position to insert the element
    node *temp = new node(value); // creating the new node
    // modifying connections
    temp->link = ptr->link;
    ptr->link->prev = temp;
    ptr->link = temp;
    temp->prev = ptr;
}

// function to delete an element by position
void deletebypos(node *&head, node *&tail, int pos)
{
    // if the list is empty
    if (head == NULL)
    {
        // list is empty
        cout << "the list is empty";
        return;
    }
    // list is not empty
    // deleting from the beginning
    if (pos <= 1)
    {
        // deleting the first element of the list
        node *temp = head;
        head = head->link;
        head->prev = NULL;
        temp->link = NULL;
        delete temp;
        return;
    }
    // deleting from the middle
    node *ptr = head;
    node *pre = NULL;
    for (int i = 1; i < pos; i++)
    {
        if (ptr->link != NULL)
        {
            pre = ptr;
            ptr = ptr->link;
        }
        else if (ptr->link == NULL && i < pos - 1)
        {
            // pointer has reached the end of the list
            cout << "pointer has reached the end of the list hence deleting from the end of the list: " << endl;
            tail = tail->prev;
            tail->link = NULL;
            ptr->prev = NULL;
            delete ptr;
            return;
        }
    }
    // if ptr has reached the end of the list
    if (ptr->link == NULL)
    {
        tail = tail->prev;
        pre->link = NULL;
        ptr->prev = NULL;
        delete ptr;
        return;
    }
    // ptr has reached the node to delete
    pre->link = ptr->link;
    ptr->link->prev = pre;
    ptr->link = NULL;
    ptr->prev = NULL;
    delete ptr;
}
int main()
{
    // creating the head pointer pointing to the first node of the list. (head will point to null if there is no node already present in the list)
    // ERROR: head will point to null but while calling the inser functions the head
    node *head = NULL;
    // creating the tail pointer also pointing to the first node of the list (same for tail)
    node *tail = NULL;

    // inserting n nodes into the linked list
    int n = 0;
    cout << "enter the number of nodes to be inserted into the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to add at the start of the list: ";
        cin >> tempvalue;
        insert_at_head(head, tail, tempvalue);
    }
    print_list(head, tail);

    cout << endl;
    n = 0;
    cout << "enter the number of nodes to be inserted at the end of the list: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value to add to the end of the list: ";
        cin >> tempvalue;
        insert_at_tail(head, tail, tempvalue);
    }
    print_list(head, tail);

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
        print_list(head, tail);
    }
    // printing the elemments of the list
    print_list(head, tail);

    // deleting n nodes from the list (deleting by position)
    n = 0;
    cout << "enter the number of nodes to be deleted from the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        cout << "enter the position to delete the node from: ";
        cin >> pos;
        deletebypos(head, tail, pos);
        cout << endl;
        print_list(head, tail);
    }
    return 0;
}
*/
// -------------------------END OF DOUBLY LINKED LIST--------------------------------------
/*
// Circular Linked List: There are two types of circular linked list: Dingly and Doubly. A circular linked list does not have a start and end point. Only a tail pointer is maintained and all the operations can be performed using the tail pointer. There is no null value present in any node.
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;

    // constructor
    node(int data)
    {
        this->data = data;
        this->link = NULL;
    }

    // desctructor
    ~node()
    {
        int value = this->data;
        if (this->link != NULL)
        {
            delete link;
            link = NULL;
        }
        cout << "the value of the deleted node : " << value << endl;
    }
};

// function to insert values an the head of the list
void insert_at_head(node *&tail, int value)
{
    // if the list is empty
    if (tail == NULL)
    {
        // the list is empty
        node *temp = new node(value); // creating the new node
        tail = temp;
        temp->link = temp; // first node points to itself
        return;
    }
    // list is not empty
    node *temp = new node(value); // creating the new node
    temp->link = tail->link;
    tail->link = temp;
}

// function to insert values at the tail of the list
void insert_at_tail(node *&tail, int value)
{
    // if list is empty
    if (tail == NULL)
    {
        // tail is empty
        node *temp = new node(value);
        tail = temp;
        temp->link = temp;
        return;
    }
    // list is not empty
    node *temp = new node(value);
    temp->link = tail->link;
    tail->link = temp;
    tail = tail->link;
    return;
}
// function to insert at position (in the middle of the list)
void insert_at_mid(node *&tail, int value, int pos) //!!!!!left to debug!!!!!
{
    // if the list is empty
    if (tail == NULL)
    {
        // list is emppty
        node *temp = new node(value); // creating the node
        tail = temp;
        tail->link = temp;
        return;
    }
    // list is not empty
    if (pos < 1)
    {
        insert_at_head(tail, value);
        return;
    }
    node *ptr = tail;
    for (int i = 0; i < pos; i++) // i = 0 & i < position since the pointer is starting from the tail and not from the "first" element of the list.
    {
        if (ptr->link != tail)
            ptr = ptr->link;
        else if (ptr == tail)
        {
            node *temp = new node(value);
            temp->link = tail->link;
            tail->link = temp;
            tail = temp;
            return;
        }
    }
    if (ptr->link == tail)
    {
        insert_at_tail(tail, value);
        return;
    }
    // ptr is at the poisition to isnert the node
    node *temp = new node(value);
    temp->link = ptr->link;
    ptr->link = temp;
    return;
}

// function to insert after a certtain node
void insert_at_node(node *&tail, int element, int value)
{
    // list is empty
    if (tail == NULL)
    {
        // list is empty
        node *temp = new node(value);
        tail = temp;
        tail->link = tail;
        return;
    }
    // list is not empty
    else
    {
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->link;
            if (curr == tail)
            {
                cout << "the element is not present in the list. " << endl;
                return;
            }
        }
        // element is found an current is on the element
        node *temp = new node(value);
        temp->link = curr->link;
        curr->link = temp;
    }
}

// function to delete the element by value
void del_by_value(node *&tail, int element)
{
    // if the list is empty
    if (tail == NULL)
    {
        cout << "the list is empty : ";
        return;
    }
    // list is not empty
    node *ptr = tail->link;
    node *pre = tail;
    // only one node in the list
    if (pre = ptr)
    {
        // only one node in the list
        tail == NULL;
        delete ptr;
        delete pre;
        return;
    }
    while (ptr->data != element)
    {
        pre = ptr;
        ptr = ptr->link;
        if (ptr->link = tail->link)
        {
            // ptr has reached the end of the list and the element has still not been found
            cout << "element is not present in the list" << endl;
            return;
        }
    }
    if (ptr == tail)
    {
        // the element is the last node of the list so tail will have to be updated after deletion
        pre->link = ptr->link;
        tail = pre;
        ptr->link == NULL;
        delete ptr;
        return;
    }
    // ptr is at the element to delete
    pre->link = ptr->link;
    ptr->link = NULL;
    delete ptr;
}
// function to print the elements in the list
void print_list(node *tail)
{
    if (tail == NULL)
    {
        // list is empty
        cout << "------------------------------------" << endl;
        cout << "list is empty" << endl;
        cout << "------------------------------------" << endl;
        return;
    }
    cout << "------------------------------------" << endl;
    cout << "the elements in the list are: ";
    node *temp = tail->link;
    // using the do-while loop so that the loop is executed at least once
    do
    {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != tail->link);
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "tail: " << tail->data << endl;
    cout << "------------------------------------" << endl;
    return;
}
int main()
{
    node *tail = NULL; // creating the tail node

    // inserting n nodes at the head of the list
    int n = 0;
    cout << "enter the number of nodes to enter in the head of the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value of the node: ";
        cin >> tempvalue;
        insert_at_head(tail, tempvalue);
    }
    // printing the elements in the list
    print_list(tail);

    // inserting n nodes at the tail of the list
    n = 0;
    cout << "enter the number of nodes to enter at the tail of the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value of the node: ";
        cin >> tempvalue;
        insert_at_tail(tail, tempvalue);
    }
    // printing the elements in the list
    print_list(tail);

    // ------------------------left to debug------------------
    // // inserting n nodes in the list (mid of the list)
    // n = 0;
    // cout << "enter the number of nodes to be entered in the list: ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int tempvalue = 0;
    //     cout << "enter the value of the node: ";
    //     cin >> tempvalue;
    //     int pos = 0;
    //     cout << "enter the position to place the node: ";
    //     cin >> pos;
    //     insert_at_mid(tail, tempvalue, pos);
    //     print_list(tail);
    // }
    // // printing the elements in the list
    // print_list(tail);
    // ---------------------------------------------------------------

    // inserting n nodes in the list by element
    n = 0;
    cout << "enter the number of nodes to be entered in the list : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tempvalue = 0;
        cout << "enter the value of the node: ";
        cin >> tempvalue;
        int element = 0;
        print_list(tail);
        cout << "enter the element after which the node should be added : ";
        cin >> element;
        insert_at_node(tail, element, tempvalue);
    }
    print_list(tail);

    // deleting n nodes by value
    n = 0;
    cout << "enter the number of nodes to be deleted: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int valuetodel = 0;
        cout << "enter the value to be deleted: ";
        cin >> valuetodel;
        del_by_value(tail, valuetodel);
        print_list(tail);
    }
    return 0;
}
 */
// -------------------------END OF CIRCULAR LINKED LIST--------------------------------------

// Linked List Cycle Detection
// Floyd Rabbit Hare Algorithm


