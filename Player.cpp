/*
* Author: William L. Baar
* Date: 3/13/2020
* Sources used: None
* Known bugs: None
*/
#include "Player.h"
#include<iostream>

using namespace std;

//default constructor sets score to 0
Player::Player()
{
  score1 = 0;
  score2 = 0;
}

//get number of wins
int Player::getScore1() const
{
  return score1;
}

//get number of losses
int Player::getScore2() const
{
  return score2;
}

//increment score if game is won.
void Player::win()
{
  score1++;
}

void Player::lose()
{
  score2++;
}
