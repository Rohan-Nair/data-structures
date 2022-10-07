/*
Reference Variable:
Another alsternate name given to the same existing variable. Same memory different name. It should be initialise at the time of declaration and cannot be null. it cannot be changed to refer to another variable.
#include <iostream>
using namespace std;
void update(int &n)
{
    n++;
}
int &function(int n)
{
    int num = n;
    int &ans = num;
    // this is bad practice as 'num' and its reference are local variables and do not exist outside the function block. hence the value of num will be erased outside of the function but the reference will still exist and might be a security bug. This case also exists in case of pointers
    return ans;
}
int main()
{
    int num = 5;
    // declaring a reference variable
    int &ref = num;
    cout << "the value of num is: " << num << endl;
    cout << "the value of num using the reference variable is: " << ref << endl;
    // the value of the original variable will also be updated by changing the reference variable
    ref++;
    cout << "the value of num after updation is: " << num << endl;
    cout << "the value of the reference variable is: " << ref << endl;

    // When passing a variable to a function its copy is made and the variable is passed by value. all modiifications done to the variable inside the function have no effect on the variable outside the function. When passing a variable to a function as a referece variable the original variable is sent to the function and all modifications will have effect on the variable even outside the function. This is called pass by reference. When passing a variable to the function by value new memory is allocated to store the copy of the variable. In pass by reference no new memory is allocated during function call.
    int val = 10;
    cout << "the value of val before updation is : " << val << endl;
    update(val);
    cout << "the value of val after updation is: " << val << endl;

    // functions with return type of a local reference variable are bad practice
    cout << function(val) << endl;
    return 0;
}
*/

/*
Dynamic memory allocation with new
Memory allocated dynamically is taken from the heap memory. Every program at runtime is allocated a temporary memory called stack memory.
int arr[n];
the above code is trying to create a array of user input length but this is bad practice and in most cases not allowed by the compiler as the memory is being used from the stack and the input may be greater than the memory available in the stack thus causing the program to crash.
To avoid this memory is allocated dynamically using the new keyword. This memory is allocated in the heap. the memory cannot be allocated to a variable in as the address is being allocated and hence a pointer is used to store the address.
#include <iostream>
using namespace std;
int main()
{
    // DMA of an array of input size
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    return 0;
}
*/

/*
Difference between static and dynamic memory allocation
1) if say 5 size array is allocated statically (int arr[5];) the memory allocated is 5*4 = 20bytes on the stack. if a 5 size array is allocated dynamically (int *arr = new int[5];) the memory allocated is 5 * 4 = 20bytes on the heap + 8 bytes for the pointer on the stack. total = 28bytes.
2)
case1:
while (true)
{
    int i = 5;
}
-----> in the above case i is allocated statically and is freeed and the loop goes back into the while loop. at every instance only one int memory is allocated and then released before the next iteration
case 2:
while (true)
{
    int* i = new int;
}
----> in the above case i is allocated dynamically with every iteration and is not freed. new memory is allocated on the heap with every iteration. the program will crash once the heap is full.

In static memory the memory is automatically allocated and freed but in DMA memory allocation and relasing is done manually.
Releasing of memory can be done as follows
int* i = new int; //allocation
delete i; //deletion
int* arr = new int[size]; //allocation
delete []arr; //deletion
*/

/*
Dynamic Memory Allocation of 2D arrays
A 2D array is a collection of 1D arrays. 1D arrays are allocated dynamically using the new keyword. But since the 1D arrays are pointers the 2D array would be a collection of 1D array pointers
hence to store the collection of pointers a pointer to pointer would be needed
one 1d array would be int *arr1 having size to store m elements and n number of such arrays are needed
2d array[3][3];
int *arr1 = new int[3];
int *arr2 = new int[3];
int *arr3 = new int[3];
this collection is a 2d array
#include <iostream>
using namespace std;
int main()
{
    // creating a square 2d array (m = n)
    int n = 0;
    cin >> n;
    int **arr2d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr2d[i] = new int[n];
    }
    // taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr2d[i][j];
        }
    }
    // output
    cout << endl;
    cout << "the 2d array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }
    // freeing the memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr2d[i];
    }
    delete[] arr2d;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    // creating a 2d array with m != n
    int n = 0;
    cout << "enter n: ";
    cin >> n;
    int m = 0;
    cout << "enter m: ";
    cin >> m;
    int **arr2d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr2d[i] = new int[m];
    }
    // taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr2d[i][j];
        }
    }
    // output
    cout << endl;
    cout << "the 2d array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }

    // freeing the memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr2d[i];
    }
    delete[] arr2d;
    return 0;
}
*/

/*
Jagged array
#include <iostream>
using namespace std;
int main()
{
    int rows = 0;
    cout << "enter rows: ";
    cin >> rows;
    int **arr = new int *[rows];
    int *cols = new int[rows]; // to store the cols sizes
    // creatng the jagged array
    for (int i = 0; i < rows; i++)
    {
        cout << "enter the size of the " << i + 1 << " row: ";
        cin >> cols[i];
        arr[i] = new int[cols[i]];
    }
    // taking input
    cout << endl;
    cout << "enter the elements in the array" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "enter the elements in the " << i + 1 << "row : ";
        for (int j = 0; j < cols[i]; j++)
        {
            cin >> arr[i][j];
        }
    }
    // output
    cout << endl;
    cout << "the jagged array is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
*/