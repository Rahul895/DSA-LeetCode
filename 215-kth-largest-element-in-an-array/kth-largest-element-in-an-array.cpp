class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l;

        for (int j = l; j < r; j++) {
            if (nums[j] < pivot)
                swap(nums[i++], nums[j]);
        }

        swap(nums[i], nums[r]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int pivotIndex = l + rand() % (r - l + 1);
            swap(nums[pivotIndex], nums[r]);

            int p = partition(nums, l, r);

            if (p == target)
                return nums[p];
            else if (p < target)
                l = p + 1;
            else
                r = p - 1;
        }

        return -1;
    }
};