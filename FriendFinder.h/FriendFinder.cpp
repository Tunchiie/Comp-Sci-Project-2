//
//  FriendFinder.cpp
//  FriendFinder.h
//
//  Created by Adetunji Fasiku on 13/10/2021.
//

#include "FriendFinder.h"
#include <iostream>
#include <string>
#include "Organization.h" //Must be implemented before FriendFinder
#include "Person.h" //Must be implemented before FriendFinder

using namespace std;

// Name: FriendFinder
// Desc - Default constructor for application for finding friends
// Preconditions - Creates a Person and an organization
// Postconditions - Welcomes user and calls Start()
FriendFinder::FriendFinder(){
    cout << "*****************************" << endl;
    cout << "Welcome to UMBC Friend Finder" << endl;
    cout << "*****************************" << endl;
    m_me = Person();
    m_organization = Organization();
    Start();
}
// Name: GetDetails
// Desc - Asks user for their first name, last name, age, and ID to populate m_me
// Preconditions - None
// Postconditions - Populates information related to m_me
void FriendFinder::GetDetails(){
    string fName = "", lName = "";
    int age = 0, ID = 0;
    while (fName == "" && lName == "" && age == 0 && ID == 0){
        cout << "What is your first name?" << endl;
        cin >> fName;
        cout << "What is your last name?" << endl;
        cin >> lName;
        cout << "What is your age?" << endl;
        cin >> age;
        cout << "What is your ID?" << endl;
        cin >> ID;
    }
    m_me = Person(fName, lName, age, ID);
    m_organization.SetName();
    m_organization.LoadRoster();
    
}
// Name: DisplayMenu
// Desc - Displays main menu for application
// Preconditions - None
// Postconditions - Called from Start updates integer passed
void FriendFinder::DisplayMenu(int &choice){
    
    while (choice < 1 || choice > 5){
        cout << "What would you like to do?" << endl;
        cout << "1. Display Entire Organization" << endl;
        cout << "2. Display Friend List" << endl;
        cout << "3. Search for a Friend" << endl;
        cout << "4. Remove Friend" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
    }
}

// Name: Start
// Desc - Main function running FriendFinder
//        Calls GetDetails
//        Populates data for organization
//        Continually calls DisplayMenu until someone enters 4 (exit)
// Preconditions - m_me and m_organization are created but not populated
// Postconditions - Runs until user enters 4. Thanks user for usage. Ends application
void FriendFinder::Start(){
    int choice = 0;
    bool quit = false;
    GetDetails();
    Person* new_friend;
    
    while (choice != 5){
        DisplayMenu(choice);
        switch(choice){
            case 1:
                
                m_organization.DisplayRoster();
                break;
                
            case 2:
                
                m_me.DisplayFriends();
                break;
                
            case 3:
                
                new_friend = m_organization.GetPerson();
                m_me.AddFriend(new_friend);
                break;

            case 4:
                m_me.RemoveFriend();
                break;
                
            case 5:
                quit = true;
                break;
                
        }
        
    }
    
    
}
