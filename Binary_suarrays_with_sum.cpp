https://leetcode.com/problems/binary-subarrays-with-sum/description/

BINARY SUBARRAYS WITH SUM

// Brute Force Method:
// TC = O(n^3)

int fun(int arr[], int n, int target){
    int sum = 0;
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            if(sum == target){
                count++;
            }
        }
    }
    return count;
}

// Better Approach:
// TC = O(n^2)

int fun(int arr[], int n, int target){
    int sum = 0;
    int count = 0;

    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == target){
                count++;
            }
        }
    }
    return count;
}


// Optimal Approach:
// TC = O(n)

int fun(int arr[], int n, int target){
    int count = 0;
    int presum = 0;
    unordered_map<int, int> mp;

    mp[0] = 1;

    for(int i=0;i<n;i++){
        presum += arr[i];
        int remove = presum - K;

        if(mp.find(remove) != mp.end()){
            count += mp[remove];
        }

        mp[presum]++;
    }

    return count;
}


// Optimal Approach-2: Sliding Window
// TC = O(n)

int fun(int arr[], int n, int target){
    int n = nums.size();
    int zerosCount = 0;
    int window_sum = 0;
    int ans = 0;

    int i = 0, j = 0;

    while(j < n){
        window_sum += nums[j];

        while(i < j && (nums[i] == 0 || window_sum > k)){
            if(nums[i] == 0){
                zerosCount++;
            }
            else{
                zerosCount = 0;
            }

            window_sum -= nums[i];
            i++;
        }

        if(window_sum == k){
            ans += 1;
            ans += zerosCount;
        }
        j++;
    }

    return ans;
}
