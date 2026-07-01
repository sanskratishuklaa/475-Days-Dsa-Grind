class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {

        // Starting index of the array
        int start = 0;

        // Last index of the array
        int end = nums.size() - 1;

        // Perform Binary Search until start crosses end
        while (start <= end) {

            // Find the middle index
            // This formula avoids integer overflow
            int mid = start + (end - start) / 2;

            // If target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }

            // If target is smaller than middle element,
            // search in the left half
            if (nums[mid] > target) {
                end = mid - 1;
            }

            // Otherwise search in the right half
            else {
                start = mid + 1;
            }
        }

        // If target is not found,
        // 'start' will point to the correct insert position
        return start;
    }
};