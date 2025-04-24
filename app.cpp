#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>

using namespace std;

pair <vector <int>, vector <bool>> FetchBrackets(string input){
    vector <int> bracketPositions;
    vector <bool> brackets;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            bracketPositions.push_back(i);
            brackets.push_back(true);
        }else if(input[i] == ')'){
            bracketPositions.push_back(i);
            brackets.push_back(false);
        }else{
            continue;
        }
    }
    return make_pair(bracketPositions, brackets);
}

int ComputeResult(int num1, int num2, char op){
    if(op == '/'){
        return (num1 / num2);
    }else if(op == 'x'){
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
            if(operators.second[j] == '/'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }else if(operators.second[j] == 'x'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }
        }
        for(int j = 0; j < operators.first.size(); j++){
            if(operators.second[j] == '+'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }else if(operators.second[j] == '-'){
                operatorPositions.push_back(operators.first[j]);
                operatorTypes.push_back(operators.second[j]);
            }
        }
    }
    return make_pair(operatorPositions, operatorTypes);
}

pair <vector<int>, vector<char>> FetchOperators(string currentExpression){
    vector <int> operatorIndices;
    vector <char> operators;
    for(int i = 0; i < currentExpression.length(); i++){
        if(currentExpression[i] == '/'){
            operatorIndices.push_back(i);
            operators.push_back('/');
        }else if(currentExpression[i] == 'x'){
            operatorIndices.push_back(i);
            operators.push_back('x');
        }else if(currentExpression[i] == '+'){
            operatorIndices.push_back(i);
            operators.push_back('+');
        }else if(currentExpression[i] == '-'){
            operatorIndices.push_back(i);
            operators.push_back('-');
        }else{
            continue;
        }
    }
    return make_pair(operatorIndices, operators);
}

bool IsNumber(string candidate){
    try{
        for(int i = 0; i < candidate.length(); i++){
            if(!candidate[i]){
                return false;
            }
            string temp;
            temp += candidate[i];
            candidate[i] = stoi(temp);
        }
        return true;
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

string ReduceToSimpler(string expression){
    pair <vector <int>, vector <char>> operatorPackage = FetchOperators(expression);
    operatorPackage = SortOperators(operatorPackage);
    vector <int> operatorPositions = operatorPackage.first;
    vector <char> operators = operatorPackage.second;
    string firstOperand;
    string secondOperand;
    int firstOperandPosition;
    int secondOperandPosition;
    int currentResult;
    int counter1 = 1;
    int counter2 = 1;

    string temp1 = {expression[operatorPositions[0] - counter1]};
    string temp2 = {expression[operatorPositions[0] + counter2]};

    while(IsNumber(temp1)){
        firstOperand.insert(firstOperand.begin(), expression[operatorPositions[0] - counter1]);
        firstOperandPosition = operatorPositions[0] - counter1;
        if(firstOperandPosition == 0){
            break;
        }else{
            counter1++;
            temp1 = {expression[operatorPositions[0] - counter1]};
        }
    }
    while(IsNumber(temp2)){
        secondOperand.push_back(expression[operatorPositions[0] + counter2]);
        secondOperandPosition = operatorPositions[0] + counter2;
        if(secondOperandPosition == expression.length() - 1){
            break;
        }else{
            counter2++;
            temp2 = {expression[operatorPositions[0] + counter2]};
        }
    }
    currentResult = ComputeResult(stoi(firstOperand), stoi(secondOperand), operators[0]);
    expression = expression.replace(firstOperandPosition, secondOperandPosition + 1, to_string(currentResult));
    return expression;
}

string EvaluateCurrentExpression(string currentExpression){
    while(!IsNumber(currentExpression)){
        currentExpression = ReduceToSimpler(currentExpression);
    }
    return currentExpression;
}

string ManageBrackets(string input){
    pair <vector <int>, vector <bool>> bracketsPackage = FetchBrackets(input);
    vector <int> bracketPositions = bracketsPackage.first;
    vector <bool> brackets = bracketsPackage.second;
    if(!brackets.size()){
        input = EvaluateCurrentExpression(input);
    }
    for(int i = 0; i < brackets.size(); i++){
        if(brackets[i] != brackets[i+1]){
            input = input.replace(bracketPositions[i], bracketPositions[i+1], EvaluateCurrentExpression(input.substr(bracketPositions[i]+1, bracketPositions[i+1] - bracketPositions[i] -1 )));
            break;
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
            // input = AddTerminalBrackets(input);
            while(!IsNumber(input)){
                input = ManageBrackets(input);
            }
        }
        cout << endl << input << endl;
    }
    return 0;
}

