/*****************************************
** File: Room.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Room class
*****************************************/
#include "Room.h"

// Room (Overloaded Constructor)
// Given valid room constructor inputs, Creates a new room
Room::Room(int id, string room, string desc, int north, int east, int south, int west) {
  m_ID = id;
  m_name = room;
  m_desc = desc;
  m_direction[0] = north; //sets north equal to 0 index
  m_direction[1] = east; //sets east equal to 1 index
  m_direction[2] = south; //sets south equal to 2 index
  m_direction[3] = west; //sets west equal to 3 index
}

// GetName
// Given a room exist, Returns room name as string
string Room::GetName() {
  return m_name;
}

// GetID
// Given a room exist, Returns room id as int
int Room::GetID() {
  return m_ID;
}

// GetDesc
// Given a room exist, Returns room desc as string
string Room::GetDesc() {
  return m_desc;
}

// CheckDirection
// Given a valid room and input, Returns id of room in that direction
// if the exit exists
int Room::CheckDirection(char myDirection) {

  //Condition if the user inputs an N or n
  if(myDirection == 'N' or myDirection == 'n') {
    if(m_direction[0] != -1) {
      m_ID = m_direction[0];
      return m_ID;
    }
    else
      return -1;
  }

  //Condition if the user enters an E or e
  if(myDirection == 'E' or myDirection == 'e') {
    if(m_direction[1] != -1) {
      m_ID = m_direction[1];
      return m_ID;
    }
    else
      return -1;
  }

  //Condition if the user enters a S or s
  if(myDirection == 'S' or myDirection == 's') {
    if(m_direction[2] != -1) {
      m_ID = m_direction[2];
      return m_ID;
    }
    else
      return -1;
  }

  //Condition if the user enters a W or w
  if(myDirection == 'W' or myDirection == 'w') {
    if(m_direction[3] != -1) {
      m_ID = m_direction[3];
      return m_ID;
    }
    else
      return -1;
  }
  return m_ID;
}

// PrintRoom
// Given a valid room, Outputs the room name, room desc, then possible exits
void Room::PrintRoom() {
  cout << m_name << endl;
  cout << m_desc << endl;
  cout << "Possible Exits: ";

  //Loops through the direction vector and finds the possible exits
  for(unsigned int i=0; i<4; i++) {
    //Conditional print out direction depending on its value
    if(m_direction[i] != -1) {
      if(i == 0)
	cout << "N";
      else if(i == 1)
	cout << "E";
      else if(i == 2)
	cout << "S";
      else if(i == 3)
	cout << "W";
    }
  }
  cout << endl;
}
