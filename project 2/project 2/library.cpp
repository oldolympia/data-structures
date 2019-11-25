//
//  library.cpp
//  project 2
//
//  Created by Olympia Pyburn on 11/24/19.
//  Copyright © 2019 Olympia Pyburn. All rights reserved.
//

#include "library.hpp"
#include <vector>
#include <string>

using namespace std;

//add a book to the library
void Library::addBook(Book book){
    toBe.push_back(book);
}

//add an employee to the system
void Library::addEmployee(Employees employee){
    employed.push_back(employee);
}


void Library::circulateBook(Book book, int day){
    priority_queue<Employees> q = book.getQueue();  //gain access to priority queue
    
    for(int i = 0; i <employed.size(); i++){
        if(employed[i] == q.top()){ //find first person to get book
            employed[i].setRT(day); //set the first person's retaining time to day
        }
        if(q.empty()){
            archived.push_back(book);
        }
    }

    
}
