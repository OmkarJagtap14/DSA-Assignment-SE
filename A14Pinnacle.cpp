/* 
 * File:   A14Pinnacle.cpp
 * Author: omkar
 *
 * Created on October 28, 2018, 7:15 AM
 */

/*Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of Second, third and final year of department can be granted membership on request.  
Similarly one may cancel the membership of club. 
First node is reserved for president of club and last node is reserved for secretary of club. 
Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to  
        a) Add and delete the members as well as president or even secretary. 
        b) Compute total number of members of club 
        c) Display members 
        d) Display list in reverse order using recursion 
        e) Two linked lists exists for two divisions. Concatenate two lists. */

#include<iostream>
#include<string>
using namespace std;

class PinnacleClub {
private:
    int prn;
    string name;
    PinnacleClub * start;
    PinnacleClub *next;

public:
    PinnacleClub();
    bool isEmpty();
    PinnacleClub * addPresident();
    void acceptDetails(PinnacleClub *);
    void addSecretary();
    void addMember();
    void displayClubMembers();
    bool secretaryExist();
    void countClubMembers();
    void delPresident();
    void delMember(int);
    void reverseList(PinnacleClub *);
    void printReverseList();
    void concatinateList();

} teComp;
;

PinnacleClub::PinnacleClub() {
    prn = 0;
    name.clear();
    start = NULL;
    next = NULL;
}

bool PinnacleClub::isEmpty() {
    return (start == NULL);
}

void PinnacleClub::acceptDetails(PinnacleClub * ptr) {
    cout << "Name: ";
    getline(cin, ptr->name);
    cout << "PRN : ";
    cin >> ptr->prn;
}

PinnacleClub * PinnacleClub::addPresident() {
    PinnacleClub * newPresident = new PinnacleClub();
    if (newPresident == NULL) {
        cerr << "\n\tMemory allocation has failed !\n";
        return 0;
    }

    acceptDetails(newPresident);
    start = newPresident;
    newPresident->next = NULL;
    return newPresident;
}

void PinnacleClub::addSecretary() {
    PinnacleClub * newSecretary = new PinnacleClub();
    if (newSecretary == NULL) {
        cerr << "\n\tMemory allocation has failed !\n";
        return;
    }

    acceptDetails(newSecretary);
    start->next = newSecretary;
    newSecretary->next = NULL;

}

void PinnacleClub::addMember() {
    PinnacleClub * temp = start;

    PinnacleClub * newMember = new PinnacleClub();
    if (newMember == NULL) {
        cerr << "\n\tMemory allocation has failed !\n";
        return;
    }
    cout << "Enter the Details of Member:\n";
    acceptDetails(newMember);

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    newMember->next = temp->next;
    temp->next = newMember;

}

void PinnacleClub::countClubMembers() {
    if (isEmpty()) {
        cerr << "\n\tPinnacle Club has no Member !\n\n";
        return;
    }
    PinnacleClub * temp = start;
    size_t memberCounter = 0;
    cout << "Total Members in Pinnacle Club = ";


    while (temp != NULL) {
        memberCounter++;
        temp = temp->next;
    }
    cout << memberCounter << endl;
}

bool PinnacleClub::secretaryExist() {
    return (start->next != NULL);
}

void PinnacleClub::displayClubMembers() {
    PinnacleClub * temp = start;

    if (isEmpty()) {
        cerr << "\n\tPinnacle Club has no Member !\n\n";
        return;
    }

    cout << "Members of Pinnacle Club\n";
    cout << "Name    \t PRN\n";

    while (temp != NULL) {
        cout << temp->name;
        cout << "    \t" << temp->prn << endl;
        temp = temp->next;
    }
}

void PinnacleClub::delPresident() {
   
    PinnacleClub * free = start;
    PinnacleClub * temp = start->next;
    delete free;
    cout << "President has been Deleted. \n"
            << "But Club Cannot exist without the President...So add new President\n";
    PinnacleClub * newPresident = addPresident();
    newPresident->next = temp;

}

void PinnacleClub::delMember(int num) {
      if (isEmpty()) {
        cerr << "\n\tPinnacle Club has no Member !\n\n";
        return;
    }
    PinnacleClub * temp = start;
    PinnacleClub * temp1 = start;
    PinnacleClub * free;
    if (start->prn == num) {
        delPresident();
    } else {
        while (temp != NULL) {
            if (temp->prn == num) {
                break;
            }
            temp = temp->next;
        }

        while (temp1->next != temp) {
            temp1 = temp1->next;
        }
        if (temp == NULL) {
            cerr << "\n\tMember with given PRN not found!\n\n";
        } else {
            cout << "Member has been Deleted.";
            free = temp;
            temp1->next = temp->next;
            delete free;
        }
    }
}

void PinnacleClub::printReverseList() {
      if (isEmpty()) {
        cerr << "\n\tPinnacle Club has no Member !\n\n";
        return;
    }
    reverseList(start);
}

void PinnacleClub::reverseList(PinnacleClub * temp) {

    if (temp->next != NULL) {
        reverseList(temp->next);
    }
    cout << "Name: " << temp->name;
    cout << "   \tPRN: " << temp->prn << endl;
}

void PinnacleClub::concatinateList() {
    PinnacleClub * temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = teComp.start;
    cout << "Concatenated list is:\n:";
    displayClubMembers();
}

int main() {
    PinnacleClub seComp;

    int choice;
    int prn;

    do {
        cout << "\t\t*****Pinnacle Club*****\n"
                << "\t\t1] Add Member in club.\n"
                << "\t\t2] Display Member of club.\n"
                << "\t\t3] Count Member in club.\n"
                << "\t\t4] Delete Member of club.\n"
                << "\t\t5] Print Reverse .\n"
                << "\t\t6] Concatenate two list.\n"
                << "\t\t7] Exit \n"
                << "\t\tEnter the choice :";
        cin>>choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (seComp.isEmpty()) {
                    cout << "Enter the Details of President:\n";
                    seComp.addPresident();
                } else if (!seComp.secretaryExist()) {

                    cout << "Enter the Details of Secretary:\n";
                    seComp.addSecretary();
                } else {
                    seComp.addMember();
                }
                break;

            case 2:
                seComp.displayClubMembers();
                break;

            case 3:
                seComp.countClubMembers();
                break;

            case 4:
                cout << "Enter the PRN of Member to delete: ";
                cin>>prn;
                cin.ignore();
                seComp.delMember(prn);
                break;
            case 5:
                cout << "Reverse list of Members:\n";
                seComp.printReverseList();
                break;
            case 6:
                char ch;
                cout << "First we need to create List for other Division\n";
                
                   teComp.addPresident();
                seComp.concatinateList();
                break;

            case 7:
                cout << "\n\t*****Thank you for visiting Pinnacle Club*****\n\n";
        }

    } while (choice != 7);
}
