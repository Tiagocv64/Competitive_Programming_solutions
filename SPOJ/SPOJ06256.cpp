#include <iostream>
#include <algorithm>

using namespace std;

long long inversions = 0;

int arrInv[200001];

void mergeArray(int arr[], int b, int m, int e){
    int l1 = m-b+1 , l2 = e-m;
    int L[l1], R[l2];
    int i= 0, j= 0, x=b;
    //copy(L, L+l1, arr+b);
    //copy(R, R+l2, arr+m+1);
    for (int z = 0 ; z < l1 ; z++){
        L[z] = arr[z+b];
    }
    for (int z = 0 ; z < l2 ; z++){
        R[z] = arr[z+m+1];
    }

    while (i < l1 && j < l2){
        if(L[i] > R[j]){
            arr[x] = R[j];
            j++;
            inversions+= l1 -i;
        } else {
            arr[x] = L[i];
            i++;
        }
        x++;
    }
    while (i < l1){
        arr[x] = L[i];
        i++; x++;
    }
    while (j < l2){
        arr[x] = R[j];
        j++; x++;
    }

}

void mergeSort(int arr[] , int b, int e){
    if (b < e){
        int mid = b+(e-b)/2;
        mergeSort(arr, b, mid);
        mergeSort(arr, mid+1, e);

        mergeArray(arr, b, mid, e);
    }
}

int main(){
    int q, n;
    cin >> q;
    while (q > 0){
        cin >> n;
        inversions = 0;
        for (int i = 0; i < n ; i++){
            cin >> arrInv[i];
        }
        mergeSort(arrInv, 0, n-1);
        cout << inversions << endl;
        q--;
    }
}
