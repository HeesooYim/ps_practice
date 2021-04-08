int max (int a, int b){
    return a>b ? a:b;
}

int rob(int* nums, int numsSize){
    int ans=0;
    int dp[102]={};
    dp[0]=nums[0];
    
    if(numsSize > 1) dp[1]=max(nums[0], nums[1]);
    if(numsSize > 2) dp[2]=max(nums[0]+nums[2], nums[1]);

    for(int i=3;i<numsSize;i++){
        dp[i]=max(dp[i-3]+nums[i], max(dp[i-2]+nums[i], dp[i-1]));
    }
    
    ans = dp[numsSize-1];
    if(numsSize > 1){
        ans=max(ans, dp[numsSize-2]);
    }
    if(numsSize > 2){
        ans=max(ans, dp[numsSize-3]);
    }
    
    return ans;
}
