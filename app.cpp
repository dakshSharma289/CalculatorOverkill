#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>

using namespace std;

int SolveDMAS();

void CheckBrackets(vector <int> bracketIndices){
    if(!(bracketIndices.size()%2)){
        cout<<"you missed a pathentasis \n the police are on thier way!"<<endl;
    }
}

pair <vector <int>, vector <bool>> FindBrackets (string input){
    vector <int> listOfBracketIndices;
    vector <bool> listOfBracketType;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            listOfBracketIndices.push_back(i);
            listOfBracketType.push_back(true);
        }else if(input[i] == ')'){
            listOfBracketIndices.push_back(i);
            listOfBracketType.push_back(false);
        }
    }

    return make_pair(listOfBracketIndices, listOfBracketType);
}

int main(){
    bool error = false;
    cout << "Wellcome to my Overkill Calculator App" << endl << "To exit the program, type 'q' in a new line and press enter" << endl << "You can enter your problem bellow:" << endl;
    while(0 < 1){
        error = false;
        string input;
        getline(cin, input);

        if((input == "q") || (input == "Q")){
            break;
        }
//here I'm iterating through the input to figure out where and how many brackets are pestent.
        vector <int> bracketIndices = FindBrackets(input).first;
        vector <bool> bracketType = FindBrackets(input).second;

        CheckBrackets(bracketIndices);

        for(int i = (bracketIndices.size()/2); (i >= 0) && !error; i--){
            string currentExpression = input.substr(bracketIndices[i], (bracketIndices[bracketIndices.size() - i]) - bracketIndices[i]);
            string operators;
            vector <int> operatorPosition;
            int currentResult;
            for(int j = 0; j < currentExpression.length(); j++){
                if (currentExpression[j == '+']){

                    operators.append("+");
                    operatorPosition.push_back(j);

                }else if (currentExpression[j == '-']){

                    operators.append("-");
                    operatorPosition.push_back(j);
                    
                }else if (currentExpression[j == '*']){

                    operators.append("*");
                    operatorPosition.push_back(j);
                    
                }else if (currentExpression[j == '/']){

                    operators.append("/");
                    operatorPosition.push_back(j);
                    
                } 
            }
            for(int j = 0; (j < currentExpression.length()) && !error; j++){
                vector <int> currentOperands;
                string operation;
                for(int t = 0; (t < operators.length()) && !error && (currentOperands.size() < 2); t++){
                    if(operators[t] == '/'){
                        operation = "div";
                        int k = 0;
                        int counter = 1;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] - counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                    break;
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    break;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    break;
                                }
                            }
                        }                     
                        counter = 0;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] + counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                    break;
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    break;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    break;
                                }
                            }
                        }
                    }else if(operators[t] == '*'){
                        operation = "mul";
                        int k = 0;
                        int counter = 1;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] - counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                    break;
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    break;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    break;
                                }
                            }
                        }                     
                        counter = 0;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] + counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    continue;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    continue;
                                }
                            }
                        }
                    }else if(operators[t] == '+'){
                        operation = "add";
                        int k = 0;
                        int counter = 1;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] - counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                    break;
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    break;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    break;
                                }
                            }
                        }                     
                        counter = 0;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] + counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    continue;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    continue;
                                }
                            }
                        }
                    }else if(operators[t] == '-'){
                        operation = "minus";
                        int k = 0;
                        int counter = 1;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] - counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                    break;
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    break;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    break;
                                }
                            }
                        }                     
                        counter = 0;
                        while((!k) && !error){
                            if(currentExpression[operatorPosition[t] + counter] == ' '){
                                counter++;
                                continue;
                            }else{
                                try{
                                    string temp;
                                    temp += currentExpression[operatorPosition[t] - counter];
                                    int operand = stoi(temp);
                                    currentOperands.push_back(operand);
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                    continue;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                    continue;
                                }
                            }
                        }
                    }
                }
            
                if(operation == "div"){
                    currentResult = currentOperands[0] / currentOperands[1];
                }else if(operation == "mul"){
                    currentResult = currentOperands[0] * currentOperands[1];
                }else if(operation == "add"){
                    currentResult = currentOperands[0] + currentOperands[1];
                }else if(operation == "sub"){
                    currentResult = currentOperands[0] - currentOperands[1];
                }
            
            }
        }

    }
    cout<<endl<< "program exited successfully.";

    return 0;
}
