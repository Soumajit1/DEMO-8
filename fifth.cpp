class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;
        const long long INF = 1e16;
        long long min_even_sum = INF;
        long long curr_odd = INF;
        long long curr_even = INF;
        for (int i = 0; i < n; ++i){
            long long val = nums[i];
            if (i % 2 != 0){
                val = -val;
            }
            total_sum += val;
            if (i == 0){
                curr_odd = val;
            } else {
            long long next_even = curr_odd + val;
            long long next_odd = min(val, curr_even + val);
            curr_even = next_even;
            curr_odd = next_odd;
            min_even_sum = min(min_even_sum, curr_even);
        }
    }
    long long max_delta = 0;
        if (n >= 2){
            max_delta = max(0LL, -2LL * min_even_sum);
        }
        return total_sum + max_delta;
        }
};
