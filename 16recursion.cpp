// Day - 1

/*
When a function calls itself it is called recursion
When to use recursion?
When a big complex problem depends on a similar smaller problem of the same type

The end condition to stop recursion is called the base case. it is mandatory to return from the base case.
creating a recursive function is necessary for recursion
*/
// example
/*
factorial of a number
the base case is 0 as the factorial of 0 is 1 is known
the recurrence relation of factorial of a number is: f(n) = n * f(n - 1)
#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    // if the base case is absent then the function call on the stack keeps on increasing till the entire stack memory and the stack overflows with function calls and then segmentation fault occurs.
    return n * factorial(n - 1);
}
int main()
{
    int n = 0;
    cin >> n;
    cout << "the factorial of " << n << " is : " << factorial(n);
    return 0;
}

Types of recursion:
In recursion the base case is always written at the beginning of the function. The processing may be written before the recurrence relation or vice versa. if the processing is written before the recurrence relation it is called tail recurrsion else and head recursion of the recurrence relation is written before the processing.
*/

/*
// power of 2
#include <iostream>
using namespace std;
int func(int n)
{
    if (n == 0)
        return 1;
    return 2 * func(n - 1);
}
int main()
{
    int n = 0;
    cin >> n;
    cout << "the value of 2**" << n << " is: " << func(n) << endl;
    return 0;
}

// print numbers
#include <iostream>
using namespace std;
void printno(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printno(n - 1);
}
int main()
{
    int n = 0;
    cin >> n;
    printno(n);
    return 0;
}

// nth fibonacci number
#include <iostream>
using namespace std;
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2); // the nth fibonacci number is the sum of its previous two fibonacci numbers .
}
int main()
{
    int n = 0;
    cin >> n;
    cout << "the " << n << " fibonacci number is: " << fibo(n);
    return 0;
}

// checking if an array is sorted
#include <iostream>
using namespace std;
bool issorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    bool issmallersorted = issorted(arr + 1, size - 1);
    return issmallersorted;
}
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    if (issorted(arr, 5))
    {
        cout << "sorted";
    }
    else
    {
        cout << "not sorted";
    }
    return 0;
}
// Recursion uses an in-built stack that stores recursive calls. Hence, the number of recursive calls must be as small as possible to avoid memory-overflow. If the number of recursion calls exceeded the maximum permissible amount, the recursion depth* will be exceeded. This condition is called stack overflow.
*/

// Day - 2

/*
// Climb Stairs
#include <iostream>
using namespace std;
int climbStairs(int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
int main()
{
    int n = 0;
    cout << "enter the number of stairs: ";
    cin >> n;
    cout << "the total number of ways to reach the top is: " << climbStairs(n);
    return 0;
}

// Say Digits
#include <iostream>
#include <string>
using namespace std;
void say(int n)
{
    // base case
    if (n == 0)
        return;
    string arr[10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    say(n / 10);
    int rem = n % 10;
    cout << arr[rem] << "\t";
}
int main()
{
    int n = 0;
    cin >> n;
    say(n);
    return 0;
}
*/

/*
// Day - 3
// Sum of an array using recursion
#include <iostream>
using namespace std;
int sumarr(int *arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int sum = arr[0] + sumarr(arr + 1, n - 1);
    return sum;
}
int main()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sumarr(arr, n);
    return 0;
}


// Linear search
#include <iostream>
using namespace std;
bool ispresent(int *arr, int n, int key)
{
    if (n == 0)
        return false;
    if (arr[0] == key)
        return true;
    bool ans = ispresent(arr + 1, n - 1, key);
    return ans;
}
int main()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key = 0;
    cin >> key;
    if (ispresent(arr, n, key))
        cout << "present";
    else
        cout << "not present";
    return 0;
}

// Binary search using recursion
#include <iostream>
using namespace std;
bool binsearch(int *arr, int start, int end, int target)
{
    if (start > end)
        return false;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return true;
    else if (arr[mid] > target)
        return binsearch(arr, mid + 1, end, target);
    else
        return binsearch(arr, start, mid - 1, target);
}
int main()
{
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int target = 0;
    cout << "enter the element to find in the array: ";
    cin >> target;
    if (binsearch(arr, 0, size - 1, target))
        cout << "present";
    else
        cout << "not present";
    return 0;
}
*/

