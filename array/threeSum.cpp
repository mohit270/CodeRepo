#include<iostream>
#include<set>
#include <vector>
using namespace std;
vector<vector<int> > threeSumBrute(vector<int>&a , int target){
    set<vector<int> >st;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k] == target){
                    vector<int> temp ;
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    temp.push_back(a[k]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }vector<vector<int> >ans(st.begin(),st.end());
    return ans;
}
vector<vector<int> > threeSumBetter(vector<int>&a , int target){
    set<vector<int> >st;
    int n = a.size();
    for(int i=0;i<n;i++){
        set<int>ss;
        for(int j=i+1;j<n;j++){
            int third = target -(a[i]+a[j]);
            if(ss.find(third)!=ss.end()){
                vector<int> temp;
                temp.push_back(a[i]);
                temp.push_back(a[j]);
                temp.push_back(third);
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }ss.insert(a[j]);
        }
    }vector<vector<int> >ans(st.begin(),st.end());
    return ans;
}
vector<vector<int> > threeSumOptimal(vector<int>&a,int target){
    int n = a.size();
    vector<vector<int> >ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i>0 && a[i] == a[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum > target) k--;
            else if(sum < target) j++;
            else{
                vector<int>temp;
                temp.push_back(a[i]);
                temp.push_back(a[j]);
                temp.push_back(a[k]);
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j] == a[j-1]) j++;
                while(j<k && a[k] == a[k-1]) k--;

            }
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> a(n);
    int target;cin>>target;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Three sum Brute force Approach \n";
    vector<vector<int> > bruteResult = threeSumBrute(a,target);
    for (const auto& triplet : bruteResult) {
        for (const int& num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout<<"Three sum better Approach \n";
    vector<vector<int> > betterResult = threeSumBetter(a,target);
    for (const auto& triplet : betterResult) {
        for (const int& num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout<<"Three sum optimal Approach \n";
    vector<vector<int> > optimalResult = threeSumOptimal(a,target);
    for (const auto& triplet : optimalResult) {
        for (const int& num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }


}