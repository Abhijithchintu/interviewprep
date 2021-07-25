//?? ??? ?????? ????
#include <bits/stdc++.h>
using namespace std;

#define vi  vector<int>
#define pb  push_back
#define ppb pop_back
#define lb  lower_bound
#define ub  upper_bound
#define all(c)  c.begin(),c.end()
#define gi  greater<int>

#define yes  cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define re return


const double pi = 3.14159265359;
const int modc = 998244353;
const int mod = 1000000007 ;

typedef long long int ll;



int lcm(int a, int b){  //for lcm 
    int g = __gcd(a,b);
    return (a*b)/g;
}


long long add(long long a, long long b,long long p){
    return (((a%p + p)%p) + ((b%p + p)%p))%p;
}

long long sub(long long a, long long b,long long p){
    return (((a%p + p)%p) - ((b%p + p)%p) + p)%p;
}


long long mul(long long a, long long b,long long p){
    return (((a%p + p)%p) * ((b%p + p)%p))%p;
}
 

//if want to reduce time limit by few milli seconds use if cndition for negative numbers
long long inline power(long long a, long long b, long long p){ //for power using modulo
    a %= p;
    long long ans = 1;
    if(a==0){
        return 0;
    }
    while(b>0){
        if(b & 1)
            ans = (((ans%p + p)%p)*((a%p + p)%p))%p;
        a = (((a%p + p)%p) * ((a%p + p)%p))%p;
        b >>= 1;
    }
    return ans;
}
 
int mod_inv(long long n, long long p){ //eulers theorm
    return power(n,p-2, p);
}


void prime_ar(int n){ //sieve of Eratosthenes,till 1e8
    bool ar[n + 1];
    memset(ar, true, sizeof(ar));
    for (int p=2;p*p<=n;p++){
        if(ar[p]==true){
            for(int i=p*p;i<=n;i += p){
                ar[i] = false;
            }
        }
    }

}

bool inline isPrime(int n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6){
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    }
    return true;
}
bool ispow2(ll x){ 
    if(ceil(log2(x))==floor(log2(x))){
        return true;
    }
    return false;
}
/*
const int M = 3e5 + 5;
int fact[M];
int ncr(int n, int r){
	int ans = fact[n];
	int denom = mul(fact[r],fact[n-r],mod);
	ans = mul(ans,mod_inv(denom,mod),mod);
	return ans%mod;
}
*/
void sol(){
    string text,pattern;
    cin>>text>>pattern;
    int m = pattern.size(),n = text.size();
    int p = 0,t=0; // hash values of pattern and text
    int d = 256,q=101;
    int h = power(d,m-1,q);
    for(int i=0;i<m;i++){
        p = (d*p + (int)pattern[i])%q;
        t = (d*t + (int)text[i])%q;
    }
    cout<<"yee"<<endl;
    for(int i=0;i<=n-m;i++){
        if(p == t){
            int f = 0;
            for(int j=0;j<m;j++){
                if(text[i+j] != pattern[j]){
                    f =1;
                }
            }
            if(f==0){
                cout<<i<<endl;
            }
        }
        
        if(i<n-m){
            t = (d*(t - (int)text[i]*h) + (int)text[i+m])%q; 
            if(t<0){
                t = t + q;
            }
        }
        
    }

    return;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int tc=1;
   // cin>>tc;

    while(tc--){
        sol();
    }
	return 0;
}
