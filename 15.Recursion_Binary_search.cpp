#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int>& a,int& s,int& e,int& key){
    int mid=s+(e-s)/2;
    if(a[mid]==key){
        return 1;
    }
    else if(a[mid]>key){
        e=mid-1;
        return BinarySearch(a,s,e,key);
    }
    else{
        s=mid+1;
        return BinarySearch(a,s,e,key);
    }
}
int main(){
    vector<int> v{10,20,30,40,60,70};
    int i=0;
    int key=60;
    int size=v.size();
    cout<<BinarySearch(v,i,size,key);
    
    return 0;
}