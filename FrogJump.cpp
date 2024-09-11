// return minimum total energy used by the frog in order to reach the nth stair 
#include<bits/stdc++.h>
using namespace std;

int solve(int n,int height[6]){
    if(n==0)return 0;
    int left=solve(n-1,height)+abs(height[n]-height[n-1] );
    int right=INT_MAX;
    if(n>1){
        right=solve(n-2,height)+abs(height[n]-height[n-2]);
    }
    return min(left,right);
}

int solveMem(int n,int height[6],vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];

    int left = solveMem(n-1,height,dp)+abs(height[n]-height[n-1]);
    int right = INT_MAX;
    if(n>=1){
        right = solveMem(n-2,height,dp)+abs(height[n]-height[n-2]);
    }
    return dp[n]=min(left,right);
}

int solveTab(int n,int height[6]){
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int left = dp[i-1]+abs(height[i]-height[i-1]);
        int right =INT_MAX;
        if(i>=1) right=dp[i-2]+abs(height[i]-height[i-2]);
        
        dp[i]=min(left,right);
    }
    return dp[n-1];
}
int solveSO(int n,int height[6]){
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int left=prev+abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(i>=1) right=prev2+abs(height[i]-height[i-2]);

        int curri=min(left,right);
        prev2=prev;
        prev=curri;
    }
    return prev;
}

int main(){
    int n = 4;
    int height[6]={30,10,60,10,50};

    // cout<<"The minimum enery required to jump to nth stair is: "<<solve(n,height);

    //memoization
    vector<int>dp(n+1,-1);
    cout<<"The minimum enery required to jump to nth stair is: "<<solveMem(n,height,dp)<<endl;

   //tabulation
   
    cout<<"The minimum enery required to jump to nth stair is: "<<solveTab(n,height)<<endl;

    //space optimization
    cout<<"The minimum enery required t o jump to nth stair is: "<<solveSO(n,height)<<endl;

    return 0;
}