#include <iostream>
#include <vector>
using namespace std;

/*
The Fibonacci sequence is defined as a sequence of numbers where each number
is the sum of the previous two:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

What is the sum of all odd numbers in the Fibonacci sequence that are less
than 10,000?


Pseudocode:
- Start a sum variable
- Use a loop to generate each value in the Fibonacci sequence
  - The next entry is the sum of the previous 2 entries
- Check if each value is odd; if so, add it to sum
  - Odd numbers are those where dividing by 2 leaves a remainder
  - So if the remainder is non-zero, it is an odd number
- This lasts as long as odd values are less than 10,000
- Store the Fibonacci numbers for printing out later; to check work
*/

int main() {

	int sum = 1;	// Start out as sum of first two numbers: 0 and 1

	vector<int> fibonacci;	// Initialize a resizable array (vector)
	fibonacci.insert(fibonacci.end(), 0);	// Seed the vector w/ first 2 vals
	fibonacci.insert(fibonacci.end(), 1);

	// Populate the vector and calculate a running sum
	int i = 1;
	int next = 0;

	while (fibonacci.back() < 10000) {

		int next = fibonacci.operator[](i-1) + fibonacci.operator[](i);
		fibonacci.insert(fibonacci.end(), next);

		if (next%2 !=0) {
			sum += next;
		}

		i++;
	}

	// Print the results
	cout << "Fibonacci sequence:\n";

	for (int j=0; j<fibonacci.size(); j++) {
		cout << fibonacci.operator[](j) << "\n";
	}

	cout << "\nSum of odd numbers under 10,000: " << sum;

	return 0;
}
