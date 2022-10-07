/*
// max and min of from an array
#include <iostream>
using namespace std;
int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max > arr[i])
            max = arr[i];
    }
    return max;
}
int getMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min < arr[i])
            min = arr[i];
    }
    return min;
}
int main()
{
    int size = 0;
    cout << "enter the size of the array: ";
    cin >> size;
    // int arr[size];  bad practice
    int arr[5];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "the max number in the array is: " << getMax(arr, 5) << endl;
    cout << "the min number in the array is: " << getMin(arr, 5) << endl;
    return 0;
}
*/

/*
IMP
int function(int arr[])
{
    // function body;
}
int main()
{
    int arr[2] = {1,2};
    function (arr);
    in the above line when passing the array to the function the entire array is not being passed to the function but only the base address of the first element as the name of the array also indicates the base address of the array.
}
*/
/*
// using the above concept
#include <iostream>
using namespace std;
int update(int arr[])
{
    arr[1] = 120;
    return 0;
}
int main()
{
    int arr[4] = {1, 24, 5, 37};
    cout << arr[1] << endl;
    update(arr);
    cout << arr[1] << endl;
    // in the above line the value of the 2nd element of the array will be 120. unlike when passing variables to an array in call by value method the entire array is not copied when passing arrays to the function.
    return 0;
}
*/
/*
// sum of all elements in an array
#include <iostream>
using namespace std;
int arrSum(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main(){
    int arr[5];
    int size = 0;
    cout << "enter the size of the array: ";
    cin >> size;
    cout <<"enter the values of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "the sum of all the elements in the array are: " << arrSum(arr,size) << endl;
    return 0;
}
*/
/*
// linear search in arrays
#include <iostream>
using namespace std;
bool isThere(int arr[], int size, int tofind)
{
    for (int i = 0; i < size; i++)
    {
        if (tofind == arr[i])
            return true;
    }
    return false;
}
int main()
{
    int arr[5] = {0};
    int size = 0;
    cout << "enter the size of the array: ";
    cin >> size;
    cout << "enter the numbers in the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int tofind = 0;
    cout << "enter the number to find in the array: ";
    cin >> tofind;
    if (isThere(arr, size, tofind))
        cout << "the number is present in the array." << endl;
    else
        cout << "the number is not present in the array." << endl;
    return 0;
}
*/
/*
// reverse an array
#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[start] <= arr[end])
            swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int arr[5] = {0};
    int size = 0;
    cout << "enter the size of the array: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "the array is: ";
    printArray(arr, 5);
    reverse(arr, 5);
    cout << "the reversed array is: ";
    printArray(arr, 5);
    return 0;
}
*/
// leetcode solving
// alternate swap
/*
#include <iostream>
using namespace std;
void swapalt(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
            swap(arr[i], arr[i + 1]);
    }
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    swapalt(arr, 6);
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/
/*
// alternate swap without using third variable
#include <iostream>
using namespace std;
void swapalt(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        // use braces for if statements for more than one command else only the first statement will be executed
        if (i + 1 < size)
        {
            // swapint(arr[i], arr[i + 1]);
            arr[i] = arr[i] + arr[i + 1];
            arr[i + 1] = arr[i] - arr[i + 1];
            arr[i] = arr[i] - arr[i + 1];
        }
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int odd[5] = {1, 2, 3, 4, 5};
    int even[6] = {1, 2, 3, 4, 5, 6};
    // for even
    printArray(even, 6);
    swapalt(even, 6);
    cout << endl;
    printArray(even, 6);
    cout << endl <<endl;
    // for odd
    printArray(odd, 5);
    swapalt(odd, 5);
    cout << endl;
    printArray(odd, 5);

    return 0;
}
*/
/*
// find unique element
#include <iostream>
using namespace std;
int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        // xor returns 0 when both elements are same hence if we xor all the elements the  same elements will give the value of xor as 0 an only the unique element will remain
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[5] = {1, 3, 1, 3, 2};
    cout << "the unique element in the array is: " << findUnique(arr, 5) << endl;
    return 0;
}
*/
/*unique occurences in an array
#include <bits/stdc++.h>
using namespace std;
bool myfunc(int a[])
{
    for (int i = 1; i <= 11; i++)
    {
        if (a[i] && a[i] == a[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 3, 3};
    int a[10] = {};
    for (auto n : arr)
        ++a[n + 10];
    sort(a, a + 11);
    if (myfunc(a))
        cout << "true";
    else
        cout << "false";
}
*/
/*
// duplicate in an array
#include <iostream>
using namespace std;
int findDuplicate(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
    int arr[5] = {1, 2, 3, 3, 4};
    cout << findDuplicate(arr, 5);
    return 0;
}
*/
/*-------------------------------------------------------------------------Dynamic arrays-----------------------------------------------------------------*/
/*
// reversing a dynamic array
#include <iostream>
void array_rev(int arr[], int start, int end, int num)
{
    for (int i = 0; i < num/2; i++)
    {
        if (start != end)
        {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}
int main()
{
    int num = 0;
    std::cout << "enter the number of elements you want in the array: ";
    std::cin >> num;
    int *arr = new int(num);
    std::cout << "the numbers you want to enter in the array are: ";
    for (int i = 0; i < num; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "the array before reversing is: ";
    for (int i = 0; i < num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int start = 0;
    int end = num - 1;
    array_rev(arr, start, end, num);
    std::cout << "the array after reversing is: ";
    for (int i = 0; i < num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
*/
/*swapping alternate values in an array
#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    cout << "enter the number of elements in the array: ";
    cin >> num;
    int *arr = new int(num);
    // taking the elements input
    for (int i = 0; i < num; i++)
    {
        cout << "enter the " << i + 1 << " number: ";
        cin >> arr[i];
        cout << endl;
    }
    cout << endl;
    // printing the numbers in the array
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // swapping the numbers in the array
    if (num % 2 == 0)
    {

        for (int i = 0; i < num; i += 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    else
    {
        for (int i = 0; i < (num - 1); i += 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // printing the numbers in the array
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/
/*finding unique element in the array
#include <iostream>
using namespace std;
int find_unique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[7] = {2, 3, 4, 9, 3, 4, 2};
    cout << "the unique element in the array is: " << find_unique(arr, 7);
    return 0;
}
*/
/*duplicate in an array
#include <iostream>
using namespace std;
int main(){
    int arr[5] = {4, 4, 3, 6, 9};
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < 5; i++)
    {
        ans = ans ^ i;
    }
    cout << "the duplicate element in the array is: " << ans;
    return 0;
}
*/
/*find all duplicates in an array leetcode
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1])
                ans.push_back(nums[i]);
        }
return ans;


    }
};
*/
/*array intersection
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> ans;
    int arr[6] = {1, 2, 3, 4, 4, 9};
    int arr2[3] = {4, 4, 5};
    for (int i = 0; i < 6; i++)
    {
        int element = arr[i];
        for (int j = 0; j < 3; j++)
        {
            // optimisation 1: if the ith element is greater than the jth element then all the elements ahead in the arr2 will be greater so increment i
            if (arr[i] > arr2[j])
                i++;
            if (element == arr2[j])
            {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
 */
