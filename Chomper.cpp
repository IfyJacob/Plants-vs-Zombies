/*****************************************
** File: Chomper.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Chomper class
** child class of Plant
*****************************************/
#include "Chomper.h"

// Chomper() - Default Constructor
// Can create a chomper
Chomper::Chomper() {
  SetName("Chomper");
  SetHealth(12);
}
// Chomper - Overloaded Constructor
// Can create a chomper
Chomper::Chomper(string name, int health):  Plant(name, health) {

}
// ~Chomper - Virtual Destructor
// Every Chomper dynamically allocated is deallocated
Chomper::~Chomper() {
  SetName("");
  SetHealth(0);
}
// SpecialAttack
// Returns damage from special attack
int Chomper::SpecialAttack() {
  int randNum = (rand() % (12 - 1) + 2); // Generates random number between 2-12
  cout << GetName() << " performs sneak attack! CHOMP!" << endl;
  cout << GetName()<< " deals " << randNum << " damage!" << endl;
  return randNum;
}
