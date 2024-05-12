https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

// LONGEST SUBARRAY WITH SUM K (for both positives and negatives)

// Better Approach
int fun(int a[], int n, int k){
    unordered_map<int, int> mp;
    int maxLen = 0;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        int remove = sum - k;
        if(mp.find(remove) != mp.end()){
            int len = i - mp[remove];
            maxLen = max(maxLen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
        
    }

    return maxLen;
}


// Optimal Approach (for positives and zeroes)
int fun(int a[], int n, int k){
    int left = 0, right = 0; 
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward through right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
