// code to calculate sum of numbers from l to r
// l and r are the lower and upper bound respectively
// sum is the sum of numbers from l to r
// i is the variable used to iterate from l to r

#include <iostream>
using namespace std;

int main() {
    int lower_bound, upper_bound, sum = 0;
    cin >> lower_bound >> upper_bound;
    if (lower_bound > upper_bound) {
        cout << "Invalid input" << endl;
        return 0;
    }
    for (int index = lower_bound; index <= upper_bound; index++) {
        sum += index;
    }
    cout << sum << endl;
    return 0;
}