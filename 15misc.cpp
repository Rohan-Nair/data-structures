// Macros in C++
/*
#define is used to create a macro
Macros are pieces of code in a program that is given some name. Whenever this name is encountered by the compiler, the compiler replaces the name with the actual piece of code. The ‘#define’ directive is used to define a macro.
macros do not consume memory.
they are not modifiable.

Types of macros (GFG):
1)Object-like Macros: An object-like macro is a simple identifier that will be replaced by a code fragment. It is called object-like because it looks like an object in code that uses it. It is popularly used to replace a symbolic name with numerical/variable represented as constant.
2)Chain Macros: Macros inside macros are termed as chain macros. In chain macros first of all parent macro is expanded then the child macro is expanded.
3)Multi-line Macros: An object-like macro could have a multi-line. So to create a multi-line macro you have to use backslash-newline.
4)Function-like Macro: These macros are the same as a function call. It replaces the entire code instead of a function name. Pair of parentheses immediately after the macro name is necessary. If we put a space between the macro name and the parentheses in the macro definition then the macro will not work.A function-like macro is only lengthened if an only if its name appears with a pair of parentheses after it. If we don’t do this, the function pointer will get the address of the real function and lead to a syntax error.
*/

// Global Variables in c++
/*
Global variables are used when variables need to be shared between functions.
Usage of global variables is bad practice as they can be modified by any function in the program.
To share variables between functions use the pass by reference method
*/

// Inline Functions
/*
(GFG)
Used to reduce function calls overhead. When the program executes the function call instruction the CPU stores the memory address of the instruction following the function call, copies the arguments of the function on the stack and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined memory location/register and returns control to the calling function. This can become overhead if the execution time of function is less than the switching time from the caller function to called function (callee). For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant compared to the amount of time the function takes to run. However, for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to actually execute the function’s code. This overhead occurs for small functions because execution time of small function is less than the switching time.

To avoid this overhead inline functions are used. inline functions are expanded in the place they are called  and is then executed as a normal line of code rather than calling a function and using switching time. The functions are expanded by the compiler at the line they are called while compiling at compile time. Inline functions should be used only for small functions.
#include <iostream>
using namespace std;
int getmax(int a, int b)
{
    return a>b ? a : b;
}
int main(){
    int a = 3;
    int b = 5;
    cout << getmax(a,b);
    return 0;
}
*/

/*
Default Arguments (GFG)
A default argument is a value provided in a function declaration that is automatically assigned by the compiler if the calling function doesn’t provide a value for the argument. In case any value is passed, the default value is overridden.
#include <iostream>
using namespace std;
inline int sum(int a = 5, int b = 0) // default arguments will be used in case arguments are not passed in the function call and 10 will be returned
{
    return a + b;
}
int main()
{
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    cout << "sum without default arguments: " << sum(a, b) << endl;
    cout << "sum with default arguments: " << sum();
    return 0;
}
*/