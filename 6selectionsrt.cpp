#include <iostream>
#include <vector>
using namespace std;
void SelectionSort_asc(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[i])
                swap(v[i], v[j]);
        }
    }
    for (int i : v)
    {
        cout << i << " ";
    }
}
void SelectionSort_desc(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] > v[i])
                swap(v[j], v[i]);
        }
    }
    for (int i : v)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> v;
    v.push_back(54);
    v.push_back(67);
    v.push_back(34);
    v.push_back(37);
    v.push_back(40);
    // selection sort
    cout << "ascending sorting: ";
    SelectionSort_asc(v);
    cout << endl;
    cout << "descending sorting: ";
    SelectionSort_desc(v);
    return 0;
}