/*
// Day - 4
// Reversing a string
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void reversestr(string &s, int start, int end)
{
    if (start > end)
        return;
    swap(s[start], s[end]);
    return reversestr(s, ++start, --end);
}
int main()
{
    string s;
    getline(cin, s);
    cout << "before reversing: " << s << endl;
    reversestr(s, 0, s.length() - 1);
    cout << "after reversing: " << s << endl;
    return 0;
}

// Reverse string using single pointer
#include <iostream>
#include <string>
using namespace std;
void revstr(string &s, int end, string &reved)
{
    if (end == -1)
        return;
    reved += s[end];
    return revstr(s, --end, reved);
}
int main()
{
    string s;
    string reved = "";
    getline(cin, s);
    cout << "before reversing: " << s << endl;
    revstr(s, s.length(), reved);
    cout << "after reversing: " << reved << endl;
    return 0;
}

// Reverse string using single pointer second method
#include <iostream>
#include <string>
using namespace std;
void revstring(string &s, int i = 0)
{
    if (i > s.length() / 2)
        return;
    swap(s[i], s[s.length() - i - 1]);
    return (revstring(s, ++i));
}
int main()
{
    string s;
    getline(cin, s);
    cout << "before reversing: " << s << endl;
    revstring(s);
    cout << "after reversing: " << s << endl;
    return 0;
}

// Check Palindrome
#include <iostream>
using namespace std;
bool isPalindrome(string &s, int i)
{
    if (i == s.length() / 2)
        return true;
    if (s[i] == s[s.length() - i - 1])
        return isPalindrome(s, ++i);
    return false;
}
int main()
{
    string s;
    getline(cin, s);
    bool palindrome = isPalindrome(s, 0);
    if (palindrome)
        cout << "is a palindrome" << endl;
    else
        cout << "not a palindrome" << endl;
    return 0;
}

// Power using recursion
#include <iostream>
using namespace std;
bool isodd(int x)
{
    return x & 1;
}
int powerto(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (isodd(b))
    {
        return a * (powerto(a, b / 2)) * (powerto(a, b / 2));
    }
    return (powerto(a, b / 2)) * (powerto(a, b / 2));
}
int main()
{
    int a = 0;
    cin >> a;
    int b = 0;
    cin >> b;
    cout << "the value of " << a << " to the power " << b << " is : " << powerto(a, b) << endl;
    return 0;
}

// Bubble Sort
#include <iostream>
#include <algorithm>
using namespace std;
void bubblesort(int *arr, int size)
{
    if (size == 0 || size == 1)
        return;
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    bubblesort(arr, --size);
}
int main()
{
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
    cout << "after sort" << endl;
    bubblesort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    return 0;
}

// Selection Sort
#include <iostream>
#include <algorithm>
using namespace std;
int minidx(int *arr, int i, int j)
{
    if (i == j)
        return i;
    int miniindex = minidx(arr, i + 1, j);
    return arr[i] < arr[miniindex] ? i : miniindex;
}
void selectionsort(int *arr, int size, int index = 0)
{
    if (index == size)
        return;
    int swapidx = minidx(arr, index, size - 1);
    if (swapidx != index)
        swap(arr[swapidx], arr[index]);
    return selectionsort(arr, size, ++index);
}
int main()
{
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
    cout << "after sort" << endl;
    selectionsort(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    return 0;
}
*/

/*
// Day - 5
*/
// Merge sort
// Merge sort: Divide the array into two parts like in binary search. Use recursion to keep dividing the arrays. Merge the divided arrays in the sorted form recursively to get the entire sorted array. This sorting algorithm is faster than bubble sort, insertion sort and selection sort. It has the same time complexity (O(nlogn)) for all three cases best, avg, worst. It has a space complexity of O(n).
#include <iostream>
using namespace std;
void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // creating the size of the new arrays
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    // adding the values to the new arrays (sorted)
    int mainidx = start;
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[mainidx++];

    mainidx = mid + 1;
    for (int i = 0; i < size2; i++)
        arr2[i] = arr[mainidx++];

    // merging the two sorted arrays
    int idx1 = 0;
    int idx2 = 0;
    mainidx = start;

    while (idx1 < size1 and idx2 < size2)
    {
        if (arr1[idx1] < arr2[idx2]) // to sort in descending order check (if arr[idx1] > arr[idx2])
            arr[mainidx++] = arr1[idx1++];
        else
            arr[mainidx++] = arr2[idx2++];
    }
    while (idx1 < size1)
        arr[mainidx++] = arr1[idx1++];
    while (idx2 < size2)
        arr[mainidx++] = arr2[idx2++];
}
void mergesort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergesort(arr, start, mid);   // sorting the left part
    mergesort(arr, mid + 1, end); // sorting the right part

    // merging the sorted parts
    merge(arr, start, end);
}
int main()
{
    int size = 0;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "before sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    mergesort(arr, 0, size - 1); // calling the sorting function
    cout << endl;
    cout << "after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}