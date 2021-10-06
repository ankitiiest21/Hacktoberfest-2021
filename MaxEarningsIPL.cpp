#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

//A player cannot play for more than 2 matches in a row 
ll maxEarning(ll a[],ll n)
{
 ll*dp=new ll[n];
 ll sum=0;
 if(n<=3){
 	REP(i,0,n)
 	 sum+=a[i];
 	return sum-*min_element(a,a+n);
 }
 dp[0]=a[0],dp[1]=a[1],dp[2]=a[2];
 sum+=a[0]+a[1]+a[2];
 REP(i,3,n)
 {
  dp[i]=a[i]+min({dp[i-1],dp[i-2],dp[i-3]});
  sum+=a[i];
 }
 return sum-min({dp[n-1],dp[n-2],dp[n-3]});
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<maxEarning(a,n)<<endl;
 return 0;
}