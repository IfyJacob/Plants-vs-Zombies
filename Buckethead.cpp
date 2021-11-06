/*****************************************
** File: Buckethead.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Buckethead class
** child class of Zombie
*****************************************/
#include "Buckethead.h"

// Buckethead() - Default Constructor
// Can create a buckethead
Buckethead::Buckethead() {
  SetName("Buckethead");
  SetHealth(7);
}

// Buckethead - Overloaded Constructor
// Can create a buckethead
Buckethead::Buckethead(string name, int health): Zombie(name, health) {

}

// SpecialAttack
// Returns damage from special attack
int Buckethead::SpecialAttack() {
  int special = 1; // initialzies Buckethead speical as 1
  cout << GetName() << " throws its bucket at you!" << endl;
  return special;
}
