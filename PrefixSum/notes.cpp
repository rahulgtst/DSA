// 02/12/25

// Prefix Sum
// Q. LeetCode 303: Range Sum Query Immutable
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.reserve(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefix[right] : prefix[right]-prefix[left-1];
    }
};


// Q. LeetCode 307: Range Sum Query Mutable
class NumArray {
public:
    vector<int> prefix;
    vector<int> nums;

    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;

        // update all prefix values from index onward
        for(int i = index; i < prefix.size(); i++) {
            prefix[i] += delta;
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefix[right] : prefix[right] - prefix[left-1];
    }
};

// Q. LeetCode 527: Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> pre;
        pre[0] = -1;
        int sum = 0, result = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if(pre.count(sum)) {
                result = max(result, i-pre[sum]);
            } else {
                pre[sum] = i;
            }
        }
        return result;
    }
};
