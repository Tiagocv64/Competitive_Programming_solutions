#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <bitset>

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

int times[101][10];
bool solved[101][10], played[101];

struct Player{
  int player;
  int solved;
  int time;
  bool operator<(const Player& rPlayer){
    if (solved != rPlayer.solved){
      return solved > rPlayer.solved;
    } else if (time != rPlayer.time){
      return time < rPlayer.time;
    } else {
      return player < rPlayer.player;
    }
  }
};

int main(){
  int T;
  cin >> T;
  cin.ignore();
  cin.ignore();
  while (T-- > 0){
    LOOP(i,0,101){
      LOOP(j,0,10){
        times[i][j] = 0;
        solved[i][j] = false;
      }
      played[i] = false;
    }

    string line;
    int player, problem, t;
    char status;
    while (getline(cin, line) && line != ""){
      stringstream ss(line);
      ss >> player >> problem >> t >> status;
      played[player] = true;
      if (status == 'C'){
        if (!solved[player][problem]){
          times[player][problem] += t;
          solved[player][problem] = true;
        }
      } else if (status == 'I'){
        if (!solved[player][problem]){
          times[player][problem] += 20;
        }
      }
    }
    vector<Player> scoreboard;
    LOOP(i,0,101){
      if (played[i]){
        int nSolve = 0, pTime = 0;
        LOOP(j,0,10){
          if (solved[i][j]){
            pTime += times[i][j];
            nSolve += 1;
          }
        }
        Player player1;
        player1.player = i;
        player1.time = pTime;
        player1.solved = nSolve;
        scoreboard.pb(player1);
      }
    }
    sort(ALL(scoreboard));
    LOOP(i,0,scoreboard.size())
      cout << scoreboard.at(i).player << " " << scoreboard.at(i).solved << " " << scoreboard.at(i).time << "\n";
    if (T > 0)
      cout << "\n";
  }
}
