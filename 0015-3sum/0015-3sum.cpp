class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Fix one element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Since array is sorted, if nums[i] > 0,
            // sum can never become 0.
            if (nums[i] > 0)
                break;

            int left = i + 1;
            int right = n - 1;

            // Step 3: Two pointer approach
            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[left]
                              + nums[right];

                if (sum == 0) {
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};