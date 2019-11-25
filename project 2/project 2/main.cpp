//
//  main.cpp
//  project 2
//
//  Created by Olympia Pyburn on 11/23/19.
//  Copyright © 2019 Olympia Pyburn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "library.hpp"


using namespace std;


int main() {
    int day = 1;
    Library library;
    Book book1;
    Employees employee1;
    Employees employee2;
    Employees employee3;
    
    book1.setName("Software Engineering");
    employee1.setName("Martha");
    employee2.setName("Allison");
    employee3.setName("Garson");
    
    book1.addEmployees(employee3);
    book1.addEmployees(employee2);
    book1.addEmployees(employee1);
    library.addBook(book1);
    
    book1.setStart(day);
    
    
    return 0;
}
