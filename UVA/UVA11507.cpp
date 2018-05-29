#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string move, posicao = "+x";
	cin >> n;
	while (n != 0){
		posicao = "+x";

		while(n-- > 1){
			cin >> move;
			if (move == "No")
				continue;
			if(posicao == "+x"){ //+x
				posicao = move;
			} else if (posicao == "-x"){ //-x
				if (move.at(0) == '+'){
					posicao = "-";
				} else {
					posicao = "+";
				}
				posicao += move.at(1);
			} else if (posicao == "+z"){
				if (move == "+z"){
					posicao = "-x";
				} else if (move == "-z"){
					posicao = "+x";
				}
			} else if (posicao == "-z"){
				if (move == "-z"){
					posicao = "-x";
				} else if (move == "+z"){
					posicao = "+x";
				}
			} else if (posicao == "+y"){
				if (move == "+y"){
					posicao = "-x";
				} else if (move == "-y"){
					posicao = "+x";
				}
			} else if (posicao == "-y"){
				if (move == "-y"){
					posicao = "-x";
				} else if (move == "+y"){
					posicao = "+x";
				}
			}
		}
		cout << posicao << endl;
		cin >> n;
	}


}