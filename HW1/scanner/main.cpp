#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s = "";
    int continNum = 0;
    while (getline(cin, s))
    {
        continNum = 0;
        int l = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' || s[i] == '\n')
            {
                continNum = 0;
                continue;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')')
            {
                continNum = 0;
                if (s[i] == '+')
                    cout << "PLUS";
                else if (s[i] == '-')
                    cout << "MINUS";
                else if (s[i] == '*')
                    cout << "MUL";
                else if (s[i] == '/')
                    cout << "DIV";
                else if (s[i] == '(')
                    cout << "LPR";
                else if (s[i] == ')')
                    cout << "RPR";
            }
            else
            {
                if (continNum == 0)
                    cout << "NUM ";
                cout << s[i];
                int j = min(i + 1, l-1);
                if(s[j]>=48 && s[j]<=57 && j!=i)
                    continNum = 1;
                else
                    continNum = 0;
            }
            if (continNum == 0)
                cout << endl;
        }
    }
}

