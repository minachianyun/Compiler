#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string input = "";
    int continNum = 0;
    int continCha = 0;
    int flag = 0;
    int flag_key = 0;
    int only_num = 0;
    
    while (getline(cin, input)){
        continNum = 0;
        int l = input.length();
        
        for(int i = 0; i < input.length(); i++){
            // blank space
            if(input[i] == ' ' || input[i] == '\n'){
                if(continCha == 1){
                    cout << endl;
                }
                continNum = 0;
                continCha = 0;
                continue;
            }
            // keyword: if
            else if(input[i]=='i' && input[i+1]=='f'){
                flag_key = 1;
                cout << "KEYWORD " << '"' << input[i] << input[i+1] << '"' << endl;
                i = i + 1;
            }
            // keyword: else
            else if(input[i]=='e' && input[i+1]=='l' && input[i+2]=='s' && input[i+3]=='e'){
                flag_key = 1;
                cout << "KEYWORD " << '"' << input[i] << input[i+1] << input[i+2] << input[i+3] << '"' << endl;
                i = i + 3;
            }
            // keyword: while
            else if(input[i]=='w' && input[i+1]=='h' && input[i+2]=='i' && input[i+3]=='l' && input[i+4]=='e'){
                flag_key = 1;
                cout << "KEYWORD " << '"' << input[i] << input[i+1] << input[i+2] << input[i+3] << input[i+4] << '"' << endl;
                i = i + 4;
            }
            // symbol
            else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='(' || input[i]==')' || input[i]=='{' || input[i]=='}' || input[i]=='=' || input[i]=='<' || input[i]=='>' || input[i]==';'){
                if(continCha == 1){
                    cout << endl;
                }
                continNum = 0;
                continCha = 0;
                flag = 1;
                cout << "SYMBOL " << '"' << input[i] << '"' << endl;
            }
            // ID
            else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == '_'){
                flag = 0;
                if(continCha == 0){
                    cout << "IDENTIFIER " << '"';
                }
                cout << input[i];
                continCha = 1;
                int next = min(i+1,l-1);
                if(!((input[next]>='0' && input[next]<='9') || (input[next]>='a' && input[next]<='z') || (input[next]>='A' && input[next]<='Z')) || i==l){
                    cout << '"';
                }
            }
            // num
            else if(input[i] >= '0' && input[i] <= '9'){
                flag_key = 0;
                flag = 0;
                only_num = 1;
                // 前一個是ID，現在是數字
                if(continCha == 1){
                    cout << input[i];
                }
                // 如果前一個不是NUM也不是ID
                if(continNum == 0 && continCha == 0){
                    cout << "NUM " << '"';
                }
                if(continCha == 0){
                    cout << input[i];
                }
                int j = min(i + 1, l - 1);
                // 如果下一個是NUM
                if(input[j] >= '0' && input[j] <= '9' && j != i){
                    continNum = 1;
                }
                // 下一個不是NUM
                else{
                    continNum = 0;
                }
                if(!(input[i+1]>='0' && input[i+1]<='9') && only_num==1){
                    flag_key = 1;
                    cout << '"';
                    cout << endl;
                }
            }
            else{
                cout << "Invalid" << endl;
            }
            if(continNum == 0 && continCha == 0 && flag == 0 && flag_key == 0){
                cout << '"';
                cout << endl;
            }
        }
    }
}
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string input = "";
    int continNum = 0;
    int continCha = 0;
    while (getline(cin, input)){
        continNum = 0;
        int l = input.length();
        bool valid = true;
        // Check for invalid characters first
        for(int i = 0; i < l; i++) {
            if (!(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '=' || input[i] == '/' || input[i] == ';' ||
                  input[i] == '(' || input[i] == ')' ||
                  (input[i] >= '0' && input[i] <= '9') ||
                  ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) ||
                  input[i] == ' ')) {
                cout << "invalid input" << endl;
                valid = false;
                break;
            }
        }
        if(valid == true){
            for(int i = 0; i < input.length(); i++){
                // blank space
                if(input[i] == ' ' || input[i] == '\n'){
                    if(continCha == 1){
                        cout << endl;
                    }
                    continNum = 0;
                    continCha = 0;
                    continue;
                }
                // OP
                else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '='){
                    if(continCha == 1){
                        cout << endl;
                    }
                    continNum = 0;
                    continCha = 0;
                    cout << "OP " << input[i];
                }
                // SEMICOLON
                else if(input[i] == ';'){
                    if(continCha == 1){
                        cout << endl;
                    }
                    continNum = 0;
                    continCha = 0;
                    cout << "SEMICOLON " << input[i];
                }
                // RBR and LBR
                else if (input[i] == '(' || input[i] == ')'){
                    if(continCha == 1){
                        cout << endl;
                    }
                    continNum = 0;
                    continCha = 0;
                    if(input[i] == '('){
                        cout << "LBR " << input[i];
                    }
                    else if(input[i] == ')'){
                        cout << "RBR " << input[i];
                    }
                }
                // ID
                else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == '_'){
                    if(continCha == 0){
                        cout << "ID ";
                    }
                    cout << input[i];
                    continCha = 1;
                }
                // num
                else if(input[i] >= '0' && input[i] <= '9'){
                    if(continCha == 1){
                        cout << input[i];
                    }
                    if(continNum == 0 && continCha == 0){
                        cout << "NUM ";
                    }
                    if(continCha == 0){
                        cout << input[i];
                    }
                    int j = min(i + 1, l - 1);
                    if(input[j] >= '0' && input[j] <= '9' && j != i){
                        continNum = 1;
                    }
                    else{
                        continNum = 0;
                    }
                }
                if(continNum == 0 && continCha == 0){
                    cout << endl;
                }
            }
        }
    }
}
*/
