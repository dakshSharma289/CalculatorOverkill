#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>

using namespace std;

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

        if(!(bracketIndices.size()%2)){
            cout<<"you missed a pathentasis \n the police are on thier way!"<<endl;
        }

        for(int i = (bracketIndices.size()/2); (i >= 0) && !error; i--){
            string currentExpression = input.substr(bracketIndices[i], (bracketIndices[bracketIndices.size() - i]) - bracketIndices[i]);
            string operators;
            vector <int> operatorPosition;
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
                for(int t = 0; t < operators.length(); t++){
                    if(operators[t] == '/'){
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
                    }else if(operators[t] == '*'){
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
            }
        }

    }
    cout<<endl<< "program exited successfully.";

    return 0;
}
