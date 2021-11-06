/*****************************************
** File: Entity.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Entity class
** Purely virtual Parent class
*****************************************/
#include "Entity.h"

// Entity() - Default Constructor
// Populates variables used in child classes (not specifically used)
Entity::Entity() {
  m_name = "Entity";
  m_health = 100;
}

// Entity - Overloaded Constructor
// Populates variables used in child classes
Entity::Entity(string name, int health) {
  m_name = name;
  m_health = health;
}

// ~Entity - Virtual Destructor
// Overall destructor that makes sure everything dynamically allocated is deallocated
Entity::~Entity() {
  m_name = "";
  m_health = 0;
}
// GetName()
// Given that an Entity exist, Returns name of Entity
string Entity::GetName() {
  return m_name;
}
// GetHealth()
// Given an Entity has health, Return health of Entity
int Entity::GetHealth() {
  return m_health;
}

// SetName()
// Given that an Entity exist, sets name of Entity
void Entity::SetName(string name) {
  m_name = name;
}
// SetHealth()
// Given that an Entity exist, sets health of Entity
void Entity::SetHealth(int health) {
  if(health < 0)
    m_health = 100;
  else
    m_health = health;
}

// Overloaded <<
// Given that all variables are set valid
// returns an ostream with output of entity
ostream& operator<<(ostream& output, Entity& entity) {
  output << "Name: " << entity.GetName() << "Health: " << entity.GetHealth() << endl;
  return output;
}
