#include<bits/stdc++.h>
using namespace std;
vector<int> lis(vector<int> v){
    vector<int> last(1,0),index(v.size(),-1);;
    last[0] = v[0];
    vector<int> tailindex(v.size(),0);
    vector<int> previndex(v.size(),-1),LIS;
    int l = 1; ///point to the empty space in the 'last' vector
    for(int i=1; i<v.size(); i++){
        if( v[i] > last[l-1] ){ ///extend the largest sequence
            last.push_back(v[i]);
            previndex[i] = tailindex[l-1]; 
            tailindex[l++] = i;
            continue;
        }
        if( v[i] < last[0] ){///start new sequence of length 1
            last[0] = v[i];
            tailindex[0] = i;
            continue;
        }
        else{///find the list that can be extended
            int pos = (int)(upper_bound(last.begin(),last.end(),v[i])-last.begin());
            last[pos] = v[i];
            previndex[i] = tailindex[pos-1];
            tailindex[pos] = i;
            continue;
        }
    }
    for(int i=tailindex[l-1]; i>=0; i=previndex[i])
         LIS.insert(LIS.begin(),v[i]);
    return LIS;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
	    int x; cin >> x;
	    v.push_back(x);
	}
 	vector<int> LIS = lis(v);
 	for(int i=0; i< LIS.size(); i++)
 	    cout << LIS[i] <<" ";cout<<endl;
	return 0;
}