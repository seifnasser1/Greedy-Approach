#include <iostream>
using namespace std;

void minSpacePreferLarge(int wall, int m, int n)
{
	// for simplicity, Assuming m is always smaller and costs more than n
	int num_m = 0, num_n = 0, min_empty = wall;

	// p and q are no of shelves of length m and n
	int p = wall / m; 
	int q = 0;

	// rem is the empty space
	int rem = wall % m;
	num_m = p;
	num_n = q;
	min_empty = rem;

	while (wall >= n) {
		// place one more shelf of length n
		q =q+ 1;
		wall = wall - n;
		// place as many shelves of length m in the remaining part
		p = wall / m;
		rem = wall % m;

		// update output variablse if curr min_empty <= overall empty
		if (rem <= min_empty) {
			num_m = p;
			num_n = q;
			min_empty = rem;
		}
	}
	cout << "m = "<<num_m << " " << "n = "<<num_n << " "
		<< "empty space = "<<min_empty << endl;
}

int main()
{
	int wall, m , n;
	cout << "Wall Length = ";
	cin >> wall;
	cout << "Shelf m Length = ";
	cin >> m;
	cout << "Shelf n Length (must be greater than m) = ";
	cin >> n;
	if (n < m)
	{
		cout << "Incorrect input! Insert number greater than " << m << endl;
		cin >> n;
	}
	minSpacePreferLarge(wall, m, n);

	//wall = 76, m = 1, n = 10;
	//wall = 24, m = 3, n = 5;
	//wall = 29, m = 3, n = 9;

	//Time Complexity: O(wall/n)
}
