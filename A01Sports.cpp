
/*  In Second year Computer Engineering class of M students, 
 * set A of students play cricket and set B of students play badminton. 
 * Write C/C++ program to find and display- 
 * i. Set of students who play either cricket or  badminton or both 
 * ii. Set of students who play both cricket and badminton  
 * iii.Set of students who play only cricket  
 * iv.Set of students who play only badminton  
 * v. Number of students who play neither cricket nor badminton      
 * (Note- While realizing the set duplicate entries are to avoided) */

#include<iostream>
#include<cstdlib>
#define SIZE 80
using namespace std;

class Sports {
private:
    size_t totalCricketPlayers;
    size_t totalBadmintonPlayers;
    size_t crickStudRollNo[SIZE];
    size_t BadStudRollNo[SIZE];
    size_t countBoth;


public:
    Sports();
    bool isNumberValid(size_t, size_t);
    int cricketPlayingStud(size_t);
    int badmintonPlayingStud(size_t);
    void const displayCrickAndBatStud();
    void const studPlayingBoth();
    void const studPlayingOnlyCrick();
    void const studPlayingOnlyBad();
    void const notPlayingSport(size_t);

};

Sports :: Sports(){
     totalCricketPlayers = 0;
     totalBadmintonPlayers = 0;
     crickStudRollNo[SIZE] = 0;
     BadStudRollNo[SIZE] = 0;
     countBoth = 0;
}
bool Sports::isNumberValid(size_t checkNumber, size_t totalStudents) {
    return (checkNumber >= 0 && checkNumber <= totalStudents);
}

int Sports::cricketPlayingStud(size_t totalStudents) {
    size_t playerCounter = 0;
    cout << "Enter the Total number of students playing Cricket: ";
    cin>>totalCricketPlayers;


    if (!isNumberValid(totalCricketPlayers, totalStudents)) {
        cerr << "\n\tTotal number of students playing Cricket can't be negative or greater than " << totalStudents << endl << endl;
        abort();
    }

    for (size_t i = 0; i < totalCricketPlayers; ++i) {
        cout << "Enter the roll number of Cricket player No " << ++playerCounter << " : ";
        cin >> crickStudRollNo[i];

        if (!isNumberValid(crickStudRollNo[i], totalStudents)) {
            cerr << "\n\tRoll Number can't be negative or greater than " << totalStudents << endl << endl;
            abort();
        }
    }
    cout << endl;
}

int Sports::badmintonPlayingStud(size_t totalStudents) {
    size_t playerCounter = 0;

    cout << "Enter the Total number of students playing Badminton: ";
    cin>>totalBadmintonPlayers;

    if (!isNumberValid(totalBadmintonPlayers, totalStudents)) {
        cerr << "\n\tTotal number of students playing Badminton can't be negative or greater than " << totalStudents << endl << endl;
        abort();
    }

    for (size_t i = 0; i < totalBadmintonPlayers; ++i) {
        cout << "Enter the roll number of Badminton player No " << ++playerCounter << " : ";
        cin >> BadStudRollNo[i];

        if (!isNumberValid(BadStudRollNo[i], totalStudents)) {
            cerr << "\n\tRoll Number can't be negative or greater than " << totalStudents << endl << endl;
          abort();
        }
    }
    cout << endl;
}

void const Sports::displayCrickAndBatStud() {
    cout << "Set of Students Playing Cricket :\t [ ";
    for (size_t i = 0; i < totalCricketPlayers; ++i) {
        cout << crickStudRollNo[i] << ",";
    }
    cout << "\b ]" << endl;

    cout << "Set of Students Playing Badminton :\t [ ";
    for (size_t i = 0; i < totalBadmintonPlayers; ++i) {
        cout << BadStudRollNo[i] << ",";
    }
    cout << "\b ]" << endl;
}

void const Sports::studPlayingBoth() {
    cout << "Set of Students playing Both  : \t[";
    for (int i = 0; i < totalCricketPlayers; ++i) {
        for (int j = 0; j < totalBadmintonPlayers; ++j) {
            if (crickStudRollNo[i] == BadStudRollNo[j]) {
                countBoth++;
                cout << crickStudRollNo[i] << ",";
                break;
            }
        }
    }
    cout << "\b ]" << endl;
}

void const Sports :: studPlayingOnlyCrick() {
    int found; 
    cout << "Set of Students playing only Cricket : \t[";
    for (int i = 0; i < totalCricketPlayers; ++i) {
        found = 0;
        for (int j = 0; j < totalBadmintonPlayers; ++j) {
            if (crickStudRollNo[i] == BadStudRollNo[j]) {
                found = 1;
                break;
                
            }
        }
        if (found == 0) {
            cout << crickStudRollNo[i] << ",";
        }
    }
    cout << "\b ]" << endl;
}
void const Sports :: studPlayingOnlyBad(){
     int found;
    cout << "Set of Students playing only Badminton : \t[";
    for (int i = 0; i < totalBadmintonPlayers; ++i) {
         found = 0;
        for (int j = 0; j < totalCricketPlayers; ++j) {
            if (crickStudRollNo[j] == BadStudRollNo[i]) {
                found = 1;
                break;
                
            }
        }
        if (found == 0) {
            cout << BadStudRollNo[i] << ",";
        }
    }
    cout << "\b ]" << endl;
}

void const Sports :: notPlayingSport(size_t totalStudents){
    cout<<"Number of students who play neither cricket nor badminton : ";
    cout<<totalStudents - (totalCricketPlayers + totalBadmintonPlayers - countBoth)<<endl;
}
int main() {

    size_t totalStudents;
    Sports seStudents;

    cout << "Enter The Total number of students in SE Comp: ";
    cin>>totalStudents;
    cout << endl;

    seStudents.cricketPlayingStud(totalStudents);
    seStudents.badmintonPlayingStud(totalStudents);
    seStudents.displayCrickAndBatStud();
    seStudents.studPlayingBoth();
    seStudents.studPlayingOnlyCrick();
    seStudents.studPlayingOnlyBad();
    seStudents.notPlayingSport(totalStudents);
}

