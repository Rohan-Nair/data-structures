/*
// ncr
#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int ncr(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}
int main()
{
    int n = 0;
    int r = 0;
    cout << "enter n: ";
    cin >> n;
    cout << "enter r:";
    cin >> r;
    cout << "the value of ncr is: " << ncr(n, r);

    return 0;
}
*/
/*
// prime number
#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    if (isPrime(n))
        cout << "the number is a prime number." << endl;
    else
        cout << "the number is not a prime number." << endl;
    return 0;
}
*/
/*
// ap
#include <iostream>
using namespace std;
int ap(int n)
{
    return ((3 * n) + 7);
}
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    cout << "the nth term is: " << ap(n) << endl;
    return 0;
}
*/
/*
// num of set bits
#include <iostream>
using namespace std;
int set(int a, int b)
{
    int bits = 0;
    while (a != 0 & b != 0)
    {
        int bit = a & 1;
        if (bit == 1)
            bits++;
        a = a >> 1;
        bit = b & 1;
        if (bit == 1)
            bits++;
        b = b >> 1;
    }
    return bits;
}
int main()
{
    int a = 0;
    int b = 0;
    cout << "enter a: ";
    cin >> a;
    cout << "enter b: ";
    cin >> b;
    cout << "the number of set bits in the numbers " << a << " and " << b << " are: " << set(a, b) << endl;
    return 0;
}
*/
/*
// nth fibo
#include <iostream>
using namespace std;
int fibo(int n)
{
    int fibo = 0;
    for (int i = 2; i <= (n - 2); i++)
    {
        fibo = (i - 1) + (i - 2);
    }
    return fibo;
}
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    cout << "the n'th fibonacci number is: " << fibo(n) << endl;
    return 0;
}
// code by Rohan Nair
*/
/* using for loop
#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    int counter = 0;
    cout << "enter the number: ";
    cin >> num;
    if (num > 2)
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                counter++;
            }
        }
        if (counter == 0)
        {
            cout << "the number is a prime number." << endl;
        }
        else
        {
            cout << "the number is not a prime number." << endl;
        }
    }
    if (num == 1 || num == 0)
    {
        cout << "the number is neither prime nor composite" << endl;
    }
    if (num == 2)
    {
        cout << "the number is a prime number";
    }

    return 0;
}
*/

/*using while loop
#include <iostream>
using namespace std;
int main()
{
    int number = 0;
    int counter = 0;
    cout << "enter the number:";
    cin >> number;
    if (number > 2)
    {
        int i = 2;
        while (i < number)
        {
            if (number % i == 0)
            {
                counter++;
            }
            i++;
        }
        if (counter == 0)
        {
            cout << "the number is a prime number." << endl;
        }
        else
        {
            cout << "the number is not a prime number." << endl;
        }
    }
    if (number == 0 || number == 1)
    {
        cout << "the number is neither prime nor composite." << endl;
    }
    if (number == 2)
    {
        cout << "the number is a prime number." << endl;
    }

    return 0;
}
*/
/*using function
#include <iostream>
using namespace std;
bool prime(int n)
{

    // if (n <= 2)
    // {
    //     return false;
    // }
    if (n > 2)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    return true;
}
int main()
{
    int number = 0;
    cout << "Enter the number you want to check is prime or not: ";
    cin >> number;
    if ((number == 1) || (number == 0))
    {
        cout << number << "  is neither prime nor composite." << endl;
    }
    else
    {
        prime(number) ? cout << number << " is a prime number. " : cout << number << " is not a prime number. ";
    }
    return 0;
}
 */