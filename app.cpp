#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>

using namespace std;

bool NotOperator(char s){
    if(s == '/'){
        return false;
    }else if(s == '*'){
        return false;
    }if(s == '+'){
        return false;
    }if(s == '-'){
        return false;
    }else{
        return true;
    }
}

pair <vector <int>, string> SortOperators(vector <int> unsortedOperatorPositions, string unsortedOperators){
    vector <int> sortedOperatorPositions;
    string sortedOperators;
    for(int i = 0; i < unsortedOperatorPositions.size(); i++){
        for(int j = 0; j < unsortedOperatorPositions.size(); i++){
            if(unsortedOperators[j] == '/'){
                sortedOperators.append("/");
                sortedOperatorPositions.push_back(unsortedOperatorPositions[j]);
            }
        }
        for(int j = 0; j < unsortedOperatorPositions.size(); i++){
            if(unsortedOperators[j] == '*'){
                sortedOperators.append("*");
                sortedOperatorPositions.push_back(unsortedOperatorPositions[j]);
            }
        }
        for(int j = 0; j < unsortedOperatorPositions.size(); i++){
            if(unsortedOperators[j] == '+'){
                sortedOperators.append("+");
                sortedOperatorPositions.push_back(unsortedOperatorPositions[j]);
            }
        }
        for(int j = 0; j < unsortedOperatorPositions.size(); i++){
            if(unsortedOperators[j] == '-'){
                sortedOperators.append("-");
                sortedOperatorPositions.push_back(unsortedOperatorPositions[j]);
            }
        }
    }
    return make_pair(sortedOperatorPositions, sortedOperators);
}

string RemoveWhiteSpace(string input){
    for(int i = 0; i < input.length(); i++){
        if(input[i] == ' '){
            input.erase(i, 1);
        }
    }

    return input;
}

pair <vector <int>, string> FetchOperators(string currentExpression){
    string listOfOperators;
    vector <int> listOfOperatorPositions;
    for(int j = 0; j < currentExpression.length(); j++){
        if (currentExpression[j == '+']){

            listOfOperators.append("+");
            listOfOperatorPositions.push_back(j);

        }else if (currentExpression[j == '-']){

            listOfOperators.append("-");
            listOfOperatorPositions.push_back(j);
            
        }else if (currentExpression[j == '*']){

            listOfOperators.append("*");
            listOfOperatorPositions.push_back(j);
            
        }else if (currentExpression[j == '/']){

            listOfOperators.append("/");
            listOfOperatorPositions.push_back(j);
            
        } 
    }
    return make_pair(listOfOperatorPositions, listOfOperators);
}

void CheckBrackets(vector <int> bracketIndices){
    if(!(bracketIndices.size()%2)){
        cout<<"you missed a pathentasis \n the police are on thier way!"<<endl;
    }
}

