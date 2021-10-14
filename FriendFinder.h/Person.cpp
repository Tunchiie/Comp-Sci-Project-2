//
//  Person.cpp
//  FriendFinder.h
//
//  Created by Adetunji Fasiku on 13/10/2021.
//

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Person
// Desc - Default Constructor for a Person
// Preconditions - Creates a Person with no data associated with it
// Postconditions - a Person is created
Person::Person(){
    m_fName = "";
    m_lName = "";
    m_age = 0;
    m_ID = 0;
    m_friendCount = 0;
    for (int i = 0; i < MAX_FRIENDS; i++){
      m_friends[i] = nullptr;
    }
}

// Name: Person
// Desc - Overloaded Constructor for a Person
// Preconditions - Creates a Person with passed data
// Postconditions - a Person is created
Person::Person(string fName, string lName, int age, int ID){
    m_fName = fName;
    m_lName = lName;
    m_age = age;
    m_friendCount = 0;
    m_ID = ID;
    for (int i = 0; i < MAX_FRIENDS; i++){
      m_friends[i] = nullptr;
    }
}
// Name: AddFriend
// Desc - A person pointer is stored from the roster of people in an organizati\
on
// Preconditions - A person pointer is passed
// Postconditions - A person pointer is added to this person's m_friend's array
//                  if not at maximum and not already in the array
void Person::AddFriend(Person* new_friend){
    if (m_friendCount < MAX_FRIENDS){
        m_friends[m_friendCount] = new_friend;
        m_friendCount++;
    }
    else{
        cout << "Friend list already full" << endl;
    }
}
// Name: RemoveFriend
// Desc - Removes a person pointer from this person's m_friend array
// Preconditions - Person pointer exists in m_friend
// Postconditions - Person is removed from m_friend and all pointers are moved \
towards front
void Person::RemoveFriend(){
    int choice = 0;
    DisplayFriends();
    while (choice < 1 || choice > m_friendCount){
        cout << "Who would you like to remove?" << endl;
        cin >> choice;
    }
    m_friends[(choice - 1)] = nullptr;
    m_friendCount--;
    
}
// Name: CheckID
// Desc - Checks to see if a specific person ID exists in m_friends - Note: IDs will always be unique in proj2
// Preconditions - m_friends is populated
// Postconditions - Returns true if id exists in m_friends else false
bool Person::CheckID(int ID){
    int index = 0;
    while (index < m_friendCount){
        if (m_friends[index]->m_ID == ID){
            return true;
        }
    }
    
    return false;
}

// Name: DisplayFriends
// Desc - Displays information about each friend in the m_friend array
// Preconditions - People are in the m_friend array
// Postconditions - Displays information about person object in array
void Person::DisplayFriends(){
    if (m_friendCount == 0)
        cout << "You don't have any friends yet" << endl;
    else{
        cout << "Friend List for " << m_fName << endl;
        for (int i = 0; i < MAX_FRIENDS; i++){
            if (m_friends[(i - 1)] != nullptr){
                cout << i << ". ";
                m_friends[i]->DisplayDetails();
                cout << endl;
            }
        }
    }
}
// Name: DisplayDetails
// Desc - Displays information about this person
// Preconditions - Person data is populated
// Postconditions - Displays information about person object
void Person::DisplayDetails(){
    if (m_fName == ""){
        cout << "No such person exists" << endl;
    }
    
    else{
        cout << m_fName << " " << m_lName << "(" << m_age << " yrs) " << m_ID <\
        < endl;
    }
}
// Name: SetDetails
// Desc - Used as a setter for first name, last name, age, and id
// Preconditions - Person already created
// Postconditions - Member variables populated
void Person::SetDetails(string fName, string lName, int age, int ID){
    m_fName = fName;
    m_lName = lName;
    m_age = age;
    m_ID = ID;
}



