#include <iostream>

using namespace std;

int main(){
    string input = "";
    while(getline(cin, input)){
        int l = input.length();
        for(int i = 1; i < l; i++){
            if(input[0] == 'a'){
                if(input[i] == 'a'){
                    continue;
                }
                else if(input[i]=='b' && input[i+1]=='$'){
                    cout << "YES s4" << endl;
                    break;
                }
                else{
                    cout << "NO" << endl;
                    break;
                }
            }
            else if(input[0] = 'b'){
                if(input[i] == 'a'){
                    if(input[i+1] == '$'){
                        cout << "YES s3" << endl;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                else if(input[i]=='c' && input[i+1]=='$'){
                    cout << "YES s4" << endl;
                    break;
                }
                else{
                    cout << "NO" << endl;
                    break;
                }
            }
            else{
                cout << "NO" << endl;
                break;
            }
        }
    }
}

/*
#include <iostream>

using namespace std;

int main(){
    string input;
    while(getline(cin, input)){
        int l = input.length();
        for(int i = 1; i < l; i++){
            if(input[0] == 'a'){
                if(input[i] == 'a'){
                    continue;
                }
                else if(input[i]=='b' && input[i+1]=='$'){
                    cout << "YES s4" << endl;
                    break;
                }
                else{
                    cout << "NO" << endl;
                    break;
                }
            }
            else if(input[0] == 'b'){
                if(input[i] == 'a'){
                    if(input[i+1] == '$'){
                        cout << "YES s3" << endl;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                else if(input[i]=='c' && input[i+1]=='$'){
                    cout << "YES s4" << endl;
                    break;
                }
                else{
                    cout << "NO" << endl;
                    break;
                }
            }
            else{
                cout << "NO" << endl;
                break;
            }
        }
    }
} */

/*#include <iostream>
using namespace std;

int main(){
    string s;
    while (getline(cin, s)){
        int i = 0;
        if (s[0] == 'a'){
            while (s[i] == 'a'){
                i++;
            }
            if (s[i] == 'c' || s[i] == '$'){
                cout << "NO" << endl;
                continue;
            }
            else if (s[i] == 'b' && s[i + 1] == '$'){
                cout << "YES s4" << endl;
                continue;
            }
            if(s[i] == 'b' && s[i+1] != '$'){
                cout << "NO" << endl;
                continue;
            }
        }
        else if (s[0] == 'b'){
            i++;
            if (s[i] == '$'){
                cout << "YES s3" << endl;
                continue;
            }
            else if (s[i] == 'b'){
                cout << "NO" << endl;
                continue;
            }
            while (s[i] == 'a'){
                i++;
            }
            if (s[i] == '$'){
                cout << "YES s3" << endl;
                continue;
            }
            if (s[i] == 'c' && s[i + 1] == '$'){
                cout << "YES s4" << endl;
                continue;
            }
            else{
                cout << "NO" << endl;
                continue;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
}
*/
