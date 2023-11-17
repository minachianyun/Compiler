#include <iostream>
#include <set>
// #include <bits/stdc++.h>


using namespace std;
// store grammar rules for each non-terminal
unordered_map<char, vector<string>> grammar;
// store the first set for each non-terminal
unordered_map<char, set<char>> first;

// compute the first set for a given non-terminal
void computeFirst(char c){
  // Loop through production rules of the non-terminal
  for(size_t i = 0; i < grammar[c].size(); i++){
    // store the first set for the current rule
    set<char> charFirst;
    char tmp;
    // Loop through characters in the current rule
    for(size_t j = 0; j < grammar[c][i].size(); j++){
      tmp = grammar[c][i][j];
      set<char> tmpFirst;
      // Check if the character is lowercase, semicolon, or dollar sign
      if((tmp >= 'a' && tmp <= 'z') || tmp == ';' || tmp == '$'){
        // Add the character to the temporary first set
        tmpFirst.insert(tmp);
      }
      else{
        // Check if the first set for the character is not computed yet
        if(first.find(tmp) == first.end()){
          computeFirst(tmp);
        }
        // Add the computed first set to the temporary first set
        tmpFirst.insert(first[tmp].begin(), first[tmp].end());
      }
      // Add the temporary first set to the overall first set for the rule
      charFirst.insert(tmpFirst.begin(), tmpFirst.end());
     // If ';' is not in the temporary first set, remove it from the overall first set
      if(tmpFirst.find(';') == tmpFirst.end()){
        charFirst.erase(';');
        break;
      }
    }
    // Add the overall first set for the rule to the first set for the non-terminal
    first[c].insert(charFirst.begin(), charFirst.end());
  }
}

int main(){
  string input;
  while(getline(cin, input) && input != "END_OF_GRAMMAR"){
    // Extract the non-terminal character from the beginning of the line
    char ch = input[0];
    // Erase the non-terminal character and the arrow symbol from the input
    input.erase(0, 2);
    int position = 0;
    for(size_t i = 0; i < input.length(); i++){
      // Check for the '|' symbol, which separates production rules
      if(input[i] == '|'){
        // Add the current production rule to the grammar for the non-terminal
        grammar[ch].push_back(input.substr(position, i - position));
        // Update the starting position for the next production rule
        position = i + 1;
      }
    }
    // Add the last production rule to the grammar for the non-terminal
    grammar[ch].push_back(input.substr(position, input.size() - position));
  }
  for(char c = 'A'; c <= 'Z'; c++){
    // Check if the non-terminal has production rules defined
    if(grammar.find(c) != grammar.end()){
      // Check if the first set for the non-terminal is not computed yet
      if(first.find(c) == first.end()){
        // Compute the first set for the non-terminal
        computeFirst(c);
      }
    }
  }
  for(char c = 'A'; c <= 'Z'; c++){
    // Check if the first set for the non-terminal is computed
    if(first.find(c) != first.end()){
      // Output the non-terminal and its corresponding first set
      cout << c << " ";
      for(auto it = first[c].begin(); it != first[c].end(); it++){
        // *it gives the character value
        cout << *it;
      }
      cout << endl;
    }
  }
  cout << "END_OF_FIRST" << endl;
}
