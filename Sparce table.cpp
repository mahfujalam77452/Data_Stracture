//We can find by the algorithm the range of minimum,maximum,gcd but not the sum.
//as well as the update is not available in this algorithm.
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 10;
const int LOG=17;
int a[N];
int m[N][LOG];//here m[i][j] means the minimum number between i to 2^j;
int bin_log[N];
int query(int L,int R){//log(1) time.
    int length=R-L+1;
    int k=bin_log[length];//you can calculate it by using log2() function.
                          //but can't by log() function. Beacuse the log()
                          //function in c++ is e based.
    return min(m[L][k],m[R-(1<<k)+1][k]);
}
//This implementation for Range sum query.Time O(log(n)).
int query_sum(int L, int R){
    int sum=0;
    for(int i=LOG-1;i>=0;i--){
        if((1<<i<=(R-L+1))){
            sum+=m[L][i];
            L+=(1<<i);
        }
    }
    return sum;
}
int32_t main()
{
   int n;
   cin>>n;
   bin_log[1]=0;
   for(int i=2;i<=n;i++)bin_log[i]=bin_log[i/2]+1;
   for(int i=0;i<n;i++){
       cin>>a[i];
       m[i][0]=a[i];
   }
   
   for(int k=1;k<LOG;k++){//preprocessing O(N*log(N));
       for(int i=0;(i+(1<<k)-1)<n;i++){
           m[i][k]=min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
       }
   }
   /* If we want to find the Range sum query
   for(int k=1;k<LOG;k++){//preprocessing O(N*log(N));
       for(int i=0;(i+(1<<k)-1)<n;i++){
           m[i][k]=m[i][k-1]+m[i+(1<<(k-1))][k-1];
       }
   }*/
   int q;
   cin>>q;
   for(int i=0;i<q;i++){
       int L,R;
       cin>>L>>R;
       cout<<query(L,R)<<endl;
   }
	return 0;
}
