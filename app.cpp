#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>

using namespace std;

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

    //     for(int i = (bracketIndices.size()/2); (i >= 0) && !error; i--){
    //         string currentExpression = input.substr(bracketIndices[i - 1] + 1, ((bracketIndices[bracketIndices.size() - i]) - bracketIndices[i-1]) - 1);
    //         vector <int> operatorPosition = FetchOperators(currentExpression).first;
    //         string operators = FetchOperators(currentExpression).second;

    //         for(int j = 0; (j < currentExpression.length()) && !error; j++){
    //             for(int t = 0; (t < operators.length()) && !error; t++){
    //                 int currentResult = 0;
    //                 vector <int> currentOperandPosition;
    //                 vector <int> currentOperands {0, 0};
    //                 if(currentExpression.length() == 1){
    //                     input.replace(bracketIndices[i-1], 3, currentExpression);
    //                     bracketIndices.erase(bracketIndices.begin() + ((bracketIndices.size()) / 2) - 1, bracketIndices.begin() + ((bracketIndices.size()) / 2) + 1);
    //                     break;
    //                 }
    //                 if(operators[t] == '/'){
    //                     int k = 0;
    //                     int counter = 1;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentOperands.push_back(operand);
    //                                 currentOperandPosition.push_back(operatorPosition[t] - counter);
    //                                 break;
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 break;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 break;
    //                             }
    //                     }                     
    //                     counter = 0;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] + counter];
    //                                 int operand = stoi(temp);
    //                                 currentOperands.push_back(operand);
    //                                 currentResult = Divide(currentOperands[0], currentOperands[1]);
    //                                 currentOperandPosition.push_back(operatorPosition[t] + counter);
    //                                 break;
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 break;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 break;
    //                         }
    //                     }
    //                 }else if(operators[t] == '*'){
    //                     int k = 0;
    //                     int counter = 1;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentOperands.push_back(operand);
    //                                 break;
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 break;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 break;
    //                         }
    //                     }                     
    //                     counter = 0;
    //                     while((!k) && !error){
    //                         try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentResult = Multiply(currentOperands[0], currentOperands[1]);
    //                                 currentOperands.push_back(operand);
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 continue;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 continue;
    //                         }
    //                     }
    //                 }else if(operators[t] == '+'){
    //                     int k = 0;
    //                     int counter = 1;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentOperands.push_back(operand);
    //                                 break;
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 break;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 break;                            }
    //                     }                     
    //                     counter = 0;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentOperands.push_back(operand);
    //                                 currentResult = Add(currentOperands[0], currentOperands[1]);
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 continue;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 continue;
    //                         }
    //                     }
    //                 }else if(operators[t] == '-'){
    //                     int k = 0;
    //                     int counter = 1;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentOperands.push_back(operand);
    //                                 break;
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 break;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 break;                            }
    //                     }                     
    //                     counter = 0;
    //                     while((!k) && !error){
    //                             try{
    //                                 string temp;
    //                                 temp += currentExpression[operatorPosition[t] - counter];
    //                                 int operand = stoi(temp);
    //                                 currentResult = Subtract(currentOperands[0], currentOperands[1]);
    //                                 currentOperands.push_back(operand);
    //                             }catch(const std:: invalid_argument& e){
    //                                 cerr << "Error Invalid Agument " << e.what() << endl;
    //                                 error = true;
    //                                 continue;
    //                             }catch(const std:: out_of_range& e){
    //                                 cerr << "Number too big." << endl;
    //                                 error = true;
    //                                 continue;                            }
    //                     }
    //                 }
                    
    //                 currentExpression.replace(currentOperandPosition[0], (currentExpression.length() - currentOperandPosition[1]), to_string(currentResult));
    //             }
            
    //         }
    //     }

    // }
    cout<<endl<< "program exited successfully.";

    return 0;
}
