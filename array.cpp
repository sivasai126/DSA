#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void displayArray(const vector<int>& arr) {
    cout<< "[ ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout<<"]";
    cout << endl;
}

void insertElement(vector<int>& arr, int element, int position) {
    if (position > arr.size()) {
        cout << "Position out of bounds" << endl;
        return;
    }
    arr.insert(arr.begin() + position, element);
}

void deleteElement(vector<int>& arr, int position) {
    if (position >= arr.size()) {
        cout << "Position out of bounds" << endl;
        return;
    }
    arr.erase(arr.begin() + position);
}

int searchElement(const vector<int>& arr, int element) {
    auto it = find(arr.begin(), arr.end(), element);
    if (it != arr.end()) {
        return distance(arr.begin(), it);
    }
    return -1; // Return -1 if element is not found
}

void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    vector<int> myArray = {5, 3, 8, 6, 1};

    cout << "Original array: ";
    displayArray(myArray); // Output: [ 5 3 8 6 1 ]

    insertElement(myArray, 4, 2); // Insert 4 at position 2
    cout << "After inserting 4 at position 2: ";
    displayArray(myArray); // Output: [ 5 3 4 8 6 1 ]

    deleteElement(myArray, 3); // Delete element at position 3
    cout << "After deleting element at position 3: ";
    displayArray(myArray); // Output: [ 5 3 4 6 1 ]

    cout << "Searching for element 8: ";
    int pos = searchElement(myArray, 8);
    if (pos != -1) {
        cout << "Element found at position " << pos << endl;
    } else {
        cout << "Element not found" << endl;
    }

    sortArray(myArray);
    cout << "Sorted array: ";
    displayArray(myArray); // Output: [ 1 3 4 5 6 ]

    return 0;
}
