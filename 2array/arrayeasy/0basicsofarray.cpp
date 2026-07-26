// Basic of Array in C++
// Includes: traversal, max element, linear search,
// and complex operations via reusable functions:
// insertion, deletion, update.

#include <bits/stdc++.h>
using namespace std;

static void printArray(const vector<int>& arr) {
    cout << "Array: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << (i + 1 < (int)arr.size() ? ' ' : '\n');
    }
}

// Linear search: returns index or -1
static int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

static int findMaxElement(const vector<int>& arr) {
    if (arr.empty()) return INT_MIN;
    int mx = arr[0];
    for (int i = 1; i < (int)arr.size(); i++) mx = max(mx, arr[i]);
    return mx;
}

// Insert at position pos (0..n). Shifts elements to the right.
static bool insertAt(vector<int>& arr, int pos, int val) {
    if (pos < 0 || pos > (int)arr.size()) return false;
    arr.insert(arr.begin() + pos, val);
    return true;
}

// Delete element at position pos (0..n-1). Shifts elements to the left.
static bool deleteAt(vector<int>& arr, int pos) {
    if (pos < 0 || pos >= (int)arr.size()) return false;
    arr.erase(arr.begin() + pos);
    return true;
}

// Update element at index pos to newVal.
static bool updateAt(vector<int>& arr, int pos, int newVal) {
    if (pos < 0 || pos >= (int)arr.size()) return false;
    arr[pos] = newVal;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Basics
    printArray(arr);

    int mx = findMaxElement(arr);
    if (mx != INT_MIN) cout << "Max: " << mx << "\n";

    int target;
    cin >> target;
    int idx = linearSearch(arr, target);
    if (idx == -1) cout << "Not found\n";
    else cout << "Found at index " << idx << "\n";

    // Complex ops (insertion/deletion/update)
    // Input format:
    // q
    // then q queries:
    // 1 pos val   -> insert val at index pos
    // 2 pos       -> delete element at index pos
    // 3 pos val   -> update index pos with val
    // 4            -> print array
    // 0            -> stop
    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 0) break;
        if (type == 4) {
            printArray(arr);
            continue;
        }

        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            cout << (insertAt(arr, pos, val) ? "Inserted\n" : "Invalid position\n");
        } else if (type == 2) {
            int pos;
            cin >> pos;
            cout << (deleteAt(arr, pos) ? "Deleted\n" : "Invalid position\n");
        } else if (type == 3) {
            int pos, val;
            cin >> pos >> val;
            cout << (updateAt(arr, pos, val) ? "Updated\n" : "Invalid position\n");
        }
    }

    return 0;
}

