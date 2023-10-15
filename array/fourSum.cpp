#include<iostream>
#include<set>
using namespace std;

vector<vector<int> > fourSumBrute(vector<int>&a ,int target){
    set<vector<int> >st;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int z = k+1;z<n;z++){
                    if(a[i]+a[j]+a[k]+a[z] == target){
                        vector<int>temp;
                        temp.push_back(a[i]);
                        temp.push_back(a[j]);
                        temp.push_back(a[k]);
                        temp.push_back(a[z]);
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }vector<vector<int> >ans(st.begin(),st.end());
    return ans;
}
vector<vector<int> > fourSumBetter(vector<int>&a , int target){
    set<vector<int> >st;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hset;
            for(int k=j+1;k<n;k++){
                long long sum = a[i] + a[j];
                sum += a[k];
                long long forth = target - (sum);

                if(hset.find(forth) != hset.end()){
                    vector<int> temp ;
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    temp.push_back(a[k]);
                    temp.push_back(forth);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hset.insert(a[k]);
            }
        }
    }vector<vector<int> >ans(st.begin(),st.end());
    return ans;
}
vector<vector<int> > fourSumOptimal(vector<int>&a ,int target){
    vector<vector<int> > ans;
    int n  = a.size();
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i>0 && a[i] == a[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j!= (i+1) && a[j] == a[j-1]) continue;
            int s  = j+1;
            int e =  n-1;
            while(s<e){
                long long sum = a[i];
                sum += a[j];
                sum += a[s];
                sum += a[e];
                if(sum == target){
                    vector<int>temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    temp.push_back(a[s]);
                    temp.push_back(a[e]);
                    ans.push_back(temp);
                    s++;e--;
                    while(s<e && a[s] == a[s-1]) s++;
                    while(s<e && a[e] == a[e+1]) e--;
                }
                else if(sum  > target) e--;
                else s++;
            }
        }
    }
    return ans;
    
}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int> > ans = fourSumBrute(a , 5);
    if(ans.size() == 0) cout<<"[-1,-1]"<<endl;  
    for(auto it:ans){
        for(auto kt:it){
            cout<<kt<<" ";
        }cout<<endl;
    }
    vector<vector<int> > ans1 = fourSumBetter(a , 5);
    if(ans1.size() == 0) cout<<"[-1,-1]"<<endl;  
    for(auto it:ans1){
        for(auto kt:it){
            cout<<kt<<" ";
        }cout<<endl;
    }
    vector<vector<int> > ans2 = fourSumOptimal(a , 5);
    if(ans2.size() == 0) cout<<"[-1,-1]"<<endl;  
    for(auto it:ans2){
        for(auto kt:it){
            cout<<kt<<" ";
        }cout<<endl;
    }

}