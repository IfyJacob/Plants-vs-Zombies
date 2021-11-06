/*****************************************
** File: Peashooter.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Peashooter class
** child class of Plant
*****************************************/
#include "Peashooter.h"

// Peashooter() - Default Constructor
// Can create a peashooter
Peashooter::Peashooter() {
  SetName("Peashooter");
  SetHealth(10);
}
// Peashooter - Overloaded Constructor
// Can create a peashooter
Peashooter::Peashooter(string name, int health): Plant(name, health) {
  
}
// ~Peashooter - Virtual Destructor
// Every Peashooter dynamically allocated is deallocated
Peashooter::~Peashooter() {
  SetName("");
  SetHealth(0);
}
// SpecialAttack
// Returns damage from special attack
int Peashooter::SpecialAttack() {
  int randNum = (rand() % (12 - 2) + 3); // Generates random number between 3 - 12
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  cout << GetName() << " deals " << randNum << " damage!" << endl;
  return randNum; 
}
