#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int cp[15][15],dp[15][15];
int main(){
string s="GEEKS FOR GEEKS";
int n=s.length();
for(int i=1;i<=n;i++) cp[i][i]=dp[i][i] = 1;
for(int len=2;len<=n;len++){
	for(int i=1;i<=n-len+1;i++){
		int j = i + len - 1;
		if(s[i - 1] == s[j - 1]){
			dp[i][j] = dp[i + 1][j - 1] + 2;
		}
		else {
			dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
		}
	}
}

int mx=1,idx=0;
string t="abcbabcbabcba";
int m=t.length();
for (int len=2;len<=m;len++){
	for(int i=1;i<=m-len+1;i++){
		int j=i+len-1;
		if(t[i-1]==t[j-1]){
			cp[i][j]=cp[i+1][j-1]+2;
			if(cp[i][j]>mx){
				mx=cp[i][j];
				idx=i-1;
			}
		}
		else cp[i][j]=0;
	}
}
cout<<dp[1][n]<<endl;
cout<<mx<<" "<<idx<<endl;
for(int i=0;i<mx;i++){
	cout<<t[i+idx];
}
return 0;
}
