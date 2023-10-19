#include<iostream>
using namespace std;
vector<int> mergeTwoSortedBrute(vector<int>&a1,vector<int>&a2,int n,int m){
    vector<int>arr(n+m);
    int k = 0;
    int i=0,j=0;
    while(i<n && j<m){
        if(a1[i]<a2[j]) arr[k++] = a1[i++]; 
        else arr[k++] = a2[j++];
    }
    while(i<n) arr[k++] = a1[i++];
    while(j<m) arr[k++] = a2[j++];
    return arr;
}
void mergeTwoSortedArrWithoutSpace(vector<int>&a1,vector<int>&a2,int n,int m){
    int len = n+m;
    int gap = (len/2 )+ (len%2);
    
    while(gap > 0){
        int i=0;
        int j=i + gap;
        while(j<len){
            if(i<n && j>= n){
                if(a1[i] > a2[j-n]) swap(a1[i]  , a2[j-n]);
            }
            else if(i>=n){
                if(a2[i-n] > a2[j-n]) swap(a2[i-n]  , a2[j-n]);
            }else{
                if(a1[i] > a1[j]) swap(a1[i]  , a1[j]);
            }
            i++;j++;
        }
        if(gap == 1)break;
        gap = (gap/2) + (gap%2);
    }

}
int main(){
    int n ,m;cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];

    mergeTwoSortedArrWithoutSpace(a,b , n , m);

    for(int i=0;i<n;i++)cout<<a[i] <<" ";
    for(int i=0;i<m;i++)cout<<b[i] <<" ";
    cout<<endl;

    vector<int> arr = mergeTwoSortedBrute(a,b,n,m);
    for(int i=0;i<arr.size();i++)cout<<arr[i] <<" ";
    cout<<endl;

}
