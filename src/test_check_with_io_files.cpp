#include <iostream>   // cin, cout
#include <vector>     // vector
#include <algorithm>  // sort, max, min, etc.
#include <fstream>    // file I/O
#include <string>     // string
using namespace std;

int main() {
    // Redirect input/output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // Example: sum elements + x
    int sum = x;
    for(int val : v) sum += val;
    cout << sum << "\n hellowwwteetas" << endl;

    return 0;
}