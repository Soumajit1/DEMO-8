class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> R(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i){
            while (!st.empty() && nums[i] < nums [st.top()]) {
                R[st.top()] = i;
                st.pop();
                    
            }
            st.push(i);
        }
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) pos[nums[i]].push_back(i);
        long long ans  = 0;
        for (int i = 0; i < n; ++i){
            int total = R[i] - 1 - i;
            if (total <= 0) continue;
            const auto& p = pos[nums[i]];
            int eq = upper_bound(p.begin(), p.end(), R[i] - 1) -
             lower_bound(p.begin(), p.end(), i + 1);
            ans += (total - eq);
        }
        return ans;
    }
};
