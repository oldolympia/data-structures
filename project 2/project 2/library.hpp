//
//  library.hpp
//  project 2
//
//  Created by Olympia Pyburn on 11/24/19.
//  Copyright © 2019 Olympia Pyburn. All rights reserved.
//

#ifndef library_hpp
#define library_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <queue>


using namespace std;


//employee class to keep track of employee attributes
class Employees{
private:
    string name;
    int waitingTime = 0;
    int retainingTime = 0;
    int weight = waitingTime - retainingTime;
public:
    Employees(){};
    friend bool operator<(const Employees& p1, const Employees& p2)
    {
        // this will return true when second person
        // has greater weight. Suppose we have p1.weight=5
        // and p2.weight=5.5 then the object which
        // have max height will be at the top(or
        // max priority)
        return p1.weight < p2.weight;
    }
    friend bool operator== (const Employees &c1, const Employees &c2){
        return c1.name == c2.name;
    };
    void setName(string n){ //set employee name
        name = n;
    }
    void setRT(int day){ //set employee name
        retainingTime = day;
    }
    string getName(){return name;}  //get employee name
    int getWT(){return waitingTime;}
    int getRT(){return retainingTime;}
};

//book class to keep track of book attributes
class Book{
private:
    string name;
    int start = 0;
    int end = 0;
    bool archived = false;
    priority_queue<Employees> circulation;

public:
    Book(){};
    void setName(string n){ //get book name
        name = n;
    }
    void setStart(int day){start = day;}
    void setEnd(int day){end = day;}
    string getName(){return name;}  //get book name
    void addEmployees(Employees employee){
        circulation.push(employee);
    }
    //allow public access to priority queue
    priority_queue<Employees> getQueue(){return circulation;}
    
};

//library class to structure system
class Library{
private:
    vector<Book> toBe;  //keep track of books to be circulated
    vector<Book> archived;  //keep track of books that are archived
    vector<Employees> employed; //keep track of employees currently in system
public:
    Library(){};
    void addBook(Book book);    //add a book to the system
    void addEmployee(Employees employee);   //add an employee to the system
    void circulateBook(Book book, int day);
    void pass();
    
};

#endif /* library_hpp */
