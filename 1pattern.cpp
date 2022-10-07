/*
square pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number of rows you want:";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 0;
        while (col < n)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
square pattern with numbers
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number of rows you want :";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            cout << row;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
square pattern with numbers 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the numbers of rows: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            cout << col;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
square patterns with numbers 3
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int rows = 1;
    while (rows <= n)
    {
        int col = n;
        while (col >= 1)
        {
            cout << col;
            col--;
        }
        cout << endl;
        rows++;
    }
}
*/
/*
square patterns with numbers 3 second way
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << " enter the number : ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            cout << n - col + 1;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
square pattern with numbers 4
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number :";
    cin >> n;
    int row = 1, counter = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            cout << counter << "\t";
            counter++;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
right angled triangle pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number :";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
right angled triangle pattern 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number :";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << row;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
right angled triangle pattern 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int counter= 0 ;
    cout << "enter the number :";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << counter<<"\t";
            counter++;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
right angled triangle pattern 3

#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number :";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        int counter = row;
        while (col <= row)
        {
            cout << counter << "\t";
            counter++;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
right angled pattern 3 method 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << (row + col) - 1 << "\t";
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
right angled pattern 4
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << (row - col) + 1 << "\t";
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
square letter pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            char ch = ('a' + row) - 1; // typecasting
            cout << ch;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
square letter pattern 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number : ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            char ch = 'A' + col -1;
            cout << ch;
            col++;
        }
        cout << endl;
        row++;
    }
}
*/
/*
square letter pattern 3
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    char counter = 'A';
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            cout << counter << "\t";
            counter++;
            col++;
        }

        cout << endl;
        row++;
    }
}
*/
/*
square letter pattern 4
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            char ch = 'A' + row + col - 2;
            cout << ch <<"\t";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
square letter pattern 4 method 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number:";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        char ch = 'A' + row - 1;
        while (col <= n)
        {
            cout << ch <<"\t";
            ch++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
triangular letter pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the num :";
    cin >> n;
    char ch = 'A';
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << ch << "\t";
            col++;
        }
        cout << endl;
        ch++;
        row++;
    }
    return 0;
}
*/
/*
triangular letter pattern 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    char ch = 'A';
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << ch << "\t";
            ch++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
triangular letter pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number : ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        char ch = 'A' + row + col - 2;
        while (col <= row)
        {
            cout << ch;
            ch++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
triangular letter pattern 3
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        char ch = 'A' + n - row ;
        while (col <= row)
        {
            cout << ch << "\t";
            ch++;
            col++;
        }
        cout << endl;
        row++;
    }

    return 0;
}
*/
/*
horizontally inverted triangle pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        // to print spaces
        int space = n - row;
        while (space)
        {
            cout << " ";
            space--;
        }
        // to print stars
        int col = 1;
        while (col <= row)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
vertically inverted triangle star program
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number:";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = n;
        while (col >= row)
        {
            cout << "*";
            col--;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
vertically inverted triangle star program method 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        int star = n - row + 1;
        while (col <= star)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}

*/
/*
horizontally and vertically inverted triangle pattern

#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        // to print spaces
        int spaces = 0;
        while (spaces <= row - 1)
        {
            cout << " ";
            spaces++;
        }
        // to print stars
        int col = 1;
        while (col <= n - row + 1)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
horizontally and vertically inverted trangle number pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int spaces = 0;
        while (spaces <= row - 1)
        {
            cout << " ";
            spaces++;
        }
        int col = 1;
        while (col <= n - row + 1)
        {
            cout << row;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
horizontally inverted triangular number pattern
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {

        int spaces = 0;
        while (spaces <= n - row)
        {
            cout << " ";
            spaces++;
        }
        int col = 1;
        while (col <= row )
        {
            cout << row;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
horizontally and vertically inverted trangle number pattern 2
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int spaces = 0;
        while (spaces <= row - 1)
        {
            cout << " ";
            spaces++;
        }
        int col = 1;
        while (col <= n - row + 1)
        {
            cout << col;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
horizontally inverted triangular number pattern 3
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number:";
    cin >> n;
    int row = 1;
    int counter = 1;
    while (row <= n)
    {
        int spaces = 0;
        while (spaces <= n - row)
        {
            cout << " ";
            spaces++;
        }
        int col = 1;
        while (col <= row)
        {
            cout << counter;
            counter++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/
/*
complex pattern
break the patterns into smaller figures and code
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the number: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        // to print first number triangle
        int col = 1;
        while (col <= n - row + 1)
        {
            cout << col << " ";
            col++;
        }
        // to print half of the stars triangle
        int stars = 1;
        while (stars <= row - 1)
        {
            cout << "*"
                 << " ";
            stars++;
        }
        // to print second half of the stars triangle
        int stars2 = 1;
        while (stars2 <= row - 1)
        {
            cout << "*"
                 << " ";
            stars2++;
        }
        // to print the second number triangle
        col = 1;
        while (col <= n - row + 1)
        {
            cout << col << " ";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------
/* //error code goes in infinte loop
#include <iostream>
using namespace std;
int main()
{
    int rows = 0;
    cout<<"enter the number of rows: ";
    cin >> rows;
    int space = rows - 1;
    // for upright triangle
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < space; j++)
        {
            cout << " ";
            space--;
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << "*" << endl;
        }
    }
    space = 1;
    for (int i = 0; i < (rows - 1); i++)
    {
        for (int j = 0; j <= space; j++)
        {
            cout << " ";
            space++;
        }
        for (int k = 0; k < 2 * (rows - i) - 1; k++)
        {
            cout << "*" << endl;
        }
    }

    return 0;
}
*/

/*   //printing the upper triangle
   for  (i = 1; i <= n; i++)
   {
      for  (j = 1; j<= space; j++)
         cout<<" ";//printing spaces
      space--;
      for  (k = 1; k <= 2 * i - 1; k++)
         cout<<"*";
      cout<<"\n";
   }
   //printing the lower triangle
   space = 1;
   for  (i = 1; i<= n - 1; i++)
   {
      for  (j = 1; j <= space; j++)
         cout<<" ";
      space++;
      for  (k = 1 ; k <= 2 * (n - i) - 1; k++)
         cout<<"*";
      cout<<"\n";
   }
   return 0;
}*/

/*striver's problems*/
// vertical pyramid
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int row = 1;
    while (row <= n)
    {
        int spaces = n;
        int col = 1;
        while (col <= spaces)
        {
            cout << " ";
        }
    }
    return 0;
}