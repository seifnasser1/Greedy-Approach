// C++ program to find the minimum
// time to place all mice in all holes.
#include <iostream>
#include<algorithm>
using namespace std;
// Returns minimum time required to place mice in holes.
int assignHole(int mices[], int holes[], int n, int m)
{
	// Base Condition
	// No. of mouse and holes should be same
	if (n != m)
		return -1;

	// Sort the arrays
	sort(mices, mices + n);
	sort(holes, holes + m);

	// Finding max difference between
	// ith mice and hole
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (max < abs(mices[i] - holes[i]))
			max = abs(mices[i] - holes[i]);
	}
	return max;
}

int main()
{
	cout << "please enter the three mices" << endl;
	// Position of mouses
	int mices[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> mices[i];
	}
	cout << "please enter the three holes" << endl;

	// Position of holes
	int holes[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> holes[i];
	}
	// Number of mouses
	int n = sizeof(mices) / sizeof(mices[0]);

	// Number of holes
	int m = sizeof(holes) / sizeof(holes[0]);

	// The required answer is returned
	// from the function
	int minTime = assignHole(mices, holes, n, m);

	cout << "The last mouse gets into the hole in time: "
		<< minTime << " minutes" << endl;

	//Complexity: O(n)

	return 0;
}

