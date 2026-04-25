#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int arr[1000001];
pair<int, int> pa[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int, pair<int,int>> st;
    int n, m, k,l,temp,temp2;
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k;
        arr[i] = k;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0)pa[arr[i]].first = arr[n - 1];
        else pa[arr[i]].first = arr[i - 1];
        if (i == n - 1)pa[arr[i]].second = arr[0];
        else pa[arr[i]].second = arr[i + 1];
        st.insert(make_pair(arr[i], pa[arr[i]]));
    }
   
    
   
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str == "BN") {
             cin >> k>> l;
            cout << st.find(k)->second.second << '\n';
            temp = st[k].second;
            st[k].second = l;
            st[temp].first = l;
            pa[l].first = k; pa[l].second = temp;
            st.insert(make_pair(l, pa[l]));
        }
        else if (str == "BP") {
             cin >> k >> l;
            cout << st.find(k)->second.first << '\n';
             temp = st[k].first;
            st[k].first = l;
            st[temp].second = l;
            pa[l].first = temp; pa[l].second = k;
            st.insert(make_pair(l, pa[l]));
        }
        else if (str == "CN") {
            cin >> k;
            cout << st[k].second << "\n";
             temp = st[k].second;
             temp2 = st[temp].second;
            st[k].second = st[temp].second;
            st[temp2].first = st[temp].first;
            st.erase(temp);
        }
        else if (str == "CP") {
            cin >> k;
            cout << st[k].first << "\n";
            temp = st[k].first; //이전역 index
            temp2 = st[temp].first; //전전역 index
            st[k].first = st[temp].first;   
            st[temp2].second = st[temp].second;
            st.erase(temp);
        }
    }

    return 0;
}