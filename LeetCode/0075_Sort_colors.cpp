class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = -1, mid = 0, high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if (nums[mid] == 0) {
                low++;
                swap(nums[mid], nums[low]);
                mid++;
            } else {
                mid++;
            }
        }
        return;
    }
};