// C++ program for the above approach
#include <bits/stdc++.h>
#define maxN 100
using namespace std;

// Stores nodes value of the Tree
int Tree[4 * maxN];

// Function to build segment tree
void build(int arr[], int index,
		int s, int e)
{
	// Base Case
	if (s == e)
		Tree[index] = arr[s];

	else {
		// Find the value of mid
		int m = (s + e) / 2;

		// Update for left subtree
		build(arr, 2 * index, s, m);

		// Update for right subtree
		build(arr, 2 * index + 1,
			m + 1, e);

		// Update the value at the
		// current index
		Tree[index]
			= max(Tree[2 * index],
				Tree[2 * index + 1]);
	}
}

// Function for finding the index
// of the first element at least x
int atleast_x(int index, int s, int e,
			int ql, int qr, int x)
{
	// If current range does
	// not lie in query range
	if (ql > e || qr < s)
		return -1;

	// If current range is inside
	// of query range
	if (s <= ql && e <= qr) {

		// Maximum value in this
		// range is less than x
		if (Tree[index] < x)
			return -1;

		// Finding index of first
		// value in this range
		while (s != e) {
			int m = (s + e) / 2;

			// Update the value of
			// the minimum index
			if (Tree[2 * index] >= x) {
				e = m;
				index = 2 * index;
			}
			else {
				s = m + 1;
				index = 2 * index + 1;
			}
		}
		return s;
	}

	// Find mid of the current range
	int m = (s + e) / 2;

	// Left subtree
	int val = atleast_x(2 * index, s,
						m, ql, qr, x);

	if (val != -1)
		return val;

	// If it does not lie in
	// left subtree
	return atleast_x(2 * index + 1, m + 1,
					e, ql, qr, x);
}

// Function for updating segment tree
void update(int index, int s, int e,
			int new_val, int pos)
{
	// Update the value, we
	// reached leaf node
	if (s == e)
		Tree[index] = new_val;

	else {

		// Find the mid
		int m = (s + e) / 2;

		if (pos <= m) {

			// If pos lies in the
			// left subtree
			update(2 * index, s, m,
				new_val, pos);
		}
		else {

			// pos lies in the
			// right subtree
			update(2 * index + 1,
				m + 1, e,
				new_val, pos);
		}

		// Update the maximum value
		// in the range
		Tree[index]
			= max(Tree[2 * index],
				Tree[2 * index + 1]);
	}
}

// Function to print the answer
// for the given queries
void printAnswer(int* arr, int n)
{
	// Build segment tree
	build(arr, 1, 0, n - 1);

	// Find index of first value
	// atleast 2 in range [0, n-1]
	cout << atleast_x(1, 0, n - 1,
					0, n - 1, 2)
		<< "\n";

	// Update value at index 2 to 5
	arr[2] = 5;
	update(1, 0, n - 1, 5, 2);

	// Find index of first value
	// atleast 4 in range [0, n-1]
	cout << atleast_x(1, 0, n - 1,
					0, n - 1, 4)
		<< "\n";

	// Find index of first value
	// atleast 0 in range [0, n-1]
	cout << atleast_x(1, 0, n - 1,
					0, n - 1, 0)
		<< "\n";
}

// Driver Code
int main()
{
	int arr[] = { 1, 3, 2, 4, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	printAnswer(arr, N);

	return 0;
}
