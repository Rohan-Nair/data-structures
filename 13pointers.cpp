/*
Pointers in C++
int num = 5
cout << num;
in the memory some memory address will store the value of num in the memory. but how is num mapped to the address of the value so that the value is printed when cout << num; ?? the compiler uses a data structure called symbol table. num is mapped to the memory address of the value of num stored in the memory. so when cout << num then the value at the address which is mapped to num is printed.

address of operator (&)
#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    cout << "the address of 5 is : " << &num << endl; //0x61fe1c hex form
    return 0;
}
*/

// Pointers are used to store addresses
/*
#include <iostream>
using namespace std;
int main()
{
    int i = 5;
    // declaring a pointer
    int *ptr = NULL; // this is a null pointer. initialise the pointer to null if there is no value to be assigned to the pointer
    // a pointer must never be left uninitialised. pointers if left uninitialized could point to random locations in memory and create problems that memory might be used by some other program.
    ptr = &i;
    cout << "the address of the value 5 is : " << ptr;
    cout << "the value of i is : " << *ptr;
    // * is the dereferencing operator is used to dereference the value stored in the pointer
    // *<ptr_name>
    // int *ptr--> ptr is a pointer to int

    return 0;
}
*/

/*
 Pointer arithmetic
#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    int *ptr = &num;
    cout << "the value of num is : " << *ptr << endl;
    cout << "the address which the pointer is pointing to is : " << ptr << endl;
    cout << "incrementing the pointer the pointer will point to some other memory address; " << endl;
    *ptr++;
    cout << "the address which the pointer is pointing to is: " << ptr << endl;
    // the difference in the addresses in the above statements will be 4 since int takes up 4 bytes
    *ptr--;
    // the pointer is now pointing back to num
    cout << "the value of num using pointer is : " << *ptr << endl;
    cout << "the address which the pointer is pointing to is : " << ptr << endl;
    // incrementing the value of num using the pointer
    (*ptr)++; // the value of num is incremented (becomes 6)
    cout << "the value of num is : " << num << endl;
    (*ptr)--; //the value of num is 5 again
    return 0;
}
*/

/*
Copying a pointer
#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    int *ptr = &num;
    int *p = ptr;
    cout << "the address stored by p is :" << p << endl;
    cout << "the address stored by ptr is :" << ptr << endl;
    cout << "the value at p is: " << *p << endl;
    cout << "the value at ptr is: " << *ptr << endl;
    return 0;
}
*/

/*
Types of pointers
1) Null pointer
2) Void pointer
3) Wild pointer
4) Dangling pointer
*/

/*
NULL pointer
Pointers can store null value besides than addresses
when a pointer points to null it means that it does not point to anything
#include <iostream>
using namespace std;
int main()
{
    // ways to initialize a null pointer
    int *ptr = NULL;
    int *ptr2 = 0;
    int *ptr3{};
    int *ptr4 = nullptr; // the null pointer keyword can be used to initialise a null pointer
    // the nullptr keyword can also be used to make a valid pointer to a null pointer like :
    int num = 5;
    int *numpointer = &num;
    cout << "the value of the pointer is : " << *numpointer << endl;
    numpointer = nullptr;
    cout << numpointer << endl;
    // accessing a null pointer will cause undefined behavior (probably an application crash).
    // cout << *ptr << endl; // warning!!!
    return 0;
}
*/

/*
Void pointer
Void pointers do not have any data type and can store the address of any type. malloc() and calloc() return void pointers. They need to be type casted to some type in oreder to be used. Void pointers cannot be dereferenced.
#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    void *ptr = NULL;
    ptr = &num;
    cout << "the value of num is: " << *(int *)ptr; // typecasting the void pointer to int type
    // cout << *ptr;                                // Void pointers cannot be dereferenced.

    return 0;
}
*/

/*
Wild pointer (!!Bad Practice!!)
An uninitialized pointer is called as void pointer
#include <iostream>
using namespace std;
int main()
{
    int *ptr; // ptr is a wild pointer here
    int num = 5;
    ptr = &num; //ptr is not a wild pointer anymore
    cout << "the value of num is: " << *ptr;
    return 0;
}
*/

/*
Dangling pointer
Dangling pointer is similar to Wild pointer but is caused as a result of deallocation of memory pointed by the ponter
#include <iostream>
using namespace std;
int main(){
    int num = 5;
    int *ptr = &num;
    free(ptr);
    // ptr is now a dangling pointer
    ptr = nullptr; //not a dangling pointer anymore
    int *ptr2;
    {
        int num2 = 5;
        ptr2 = &num2;
    }
    // here ptr2 is a dangling ponter as it is out of scope
    return 0;
}
*/

