#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
 
ll dp[2000009];

void maxSumKPartition(ll a[],ll n,ll k)
{
 ll max1=-1,max2=-1,index_of_max1=-1;
 REP(i,0,k)
 {
  dp[i]=max(a[i],0ll);
  if(max1<=dp[i])
  	max2=max1,max1=dp[i],index_of_max1=i;
  else if(dp[i]>max2&&dp[i]<=max1)
  	max2=dp[i];
 }
 for(ll i=k;i<n;i+=k)
 {
  for(ll j=0;j<k&&i+j<n;j++)
  {
   if(i+j-index_of_max1!=k)
   	dp[i+j]=max(0ll,max(max1,a[i+j]+max1));
   else
   	dp[i+j]=max(0ll,max(max2,a[i+j]+max2));
  }
  max1=-1,max2=-1,index_of_max1=-1;
  for(ll j=0;j<k&&i+j<n;j++)
  {
   if(max1<=dp[i+j])
   	max2=max1,max1=dp[i+j],index_of_max1=i+j;
   else if(dp[i+j]>max2&&dp[i+j]<=max1)
  	max2=dp[i+j];
  }
 }
}

int main()
{
 ll n,k,ans=INT_MIN;
 cin>>n>>k;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 maxSumKPartition(a,n,k);
 REP(i,0,n)
  ans=max(ans,dp[i]);
 cout<<ans<<endl;
}