class Solution {
public:

    // Function to find all unique triplets
    // whose sum becomes 0
    vector<vector<int>> threeSum(vector<int>& nums) {

        // This will store final answer
        vector<vector<int>> res;

        // Step 1:
        // Sort the array
        // Why?
        // Because two pointer technique works on sorted array
        sort(nums.begin(), nums.end());

        // Store size of array
        int n = nums.size();

        // Step 2:
        // Pick one element one by one
        // We stop at n-2 because we need 3 elements
        for (int i = 0; i < n - 2; ++i) {

            // Skip duplicate elements
            // Example:
            // [-1, -1, 0, 1]
            // If we use both -1 again and again,
            // duplicate answers will come
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Left pointer starts just after i
            int left = i + 1;

            // Right pointer starts from end
            int right = n - 1;

            // Step 3:
            // Use two pointers to find remaining 2 numbers
            while (left < right) {

                // Calculate sum of 3 numbers
                int sum = nums[i] + nums[left] + nums[right];

                // Case 1:
                // If sum becomes 0
                // then we found one valid triplet
                if (sum == 0) {

                    // Add triplet into result
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values from left side
                    // Example:
                    // [0,0,0,0]
                    while (left < right &&
                           nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicate values from right side
                    while (left < right &&
                           nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers
                    left++;
                    right--;
                }

                // Case 2:
                // Sum is smaller than 0
                // We need bigger value
                // Move left pointer forward
                else if (sum < 0) {
                    left++;
                }

                // Case 3:
                // Sum is greater than 0
                // We need smaller value
                // Move right pointer backward
                else {
                    right--;
                }
            }
        }

        // Return final answer
        return res;
    }
};