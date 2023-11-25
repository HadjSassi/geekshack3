class Main {
int solve(int arr[],vector<vector<int>>& dp, int i, int j)
{
    if(i>j) return 0;
    if(i==j) return arr[i];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
 int left = arr[i] + min(solve(arr,dp,i+1,j-1),solve(arr,dp,i+2,j));
 int right= arr[j] + min(solve(arr,dp,i+1,j-1),solve(arr,dp,i,j-2));
    
    return dp[i][j] = max(left,right);
}
int maximumAmount(int arr[], int n) 
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(arr,dp,0,n-1);
}
