#include<bits/stdc++.h>
using namespace std;
int dp[100][100];


    int MCM(int arr[], int i , int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = INT_MAX;
        for(int k =i;k<=j;k++){
            dp[i][j] = min(dp[i][j], MCM(arr,i,k)+MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]));
        }
        return dp[i][j];

    }

    int ans(int arr[], int n){
    int i = 1;
    int j = n - 1;
    return MCM(arr, i, j);
    }

int main(){
    int s;
    cin>>s;
    int a[s];
    for (int q = 0; q<s;q++){
        cin>>a[q];
    }
    memset(dp, -1, sizeof dp);
    cout<<"Multiplications :"<<ans(a,s)<<endl;

  



}