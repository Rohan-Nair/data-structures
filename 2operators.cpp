/*
fibonacci series
#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 1;
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    cout << a << endl
         << b << endl;
    for (int i = 2; i <= (n - 2); i++)
    {
        int next = a + b;
        cout << next << endl;
        a = b;
        b = next;
    }
    return 0;
}
*/
/*
check prime nummber
// check if a number is prime or not
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number:";
    cin >> n;
    int flag = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag++;
        }
    }
    if (n > 2)
    {
        if (flag > 0)
        {
            cout << "the number is not a prime number" << endl;
        }
        else
        {
            cout << "the number is a prime number" << endl;
        }
    }
    else if (n == 2)
    {
        cout << "the number is a prime number" << endl;
    }
    else if (n == 0 || n == 1)
    {
        cout << n << " is neither prime nor composite" << endl;
    }
    else
    {
        cout << "the number is invalid" << endl;
    }
    return 0;
}
*/
/*
// program to print the prime numbers till a number
#include <iostream>
using namespace std;
bool checkprime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num = 0;
    cout << "enter the number: ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        if (checkprime(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}
*/
/* convert decimal to binary
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = bit * pow(10, i) + ans;
        n = n >> 1;
        i++;
    }
    cout << "the number in binary form is:" << ans << endl;

    return 0;
}
*/
/*
 convert negative number to binary
*/
/*
 convert binary to decimal
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number in binary: ";
    cin >> n;
    int i = 0;
    int ans = 0;
    while (n != 0)
    {
        // here we will take digit and not binary because we know the input is a binary number because we are coding it but the computer reads it as a decimal number.
        // int bit = n & 1;
        // if (bit == 1)
        int digit = n % 10;
        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }
        n /= 10;
        i++;
    }
    cout << "the number in decimal is: " << ans << endl;
    return 0;
}
/*
// swapping integers without third variable
#include <iostream>
using namespace std;
void swapint(int a, int b)
{
    cout << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b << endl;
}
int main()
{
    swapint(20, 30);
    return 0;
}
*/