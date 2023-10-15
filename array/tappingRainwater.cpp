#include<iostream>
using namespace std;

int tappingRainWaterBrute(vector<int>&a){
    int cnt = 0;
    int n = a.size();
    int maxileft  = a[0] , maxiright = a[n-1];
    if(n == 0)return n;
    vector<int>left , right;
    left.push_back(maxileft);
    right.push_back(maxiright);
    for(int i=0;i<n;i++){
        maxileft = max(a[i] , maxileft);
        left.push_back(maxileft);
        maxiright  = max(maxiright , a[n-i-1]);
        right.push_back(maxiright);
    }
    reverse(right.begin(),right.end());
    for(int i=0;i<n;i++) cnt += max(0,min(left[i],right[i]) - a[i]); 
    return cnt;
}
int tappingRainWaterOptimal(vector<int>&a){
    int ans = 0;
    int n = a.size();
    if(n == 0)return n;
    int s = 0 ,e = n-1;
    int maxstart = 0 ,maxend = 0;
    while(s<=e){
        if(a[s] <= a[e]){
            if(a[s] >= maxstart) maxstart = a[s];
            else ans += maxstart - a[s];
            s++;
        }else{
            if(a[e] >= maxend) maxend = a[e];
            else ans += maxend - a[e];
            e--;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int ans1 = tappingRainWaterBrute(a);
    cout<<ans1<<endl;

    int ans2 = tappingRainWaterOptimal(a);
    cout<<ans2<<endl;

}