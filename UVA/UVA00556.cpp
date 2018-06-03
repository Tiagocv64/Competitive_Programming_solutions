#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

#define LOOP(i,l,r) for (int i = l; i < r; i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define TESTS(T) int T; cin >> T; while(T--)
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define REMVAL(t,v) t.erase(remove(t.begin(),t.end(), v), t.end())
#define REMPOS(t,i) t.erase(t.begin()+i)
#define REMDUP(t) t.erase(unique(t.begin(), t.end() ), t.end());
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define IOS ios_base::sync_with_stdio(false); //to desynchronize the input of cin and scanf
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
	int R, C;
	cin >> R >> C;
	while (R != 0 || C != 0){
		vvi maze;
		LOOP(i,0,R){
			vi column;
			char c;
			LOOP(j,0,C){
				cin >> c;
				if (c == '1')
					column.pb(-1);
				else 
					column.pb(0);				
			}
			maze.pb(column);
		}
		int finalY = R-1, finalX = 0, posY = R-1, posX = 0;
		char direction = 'E';
		bool checkEnd = false;
		while(true){
			//cout << "Y: " << posY << " X: " << posX << " DIC: " << direction << "\n";
			if (checkEnd && posY == finalY && posX == finalX)
				break;
			if (!checkEnd)
				if (posY != finalY || posX != finalX)
					checkEnd = true;

			bool right = true, front = true;
			if (direction == 'E'){
				if (posY+1 >= R || maze[posY+1][posX] == -1)
					right = false;
				if (posX+1 >= C || maze[posY][posX+1] == -1)
					front = false;

				if (front && !right){
					maze[posY][posX]++;
					posX++;
				} else if (right){
					maze[posY][posX]++;
					posY++;
					direction = 'S';
				} else if (!front && !right){
					direction = 'N';
				}
			} else if (direction == 'N'){
				if (posX+1 >= C || maze[posY][posX+1] == -1)
					right = false;
				if (posY-1 < 0 || maze[posY-1][posX] == -1)
					front = false;

				if (front && !right){
					maze[posY][posX]++;
					posY--;
				} else if (right){
					maze[posY][posX]++;
					posX++;
					direction = 'E';
				} else if (!front && !right){
					direction = 'W';
				}
			} else if (direction == 'W'){
				if (posY-1 < 0 || maze[posY-1][posX] == -1)
					right = false;
				if (posX-1 < 0 || maze[posY][posX-1] == -1)
					front = false;

				if (front && !right){
					maze[posY][posX]++;
					posX--;
				} else if (right){
					maze[posY][posX]++;
					posY--;
					direction = 'N';
				} else if (!front && !right){
					direction = 'S';
				}
			} else if (direction == 'S'){
				if (posX-1 < 0 || maze[posY][posX-1] == -1)
					right = false;
				if (posY+1 >= R || maze[posY+1][posX] == -1)
					front = false;

				if (front && !right){
					maze[posY][posX]++;
					posY++;
				} else if (right){
					maze[posY][posX]++;
					posX--;
					direction = 'W';
				} else if (!front && !right){
					direction = 'E';
				}
			}
		}

		int count[5] = {0,0,0,0,0};
		LOOP(i,0,R)
			LOOP(j,0,C)
				if (maze[i][j] > -1 && maze[i][j] < 5)
					count[maze[i][j]]++;				

		LOOP(i, 0, 5)
			cout << setw(3) << count[i];
		cout << "\n";
		cin >> R >> C;
	}
}
