/*****************************************
** File: Engineer.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Engineer class
** child class of Zombie
*****************************************/
#include "Engineer.h"

// Engineer() - Default Constructor
// Can create a engineer
Engineer::Engineer() {
  SetName("Engineer");
  SetHealth(5);
}
// Engineer - Overloaded Constructor
// Can create a engineer
Engineer::Engineer(string name, int health): Zombie(name, health) {

}

// SpecialAttack
// Returns damage from special attack
int Engineer::SpecialAttack() {
  int special = 2; //initalizes Engineer special attack damage as 4
  cout << GetName() << " blasts you with their steam blaster!" << endl;
  return special;
}
