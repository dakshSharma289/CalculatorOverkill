#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    cout << "Wellcome to my Overkill Calculator App" << endl << "To exit the program, type 'q' in a new line and press enter" << endl << "You can enter your problem bellow:" << endl;
    while(0 < 1){
        string input;
        getline(cin, input);

        if((input == "q") || (input == "Q")){
            break;
        }
//here I'm iterating through the input to figure out where and how many brackets are pestent.
        vector <int> bracketIndices;
        vector <bool> bracketType;
        for(int i = 0; i < input.length(); i++){
            if(input[i] == '('){
                bracketIndices.push_back(i);
                bracketType.push_back(true);
            }else if(input[i] == ')'){
                bracketIndices.push_back(i);
                bracketType.push_back(false);
            }
        }
    }
    cout<<endl<< "program exited successfully.";

    return 0;
}
