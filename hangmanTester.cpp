/*
* Author: William L. Baar
* Date: 3/13/2020
* Sources used: None
* Known bugs: None
*/
#include "Words.h"
#include "Player.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int main(){
  //display menu
  cout << "1. Play" << endl;
  cout << "2. Score" << endl;
  cout << "3. Exit" << endl;
  cout << "Please select an option: ";
  int choice; //store users choice
  Player p1;
  cin >> choice;
  while(choice!=3) // type 3 to exit
  {
    //if user selects 1, play a game of Hang Man!
    if(choice==1){
      Words w1("words.txt"); //start game

      /*
      *Keep track of whether a letter has already been guessed.
      *Use char array of the alphabet which maps to an int array of ints 0-25.
      *Increment each element of int array once a letter is guessed.
      */
      char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Char comparison array.
      int letterCount[26] = {0}; //an array to count each letter occurrence. a is in index 0, b in 1, c in 2, etc.
      int size = sizeof(letterCount) / sizeof(letterCount[0]); //calculate size of array

      string secretWord = w1.getRandomWord(); //generate a secret word for winning condition
      int wordLen = secretWord.length()-1;
      char userWord[wordLen]; //create a char array to store user guesses and _'s

      //display _’s for each letter of the selected word.
      for(int i=0; i<wordLen;i++){
        userWord[i] = '_';
        cout << userWord[i] << " ";
      }
      cout << endl;


      bool win = false; //kill loop if player wins
      int chances = 0; //the user has 7 chances to guess the right word.
      while(chances < 7 && !win)
      {
        //play the game
        char select;
        cout << "Please select a character: " << endl;
        cin >> select;

        //check if letter has already been guessed.
        bool alreadyGuessed = false;
        for(int i = 0; i<size; i++){
          if(select==alphabet[i]){
            if(letterCount[i]!=0){
              alreadyGuessed = true;
              break;
            }
          }
        }

        //check if letter entered matches a letter of secret word
        bool flag = false;
        for(int i=0; i<wordLen;i++){
          if(secretWord[i]==select){ //check if letter matches
            flag = true;
            userWord[i]=select; //insert letter
          }
        }

        //display the appropriate response to user.
        if(alreadyGuessed){ //letter was already guessed
          cout << "You already entered this word." << endl;
        }
        else if(!flag){ //letter is not in word
          chances++; //increment chance counter
          cout << "The letter is not in the word. You have this many guesses left: " << (7-chances) << endl;
        }
        else{ //letter was in word.
          cout << "The letter is in the word!" << endl;
          for(int i = 0; i<wordLen;i++){
            cout << userWord[i] << " "; //display updated user char array.
          }
          cout << endl;
        }
        //check if player has won.
        bool checkWin = true;
        for(int i = 0; i<wordLen; i++){
          if(secretWord[i]!=userWord[i]){ //compare each letter of user char array to secret word.
            checkWin = false;
            break;
          }
        }

        //check if user won, so loop can be killed
        if(checkWin){
          win=true;
        }
        //add letter to a list of guessed letters.
        for(int i = 0; i<size; i++){
          if(select==alphabet[i]){
            letterCount[i]++;
            break;
          }
        }
      }
      cout << endl;

      //check if user won or lost
      if(!win){
        cout << "You lost!" << endl;
        p1.lose(); //increment the player loss score in Player object.
      }
      else{
        cout << "Congrats! You win." << endl;
        p1.win(); //increment the player win score in Player object.
      }
      cout << endl;
      //display menu again.
      cout << "1. Play" << endl;
      cout << "2. Score" << endl;
      cout << "3. Exit" << endl;
      cout << "Please select an option: ";
      cin >> choice;
    }
    //if user chooses choice 2, display the number of wins and losses he/she has.
    else if(choice==2){
      int win = p1.getScore1(); //from Player object
      int lose = p1.getScore2(); //from Player object
      cout << endl;
      cout << "Wins: " << win << endl;
      cout << "Losses: " << lose << endl;
      cout << endl;

      //display menu
      cout << "1. Play" << endl;
      cout << "2. Score" << endl;
      cout << "3. Exit" << endl;
      cout << "Please select an option: ";
      cin >> choice;
    }
    //choice selected is invalid.
    else{
      cout << endl;
      cout << "Enter a valid choice: " << endl;
      cout << endl;
      cout << "1. Play" << endl;
      cout << "2. Score" << endl;
      cout << "3. Exit" << endl;
      cout << "Please select an option: ";
      cin >> choice;
    }
  }
}