/*optimisation 2 od the above question :
if arr[i] < arr[j] : i++
if arr[i] == arr[j]: print/ add to vector and i++, j++
#include <iostream>
if arr[i] > arr[j] : j++
#include <vector>
using namespace std;
int main()
{
    vector<int> ans;
    int arr[6] = {1, 2, 3, 4, 4, 9};
    int arr2[3] = {4, 4, 5};
    int i = 0, j = 0;
    while (i < 6 && j < 3)
    {
        if (arr[i] < arr[j])
            i++;
        else if (arr[i] == arr[j])
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return 0;
}
// this method is called the two pointer approach and is used for finding pains in two sorted arrays
 */
/*three sum
given a sorted array and a value find if there exists three numbers whose sum is equal to the given value
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;
int main()
{
    vector<vector<int>> ans;
    int value = 6;
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        for (int j = i + 1; i < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[i] + arr[j] == value)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }

    /*
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto it = ans[i].begin(); it != ans[i].end(); i++)
        {
            cout << *it << endl;
        }
    }
    */
/*
 for (auto &i : ans)
 {
     for(auto j : i)
     {
         cout << j << endl;
     }
 }

return 0;
}
*/
/*2sum O(n^2) solution leetcode
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i<nums.size();i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
*/
/*
2sum O(n) solution leetcode
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];
            if (umap.find(num) != umap.end())
            {
                auto it = umap.find(num);
                ans.push_back(it->second);
                ans.push_back(i);
            }
            umap.insert(std::pair(nums[i], i));
        }
        return ans;
    }
};
*/
/*3sum leetcode O(n^3) solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1 ; j < nums.size(); j++)
            {
                for(int k = j+1; k < nums.size(); k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> v(3);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[k];
                        sort(v.begin(), v.end());
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto i : s)
        {
            ans.push_back(i);
        }
        return ans;

    }
};
*/
/*plus-one problem leetcode
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> a;
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    return 0;
}
*/
/*Pivot index in an array
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
new-> using std::accumulate() function to get sum of the numbers
format-> std::accumulate(start, end, init);
Solution:
 1: traverse through the array using a for loop
 2: if leftsum ( accumulate (arr.begin(), arr.begin()+1, 0 )) is equal to   the rightsum ( accumulate (arr.begin() + i, arr.end(), 0)) then return i
 3: else return -1.
*/
