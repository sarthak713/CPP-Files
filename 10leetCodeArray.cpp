#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void reverseArray(int arr[],int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }
}
void swapAlternate(int arr[],int n){
    for(int i=0;i<n-1;i+=2){
        swap(arr[i],arr[i+1]);
    }
}

int main(){
    
    // int arr[]={1,2,3,4,5,6,7};
    // int n=7;
    // printArray(arr,n);

// reverse array
    // reverseArray(arr,n);

// swap alternate
    // swapAlternate(arr,n);

// find unique
    // int arr[]={1,1,3,4,5,4,5,6,6,10,3}; 
    // int n=11;
    // int ans=0;
    // for(int i=0;i<n;i++)
    //     ans=ans^arr[i]; 
    // cout<<ans<<endl;

// unique no. of occurences
    // int arr[]={1,2,2,1,1,3};
    // int n=6;
    // vector<int> ans;
    // int size = arr.size();
    // int i = 0;
    // sort(arr.begin(),arr.end());
    // while(i<size){
    //     int count = 1;
    //     for(int j =i+1;j<size;j++){
    //         if(arr[i]==arr[j]){
    //             count++;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     ans.push_back(count);
    //     i = i+count;
    // }
    // size = ans.size();
    // sort(ans.begin(),ans.end());
    // for(int i = 0;i<size-1;i++){
    //     if(ans[i]==ans[i+1]){
    //         return false;
    //     }
    // }
    // return true;

// find duplicate = elements are less than n
    // int arr[]={1,2,3,4,5,1};
    // int n=6;
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     ans=ans^arr[i];
    // }
    // for(int i=1;i<n;i++){
    //     ans=ans^i;
    // }
    // cout<<ans<<endl;

// find all duplicates in array
    // int arr[]={1,1,2};    // 1<=nums<=n
    // int n=3;
    // vector<int> result;
    // for(int i=0;i<n;i++){
    //     int m=abs(arr[i]);
    //     if(arr[m-1]>0){
    //         arr[m-1]*=-1;
    //     }else{
    //         result.push_back(m);
    //     }
    // }
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<" ";
    // }cout<<endl;

// array intersection
        // Brute Force
    // int arr1[]={1,2,3,4,5};int n=5;
    // int arr2[]={2,2,4,5};int m=4;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr1[i]==arr2[j]){
    //             cout<<arr1[i]<<" ";
    //             arr2[j]=-1;
    //             break;
    //         }
    //     }
    // }cout<<endl;
        // Optimised
    // int arr1[]={1,2,3,4,5,5};int n=6;
    // int arr2[]={2,2,4,5};int m=4;
    // int i=0;int j=0;
    // while(i<n && j<m){
    //     if(arr1[i]==arr2[j]){
    //         cout<<arr1[i]<<" ";
    //         i++;
    //         j++;
    //     }else if(arr1[i]>arr2[j]){
    //         j++;
    //     }else{
    //         i++;
    //     }
    // }cout<<endl;

// pair sum
    // int arr[]={2,-3,3,3,-2};
    // int n=5;int s=0;
    // vector<vector<int>>ans;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]+arr[j]==s){
    //             vector<int>temp;
    //             temp.push_back(min(arr[i],arr[j]));
    //             temp.push_back(max(arr[i],arr[j]));
    //             ans.push_back(temp);
    //         }
    //     }   
    // }
    // sort(ans.begin(),ans.end());
    // int size=ans.size();
    // for(int i=0;i<size;i++){
    //     for(int j=0;j<size;j++){
    //         cout<<ans[i][j]<<" ";
    //     }cout<<endl;
    // }

// triplet sum
        // brute force
    // int arr[]={1,2,3,1,2,3};
    // int n=6;
    // int s=6;
    // bool flag;
    // for(int i=0;i<n;i++){
    //     flag=false;
    //     for(int j=i+1;j<n;j++){
    //         for(int k=j+1;k<n;k++){
    //             if(arr[i]+arr[j]+arr[k]==s){
    //                 cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
    //                 flag=true;
    //             }
    //             if(flag) break;
    //         }
    //         if(flag) break;
    //     }
    //     if(flag) break;
    // }
    // if(!flag){
    //     cout<<-1<<endl;
    // }
        // optimised
    // int arr[]={1,2,3,1,2,3};
    // int n=6;
    // int s=6;
    // int arr[]={1,1,2,2,1,1};
    // int n=6;
    // int s=4;
    // bool flag=false;
    // int l,r;
    // sort(arr,arr+n);
    // for(int i=0;i<n-2;i++){
    //     l=i+1;
    //     r=n-1;
    //     while(l<r){
    //         if(arr[i]+arr[l]+arr[r]==s){
    //             cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
    //             flag=true;
    //             break;
    //         }
    //         else if(arr[i]+arr[l]+arr[r]<s){
    //             l++;
    //         }
    //         else{
    //             r--;
    //         }
    //     }
    // }
    // if(!flag){
    //     cout<<-1<<endl;
    // }



// sort 0's & 1's
    // int arr[]={0,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0};
    // int n=16;
    // int l=0;int r=n-1;
    // while(l<r){
    //     if(arr[l]==0){
    //         l++;
    //     }
    //     else if(arr[r]==1){
    //         r--;
    //     }
    //     else{
    //         swap(arr[l],arr[r]);
    //         l++;
    //         r--;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

// sort 0 1 2
    // int arr[]={1,2,0,1,2,1,0};
    // int n=7;
    // int low=0;
    // int mid=0;
    // int high=n-1;
    // while(mid<=high){
    //     if(arr[mid]==0){
    //         swap(arr[low],arr[mid]);
    //         low++;
    //         mid++;
    //     }
    //     else if(arr[mid]==1){
    //         mid++;
    //     }
    //     else{
    //         swap(arr[mid],arr[high]);
    //         high--;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }



    
    return 0;
}