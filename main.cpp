#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
using namespace std;

int randomnum(int arr_length){ // generates a random number to pick a item from array randomly
    srand(time(0));
    int num = rand() % arr_length;
    return num;
}

void displayitem(char str[50],char cguess = ' '){   // Takes a string and breaks it up and only shows the vowels and correct guesses
    cout << "\n";
    for(int i=0; str[i] != '\0' ;i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == cguess || str[i] == toupper(cguess)){
            cout <<' ' << str[i] << ' ';
        }else if(str[i] == ' '){
            cout << "\t";
        }else{
            cout <<' ' << '_'<<' ';
        }
    }
    cout << "\n";
}

void counterfunc(int tries,char item[50]){    // responsible for giving chance to the players to enter their input and  also verifies the input
    char guess;
    int flag=0;
    for(int i=tries;i>0;i--){
        flag=0;
        cout << "\nEnter Your guess(a-z): ";
        cin >> guess;
        for(int i=0;item[i] != '\0';i++){
            if(guess == item[i] || guess == tolower(item[i]) || guess == toupper(item[i])){
                flag = 1;
            }
        }
        if(flag==1){
            cout << "Correct"<<endl;
            displayitem(item,guess);
            i++;
        }
        cout << "You have " << i-1 << " tries left\n";
    }
}

void countletters(char item[50]){
    int num;
    for(int i=0;item[i] !='\0';i++){
        num++;
    }
    cout << "\nThe total characters are "<<  num;
}



int main()
{
    int opt ,numtries=7;
    char item[50];
    char movies[][50] = {"Fight Club" ,"The Conjuring","Mission Impossible","The Matrix","The Godfather","The Dark Knight","Inception"};
    char sports[][50] = {"Cricket","Football","Basketball","Lawn Tennis","Hockey","Badminton","Volleyball","Kabadi","Squash"};
    char famper[][50] = {"Amitabh Bachchan","Sachin Tendulkar","Lata Mangeshkar","Roger Federer","APJ Abdul Kalam","Narendra Modi"};

    cout << "\t \t \t Welcome To Hangman\n";
    cout << "1)Movies\n2)SportS\n3)Famous Personalities\n";
    cout <<"Enter the number of your desired Field: "; // takes the choice of field
    cin >> opt;


    switch(opt){    // switches according to the choice of user
    case 1:
        strcpy(item,movies[randomnum(7)]);
        break;
    case 2:
        strcpy(item,sports[randomnum(9)]);
    case 3:
        strcpy(item,famper[randomnum(6)]);
        break;
    }
    countletters(item);
    cout << item;
    displayitem(item);
    cout << "\n" ;
    counterfunc(numtries,item);

}
