/*****************************************
** File: Zombie.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Zombie (intermediate) class
** child class of Enitity
*****************************************/
#include "Zombie.h"

// Zombie() - Default Constructor
// Used to populate child zombie class data
Zombie::Zombie(): Entity() {

}
// Zombie - Overloaded Constructor
// Used to populate child class data
Zombie::Zombie(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// Attack()
// Returns damage and prints out statement 
int Zombie::Attack() {
  cout << GetName() << " deals 1 point of damage!" << endl;
  return 1; //Every zombie's generic attack does 1 damage
}
