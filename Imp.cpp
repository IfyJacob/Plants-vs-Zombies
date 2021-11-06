/*****************************************
** File: Imp.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Imp class
** child class of Zombie
*****************************************/
#include "Imp.h"

// Imp() - Default Constructor
// Can create an imp
Imp::Imp() {
  SetName("Imp");
  SetHealth(10);
}

// Imp - Overloaded Constructor
// Can create an imp
Imp::Imp(string name, int health): Zombie(name, health) {

}

// SpecialAttack
// Returns damage from special attack
int Imp::SpecialAttack() {
  int special = 4; //initializes special value as 4 for Imp
  cout << GetName() << " blasts you with their Impkata attack!" << endl;
  return special;
}
