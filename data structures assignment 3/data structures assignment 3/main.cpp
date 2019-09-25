//
//  main.cpp
//  data structures assignment 3 code
//
//  Created by Olympia Pyburn on 9/25/19.
//  Copyright © 2019 Olympia Pyburn. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include "Infix_To_Postfix.hpp"
#include <queue>


using namespace std;

//function that reads line and reverses the words in the line
void reverse()
{
    //The quick brown fox jumps over the lazy dog.
    stack<string> backwards;
    string phrase;
    cout <<"Enter a string :";
    getline(cin, phrase);
    string space = "";
    
    for(int i = 0; i <= phrase.length(); i++)
    {
        if(phrase[i] == ' ' || phrase[i] == '\0')
        {
            //Push operation
            backwards.push(space);
            space = "";
        }
        else{
            space += phrase[i];
    }
    }

    while(!backwards.empty())
    {
        cout << backwards.top() << " ";
        backwards.pop();
    }
    cout << endl;
}

void move_to_rear(){
    queue<int> fun;
    
    if(!fun.empty()){
        
        int first = fun.front();
        
        while(true){
            
            int temp = fun.back();
            
            if(temp == first){
                int second = fun.front();
                break;
            }
            
            fun.push(temp);
        }
        fun.push(first);
    }
}



int main() {
    reverse();
    return 0;
}
