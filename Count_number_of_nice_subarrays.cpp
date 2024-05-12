https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// COUNT NUMBER OF NICE SUBARRAYS


int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] % 2 != 0){
                nums[i] = 1;
            }
            else{
                nums[i] = 0;
            }
        }

        unordered_map<int, int> mp;

        int preSum = 0;
        int count = 0;

        mp[0] = 1;

        for(int i=0;i<n;i++){
            preSum += nums[i];
            int remove = preSum - k;
            if(mp.find(remove) != mp.end()){
                count += mp[remove];
            }
            mp[preSum]++;
        }
        return count;
    }