/*****************************************
** File: Sunflower.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Sunflower class
** child class of Plant
*****************************************/
#include "Sunflower.h"

// Sunflower() - Default Constructor
// Can create a sunflower
Sunflower::Sunflower() {
  SetName("Sunflower");
  SetHealth(15);
}
// Sunflower - Overloaded Constructor
// Can create a sunflower
Sunflower::Sunflower(string name, int health):  Plant(name, health) {
  
}
// ~Sunflower - Virtual Destructor
// Every Sunflower dynamically allocated is deallocated
Sunflower::~Sunflower() {
  SetName("");
  SetHealth(0);
}
// SpecialAttack
// Returns damage from special attack
int Sunflower::SpecialAttack() {
  int randNum = (rand() % (8) + 1); // Generates random number between 1-8
  cout << GetName() << " uses a high beam turret- **SUNBEAM**" << endl;
  cout << GetName() << " deals " << randNum << " damage!" << endl;
  return randNum;
  
}
