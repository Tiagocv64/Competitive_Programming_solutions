#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(int distance, int cows, vector<int> &v){
    int last = v.at(0);
    int done = 1;
    for (int i = 1 ; i < v.size() && done < cows ; i++){
        if (v.at(i) - last >= distance){
            last = v.at(i);
            done++;
        }
    }
    if (done == cows){
        return true;
    } else {
        return false;
    }
}

int main(){
    int q;
    cin >> q;
    while (q > 0){

        int barns , cows;
        cin >> barns >> cows;
        vector<int> places;
        places.reserve(barns);
        int current;
        for (int i = 0 ; i < barns ; i++){
            cin >> current;
            places.push_back(current);
        }
        sort(places.begin(), places.begin()+barns);

        int hi = 1000000000 , lo = 1;

        while (lo < hi){
            int mid = (lo+hi+1) / 2;
            if (possible(mid, cows, places)){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        cout << hi << endl;
        q--;
    }

}
