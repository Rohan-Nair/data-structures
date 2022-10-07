/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(0);
    a.push_back(0);
    b.push_back(4);
    b.push_back(5);
    vector<int> v;
    int i = 0, j = 0;
    while (i < a.size() - 1)
    {
        if (a[i] < b[j])
        {
            v.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            v.push_back(b[j]);
            j++;
        }
    }
    for (int k : v)
    {
        cout << k << " ";
    }

    return 0;
}
*/

/*merge sorted array leetcode
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    b.push_back(2);
    b.push_back(5);
    b.push_back(6);
    int i = 3;
    int j = 0;
    while (i < a.size())
    {
        a[i] = b[j];
        i++;
        j++;
    }
    sort(a.begin(), a.end());
    for (int k : a)
    {
        cout << k << " ";
    }
    return 0;
}
*/

/*merge sorted array into third array
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> sorted;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(9);
    b.push_back(2);
    b.push_back(4);
    b.push_back(6);

    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            sorted.push_back(a[i]);
            i++;
        }
        else
        {
            sorted.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        sorted.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        sorted.push_back(b[i]);
        j++;
    }
    for (int k : sorted)
    {
        cout << k << " ";
    }
    return 0;
}
*/
