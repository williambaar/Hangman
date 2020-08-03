/*
* Author: William L. Baar
* Date: 3/13/2020
* Sources used: None
* Known bugs: None
*/
#include "Words.h"
#include<iostream>
#include<vector>
#include<stdlib.h> //generate random integer
#include<fstream> //basic file operations
#include <time.h>       /* time */
using namespace std;


//constructor receives a file name to store words in vector
Words::Words(string fileName)
{
  myVec = new vector<string>();
  ifstream myFile;
  myFile.open(fileName); //Open file.
  myFile.seekg(0, ios::beg);//character by character.
  string line;
  while(getline(myFile, line)){ //Read the file line by line.
    myVec -> push_back(line); //Add each word to vector.
  }
  myFile.close(); //Close file.
  size = myVec -> size(); //update size
}

//copy constructor
Words::Words(const Words & other)
{
  myVec = new vector<string>();
  size = other.size; //copy size
  for(int i = 0; i<size; i++){ //copy each element of vector
    myVec -> push_back(other.myVec -> at(i));
  }
}

//default constructor
//the word "coronavirus" will be the secret word in this default game.
Words::Words()
{
  myVec = new vector<string>();
  myVec -> push_back("coronavirus");
  size = 1;
}

//destructor
Words::~Words()
{
  delete myVec;
}

//overload the = operator to produce a deep copy
Words Words::operator=(const Words & other)
{
  if(this!=&other){ //check that the Words objects aren't already the same.
    delete myVec; //deallocate vector
    myVec = new vector<string>(); //reallocate cleaned memory
    size = other.size; //copy size
    for(int i = 0; i<size; i++){ //store each string in copied vector
      myVec -> push_back(other.myVec -> at(i));
    }
  }
  return *this;
}

//get a random word from the vector
string Words::getRandomWord()
{
  srand (time(NULL)); //Initialize random seed
  int randomVal = rand() % size; //generate random number between 0 and size-1
  return myVec -> at(randomVal);
}
