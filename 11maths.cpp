// // find primes sieve of erastothenes
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// int main()
// {
//     int n = 0;
//     cin >> n;
//     int count = 0;
//     vector<bool> prime(n + 1, true);
//     prime[0] = prime[1] = false;
//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i])
//         {
//             count++;
//             for (int j = 2; j < n; j++)
//             {
//                 int temp = i * j;
//                 prime[temp] = false;
//             }
//         }
//     }
//     cout << count;
//     return 0;
// }

// segmented sieve

// gdc/hcf eucilidian algorithm
// formula: gcd (a,b) = gdc(a-b,b)
// lcm and gcd are related by : lcm (a,b) * gcd (a,b) = |a * b|
// hence lcm(a,b) = gcd(a,b) / |a*b|
// #include <iostream>
// using namespace std;
// int gcd(int a, int b)
// {
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     while (a != b)
//     {
//         if (a > b)
//         {
//             a = a - b;
//         }
//         else
//             b = b - a;
//     }
//     return a; // when both become equal a or b can be returned
// }
// int main()
// {
//     int a = 0;
//     int b = 0;
//     cin >> a >> b;
//     int ans = gcd(a, b);
//     cout << "the hcf of " << a << " and " << b << " are: " << ans << endl;
//     return 0;
// }

// fast exponentiation (modular exponentiation)
// qn : given x , n and m find (x ^ n) % m

// factorial of a number
#include <iostream>
#include <algorithm>
using namespace std;
bool even(int x)
{
    return (!(x & 1));
}

void function()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        arr[i] = temp;
    }
    // find the number of even and odd elements in the array
    int ec = 0;
    int oc = 0;
    for (int i = 0; i < n; i++)
    {
        // even
        if (even(arr[i]))
        {
            ec++;
        }
        if (!even(arr[i]))
        {
            oc++;
        }
    }
    cout << n - max(oc, ec) << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        function();
    }
    return 0;
}
