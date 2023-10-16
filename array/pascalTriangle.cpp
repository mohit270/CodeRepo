#include<iostream>
using namespace std;
// find the element at that place r = x , c = y time complexity 0(n) and space complexity  0(1)
int nCr(int n , int r){  
    long long ans = 1;
    for(int i=0;i<r;i++){
        ans = ans * (n-i);
        ans = ans/(i+1);
    }return ans;
}
// print nth row of pascal triangle time complexity 0(n^2) and space complexity  0(n)
vector<int> printNthRowBrute(int n){ 
    vector<int>ans;
    for(int c=1;c<=n;c++){
        ans.push_back(nCr(n-1,c-1));
    }return ans;
}
// print nth row of pascal triangle time complexity 0(n) and space complexity  0(n)
vector<int> printNthRowOptimal(int n){
    vector<int>ans;
    ans.push_back(1);
    int as =1;
    for(int c=1;c<n;c++){
        as = as*(n-c);
        as = as/c;
        ans.push_back(as);
    }return ans;
}
// print pascal triangle time complexity 0(n^3) and space complexity  0(n^2)
vector<vector<int> > printPascalTriangleBrute(int n){
    vector<vector<int> > ans;
    for(int r=1;r<=n;r++){
        vector<int> temp;
        for(int c=1;c<n;c++){
            temp.push_back(nCr(r-1,c-1));
        }ans.push_back(temp);
    }return ans;
}
// print pascal triangle time complexity 0(n^2) and space complexity  0(n^2)
vector<vector<int> > printPascalTriangleOptimal(int n){
    vector<vector<int> > ans;
    for(int r=1;r<=n;r++){
        ans.push_back(printNthRowOptimal(r));
    }return ans;
}
int main(){
    int r;cin>>r;
    int c;cin>>c;
    int ncr = nCr(r-1,c-1);
    cout<<ncr<<endl;

    int n;cin>>n;

    vector<int>printNthRowOfPascalTriangle1 = printNthRowBrute(n);
    for(int i=0;i<printNthRowOfPascalTriangle1.size();i++) cout<<printNthRowOfPascalTriangle1[i]<<" ";
    cout<<endl;

    vector<int>printNthRowOfPascalTriangle2 = printNthRowOptimal(n);
    for(int i=0;i<printNthRowOfPascalTriangle2.size();i++) cout<<printNthRowOfPascalTriangle2[i]<<" ";
    cout<<endl;

    vector<vector<int> > printPascalTriangleBrute1 = printPascalTriangleBrute(n);
    for(int i=0;i<printPascalTriangleBrute1.size();i++) {
        for(int j=0;j<printPascalTriangleBrute1.size();j++) {
            cout<<printPascalTriangleBrute1[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;

    vector<vector<int> > printPascalTriangleBrute2 = printPascalTriangleOptimal(n);
    for(int i=0;i<printPascalTriangleBrute2.size();i++) {
        for(int j=0;j<printPascalTriangleBrute2.size();j++) {
            cout<<printPascalTriangleBrute2[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}