/*
Pointers and arrays
#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {34, 434, 3, 34, 2234, 789, 5867, 234, 23, 5235};
    // the name of the array depicts the address of the first location in the array
    cout << "the address of the first location of the array is: " << arr << endl;
    // the address of the first location of the array can also be found using the & operator
    cout << "the address of the first location of the array using the & operator is : " << &arr[0] << endl;
    // printing the first element of the array can be done using the dereferencing operator alonng with
    cout << "the first element of the array is: " << arr[0] << endl;
    cout << "the first element of the array is: " << *arr << endl;
    cout << "the value at the first index is: " << *(arr + 1) << endl;
    cout << "*arr + 1 will add one to the index at the 0th index : " << *arr + 1 << endl;
    // !!IMP!! -> arr[i] = *(arr + i)
    // !!IMP!! -> i[arr] = *(i + arr)
    cout << "the 5th element of the array is : " << arr[5] << endl;
    cout << "the 5th element of the array is : " << *(arr + 5) << endl;
    cout << "the 5th element of the array is : " << 5 [arr] << endl;
    cout << "the 5th element of the array is : " << *(5 + arr) << endl;

    // sizeof()
    // in case of int array 4*number of elements
    cout << "the size of (memory locations allocated) the array is : " << sizeof(arr) << endl;
    int *ptr = &arr[0];
    // in case of pointer since pointer stores address hence size will be 8
    cout << "the size of the pointer to the array is " << sizeof(ptr) << endl;
    // in case of first element of the integer
    cout << "the size of the first element of the array is: " << sizeof(*ptr) << endl;

    // Symbol table of cannot be modified hence
    // arr = arr + 1 will give error even though arr points to the first element of the array. On the other hand incrementing a pointer is valid and will not give any error
    // int *ptr = arr; ptr++ is valid and will point to the address of the second element in the array


    return 0;
}
*/

/*
Character arrays
#include <iostream>
using namespace std;
int main()
{

    // cout works differently for character arrays and integer arrays.
    int arr[3] = {46, 4, 7};
    char ch[6] = "abcde";
    cout << "printing the name of the array will return the address to the first location of the array : " << arr << endl;
    cout << "printing the name of the character array will print all the values in the character array : " << ch << endl;
    // even the pointer to the character array will print the entire string and not the address to the first location of the character array
    char *c = &ch[0];
    cout << "in integer array the address of the first location will be printed but in character array all the values of the character array will be printed like : " << c << endl;

    // the pointer will print till a null character is found
    char l = 'x';
    char *p = &l;
    cout << p << endl;
    return 0;
}
*/

/*
Pointers and functions
#include <iostream>
using namespace std;
void print(int *p)
{
    cout << "printing p will print the address stored in p: " << p << endl;
    cout << "printing the value of p: " << *p << endl;
}
void updateptr(int *p)
{
    p = p + 1;
    // the pointer in the function is a copy of the argument passed in the main() function and any modification will not have any effect on the original pointer outisde the function block
    cout << p << endl;
    cout << *p << endl;
}
void updateval(int *p)
{
    *p = *p + 1;
    // the above vode will have effect on the original pointer in the main function
}
int main()
{
    int num = 5;
    int *ptr = &num;
    print(ptr);
    cout << "before updating pointer : " << ptr << endl;
    updateptr(ptr);
    cout << "after updating pointer : " << ptr << endl;
    cout << "before updating value of the pointer using function : " << *ptr << endl;
    updateval(ptr);
    cout << "after updating value of the pointer using function : " << *ptr << endl;
    return 0;
}
*/

/*
Double Pointers in C++
POinters to pointers. When a double pointer is defined it contains the address of a pointer which points to the actual value
#include <iostream>
using namespace std;
void print(int **ptr)
{
    cout << "the value of num is: " << **ptr << endl;
    cout << "the value of the pointer to num (address of num) is" << *ptr << endl;
    cout << "the value of the address of the pointer to num is: " << ptr << endl;
}
void updateval(int **ptr)
{
    // updating the value of num using pointer to pointer
    **ptr = **ptr + 1;
}
void updateptr2ptr(int **ptr)
{
    ptr = ptr + 1;
    // the pointer to pointer in the function is a copy and the above modiification will not have any effect on the original double pointer in the main() function
}
int main()
{
    int num = 5;
    int *ptr = &num;
    // declaring a pointer to pointer
    int **ptr2 = &ptr;
    cout << "the value of num is : " << num << endl;
    cout << "the value of num using pointer is: " << *ptr << endl;
    cout << "the value of num using pointer to pointer is: " << **ptr2 << endl;
    cout << "the address of num is: " << ptr << endl;
    cout << "the address of num is: " << *ptr2 << endl;
    cout << "the address of the pointer to num is: " << &ptr << endl;
    cout << "the address of the pointer to num is: " << ptr2 << endl;

    // using double pointers in functions
    print(ptr2);
    cout << "the value of num before updation is : " << num << endl;
    updateval(ptr2);
    cout << "the value of num after updation is : " << num << endl;
    cout << "the value of the double pointer before updation is : " << ptr2 << endl;
    cout << "the value of the double pointer after updation is : " << ptr2 << endl;
    return 0;
}
*/