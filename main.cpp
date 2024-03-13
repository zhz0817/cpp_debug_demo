#include "bits/stdc++.h"
using namespace std;
int sum(int *p,int length){
    int ans = 0;
    for(int i=0;i<length;i++){
        ans+=*(p+i);
    }
    return ans;
}
int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i] = i+1;
    }
    int ans = sum(arr,sizeof(arr)/sizeof(int));
    cout<<ans<<endl;
    return 0;
}