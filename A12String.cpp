/* 
 * File:   A12String.cpp
 * Author: omkar
 *
 * Created on October 28, 2018, 6:55 PM
 */

/** Write C++ program for string operations- copy, concatenate, check substring, equal, reverse  and length */
#include<iostream>
#define SIZE 50
using namespace std;

class String{

public:
    int findLength(char[]);
    void copyString(char[] );
    void reverseString(char[] ,int);
    void equalString(char[],char[]);
    void stringConcatenate(char[],char[]);
    void substring(char [],char []);
    
};

int String :: findLength(char str[]){
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    
    return count;
}

void String :: copyString(char str[] ){
    int i = 0;
    char strCopy[SIZE];
    while(str[i] != '\0'){
        strCopy[i] = str[i];
        i++;
    }strCopy[i] = '\0';
    cout<<"The Copied string is "<<strCopy<<endl;
}

void String :: reverseString(char ptr[],int len){
   
    char strReverse[SIZE];
    int i;
    int j = 0;
    for(i = len-1; i >=0;--i){
        strReverse[j] = ptr[i];
        j++;
    }strReverse[j] = '\0';
    cout<<"Reverse string of '"<<ptr<<"' is "<<strReverse<<endl;
}

void String :: equalString(char str1[], char str2[]){
    int count = 0;
    int len1 = findLength(str1);
    int len2 = findLength(str2);
    if(len1 == len2){
        for(int i = 0; str1[i] != '\0'; ++i){
            if(str1[i] == str2[i]){
                count++;
            } 
        }
        if(count == len1){
            cout<<"Strings are equal.\n";
        }else{
            cout<<"Strings are not equal.\n";
        }
    }else{
        cout<<"Strings are not equal.\n";
    }
    
}
 void String :: stringConcatenate(char str1[],char str2[]){
     int len1 = findLength(str1);
     for(int i = 0; str2[i] != '\0'; ++i){
         str1[len1] = str2[i];
         len1++;
     }str1[len1] = '\0';
     cout<<"The concatenated string is "<<str1<<endl;
 }
 void String :: substring(char str[],char sub[]){
     int i =0;
     int j= 0;
     while(str[i] != '\0' && sub[j] != '\0'){
         if(str[i] != sub[j]){
             i = i-j;
             i++;
             j = 0;
         }else{
             i++;
             j++;
         }
     }
     if(sub[j] == '\0'){
         cout<<"Substring Present\n";
     }else{
         cout<<"Substring not Present\n";
     }
 }

int main(){
    String obj;
    int count1;
    int count2;
    char string1[SIZE];
     char string2[SIZE];
     
     cout<<"Enter the first String:  ";
     cin>>string1;
     //cin.getline(string1, SIZE ,'\n');
          
     cout<<"Enter the Second String:  ";
     cin>>string2;
     //cin.getline(string2, SIZE ,'\n');
     
     count1 = obj.findLength(string1);
     cout<<"Length of the string '"<<string1<<"'"<<" is "<<count1<<endl;
    count2=  obj.findLength(string2);
    cout<<"Length of the string '"<<string2<<"'"<<" is "<<count2<<endl;
     
     obj.copyString(string1);
     obj.copyString(string2);
     
     obj.reverseString(string1, count1);
     obj.reverseString(string2, count2);
     
     obj.equalString(string1,string2);
     
     //obj.stringConcatenate(string1,string2);
     
     obj.substring(string1,string2);
     
     obj.stringConcatenate(string1,string2);
}