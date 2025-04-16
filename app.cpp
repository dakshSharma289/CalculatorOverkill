#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

int ComputeResult(int num1, int num2, char op){
    if(op == '/'){
        return (num1 / num2);
    }else if(op == '*'){
        return (num1 * num2);
    }else if(op == '+'){
        return (num1 + num2);
    }else{
        return (num1 - num2);
    }
}

bool IsNumber(string candidate){
    try{
        for(int i = 0; i < candidate.length(); i++){
            string temp;
            temp += candidate[i];
            candidate[i] = stoi(temp);
            return true;
        }
    }catch(const invalid_argument & e){
        return false;
    }catch(const out_of_range & e){
        return false;
    }
}

pair <vector <int>, vector <char>> SortOperators (vector <int> listOfOperatorIndices, vector <char> listOfOperators){
    vector <int> sortedOperatorIndices;
    vector <char> sortedOperators;
    for(int i = 0; i < listOfOperatorIndices.size(); i++){
        for(int j = 0; j < listOfOperatorIndices.size(); j++){
            if(listOfOperators[j] == '/'){
                sortedOperatorIndices.push_back(j);
                sortedOperators.push_back(listOfOperators[j]);
            }
        }
        for(int j = 0; j < listOfOperatorIndices.size(); j++){
            if(listOfOperators[j] == '*'){
                sortedOperatorIndices.push_back(j);
                sortedOperators.push_back(listOfOperators[j]);
            }
        }
        for(int j = 0; j < listOfOperatorIndices.size(); j++){
            if(listOfOperators[j] == '+'){
                sortedOperatorIndices.push_back(j);
                sortedOperators.push_back(listOfOperators[j]);
            }
        }
        for(int j = 0; j < listOfOperatorIndices.size(); j++){
            if(listOfOperators[j] == '-'){
                sortedOperatorIndices.push_back(j);
                sortedOperators.push_back(listOfOperators[j]);
            }
        }
    }

    return make_pair(sortedOperatorIndices, sortedOperators);
}

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
    }
    return make_pair(listOfOperatorIndices, listOfOperators);
}

string AddTerminalBrackets(string input){
    input.push_back(')');
    input.insert(input.begin(), '(');
    return input;
}

string RemoveWhiteSpace(string input){
    for(int i = 0; i < input.length(); i++){
        for(int j = 0; j < input.length(); j++){
            if(input[j] == ' '){
                input.erase(j, 1);
                cout << endl << input << endl;
                break;
            }
        }
    }
    return input;
}

bool CheckBrackets(string input){
    int noOfBrackets = 0;
    for(int i = 0; i < input.length(); i++){
        if ((input[i] == '(') || (input[i] == ')')){
            noOfBrackets++;
        }
    }
    if(!(noOfBrackets % 2)){
        return true;
    }else{
        cout << "check the brackets in your input" << endl;
        return false;
    }
}

int main(){

    cout << "the program starts here: " << endl;

    while (1 > 0){
        string input;
        cout << "enter your input:" << endl;
        getline(cin, input);
        // input = "12    +   7";

        if (toupper(input[0]) == 'Q'){
            break;
        }else if (CheckBrackets(input)){
            input = RemoveWhiteSpace(input);
            cout << input;
            input = AddTerminalBrackets(input);
            while(!(IsNumber(input))){
                vector <int> bracketIndices = FetchBrackets(input).first;
                vector <bool> bracketTypes = FetchBrackets(input).second;
                const int iterations = bracketIndices.size();
                int extraIterations;

                for(int i = 0; i < iterations + extraIterations; i++){
                    if(bracketTypes[i] != bracketTypes[i+1]){
                        string currentExpression = input.substr(bracketIndices[i] + 1, bracketIndices[i + 1] - bracketIndices[i] - 1);
                        vector <int> operatorIndices = FetchOperators(currentExpression).first;
                        vector <char> operators = FetchOperators(currentExpression).second;
                        operatorIndices = SortOperators(operatorIndices, operators).first;
                        operators = SortOperators(operatorIndices, operators).second;
                        if(IsNumber(currentExpression)){
                            input.replace(input.begin() + bracketIndices[i], input.begin() + bracketIndices[i+1] + 1, currentExpression);
                            break;
                        }

                        for(int j = 0; j < operators.size(); j = j){
                            string firstOperand;
                            string secondOperand;
                            int currentResult = 0;
                            int counter1 = 1;
                            string temp1;
                            temp1 += currentExpression[operatorIndices[j] - counter1];
                            while((IsNumber(temp1))){
                                firstOperand.insert(0, 1, currentExpression[operatorIndices[j] - counter1]);
                                counter1++;
                            }
                            int counter2 = 1;
                            string temp2;
                            temp2 += currentExpression[operatorIndices[j] + counter2];
                            while((IsNumber(temp2))){
                                secondOperand.insert(secondOperand.end(), 1, currentExpression[operatorIndices[j] + counter2]);
                                counter2++;
                            }
                            int firstNum = stoi(firstOperand);
                            int secondNum = stoi(secondOperand);
                            currentResult = ComputeResult(firstNum, secondNum, operators[j]);
                            input.replace(input.begin() + bracketIndices[i] + 1 + operatorIndices[j] - counter1, input.begin() + bracketIndices[i] + 1 + operatorIndices[j] + counter2 - 1, to_string(currentResult));
                        }
                    }else{
                        extraIterations++;
                    }
                }
            }
            // cout << endl << input << endl;
        }
        cout << endl;
    }
    cout << endl << "program terminated successfully" << endl;
    return 0;
}