pair <vector <int>, vector <bool>> FetchBrackets (string input){
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

int Divide(int a, int b){
    return (a / b);
}

int Multiply(int a, int b){
    return (a * b);
}

int Add(int a, int b){
    return (a + b);
}

int Subtract(int a, int b){
    return (a - b);
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

        input = RemoveWhiteSpace(input);
//here I'm iterating through the input to figure out where and how many brackets are pestent.
        vector <int> bracketIndices = FetchBrackets(input).first;
        vector <bool> bracketType = FetchBrackets(input).second;

        CheckBrackets(bracketIndices);

        for(int m = 0; m < (bracketIndices.size())/2 ; m++){
            for(int i = 0; i < bracketType.size(); i++){
                if(bracketType[i] != bracketType[i+1]){
                    string currentExpression = input.substr(bracketIndices[i] + 1, bracketIndices[i+1] - bracketIndices[i] - 1);
                    vector <int> operatorPosition = FetchOperators(currentExpression).first;
                    string operators = FetchOperators(currentExpression).second;
                    const int numberOfOperators = operatorPosition.size();
                    
                    for(int t = 0; (t < (numberOfOperators + 1)) && !error; t++){
                        operatorPosition = FetchOperators(currentExpression).first;
                        operators = FetchOperators(currentExpression).second;
                        operatorPosition = SortOperators(operatorPosition, operators).first;
                        operators = SortOperators(operatorPosition, operators).second;


                        int currentResult = 0;
                        vector <int> currentOperandPosition = {0, 0};
                        vector <int> currentOperands {0, 0};
                        if(!((FetchOperators(currentExpression).first).size())){
                            input.replace(bracketIndices[i-1], currentExpression.size(), currentExpression);
                            bracketIndices.erase(bracketIndices.begin() + ((bracketIndices.size()) / 2) - 1, bracketIndices.begin() + ((bracketIndices.size()) / 2) + 1);
                            break;
                        }
                        if(operators[t] == '/'){
                            int counter = 1;
                            string secondOperand;
                            string firstOperand;
                            while(NotOperator(currentExpression[operatorPosition[0] - counter]) && !error){
                                        string temp;
                                        temp += currentExpression[operatorPosition[0] - counter];
                                        firstOperand.insert(0, 1, currentExpression[operatorPosition[0] - counter]);
                                        currentOperandPosition.push_back(operatorPosition[0] - counter);
                                        continue;

                                }

                                try{
                                    firstOperand = stoi(firstOperand);
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                }
                            
                            counter = 0;
                            while(NotOperator(currentExpression[operatorPosition[0] + counter]) && !error){
                                string temp;
                                temp += currentExpression[operatorPosition[0] + counter];
                                firstOperand.insert(0, 1, currentExpression[operatorPosition[0] + counter]);
                                currentOperandPosition.push_back(operatorPosition[0] + counter);
                                break;
                        }
                        try{
                            string temp1;
                            string temp2;
                            temp1 += firstOperand;
                            temp2 += secondOperand;
                            currentOperands[0] = stoi(temp1);
                            currentOperands[1] = stoi(temp2);
                            currentResult = Divide(currentOperands[0], currentOperands[1]);
                        }catch(const std:: invalid_argument& e){
                            cerr << "Error Invalid Agument " << e.what() << endl;
                            error = true;
                        }catch(const std:: out_of_range& e){
                            cerr << "Number too big." << endl;
                            error = true;
                        }
                        }else if(operators[t] == '*'){
                            int counter = 1;
                            string secondOperand;
                            string firstOperand;
                            while(NotOperator(currentExpression[operatorPosition[0] - counter]) && !error){
                                        string temp;
                                        temp += currentExpression[operatorPosition[0] - counter];
                                        firstOperand.insert(firstOperand.end() - counter + 1, 1, currentExpression[operatorPosition[0] - counter]);
                                        currentOperandPosition[0] = operatorPosition[0] - counter;
                                        counter++;
                                        continue;

                                }

                                try{
                                    firstOperand = stoi(firstOperand);
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                }
                            
                            counter = 0;
                            while(NotOperator(currentExpression[operatorPosition[0] + counter]) && !error){
                                string temp;
                                temp += currentExpression[operatorPosition[0] + counter];
                                firstOperand.insert(counter -1, 1, currentExpression[operatorPosition[0] + counter]);
                                currentOperandPosition[1] = operatorPosition[0] + counter;
                                counter++;
                                break;
                        }
                        try{
                            string temp1;
                            string temp2;
                            temp1 += firstOperand;
                            temp2 += secondOperand;
                            currentOperands[0] = stoi(temp1);
                            currentOperands[1] = stoi(temp2);
                            currentResult = Multiply(currentOperands[0], currentOperands[1]);
                            operators.erase(0);
                            operatorPosition.erase(operatorPosition.begin());
                        }catch(const std:: invalid_argument& e){
                            cerr << "Error Invalid Agument " << e.what() << endl;
                            error = true;
                        }catch(const std:: out_of_range& e){
                            cerr << "Number too big." << endl;
                            error = true;
                        }
                        }else if(operators[t] == '+'){
                            int counter = 1;
                            string secondOperand;
                            string firstOperand;
                            while(NotOperator(currentExpression[operatorPosition[0] - counter]) && !error){
                                        string temp;
                                        temp += currentExpression[operatorPosition[0] - counter];
                                        firstOperand.insert(0, 1, currentExpression[operatorPosition[0] - counter]);
                                        currentOperandPosition[0] = operatorPosition[0] - counter;
                                        continue;

                                }

                                counter = 1;
                                while(NotOperator(currentExpression[operatorPosition[0] + counter]) && !error){
                                    string temp;
                                    temp += currentExpression[operatorPosition[0] + counter];
                                    firstOperand.insert(0, 1, currentExpression[operatorPosition[0] + counter]);
                                    currentOperandPosition[1] = operatorPosition[0] + counter;
                                    break;
                            }
                            try{
                                string temp1;
                                string temp2;
                                temp1 += firstOperand;
                                temp2 += secondOperand;
                                currentOperands[0] = stoi(temp1);
                                currentOperands[1] = stoi(temp2);
                                currentResult = Add(currentOperands[0], currentOperands[1]);
                            }catch(const std:: invalid_argument& e){
                                cerr << "Error Invalid Agument " << e.what() << endl;
                                error = true;
                            }catch(const std:: out_of_range& e){
                                cerr << "Number too big." << endl;
                                error = true;
                            }
                        }else if(operators[t] == '-'){
                            int counter = 1;
                            string secondOperand;
                            string firstOperand;
                            while(NotOperator(currentExpression[operatorPosition[0] - counter]) && !error){
                                        string temp;
                                        temp += currentExpression[operatorPosition[0] - counter];
                                        firstOperand.insert(0, 1, currentExpression[operatorPosition[0] - counter]);
                                        currentOperandPosition.push_back(operatorPosition[0] - counter);
                                        continue;

                                }

                                try{
                                    firstOperand = stoi(firstOperand);
                                }catch(const std:: invalid_argument& e){
                                    cerr << "Error Invalid Agument " << e.what() << endl;
                                    error = true;
                                }catch(const std:: out_of_range& e){
                                    cerr << "Number too big." << endl;
                                    error = true;
                                }
                            
                                counter = 0;
                                while(NotOperator(currentExpression[operatorPosition[0] + counter]) && !error){
                                    string temp;
                                    temp += currentExpression[operatorPosition[0] + counter];
                                    firstOperand.insert(0, 1, currentExpression[operatorPosition[0] + counter]);
                                    currentOperandPosition.push_back(operatorPosition[0] + counter);
                                    break;
                            }
                            try{
                                string temp1;
                                string temp2;
                                temp1 += firstOperand;
                                temp2 += secondOperand;
                                currentOperands[0] = stoi(temp1);
                                currentOperands[1] = stoi(temp2);
                                currentResult = Subtract(currentOperands[0], currentOperands[1]);
                            }catch(const std:: invalid_argument& e){
                                cerr << "Error Invalid Agument " << e.what() << endl;
                                error = true;
                            }catch(const std:: out_of_range& e){
                                cerr << "Number too big." << endl;
                                error = true;
                            }
                        
                        currentExpression.replace(currentOperandPosition[0], (currentExpression.length() - currentOperandPosition[1]), to_string(currentResult));
                    }
                    
                    currentExpression.replace(currentOperandPosition[0], currentOperandPosition[1] - currentOperandPosition[0] + 1, to_string(currentResult));
                }
            }
        }

    cout<<endl<< "program exited successfully.";

    return 0;
    }
}
