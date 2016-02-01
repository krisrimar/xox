#include <iostream>
#include <locale> // also for the language Ukrainian setting to work
#include <string> // for usign 'string' type
#include <typeinfo> // for printing out types of variables
#include "windows.h"; // this is for the language Ukrainian setting to work

using namespace std;



void printBoard(int * l, int * m, int * n, string (*exoup)[9]) {
    string openCell = "| ", closeCell = "|\n", emptyCellSpace = " ", cellRowDivider = " -----------\n";

    for (*l; *l < 4; (*l)++) {
        cout << cellRowDivider;
        cout << openCell << (*exoup) [*n] << emptyCellSpace << openCell << (*exoup) [*n+1] << emptyCellSpace << openCell << (*exoup) [*n+2] << emptyCellSpace << closeCell;
        *n = *n + 3;
    }
    cout << cellRowDivider;
}


int main(void) {

    SetConsoleCP(1251); // also for Ukrainian locale. is Windows-specific, requires the "windows.h" header
    SetConsoleOutputCP(1251);

    setlocale(LC_CTYPE, "ukr"); // in order to display Ukrainian in the console window

    int j = 1, k = 0, i = 0;
    string exou [9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    printBoard(&j, &k, &i, &exou);



    return 0;

}



/* CHARACTER TYPES:

UTF - unicode transformation format

Characters:

char - exactly one byte size (e.g. ? = 0011 1111 (UTF-8))
char16_t - not smaller than char (e.g. ? = 0000 0000 0011 1111 (UTF-16))
char32_t - not smaller than char16_t (e.g. ? = 00000 00000 00000 00000 0000 0011 1111 (UTF-32))
wchar_t - can represent the largest supported character set (65 535 bits);

Numbers signed (minus to plus) (1000 0001 = -1, because it is "signed with a 1 in the beginning):

signed char - one byte size (-128 to 127):
    -> as compared to char: char is generaly used to represent literals (e.g. 'a', 'abcde')

        *signed char is used to represent numbers in the range from -127 to 127;
        *unsigned char is used to represent numbers in the range from 0 to 255;

        Different machines set different sizes for bytes (can be 9, 36, 16 or 32), therefore C++ needs a standard size in order to compile correctly (1 byte = 8 bits).

        sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

        SO BASICALLY: the who difference betwen signed and unsigned is covered above in *.

short - not smaller than char (16 bit) (-32 768 to 32767); <- use only if you need to save memory, because it is narrower than int
int - not smaller than short (16 bit) (-3 768 to 32 767);
long - not smaller than int (32 bit) (-2 147 483 648 to 2 147 483 647);
long long - not smaller than long (64 bit) (-9 223 372 036 854 775 808 to 9 223 372 036 854 775 807);

Numbers unsigned (0 to plus):

unsigned char - (8 bit) (255)
unsigned short - (16 bit) (65 535)
unsigned - (16 bit) (65 535)
unsigned long - (32 bit) (4 294 967 295)
unsigned long long - (64 bit) (18 446 744 073 709 551 615)

Float:

float - e.g. 1.1111111f + 2.2222222f + 3.3333333f = 6.66667 (5 digits after . percision);
double -
long double -

Boolean:

bool - true / false;

Void:

void - no storage, just calculation;

Null pointer:

decltype(nullprt) - ???

VARIABLES

int a = 5;
int a (5);
int a {5};

DECLARING A TYPE

int foo = 0;
auto bar = foo; // will be of the same type as foo

SPECIAL CHARS

\n  newline
\r  carriage return
\t  tab
\v  vertical tab
\b  backspace
\f  form feed (page feed)
\a  alert (beep)
\'  single quote (')
\"  double quote (")
\?  question mark (?)
\\  backslash (\)

FUNCTION REFERENCE:

int  x = 5, y = 3, z;
z = addition (x, y);

int addition (x, y) {
    return x + y;
}

// in this case, function addition is passed 5 and 3, which are copies of the values of x and y, respectively. These values (5 and 3) are used to initialize the variables set as parameters in the functon's definition, but any modifications of these variables has no effect on the values of the variables x and y outside it, because x and y were themselves not passed to the function on the call, but only copies of their values at that moment

to pass a variable by reference (so that it is actually modified by the function), arguments can be passed by reference, instead of by value.

void duplicate (int& a, int& b, int& c) {
    a* = 2;
    b* = 2;
    c *= 2;
}

int main() {
    int x=1, y=2, z=3;
    duplicate (x, y, z);
    cout << "x= " << x << " , y= " << y << " z= " << z; // x=2, y=4, z=6;
    return EXIT_SUCCESS;
}

OVERLOADS:

Two different functions can have the same names if they have different number of parameters or a different return type:

int operate (int a, int b)
{
  return (a*b);
}

double operate (double a, double b)
{
  return (a/b);
}

int main ()
{
  int x=5,y=2;
  double n=5.0,m=2.0;
  cout << operate (x,y) << '\n';
  cout << operate (n,m) << '\n';
  return 0;
}

(!) Note that a function cannot be overloaded only by its return type. At least one of its parameters must have a different type. (!)

FUNCTION TEMPLATES:

template <class SomeType>
SomeType sum (SomeType a, SomeType b)
{
  return a+b;
}

When you don't know what the returnt type of the function will be, you can use the template declaration. Later on, you can change the type like this:

x = sum<int>(10,20); // where <int> is the type you want

So the above mentioned function will be interpreted as:

int sum (int a, int b)
{
  return a+b;
}

An expanded example:

#include <iostream>
using namespace std;

template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

int main () {
  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum<int>(i,j);
  h=sum<double>(f,g);
  cout << k << '\n'; // 11
  cout << h << '\n'; // 2.5
  return 0;
}

NON-TYPE TEMPLATE ARGUMENTS:

#include <iostream>
using namespace std;

template <class T, int N> // define that T will take on any type and N will take on type of int

T fixed_multiply (T val)
{
  return val * N;
}

int main() {
  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';
}

NAMESPACES

Are used to separate variables of with the same name within one scope, by giving them a namespace (::)

#include <iostream>
using namespace std;

namespace foo
{
  int value() { return 5; }
}

namespace bar
{
  const double pi = 3.1416;
  double value() { return 2*pi; }
}

int main () {
  cout << foo::value() << '\n';
  cout << bar::value() << '\n';
  cout << bar::pi << '\n';
  return 0;
}

USING

The keyword using introduces a name into the current declarative region (such as a block), thus avoiding the need to qualify the name. For example:

#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {
  using first::x;
  using second::y;
  cout << x << '\n';
  cout << y << '\n';
  cout << first::y << '\n';
  cout << second::x << '\n';
  return 0;
}

// Example of using two diffrent namespaces in different blocks

#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {
  using namespace first;
  cout << x << '\n';
  cout << y << '\n';
  cout << second::x << '\n';
  cout << second::y << '\n';
  return 0;
}

STORAGE CLASSES:

Global variables - have the same storage point for the entire life of the app
Local variables - have storage only when the block of code is in use

Meaning, this is: static storage vs. automatic storage

#include <iostream>
using namespace std;

int x;

int main ()
{
  int y;
  cout << x << '\n'; // outputs 0
  cout << y << '\n'; // outputs 4285838 (or a different number)
  return 0;
}

ARRAYS:

int foo [5] = {20, 21, 22, 23, 24};

int foo[5];         // declaration of a new array
foo[2] = 75;        // access to an element of the array.

Printing out sum of all numbers in array:

int foo [] = {16, 2, 77, 40, 12071};
int n, result=0;

int main ()
{
  for ( n=0 ; n<5 ; ++n )
  {
    result += foo[n];
  }
  cout << result;
  return 0;
}

MULTIDIMENTIONAL ARRAYS:

jimmy represents a bidimensional array of 3 per 5 elements of type int. The C++ syntax for this is:

int jimmy [3][5];

ARRAYS AS PARAMETERS:

void procedure (int arg[]) // receive

int myarray [40]; // create

procedure (myarray); // pass

Also it is possible po pass multi-dimentional arrays:

void procedure (int myarray[][3][4])

STRING TO CHAR[]:

Null-terminated character sequences can be transformed into strings implicitly, and strings can be transformed into null-terminated character sequences by using either of string's member functions c_str or data:

char myntcs[] = "some text";
string mystring = myntcs;  // convert c-string to string
cout << mystring;          // printed as a library string
cout << mystring.c_str();  // printed as a c-string

POINTERS:

The address of a variable can be obtained by preceding the name of a variable with an ampersand sign (&), known as address-of operator. For example:

foo = &myvar;

// example (when Add() can't alter main's vars)

void Add25(int a) { // takes the value of the second a[10]
  a = a + 25; // adds 25 to 10 and stores it in the second a[35]
} // deletes second a[35]

int main() {
  int a = 10; // sets a to 10
  Add25(a); // calls the function and passes a parameter, but creates a copy of this variable in the memory, e.g.: a [10], a[10]
  cout << a; // prints 10
  return 0;
}

// now with no copies, but just working with first a[]:

void Add(int *a) { // checks the value of a[10]
  *a = *a + 25; // assigns a new value to a[35]
} // deletes *a[0x27f3]

int main() {
  int a = 10; // sets a to 10: a[10]
  Add25(&a); // sends a refferal to a's address to Add() *a[0x27f3]
  cout << a; // prints 35
  return 0;
}

// passed by refference (same as previous, but simpler)

void Add25(int &a) { // looks in the stack for the address passed, and creates an alias
  a = a + 25; // assigns 35 to a[]
}

int main() {
  int a = 10; // sets a to 10: a[10]
  Add25(a); // copy the address of a[10]
  cout << a; // prints 35
  return 0;
}

What's the point? - To be able to return more than one value with a function: someFunction(int &a, int &b, int &c)

Why pointers are better than reference? - Just that you can pass a NULL with them

Example of defining pointers beforehand:

#include <iostream>
using namespace std;

int main ()
{
  int firstvalue = 5, secondvalue = 15;
  int * p1, * p2;

  p1 = &firstvalue;  // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  *p1 = 10;          // value pointed to by p1 = 10
  *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
  p1 = p2;           // p1 = p2 (value of pointer is copied)
  *p1 = 20;          // value pointed to by p1 = 20

  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
  return 0;
}

ARRAYS AND POINTERS:

#include <iostream>
using namespace std;

int main ()
{
  int numbers[5];
  int * p;
  p = numbers;  *p = 10;
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;
  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  return 0;
}

POINTERS AND CONST:

When you don't want to edit a value, and just read it, use const:

int x;
int y = 10;
const int * p = &y;
x = *p;          // ok: reading p
*p = x;          // error: modifying p, which is const-qualified


// pointers as arguments:
#include <iostream>
using namespace std;

void increment_all (int* start, int* stop)
{
  int * current = start;                // assign current to 0
  while (current != stop) {             // while current != 4
    ++(*current);                       // increment value pointed // 10 + 1
    ++current;                          // increment pointer // 0 + 1
  }
}

void print_all (const int* start, const int* stop) // no editing
{
  const int * current = start;          // set 'current' to 0
  while (current != stop) {             // while 'current' != 4
    cout << *current << '\n';           // print value of current
    ++current;                          // increment pointer
  }
}

int main ()
{
  int numbers[] = {10,20,30};           // 1. create an array with 3 elements
  increment_all (numbers,numbers+3);    // 2. call function 'increment_all' start from 0 go to 4
  print_all (numbers,numbers+3);
  return 0;
}


*/
