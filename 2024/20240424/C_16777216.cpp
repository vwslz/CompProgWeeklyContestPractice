#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<int> vals(n);
    int cmax = 0;
    int cmin = 0;
    int cval = 0;
    int total = 0;
    for(int i = 0; i < n;++i){
        cin >> vals[i];
        if(i%2 == 0){
            cval += vals[i];
        }else{
            cval -= vals[i];
        }
        total += abs(vals[i]);
        cmax = max(cval,cmax);
        cmin = min(cval,cmin);
    }
    vector<vector<char>> data(cmax-cmin, vector<char>(total,' '));
    int cy = 0;
    int cx = 0;
    for(int i = 0; i < vals.size();++i){
        int cd = vals[i];
        for(int j = cx;j<cx+abs(cd);++j){
            data[cmax-cy-1][j] = (i%2 == 0)? '/' : '\\';
            if(i%2 == 0){
                cy++;
            }else{
                cy--;
            }
        }
        if(i%2 == 0){
            cy--;
        }else{
            cy++;
        }
        cx += abs(cd);

    }
    for(auto& v: data){
        for(auto& c: v)cout << c ;
        cout << endl;
    }

    return 0;
}
