#include <iostream>
#include <vector>
using namespace std;
void display(int *arr, int r, int c)
{
    // function to print the 2d array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << *((arr + i * c) + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// alternative display function
void display_use(int arr[][4], int r, int c) // here atleast the column size of the array must be specified.
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool isPresent(int arr[][4], int element, int r, int c)
{
    // linear search in 2d array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == element)
                return true;
        }
    }
    return false;
}
void print_row_sum(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[i][j];
        }
        cout << "sum of the " << i + 1 << " row is : " << sum << endl;
    }
}
void print_col_sum(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[j][i];
        }
        cout << "sum of the " << i + 1 << " column is : " << sum << endl;
    }
}
void largest_row_sum(int arr[][3], int r, int c)
{
    int max_row_sum = 0;
    int max_row_sum_row = -1;
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[i][j];
        }
        if (max_row_sum < sum)
        {
            max_row_sum = sum;
            max_row_sum_row = i;
        }
    }
    cout << "maximum row sum : " << max_row_sum << endl;
    cout << "maximum row sum row is : " << max_row_sum_row << endl;
}
void largest_col_sum(int arr[][3], int r, int c)
{
    int max_col_sum = 0;
    int max_col_sum_col = -1;
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[j][i];
        }
        if (max_col_sum < sum)
        {
            max_col_sum = sum;
            max_col_sum_col = i;
        }
    }
    cout << "maximum col sum : " << max_col_sum << endl;
    cout << "maximum col sum col is : " << max_col_sum_col << endl;
}
void transpose(int arr[][3], int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    cout << endl;
    cout << "the transpose of the matrix is : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    // creating a 2d array
    // int arr[3][4];

    /* taking input and printing the array
    // taking input -> row wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    // to pass a 2d array to a function
    display((int *)arr, 3, 4);
    // or
    display(&arr[0][0], 3, 4);

    // taking input -> col wise
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j][i];
        }
    }
    display(&arr[0][0], 3, 4);
    */

    /*searching an element in a 2d array (linear search)
    // taking input of the elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    int element = 0;
    cout << "enter the element to search : ";
    cin >> element;
    if (isPresent(arr, element, 3, 4))
    {
        cout << "element found" << endl;
    }
    else
    {
        cout << "element not found" << endl;
    }
    */

    /*row-wise sum and col_wise sum problem
    // print th row wise and col wise sum of the matrix
    // creating the array
    int arr[3][3];
    // taking input of the elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    // row wise sum
    cout << "printing the row sums of the matrix :" << endl;
    print_row_sum(arr, 3, 3);
    cout << endl;
    cout << "printing the col sums of the matrix :" << endl;
    print_col_sum(arr, 3, 3);
    cout << endl;
    cout << "printing the largest row sum of the matrix" << endl;
    largest_row_sum(arr, 3, 3);
    cout << endl;
    cout << "printing the largest col sum of the matrix" << endl;
    largest_col_sum(arr, 3, 3);
     */

    /*printing like a wave (solved codestudio) */

    /*transpose of a matrix
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    transpose(arr, 3, 3);
    */

    vector<vector<int>> v{
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}};
    cout << v.size();
    cout << endl
         << v[0].size();
    cout << endl;
   
    return 0;
}