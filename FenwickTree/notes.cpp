// 03/12/25

// Fenwick Trees
// Q. LeetCode 307: Range Sum Query Mutable
class NumArray {
    vector<int> bits;
    vector<int> a;
    int n;

    void updateBits(int i, int val) {
        while(i <= n) {
            bits[i] += val;
            i += (-i&i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i >= 1) {
            sum += bits[i];
            i -= (-i&i);
        }
        return sum;
    }
public:

    NumArray(vector<int>& nums) {
        n = nums.size();
        bits.assign(n+1, 0);
        a.assign(n+1, 0);
        for(int i = 1; i <= n; i++) {
            a[i] = nums[i-1];
            updateBits(i, nums[i-1]);
        }
    }
    
    void update(int i, int val) {
        int delta = val - a[i+1];
        a[i+1] = val;
        updateBits(i+1, delta);
    }
    
    int sumRange(int l, int r) {
        return query(r+1) - query(l);
    }
};
