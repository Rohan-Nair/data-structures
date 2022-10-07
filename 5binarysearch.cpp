/*binary search function
#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int> arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start / 2) + (end / 2);
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1; // return -1 if the element is not found in the array
}
int main()
{
    vector<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(7);
    a.push_back(8);
    a.push_back(8);
    a.push_back(10);
    cout << "the element is present at index: " << binary_search(a, 8) << endl;
    return 0;
}
*/
// binary search questions
/*1) Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Solution:
 1: use binary searc hto find the first occurence in the array. search the mid element, if it is equal to the key then store it (in lets say 'ans') and continue the binary search in the elements at lesser index position and update ans.
 2: in the same way find the last occurence in the array by searching in the elements with index higher than mid's index.
 3: return the vector ans containing the index of obth the occurences.
 */
// add code: code is on qn 34 leetcode

/*2) Given an array of integers nums sorted in non-decreasing order, find the total number of occurences of the target value.
If target is not found in the array, return -1.
You must write an algorithm with O(log n) runtime complexity.
Solution:
 1: find the first and last occurences of the target value in the array.
 2: subtract the first occurence index from the last occurence and add one and store it in a variable (say totalocc).
 3: return totalocc.
*/
// add code: code is similar to question 34 leetcode.

/*3) Peak Index in a Mountain array
An array arr is a mountain array if the following properties hold:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
You must solve it in O(log(arr.length)) time complexity.
Solution:
 1: use binary search: if mid element is lesser than mid + 1 then start = mid + 1.
 2: else that is if the mid element is greater than or equal to the mid element then end = mid.
 3: return mid. (mid will contain the index of the peak value in the array)
*/

/*
find pivot in an array
#include <iostream>
using namespace std;
int gethigherpivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return end;
}
int getlowerpivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
int main()
{
    int arr[5] = {8, 10, 17, 1, 3};
    cout << "the lower pivot index of the array is: " << getlowerpivot(arr, 5) << endl;
    cout << "the higher pivot index of the array is: " << gethigherpivot(arr, 5) << endl;
    return 0;
}
*/
/*search in a rotated sorted array
class Solution
{
public:
    int getpivot(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;
        while (start < end)
        {
            if (arr[mid] >= arr[0])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }
        return start;
    }
    int binarySearch(vector<int> &arr, int s, int e, int key)
    {
        int start = s;
        int end = e;

        int mid = start + (end - start) / 2;

        while (start <= end)
        {

            if (arr[mid] == key)
            {
                return mid;
            }

            // go to right wala part
            if (key > arr[mid])
            {
                start = mid + 1;
            }
            else
            { // key < arr[mid]
                end = mid - 1;
            }

            mid = start + (end - start) / 2;
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int pivot = getpivot(nums);
        if (target >= nums[pivot] && target <= nums[nums.size() - 1])
        {
            return binarySearch(nums, pivot, nums.size() - 1, target);
        }
        else
        {
            return binarySearch(nums, 0, pivot, target);
        }
    }
};
 */

/*book allocation problem
 */
/*my soln
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
//         also solution for book allocation problem
//         finding the sum of all the elements in the array as the sum of any elements in the array will not be more than the sum of all the elements in the array
//         setting the search space for the binary search
        int n = nums.size();
        int start = -1;
        int end = 0;
        for (int i : nums)
        {
            start = max(i, start);
            end += i;
        }
        int mid = start + (end - start) / 2;
        int ans = -1;
        while (start <= end)
        {
            if (isPossible(nums,n, m, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;

            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
    bool isPossible(vector<int>& nums, int n, int m, int mid)
    {
        int student = 1;
        int pages = 0;
        for (int i = 0; i < n ; i++)
        {
            if (pages + nums[i] < mid)
            {
                pages += nums[i];
            }
            else
            {
                student++;
                if (student > m)
                {
                    return false;
                }
                pages = nums[i];

            }
        }
        return true;
    }

};*/
/*agressive cows problem
bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cows = 1; // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    int lastCowPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastCowPosition >= minDist)
        {
            cows++;
            lastCowPosition = stalls[i];
            if (cows >= k)
                return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0]; // just take low=0 and high = 1000000 any large number if this seems tricky
    int res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(stalls, mid, k))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}
*/