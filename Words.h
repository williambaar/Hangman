/*
* Author: William L. Baar
* Date: 3/13/2020
* Sources used: None
* Known bugs: None
*/
#pragma once
#include<iostream>
#include<vector>
#include<fstream> //basic file operations
using namespace std;

class Words
{
private:
  vector<string> *myVec;
  int size;
public:
  Words(string fileName); //constructor
  ~Words(); //destructor
  Words(); //default constructor will push back the word "Coronavirus" everytime.
  string getRandomWord(); //select random word for game.
  Words operator=(const Words & other); //overload = operator
  Words(const Words & other); //copy constructor
};
