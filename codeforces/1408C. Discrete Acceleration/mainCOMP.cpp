#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin>>t;
    while(t--){
        int n,l; cin>>n>>l;
        vi a; a.resize(n+2);
        a[0]=0;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        a[n+1]=l;

        long double ta1=0,xa1=0,tb1,xb1,v1=1;
        long double ta2=0,xa2=l,tb2,xb2,v2=-1;
        int j=n;
        for(int i=1; i<n+2; i++){
            xb1=a[i];
            tb1=ta1+(xb1-xa1)/v1;
            while(true){
                xb2=a[j];
                tb2=ta2+(xb2-xa2)/v2;

                // complicado

                xa2=xb2;
                ta2=tb2;
                j--;
            }
            xa1=xb1;
            ta1=tb1;
        }
    }
    
    return 0;
}
