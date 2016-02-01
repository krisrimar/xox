#include <iostream>
using namespace std;

/*data types in C++




*/

int main(void)
{
	setlocale(0, "");
	double num;

	cout << "Enter random number: ";
	cin >> num;

	if (num < 10) {
		cout << "You have entered a number that is less than 10" << endl;
	} else if (num == 10) {
		cout << "You have entered a number that is equal to 10" << endl;
	} else {
		cout << "You have entered a number that is more than 10" << endl;
	}

	return 0;
}