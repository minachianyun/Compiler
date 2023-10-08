#include <iostream>

using namespace std;

string input = "";

string peek(){
    // ID
    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= '0' && input[0] <= '9') || (input[0] == ' '))
        return "ID";
    // STRLIT
    else if (input[0] == '"')
        return "STRLIT";
    // LBR
    else if (input[0] == '(')
        return "LBR";
    // RBR
    else if (input[0] == ')')
        return "RBR";
    // DOT
    else if (input[0] == '.')
        return "DOT";
    else
        return "";
}

void error(){
    cout << "invalid input" << endl;
}

void id(){
    int l = input.length();
    // Initialize a flag to control whether to print the "ID" token
    int print = 0;
    // Declare a string variable "m" to store the extracted identifier
    string m = "";
    for (int i = 0; i < l; i++){
        if (input[i] == '"' || input[i] == '(' || input[i] == ')' || input[i] == '.'){
            // Set the flag to print the "ID" token
            print = 1;
            // Extract the identifier from the beginning of "s"
            m = input.substr(0, i);
            // Remove the extracted part from "s"
            input = input.substr(i);
            cout << "ID " << m << endl;
            break;
        }
        if ((input[0] >= '0' && input[0] <= '9') || !((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] == '_'))){
            print = 1;
            error();
            input = "";
            break;
        }
    }
    if (print == 0){
        cout << "ID " << input << endl;
        input = "";
    }
}
void stmt();

void primary_tail(){
    if (peek() == "DOT"){
        cout << "DOT ." << endl;
        input = input.substr(1);
        id();
        primary_tail();
    }
    else if (peek() == "LBR"){
        cout << "LBR (" << endl;
        input = input.substr(1);
        stmt();
        if(input[0] == ')'){
            cout << "RBR )" << endl;
            input = input.substr(1);
        }
        else{
            error();
            input = "";
        }
        primary_tail();
    }
}

void primary(){
    if (peek() == "ID"){
        id();
        if (peek() == "DOT" || peek() == "LBR"){
            primary_tail();
        }
    }
}

void stmt(){
    if (peek() == "STRLIT"){
        // Initialize a flag to check if a valid string literal is found
        int t = 0;
        int l = input.length();
        string m = "";
        for (int i = 1; i < l; i++){
            if (input[i] == '"'){
                // Set the flag to indicate a valid string literal.
                t = 1;
                m = input.substr(0, i+1);
                input = input.substr(i+1);
                cout << "STRLIT " << m;
                break;
            }
        }
        // Print a newline to separate tokens if a valid string literal was found
        if(t == 1){
            cout << endl;
        }
        else{
            error();
            input = "";
        }
    }
    // If the next token is an identifier, call the "primary" function
    else if(peek() == "ID"){
        primary();
    }
}

void stmts(){
    if (peek() == "STRLIT" || peek() == "ID"){
        stmt();
        stmts();
    }
}

int main(){
    while (getline(cin, input)){
        stmts();
    }
}
