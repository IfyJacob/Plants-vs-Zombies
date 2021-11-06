/*****************************************
** File: Plant.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Plant (intermediate) class
** child class of Enitity
*****************************************/
#include "Plant.h"

// Plant() - Default Constructor
// Can create a plant
Plant::Plant() {
  SetName("Plant");
  SetHealth(10);
}

// Plant - Overloaded constructor
// Can be used to populate plant or child classes
Plant::Plant(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// ~Plant - Virtual Destructor
// Everything dynamically allocated is deallocated
Plant::~Plant() {
  SetName("");
  SetHealth(0);
}

// Attack()
// Returns damage and prints out all info
int Plant::Attack() {
  int randNum = (rand() % (6) + 1); // gives a random number between 1-6 
  cout << GetName() << " attacks dealing " << randNum << " damage!" << endl;
  return randNum;
}

// SpecialAttack()
// May be used to call child class SpecialAttack
int Plant::SpecialAttack() {
  // Plant does not have a speical attack
  cout << "Plant does not have a special attack" << endl;
  return 0;
}

