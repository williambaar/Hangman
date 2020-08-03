/*
* Author: William L. Baar
* Date: 3/13/2020
* Sources used: None
* Known bugs: None
*/
#pragma once
#include<iostream>
using namespace std;

class Player
{
private:
  int score1; //keep count of wins
  int score2; //keep count of losses
public:
  Player(); //default constructor sets score to 0
  int getScore1() const; //return number of wins
  int getScore2() const; //return number of losses
  void win(); //increment score1 when player wins.
  void lose(); //increment score2 when player loses
};
