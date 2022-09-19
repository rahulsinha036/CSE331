// C++ code for the above approach:

#include <bits/stdc++.h>
using namespace std;

// Function to find if target[] can be reached
bool createTarget(vector<int>& target)
{

	// Initialise size of target array
	int n = target.size();

	// Initialise variable to store
	// sum of values
	int sum = 0;

	// Initialise variable to store
	// last sum
	int lastSum;

	// Initialise a max-heap to keep track
	// of the maximum element
	priority_queue<int> maxHeap(target.begin(),
								target.end());

	// Start traversing to find the sum
	for (int i = 0; i < n; i++) {
		sum = sum + target[i];
	}

	// While heap has element traverse
	while (true) {

		// Update last sum with
		// maximum value of heap
		lastSum = maxHeap.top();

		// Pop the maximum element
		// of the heap
		maxHeap.pop();

		// Update sum of values
		sum = sum - lastSum;

		// If either sum or last sum is
		// equal to 1, then
		// target array possible
		if (lastSum == 1 || sum == 1) {

			// Return true
			return true;
		}

		// If last sum becomes less than
		// sum or if sum becomes equal
		// to 0 or if difference of last
		// sum and sum becomes 0
		if (lastSum < sum || sum == 0
			|| lastSum - sum == 0) {

			// Return false
			return false;
		}

		// Update last sum
		lastSum = lastSum - sum;

		// Update sum
		sum = sum + lastSum;

		// Push last sum into the queue
		maxHeap.push(lastSum);
	}
}

// Driver code
int main()
{
	int N = 2;
	vector<int> target = { 2, 3 };
	bool ans = createTarget(target);
	if (ans)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
