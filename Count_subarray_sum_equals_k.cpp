https://leetcode.com/problems/subarray-sum-equals-k/description/

COUNT SUBARRAY SUM EQUALS K

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