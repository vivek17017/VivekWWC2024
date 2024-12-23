#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;  // If the array is empty, there are no unique elements

    int j = 1;  // Pointer for the next unique position
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i];  // Place the unique element at the correct position
            j++;  // Increment the position for the next unique element
        }
    }

    return j;  // Return the number of unique elements
}

int main() {
    // Example input: sorted array with duplicates
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    
    // Remove duplicates and get the number of unique elements
    int length = removeDuplicates(nums);
    
    // Output the result
    cout << "Number of unique elements: " << length << endl;
    cout << "Array after removing duplicates: ";
    
    // Print the unique elements
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
