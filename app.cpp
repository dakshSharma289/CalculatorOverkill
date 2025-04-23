#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>

using namespace std;

int EvaluateCurrentExpression(string currentExpression){
    pair <vector<int>, vector<char>> operatorsPackage = FetchOperators(currentExpression);
    operatorsPackage = SortOperators(operatorsPackage);
    vector <int> operatorIndices = operatorsPackage.first;
    vector <char> operators = operatorsPackage.second;
    int iterations = operatorIndices.size();
    for(int i = 0; i < iterations; i++){
        pair <vector<int>, vector<char>> operatorsPackage = FetchOperators(currentExpression);
        operatorsPackage = SortOperators(operatorsPackage);
        vector <int> operatorIndices = operatorsPackage.first;
        vector <char> operators = operatorsPackage.second;
        bool paranthesis = false;
        string firstOperand;
        string secondOperand;
        int currentResult = 0;
        int counter1 = 1;
        int counter2 = 1;
        string temp1;
        string temp2;
        temp2 += currentExpression[operatorIndices[i] + counter2];
        temp1 += currentExpression[operatorIndices[i] - counter1];
        if(temp1 == ")"){
            paranthesis = true;
            int end_pos;
            int start_pos = operatorIndices[i] - counter1;
            int outerMostBracket = 0;
            int counter11 = 0;
            int counter12 = 0;
            while(paranthesis){
                if(currentExpression[operatorIndices[i] - counter1 - counter12] == ')'){
                    counter11++;
                    continue;
                }else if((currentExpression[operatorIndices[i] - counter1 - counter12] == '(') && !counter11){
                    end_pos = operatorIndices[i] - counter1 - counter12;
                    paranthesis = false;
                    continue;
                }else if(currentExpression[operatorIndices[i] - counter1 - counter12] == '('){
                    counter11--;
                    continue;
                }else{
                    continue;
                }
            currentExpression.replace(start_pos, end_pos, to_string(EvaluateCurrentExpression(currentExpression.substr(end_pos, start_pos - end_pos - 1))));
            }
        }else if(temp2 == "("){
            paranthesis = true;
            int end_pos;
            int start_pos = operatorIndices[i] + counter2;
            int NotOuterMostBracket = 0;
            int counter21 = 0;
            int counter22 = 0;
            while(paranthesis){
                if(currentExpression[operatorIndices[i] + counter2 + counter22] == '('){
                    NotOuterMostBracket++;
                    continue;
                }else if((currentExpression[operatorIndices[i] + counter2 + counter22] == ')') && !NotOuterMostBracket){
                    end_pos = operatorIndices[i] + counter2 +counter22;
                    paranthesis = false;
                    continue;
                }else if(currentExpression[operatorIndices[i] + counter2 - counter22] == ')'){
                    NotOuterMostBracket--;
                    continue;
                }else{
                    continue;
                }
            currentExpression.replace(start_pos, end_pos, to_string(EvaluateCurrentExpression(currentExpression.substr(start_pos, end_pos - start_pos - 1))));
            }
        }
        while((IsNumber(temp1))){
            firstOperand.insert(0, 1, currentExpression[operatorIndices[i] - counter1]); 
            counter2++;
        }
        while((IsNumber(temp2))){
            secondOperand.insert(secondOperand.end(), 1, currentExpression[operatorIndices[i] + counter2]);
            counter2++;
        }
        currentResult = ComputeResult(stoi(firstOperand), stoi(secondOperand), operators[i]);
        currentExpression.replace(operatorIndices[i] - counter1, operatorIndices[i] + counter2, to_string(currentResult));
    }
}

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

pair <vector <int>, vector <char>> SortOperators(pair<vector<int>, vector <char>> operators){
    vector <int> operatorPositions;
    vector <char> operatorTypes;
    for(int i = 0; i < operators.first.size(); i++){
        for(int j = 0; j < operators.first.size(); j++){
            if(operators.first[j] == '/'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }else if(operators.first[j] == '*'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }
        }
        for(int j = 0; j < operators.first.size(); j++){
            if(operators.first[j] == '+'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }else if(operators.first[j] == '-'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }
        }
    }
    return make_pair(operatorPositions, operatorTypes);
}

pair <vector<int>, vector<char>> FetchOperators(string currentExpression){
    bool paranthesis = false;
    int counter = -1;
    vector <int> operatorIndices;
    vector <char> operators;
    for(int i = 0; i < currentExpression.length(); i++){
        if(currentExpression[i] == '('){
            counter++;
            paranthesis = true;
            continue;
        }else if((currentExpression[i] == ')') && !counter){
            paranthesis = false;
            counter = -1;
        }else if(currentExpression[i] == ')'){
            counter--;
            continue;
        }else if(!paranthesis){
            if(currentExpression[i] == '/'){
                operatorIndices.push_back(i);
                operators.push_back(currentExpression[i]);
            }else if(currentExpression[i] == '*'){
                operatorIndices.push_back(i);
                operators.push_back(currentExpression[i]);
            }else if(currentExpression[i] == '+'){
                operatorIndices.push_back(i);
                operators.push_back(currentExpression[i]);
            }else if(currentExpression[i] == '-'){
                operatorIndices.push_back(i);
                operators.push_back(currentExpression[i]);
            }
        }
    }
    return make_pair(operatorIndices, operators);
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

string AddTerminalBrackets(string input){
    input.push_back(')');
    input.insert(input.begin(), '(');
    return input;
}

string RemoveWhiteSpace(string input){
    const int len = input.length();
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(input[j] == ' '){
                input.erase(j, 1);
                break;
            }
        }
    }
    return input;
}

int main(){
    cout << "The Program starts here" << endl;
    while(0 < 1){
        string input;
        cout << "enter your input:" << endl;
        getline(cin, input);

        if(toupper(input[0]) == 'Q'){
            break;
            }else if(CheckBrackets(input)){
                input = RemoveWhiteSpace(input);
                input = AddTerminalBrackets(input);
                while(!IsNumber(input)){
                    int Result = EvaluateCurrentExpression(input);
                }
            }
        }
        return 0;
    }
