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
        int n,k; cin>>n>>k;
        vi a; a.resize(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        if(k==1) {
            cout<<(a[0]==a[n-1]?1:-1)<<endl;
            continue;
        }

        int ans=0;
        do{
            ans++;
            int dif=0,b=-1;
            for(int i=0; i<n; i++){
                if(dif<k && a[i]!=b){
                    b=a[i];
                    dif++;
                }
                a[i]-=b;
            }
        }while(a[n-1]!=0);
        cout<<ans<<endl;
    }
    
    return 0;
}
