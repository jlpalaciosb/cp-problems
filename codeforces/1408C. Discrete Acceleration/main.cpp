#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    
    int t; cin>>t;
    while(t--){
        int n, l; cin>>n>>l;
        vi a; a.resize(n+2);
        a[0]=0;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        a[n+1]=l;

        vector<ld> ta; ta.resize(n+2);
        ta[0]=0;
        ld v=1;
        for(int i=1; i<n+2; i++, v++){
            ta[i]=(a[i]-a[i-1])/v+ta[i-1];
        }

        vector<ld> tb; tb.resize(n+2);
        tb[n+1]=0;
        v=-1;
        for(int i=n; i>=0; i--, v--){
            tb[i]=(a[i]-a[i+1])/v+tb[i+1];
        }

        for(int i=0; i<n+2; i++){
            if(ta[i]>tb[i]){
                ld t1a=ta[i-1], t2a=ta[i], t1b=tb[i-1], t2b=tb[i];
                ld c=(t2a-t1a)/(t2b-t1b);
                cout<<fixed<<((t1a-c*t1b)/(1-c))<<endl;
                break;
            }
        }
    }
    
    return 0;
}
