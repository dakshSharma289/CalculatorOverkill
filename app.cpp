#include<iostream>
#include<string>
#include<vector>

using namespace std;

pair <vector<int>, vector<bool>> FetchBrackets(string input){
        vector <int> listOfBracketIndices;
        vector <bool> listOfBracketTypes;

        for(int i = 0; i < input.length(); i++){
            if(input[i] == '('){
                listOfBracketIndices.push_back(i);
                listOfBracketTypes.push_back(true);
            }else if(input[i] == ')'){
                listOfBracketIndices.push_back(i);
                listOfBracketTypes.push_back(false);
            }else{
                continue;
            }
        }

        return make_pair(listOfBracketIndices, listOfBracketTypes);
}

pair <vector <int>, vector <char>> FetchOperators(string currentExpression){
    vector <int> listOfOperatorIndices;
    vector <char> listOfOperators;
    for(int j = 0 ; j < currentExpression.length(); j++){
        if(currentExpression[j] == '/'){
            listOfOperatorIndices.push_back(j);
            listOfOperators.push_back(currentExpression[j]);
        }else if(currentExpression[j] == '*'){
            listOfOperatorIndices.push_back(j);
            listOfOperators.push_back(currentExpression[j]);
        }else if(currentExpression[j] == '+'){
            listOfOperatorIndices.push_back(j);
            listOfOperators.push_back(currentExpression[j]);
        }else if(currentExpression[j] == '-'){
            listOfOperatorIndices.push_back(j);
            listOfOperators.push_back(currentExpression[j]);
        }else {
            continue;
        }

        return make_pair(listOfOperatorIndices, listOfOperators);
    }
}

string AddTerminalBrackets(string input){
    input.push_back(')');
    input.insert(input.begin(), '(');
    return input;
}

bool CheckBrackets(string input){
    int noOfBrackets = 0;
    for(int i = 0; i < input.length(); i++){
        if ((input[i] == '(') || (input[i] == ')')){
            noOfBrackets++;
        }
    }
    if(!(2 % noOfBrackets)){
        return true;
    }else{
        cout << "check the brackets in your input" << endl;
        return false;
    }
}

int main(){

    cout << "the program starts here: " << endl;

    string input;
    getline(cin, input);

    while (1>0){
        if (toupper(input[0]) == 'q'){
            break;
        }else if (CheckBrackets(input)){
            input = AddTerminalBrackets(input);
            vector <int> bracketIndices = FetchBrackets(input).first;
            vector <bool> bracketTypes = FetchBrackets(input).second;
            int extraIterations;

            for(int i = 0; i < bracketIndices.size() + extraIterations; i++){
                if(bracketTypes[i] != bracketTypes[i+1]){
                    string currentExpression = input.substr(bracketIndices[i] + 1, bracketIndices[i + 1] - bracketIndices[i] - 1);
                    vector <int> operatorIndices = FetchOperators(currentExpression).first;
                    vector <char> operators = FetchOperators(currentExpression).second;

                    
                }else{
                    extraIterations++;
                }
            }
        }
        cout << endl;
    }
    cout << endl << "program terminated successfully" << endl;
    return 0;
}