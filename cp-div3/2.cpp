#include <iostream>
#include <vector>

// Function that removes duplicates from a sorted vector in-place.
// Returns the number of unique elements.
int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;  // slow-runner index
    for (int j = 1; j < (int)nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    // Example usage:

    // Input vector (sorted, may contain duplicates)
    std::vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5};

    std::cout << "Original vector: ";
    for (int x : nums) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // Call removeDuplicates
    int newLength = removeDuplicates(nums);

    // Output result
    std::cout << "After removing duplicates, new length = " << newLength << "\n";
    std::cout << "Unique elements: ";
    for (int i = 0; i < newLength; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
