//                                                                              
//  Organization.cpp                                                            
//  FriendFinder.h                                                              
//                                                                              
//  Created by Adetunji Fasiku on 13/10/2021.                                   
//                                                                              
#include "Organization.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Name: Organization                                                           
// Desc - Default constructor for Organization                                  
// Preconditions - None                                                         
// Postconditions - Organization is created (empty) with 0 people in the roster 
Organization::Organization(){
    m_name = "";
    m_fileName = "";
    m_numRoster = 0;
}
// Name: SetName                                                                
// Desc - Sets m_name by asking user for name                                   
// Preconditions - m_name exists                                                
// Postconditions - Asks user for the organization name and populates m_name    
void Organization::SetName(){
    while (m_name == ""){
        cout << "What is the name of your organization?" << endl;
        cin >> m_name;
    }
}
// Name: LoadRoster                                                             
// Desc - Sets m_fileName by asking user. Then populates all of the people load\
ed from file                                                                    
// Preconditions - m_fileName exists. m_roster empty                            
// Postconditions - Asks user for m_fileName. Loads data from file and populate\
s m_roster                                                                      
void Organization::LoadRoster(){
    string fName, lName, age, ID;
    int real_age, real_ID;
    ifstream infile;
    m_fileName = FILE_NAME;
    infile.open (m_fileName, ifstream::in);
    if (infile.is_open()){
        while (getline(infile, fName, ',')){
          getline(infile, lName, ',');
          getline(infile, age, ',');
          getline(infile, ID, '\n');
          real_age = stoi(age);
          real_ID = stoi(ID);
          m_roster[m_numRoster] = Person(fName, lName, real_age, real_ID);
          m_numRoster++;
        }
        infile.close();

        cout << m_numRoster << " People loaded into the roster" << endl;
    }
    else{
        cout << "Error opening file" << endl;
    }
}
// Name: DisplayRoster                                                          
// Desc - Displays a numbered list of everyone in the roster (starts at 1)      
// Preconditions - m_roster is populated                                        
// Postconditions - Displays a numbered list of people                          
void Organization::DisplayRoster(){
  for (int i = 0; i < m_numRoster; i++){
    cout << i + 1<< " ";
    m_roster[i].DisplayDetails();
    cout << endl;
  }
}
// Name: GetPerson                                                              
// Desc - Displays a list of people in m_roster and user enters number of desir\
ed person.                                                                      
//        Returns pointer of that person in m_roster                            
// Preconditions - m_roster is populated                                        
// Postconditions - Returns pointer for the person chosen from list             
Person* Organization::GetPerson(){
    int desiredIndex = 0;
    for (int i = 0; i < m_numRoster; ++i){
        cout << i << " ";
        m_roster[(i - 1)].DisplayDetails();
        cout << endl;
    }
    while (desiredIndex < 1 || desiredIndex > m_numRoster){
        cin >> desiredIndex;
    }
    Person* new_friend = &m_roster[(desiredIndex - 1)];
    return new_friend;
}

