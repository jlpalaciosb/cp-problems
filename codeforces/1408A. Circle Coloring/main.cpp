#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int a[3][100];
        for(int k=0; k<3; k++){
            for(int i=0; i<n; i++){
                cin>>a[k][i];
            }
        }

        vi p; p.resize(n);
        p[0]=a[0][0];
        for(int i=1; i<n; i++){
            for(int k=0; k<3; k++){
                if(a[k][i]!=p[i-1]){
                    p[i]=a[k][i];
                    break;
                }
            }
        }
        for(int k=0; k<3; k++){
            if(a[k][0]!=p[1] && a[k][0]!=p[n-1]){
                p[0]=a[k][0];
                break;
            }
        }

        for(int i=0; i<n; i++){
            cout<<p[i]<<' ';
        } cout << endl;
    }
    
    return 0;
}
