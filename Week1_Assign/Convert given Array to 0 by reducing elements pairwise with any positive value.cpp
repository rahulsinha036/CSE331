// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check whether
// all element of vector can
// become zero after the operations
void gfg(vector<int>& v)
{

	// Priroty queue to store
	// elements of vector v
	priority_queue<int> q;

	// Loop to store elements
	// in priroty queue
	for (auto x : v) {
		q.push(x);
	}

	// Stores the number
	// of operations needed
	int cnt = 0;
	while (q.size() >= 2) {

		// Variable to store greatest
		// element of priority queue
		int ele1 = q.top();
		q.pop();

		// Variable to store second greatest
		// element of priority queue
		int ele2 = q.top();
		q.pop();

		// Decrementing both by 1
		ele1--;
		ele2--;
		cnt += 2;

		// If elements are greater
		// then zero it is again
		// stored in the priority queue
		if (ele1) {
			q.push(ele1);
		}
		if (ele2) {
			q.push(ele2);
		}
	}

	if (q.size() == 0)
		cout << cnt << endl;
	else
		cout << -1;
}

// Driver code
int main()
{

	vector<int> v = { 5, 3, 4 };
	gfg(v);
}
