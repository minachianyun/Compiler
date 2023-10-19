#include <iostream>

using namespace std;

int main(){
    string input = "";
    while(getline(cin,input)){
        int l = input.length();
        int flag = 0;
        bool valid = true;
        // invalid input
        for(int i = 0; i < l; i++){
            if(!(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='(' || input[i]==')' || (input[i]>='0' && input[i]<='9') || (input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') || input[i]==' ')){
                valid = false;
                cout << "invalid input" << endl;
                break;
            }
        }
        if(valid == true){
            for(int i = 0; i < l; i++){
                // OP
                if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='='){
                    flag = 0;
                    cout << "OP " << input[i] << endl;
                }
                // LPR
                else if(input[i] == '('){
                    flag = 0;
                    cout << "LPR" << endl;
                }
                // RPR
                else if(input[i] == ')'){
                    flag = 0;
                    cout << "RPR" << endl;
                }
                // NUM
                else if(input[i]>='0' && input[i]<='9'){
                    if(flag == 0){
                        cout << "NUM ";
                    }
                    cout << input[i];
                    int next = min(i+1, l-1);
                    if(input[next]>='0' && input[next]<='9' && next!=i){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                    }
                    if(flag == 0){
                        cout << endl;
                    }
                }
                // ID
                else if((input[i]>='A' && input[i]<='Z') || (input[i]>='a' && input[i]<='z')){
                    if(flag == 0){
                        cout << "ID ";
                    }
                    cout << input[i];
                    int next = min(i+1, l-1);
                    if((input[next]>='A' && input[next]<='Z') || (input[next]>='a' && input[next]<='z')){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                    }
                    if(flag == 0){
                        cout << endl;
                    }
                }
                // blank space
                else if(input[i] == ' '){
                    continue;
                }
            }
        }
    }
}


/*
#include <iostream>

using namespace std;

int main(){
    string input = "";
    while(getline(cin, input)){
        int l = input.length();
        int flag = 0;
        bool valid = true;
        // Check for invalid characters first
        // because if there exist an invalid character then no need to print out other valid characters
        // only has to print out "invalid input"
        for (int i = 0; i < l; i++) {
            if (!(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '=' || input[i] == '(' || input[i] == ')' || (input[i] >= '0' && input[i] <= '9') || ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) || input[i] == ' ')) {
                cout << "invalid input" << endl;
                valid = false;
                break;
            }
        }
        if(valid == true){
            for(int i = 0; i < l; i++){
                // OP
                if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='='){
                    cout << "OP " << input[i] << endl;
                }
                // LPR
                else if(input[i] == '('){
                    cout << "LPR" << endl;
                }
                // RPR
                else if(input[i] == ')'){
                    cout << "RPR" << endl;
                }
                // NUM
                else if(input[i]>='0' && input[i]<='9'){
                    if(flag == 0){
                        cout << "NUM ";
                    }
                    cout << input[i];
                    int next = min(i+1, l-1);
                    if(input[next]>='0' && input[next]<='9' && next!=i){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                    }
                    if(flag == 0){
                        cout << endl;
                    }
                }
                // ID
                else if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z')){
                    if(flag == 0){
                        cout << "ID ";
                    }
                    cout << input[i];
                    int next = min(i+1, l-1);
                    if(((input[next]>='a' && input[next]<='z') || (input[next]>='A' && input[next]<='Z')) && next!=i){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                    }
                    if(flag == 0){
                        cout << endl;
                    }
                }
                // blank space
                else if(input[i] == ' '){
                    continue;
                }
            }
        }
    }
} */
