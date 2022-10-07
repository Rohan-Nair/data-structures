#include <iostream>
using namespace std;
void function_for_pointer(int *p);
void update_pointer_value(int *p);
auto update_pointer(int *arr_ptr);
int main()
{
    // int num = 5;
    // // pointer stores the address
    // int *ptr = NULL; // creating a pointer do not leave it uninitialized as it may point to any garbage memory and is bad practice
    // ptr = &num;      //---1
    // // either create a null pointer and then assign the address to the pointer variable or
    // int *ptr2 = &num; // ----2
    // // 1 & 2 are equivalent;

    // // to print the values in a pointers using the dereferencing operator
    // cout << endl;
    // cout << "num = " << num << endl;
    // cout << endl;
    // cout << "value of the pointer ptr (the address of num) is = " << ptr << endl;
    // cout << endl;
    // cout << "this is same as the address of num which is  = " << &num << endl;
    // cout << endl;
    // cout << "the value of the dereferencing of the pointer(ptr) to num is : " << *ptr << endl;
    // cout << endl;

    // // copying a pointer
    // int *ptr_cpy = ptr; // will not need address operator (&) here as ptr is a poiinter and already holds an address

    // cout << "address of the pointer to pointer is : " << ptr_cpy << endl;
    // cout << endl;
    // cout << "value of the address at the pointer to the pointer is : " << *ptr_cpy << endl;
    // cout << endl;

    // // pointer arithmetic
    // int example = 100;
    // int *ex_ptr = NULL;
    // ex_ptr = &example;
    // cout << "incrementing example: " << ++example << endl;
    // cout << endl;
    // cout << "incrementing example through pointer: " << ++(*ex_ptr) << endl;
    // cout << endl;
    // // incrementing the pointer
    // cout << "before : " << ex_ptr << endl;
    // cout << endl;
    // ex_ptr++; // the pointer will go to the next address
    // cout << "after  :" << ex_ptr << endl;
    // cout << endl;

    // // arrays and pointers
    // int arr[3] = {1, 5, 9};
    // // the name of the array points to the address of the first element of the array
    // cout << "the address of the first element of the array is : " << arr << endl;
    // cout << endl;
    // cout << "second way \nthe address of the first element of the array is : " << &arr[0] << endl;
    // cout << endl;
    // cout << "the first element of the array is : " << *arr << endl;
    // cout << endl;
    // cout << "the second element of the array(as the dereferencing of arr + 1 is being done) is : " << *(arr + 1) << endl;
    // cout << endl;
    // cout << "the sum of the first element of the array with 10 is : " << *arr + 10 << endl;
    // cout << endl;
    // cout << "(the above statment and this statement are equivalent) the sum of the first element of the array with 10 is : " << *(arr) + 10 << endl;
    // cout << endl;
    // // the value off the ith element in the array is *(arr + i - 1) where i is index of the element
    // cout << "the value of the 3rd element in the array using poimters is : " << *(arr + 3 - 1) << endl;
    // cout << endl;
    // // !!important!!
    // // the above formula also works as `i-1[arr] = *(i-1 + arr) where i is index of the element`
    // cout << "the value of the 3rd element in the array is : " << (3 - 1)[arr] << endl;
    cout << endl;

    // difference between arrays and pointers
    // int arr[10]{1}; // will allocate 40 bytes of memory (since 4 bytes are required to store int)
    // int *ptr = &arr[0];
    // cout << "the size of the pointer-to-the-array (stores address) is : " << sizeof(ptr) << endl;
    // cout << endl;
    // cout << "the size of the first element using pointers is : " << sizeof(*ptr) << endl;
    // cout << endl;
    // cout << "the size of the address of the first element is : " << sizeof(&ptr) << endl;
    // cout << endl;
    // cout << "----------------" << endl;
    // cout << "the size of the array (memory allocated) is : " << sizeof(arr) << endl;
    // cout << endl;
    // cout << "the size of the first element of the array is : " << sizeof(*arr) << endl;
    // cout << endl;
    // cout << "the size of the address of the first element is : " << sizeof(&arr) << endl;
    // cout << endl;
    // cout << "----------------" << endl;
    // cout << "the address of the first element of the array is : " << &arr[0] << endl;
    // cout << "the address of the first element of the array is : " << &arr << endl;
    // cout << "the address of the first element of the array is : " << arr << endl;
    // cout << "array type is not assignable hence arr = arr + 1 will throw error" << endl;
    // cout << "----------------" << endl;

    // !!important!!
    // cout works differently for charachert arrays and integer arrays
    // char char_arr[6] = "rohan";
    // int int_arr[3] = {1, 2, 3};
    // cout << "the address of the first element in the array is : " << int_arr << endl;
    // cout << endl;
    // cout << "the entire char array is printed : " << char_arr << endl;
    // cout << endl;
    // int *ptr = &int_arr[0];
    // char *c_ptr = &char_arr[0];
    // cout << "the address of the first element of the integer array is: " << ptr << "\nthe value of the first element of the integer array is : " << *ptr << endl;
    // cout << endl;
    // cout << "wont print the addres sbut print the entire string : " << char_arr << "\n will print the first element of the character array :  " << *char_arr << endl;
    // cout << endl;
    // cout << "cout will work till null character is not found like : " << char_arr << endl;
    // char temp1 = 'r';
    // char *temp1_ptr = &temp1;
    // cout << "if null character is not found then cout(with pointer) will keep printing till a null character is found like : " << temp1_ptr << endl;
    // // lec 26 : 46:00

    // pointer s and functions
    int value = 5;
    int *p = &value;
    function_for_pointer(p);
    return 0;
}
void function_for_pointer(int *p)
{
    cout << "the value stored at the address stored at the pointer p is  : " << *p << endl;
    cout << endl;
    cout << "the address stored at the pointer p is : " << p << endl;
    cout << endl;
    cout << "the value before updation is :" << *p << endl;
    cout << endl;
    update_pointer_value(p);
    cout << "the value after updation is : " << *p << endl;
    cout << "----------------" << endl;
    cout << "trying to update the pointer" << endl;
    int arr[3] = {1, 2, 3};
    int *arr_ptr = arr;
}
void update_pointer_value(int *p)
{
    // p = p + 1;
    // this will update the pointer inside the function p will still point to where it was pointing before the function call. the pointer cannot be updated inside the function
    // although the value of the pointer can be updated iside the function like
    *p = *p + 1;
}
auto update_pointer(int *arr_ptr)
{
    arr_ptr = arr_ptr + 1;
    return arr_ptr;
}