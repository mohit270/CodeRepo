#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > mergeIntervalBrute(vector<vector<int> >& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int> > ans;
    for (int i = 0; i < n; i++) {
        int s = a[i][0];
        int e = a[i][1];
        if (!ans.empty() && e <= ans.back()[1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (a[j][0] <= e) e = max(e, a[j][1]);
            else break;
        }
        vector<int> temp(2);
        temp[0] = s;
        temp[1] = e;
        ans.push_back(temp);
    }
    return ans;
}
vector<vector<int> > mergeIntervalOptimal(vector<vector<int> >& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int> > ans;
    for (int i = 0; i < n; i++) {
        if(ans.empty() || a[i][0] > ans.back()[1]) ans.push_back(a[i]);
        else ans.back()[1] = max(a[i][1] , ans.back()[1]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }cout << endl;

    vector<vector<int> > mergeInterval1 = mergeIntervalBrute(a);
    for (int i = 0; i < mergeInterval1.size(); i++) {
        for (int j = 0; j < mergeInterval1[0].size(); j++) {
            cout << mergeInterval1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<vector<int> > mergeInterval2 = mergeIntervalOptimal(a);
    for (int i = 0; i < mergeInterval2.size(); i++) {
        for (int j = 0; j < 2; j++) {
            cout << mergeInterval2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
