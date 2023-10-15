#include<iostream>
#include<map>
using namespace std;
int countNoOfSubarrayWithGivenXorKOptimial(vector<int>&a , int target){
    int n = a.size();
    int xr =0;
    int cnt=0;
    map<int,int>mp;
    mp[xr]++;
    for(int i=0;i<n;i++){
        xr = xr^a[i];
        cnt += mp[target^xr];
        mp[xr]++;
    }
    return cnt;

}
int countNoOfSubarrayWithGivenXorKBrute(vector<int>&a , int target){
    int n = a.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xr=0;
            for(int k=i;k<=j;k++){
                xr = xr^a[k];
            }if(xr == target) cnt++;
        }
    }
    return cnt;
}
int countNoOfSubarrayWithGivenXorKBetter(vector<int>&a , int target){
    int n = a.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
            xr = xr^a[j];
            if(xr == target) cnt++;
        }
    }
    return cnt;

}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    int target ;cin>>target;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans1 = countNoOfSubarrayWithGivenXorKBrute(a,target);
    cout<<ans1<<endl;

    int ans2 = countNoOfSubarrayWithGivenXorKBetter(a,target);
    cout<<ans2<<endl;

    int ans3 =countNoOfSubarrayWithGivenXorKOptimial(a,target);
    cout<<ans3<<endl;
}