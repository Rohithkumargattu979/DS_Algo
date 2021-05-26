/*** RohithGattu ***/
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<functional>
#include<map>
#include<unordered_map>
#include<math.h>
#include <cctype>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair
#define fr(i,s,e) for(int i=s; i<e; i++)
#define rf(i,s,e) for(int i=e; i>s; i--)
#define vfr(it, g1)  for (auto it = g1.begin(); it != g1.end(); it++)
#define pp pop_back
#define bs binary_search
#define ins insert
#define ln length
#define ll long long int
#define vsort(a) sort(a.begin(), a.end())
#define asort(a,n) sort(a,a+n);
#define adsort(arr,n) sort(arr, arr + n, greater<int>())
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rea(a,n)  for(int i=0; i<n; i++) cin>>a[i]
#define pra(a,n)  for(int i=0;i<n;i++) cout<<a[i]<<" "
#define lb lower_bound
#define ub upper_bound
#define lss bool operator < (const class_name& rhs) const {return object<rhs.object;}
#define grtr bool operator < (const class_name& rhs) const {return object>rhs.object;}


// Memoization approach 
int helper(vector<int> weights, vector<int> values, int capacity, int n, vector<vector<int>>& dp) {
    
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }
    if (weights[n - 1] <= capacity) {
        return dp[n][capacity] =  max(values[n - 1] + helper(weights, values, capacity - weights[n - 1], n-1, dp),
                   helper(weights, values, capacity, n - 1, dp));
    }
     else if (weights[n - 1] > capacity) {
        return dp[n][capacity] = helper(weights, values, capacity, n - 1, dp);
    }
    return 0;
}
int main(){
    int capacity;
    cin>>capacity;
    int n;
    cin>>n;
    vector<int> weights, values;
    rea(weights,n);
    rea(values,n);
    vector<vector<int>> dp(n+1, vector<int> (capacity,-1)); // dp  table with sizes n+1 and capacity + 1 initialized to -1 
    int maxx = helper(weights, values, capacity, n, dp);
}
