#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <sstream>

using namespace std;

#define LOOP(i,l,r) for (int i = l; l < r; i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define IOS ios_base::sync_with_stdio(false); //to synchronize the input of cin and scanf
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
//for vectors
#define pb push_back
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

int main(){
	int test = 1;
	string p1, p2, child;
	while(true){
		cin >> p1 >> p2 >> child;
		if (p1 == "E" && p2 == "N" && child == "D")
			break;
		cout << "Case " << test << ": ";
		if (p1 == "?"){
			bool pos2 = false, posC = false;
			int sinalAns = 2; //0 neg 1 pos 2 both
			if (p2.at(p2.size()-1) == '+')
				pos2 = true;
			if (child.at(child.size()-1) == '+')
				posC = true;
			if (posC && !pos2)
				sinalAns = 1;

			if (p2.size() == 3){ // AB
				if (child.size() == 3){ // AB
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-, B+, B-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+, B+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-, B-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-, B-, O-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'B') {
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-, B-, O-} " << p2 << " " << child << "\n";
					}
				} else {
					cout << "IMPOSSIBLE " << p2 << " " << child << "\n";
				}
			} else if (p2.at(0) == 'A'){ // A
				if (child.size() == 3){ // AB
					if (sinalAns == 2){
						cout << "{AB+, AB-, B+, B-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, B+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, B-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-, B-, O-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << "{AB+, AB-, B+, B-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, B+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, B-} " << p2 << " " << child << "\n";
					}
				} else {
					if (sinalAns == 2){
						cout << "{A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{A-, B-, O-} " << p2 << " " << child << "\n";
					}				}
			} else if (p2.at(0) == 'B') {
				if (child.size() == 3){ // AB
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'B'){ // B
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-, B-, O-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-} " << p2 << " " << child << "\n";
					}
				} else {
					if (sinalAns == 2){
						cout << "{A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{A-, B-, O-} " << p2 << " " << child << "\n";
					}				}
			} else {
				if (child.size() == 3){ // AB
					cout << "IMPOSSIBLE " << p2 << " " << child << "\n";
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << "{AB+, AB-, A+, A-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, A+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, A-} " << p2 << " " << child << "\n";
					}
				} else if (child.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << "{AB+, AB-, B+, B-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{AB+, B+} " << p2 << " " << child << "\n";
					} else {
						cout << "{AB-, B-} " << p2 << " " << child << "\n";
					}
				} else {
					if (sinalAns == 2){
						cout << "{A+, A-, B+, B-, O+, O-} " << p2 << " " << child << "\n";
					} else if (sinalAns == 1){
						cout << "{A+, B+, O+} " << p2 << " " << child << "\n";
					} else {
						cout << "{A-, B-, O-} " << p2 << " " << child << "\n";
					}
				}
			}
		} else if (p2 == "?") {
			bool pos1 = false, posC = false;
			int sinalAns = 2; //0 neg 1 pos 2 both
			if (p1.at(p1.size()-1) == '+')
				pos1 = true;
			if (child.at(child.size()-1) == '+')
				posC = true;
			if (posC && !pos1)
				sinalAns = 1;

			if (p1.size() == 3){ // AB
				if (child.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 << " {AB+, AB-, A+, A-, B+, B-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 << " {AB+, A+, B+} " << child << "\n";
					} else {
						cout << p1 << " {AB-, A-, B-} " << child << "\n";
					}
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, A+, A-, B+, B-, O+, O-} "  << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, A+, B+, O+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, A-, B-, O-} " << child << "\n";
					}
				} else if (child.at(0) == 'B') {
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, A+, A-, B+, B-, O+, O-} "  << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, A+, B+, O+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, A-, B-, O-} " << child << "\n";
					}
				} else {
					cout << p1 <<" IMPOSSIBLE " << child << "\n";
				}
			} else if (p1.at(0) == 'A'){ // A
				if (child.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, B+, B-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, B+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, B-} " << child << "\n";
					}
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, A+, A-, B+, B- O+, O-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, A+, B+, O+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, A-, B-, O-} " << child << "\n";
					}
				} else if (child.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, B+, B-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, B+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, B-} " << child << "\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 <<" {B+, B-, A+, A-, O+, O-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {B+, A+, O+} " << child << "\n";
					} else {
						cout << p1 <<" {B-, A-, O-} " << child << "\n";
					}				}
			} else if (p1.at(0) == 'B') {
				if (child.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, A+, A-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, A+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, A-} " << child << "\n";
					}
				} else if (child.at(0) == 'B'){ // B
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, B+, B-, A+, A-, O+, O-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, B+, A+, O+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, B-, A-, O-} " << child << "\n";
					}
				} else if (child.at(0) == 'A'){ // B
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, A+, A-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, A+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, A-} " << child << "\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 <<" {B+, B-, A+, A-, O+, O-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {B+, A+, O+} " << child << "\n";
					} else {
						cout << p1 <<" {B-, A-, O-} " << child << "\n";
					}				}
			} else {
				if (child.size() == 3){ // AB
					cout << p1 <<" IMPOSSIBLE " << child << "\n";
				} else if (child.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, A+, A-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, A+} " << child << "\n";
					} else {
						cout << p1 <<" {AB-, A-} " << child << "\n";
					}
				} else if (child.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << p1 <<" {AB+, AB-, B+, B-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {AB+, B+} "  << child << "\n";
					} else {
						cout << p1 <<" {AB-, B-} "  << child << "\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 <<" {O+, O-, A+, A-, B+, B-} " << child << "\n";
					} else if (sinalAns == 1){
						cout << p1 <<" {O+, A+, B+} " << child << "\n";
					} else {
						cout << p1 <<" {O-, A-, B-} " << child << "\n";
					}
				}
			}
		} else {
			bool pos1 = false, pos2 = false;
			int sinalAns = 2; //0 neg 1 pos 2 both
			if (p1.at(p1.size()-1) == '+')
				pos1 = true;
			if (p2.at(p2.size()-1) == '+')
				pos2 = true;
			if (!pos2 && !pos1)
				sinalAns = 0;

			if (p1.size() == 3){ // AB
				if (p2.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-}\n";
					}
				} else if (p2.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-}\n";
					}
				} else if (p2.at(0) == 'B') {
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-}\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {A-, B-}\n";
					}
				}
			} else if (p1.at(0) == 'A'){ // A
				if (p2.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-}\n";
					}
				} else if (p2.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {A+, A-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {A+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {A-, O-}\n";
					}
				} else if (p2.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-, O-}\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {A+, A-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {A+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {A-, O-}\n";
					}				}
			} else if (p1.at(0) == 'B') {
				if (p2.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-}\n";
					}
				} else if (p2.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {B+, B-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {B+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {B-, O-}\n";
					}
				} else if (p2.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {AB+, AB-, A+, A-, B+, B-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {AB+, A+, B+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {AB-, A-, B-, O-}\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {B+, B-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {B+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {B-, O-}\n";
					}
				}
			} else {
				if (p2.size() == 3){ // AB
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {A+, A-, B+, B-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {A+, B+}\n";
					} else {
						cout << p1 << " " << p2 << " {A-, B-}\n";
					}
				} else if (p2.at(0) == 'A'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {A+, A-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {A+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {A-, O-}\n";
					}
				} else if (p2.at(0) == 'B'){ // A
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {B+, B-, O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " {B+, O+}\n";
					} else {
						cout << p1 << " " << p2 << " {B-, O-}\n";
					}
				} else {
					if (sinalAns == 2){
						cout << p1 << " " << p2 << " {O+, O-}\n";
					} else if (sinalAns == 1){
						cout << p1 << " " << p2 << " O+\n";
					} else {
						cout << p1 << " " << p2 << " O-\n";
					}
				}
			}
		}
		test++;
	}
}