// bubble sort : compare adjacent elements and swap
#include <iostream>
#include <vector>
using namespace std;
void BubbleSort_asc(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
            for (int k : v)
            {
                cout << k << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(6);
    v.push_back(10);
    v.push_back(9);
    v.push_back(14);
    BubbleSort_asc(v);
    return 0;
}
