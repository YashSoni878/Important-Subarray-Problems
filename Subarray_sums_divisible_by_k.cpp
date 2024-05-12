https://leetcode.com/problems/subarray-sums-divisible-by-k/

// SUBARRAY SUMS EQUAL TO K

// Cumulative sum approach
// TC = O(n^2)

    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];
                
                if(sum % k == 0){
                    count++;
                }
            }
        }

        return count;
    }



// Optimal Approach
// TC = O(n)
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = 1;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }