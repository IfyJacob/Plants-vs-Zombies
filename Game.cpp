/*****************************************
** File: Game.cpp
** Project: CMSC 202 Project 4, Fall 2020
** Author: Ify Jacob
** Date: 11/12/20
** Section: 20/24
** E-mail: i23@gl.umbc.edu
** Description: cpp file for Game class
*****************************************/
#include "Game.h"

// Game() - Default Constructor
// After asking for a file name, loads map, creates char and starts.
Game::Game() {
  string file;
  cout << "What is the name of the file? ";
  cin >> file;
  LoadMap(file);  
  PlantCreation();
  StartGame();
}

// Game - Overloaded Constructor
// Uses filesname to LoadMap, calls createplant,
// and sets both numRests and m_numSpecial using constants.
Game::Game(string file) {
  cout << "Welcome to UMBC Adventure!" << endl;
  LoadMap(file);
  PlantCreation();
  StartGame();
}

// Name: ~Game
// Deallocates anything dynamically allocated in Game
Game::~Game() {
  for(unsigned int i=0; i<m_myMap.size(); i++) {
    delete m_myMap[i];
  }
  delete m_myPlant;
  delete m_curZombie;

  m_myPlant = nullptr;
  m_curZombie = nullptr;
}

// LoadMap
// Given a File contains map information, Map is populated with Room objects.
void Game::LoadMap(string file) {
  ifstream myFile; // initializes ifstream value 
  string ID; // initializes ID value
  string name; // initializes name value
  string desc; // initializes desc value
  string north; // initializes north value
  string east; // initializes east value
  string south; // initializes south value
  string west; // initializes west value

  myFile.open(file);

  //Loops until the end of file is reached
  while(!myFile.eof()) {
    getline(myFile, ID, '|');
    getline(myFile, name, '|');
    getline(myFile, desc, '|');
    getline(myFile, north, '|');
    getline(myFile, east, '|');
    getline(myFile, south, '|');
    getline(myFile, west, '|');

    //If the loop hasn't reached the end of file
    //dynamically creates new room
    if(!myFile.eof()) {
      int numID = stoi(ID);
      int northNum = stoi(north);
      int eastNum = stoi(east);
      int southNum = stoi(south);
      int westNum = stoi(west);

      //Creates new room and adds it to Map vector
      Room *room = new Room(numID, name, desc, northNum, eastNum, southNum, westNum);
      m_myMap.push_back(room);
    }
  }
  myFile.close();
}

// PlantCreation()
// m_myPlant is populated
void Game::PlantCreation() {
  string plantName; // initializes plant name
  int choice; // initializes input option

  cout << "Plant Name: ";
  cin >> plantName;

  cout << "Select a class" << endl;
  cout << "1. Peashooter" << endl;
  cout << "2. Chomper" << endl;
  cout << "3. Sunflower" << endl;
  cout << "4. No class" << endl;
  cin >> choice;

  // Loop occurs if there is an input error
  while(cin.fail() or choice > 4 or choice < 1) {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter a number (1-4):" << endl;
    cin >> choice;
  }
  cout << endl;

  //Condtitonals for each choice input scenario
  //Creates corresponding plant and populates m_myPlant
  if(choice == 1) {
    m_myPlant = new Peashooter(plantName, PEASHOOTER_HEALTH);
  }
  else if(choice == 2) {
     m_myPlant = new Chomper(plantName, CHOMPER_HEALTH);
  }
  else if(choice == 3) {
     m_myPlant = new Sunflower(plantName, SUNFLOWER_HEALTH);
  }
  else {
     m_myPlant = new Plant(plantName, PLANT_HEALTH);
  }
}

// StartGame()
// Given LoadMap and CharacterCreation must have been completed
// m_numRests, m_numSpecial and curRoom populated and action called
void Game::StartGame() {
  m_curRoom = START_ROOM; // sets curRoom to START_ROOM (0)
  m_numRests = NUM_RESTS; // sets numRests to NUM_REST (1)
  m_numSpecial = NUM_SPECIAL; // sets numspecial to NUM_SPECIAL (3)

  m_myMap.at(m_curRoom)->PrintRoom(); // calls room class PrintRoom function
  
  m_curZombie = RandomZombie(); // calls RandomZombie() and sets it equal to Entity

  // Conditional to check if a zombie exist or not
  if(m_curZombie != nullptr) {

    // Series of conditionals that which zombie was made and prints info
    if(m_curZombie->GetName() == "Engineer")
      cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER." << endl;
    else if(m_curZombie->GetName() == "Buckethead")
      cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
    else if(m_curZombie->GetName() == "Imp")
      cout << "A dirty imp licks his lips and glares at you." << endl;
  }
  
  // Conditional if zombie is nullptr
  else
    cout << "It is peaceful here." << endl;

  cout << endl;
  Action(); // After start game is finish calls Action
}

// Action()
// Given that StartGame() is complete, Runs game until quit or player dies
void Game::Action() {
  int action = 0; // initialzies action value as 0

  // Loop runs until user quits or the play HP drops below 0
  while(action != 6 and m_myPlant->GetHealth() > 0) {
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Zombie" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    cin >> action;

    // Loop occurs if there is an input error
    while(cin.fail() or action > 6 or action < 1) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a number (1-6):" << endl;
      cin >> action;
    }

    // Series of conditonals depending on what action was taken
    // Calls certain function depending on the action
    if(action == 1) {
      cout << endl;
      
      //Same code from StartGame()
      m_myMap.at(m_curRoom)->PrintRoom();
      if(m_curZombie != nullptr) {
	if(m_curZombie->GetName() == "Engineer")
	  cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER."<< endl;
	else if(m_curZombie->GetName() == "Buckethead")
	  cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
	else if(m_curZombie->GetName() == "Imp")
	  cout << "A dirty imp licks his lips and glares at you." << endl;
      }
      else
	cout << "It is peaceful here." << endl;
      cout << endl;
    }  
    
    else if(action == 2) {
      Move(); // calls move function 
      cout << endl;
      
      //Same code from StartGame()
      m_myMap.at(m_curRoom)->PrintRoom();
      if(m_curZombie != nullptr) {
	if(m_curZombie->GetName() == "Engineer")
	  cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER." << endl;
	else if(m_curZombie->GetName() == "Buckethead")
	  cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
	else if(m_curZombie->GetName() == "Imp")
	  cout << "A dirty imp licks his lips and glares at you." << endl;
      }
      else
	cout << "It is peaceful here." << endl;
      cout << endl;
    }

    else if(action == 3)
      Attack(); // calls Attack function
      
    else if(action == 4)
      Rest(); // calls Rest function
    
    else if(action == 5)
      Stats(); // calls Stats function
  }
  cout << "Good bye!" << endl;
}

// RandomZombie()
// Given an entity pointer to hold zombie child
// Returns object of type Buckethead, Imp, or Engineer
Entity* Game::RandomZombie() {
  int randNum = (rand() % (4) + 1); // Generates a random number 1-4
  Entity* newZombie; // initializes an entity pointer

  // Series of conditional that are dependent on the random number
  // Will create one of the following: Buckethead, Imp, or Engineer, or nullptr
  if(randNum == 1) {
    newZombie = new Buckethead("Buckethead", BUCKETHEAD_HEALTH);
    return newZombie;
  }
  else if(randNum == 2) {
    newZombie = new Engineer("Engineer", ENGINEER_HEALTH);
    return newZombie;
  }
  else if(randNum == 3) {
    newZombie = new Imp("Imp", IMP_HEALTH);
    return newZombie;
  }
  else {
    return nullptr;
  }
}

// Name: Rest
// Given a valid room with no zombies (room must exist) and have rests
// Reduces available rests by one and increases hp by 10 REST_HEAL
void Game::Rest() {
  
  // Conditional ensures zombie pointer is nullptr
  if(m_curZombie != nullptr) {
    cout << "You cannot rest with a zombie in the room!" << endl;
  }
  else {
    
    // Conditional that allows user to rest if they have rests
    if(m_numRests > 0) {
      int restHP = m_myPlant->GetHealth() + REST_HEAL; // adds 10 HP to user
      m_myPlant->SetHealth(restHP); 
      m_numRests -= 1; // reduces number of rests
      m_numSpecial = NUM_SPECIAL; // resets number of sepcials
      cout << "You rest and wake up refreshed." << endl;
    }
    else {
      cout << "You cannot rest anymore!" << endl;
    }
  }
}

// Move
// Given a valid move (room must exist)
// Displays room information, checks for new zombie (deletes old)
void Game::Move() {
  char direction; // initializes direction char value
  
  cout << "Which direction? (N E S W)" << endl;
  cin >> direction;

  
  // Condition occurs if there is an input error or one of the valid inputs (N,n,E,e,S,s,W,w) are not entered
  if(cin.fail() || (direction !='N' && direction !='n' && direction !='e' && direction !='E' && direction !='s' && direction !='S' && direction !='w' && direction !='W')) {

    // Loops occurs if there is an input error or one of the valid inputs (N,n,E,e,S,s,W,w) are not entered 
    while(cin.fail() || (direction !='N' && direction !='n' && direction !='e' && direction !='E' && direction !='s' && direction !='S' && direction !='w' && direction !='W')) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Which direction? (N E S W)" << endl;
      cin >> direction;
    }
  }
  
  int move = m_myMap.at(m_curRoom)->CheckDirection(direction); // sets move to return of current rooms CheckDirection value

  // Condition if Checkdiretion returns a -1 value 
  if(move == -1) {
    cout << "That's a dead end!" << endl;
    m_curRoom = m_curRoom; // curRoom does not change
    m_myMap.at(m_curRoom); // user put in the same room 
    m_myMap.at(m_curRoom)->PrintRoom(); 
    Move(); // recalls move so user can try to move to a different room
  }


  // Condition that move was valid and not a dead end which moves player
  else {
    m_curRoom = move; // sets curRoom equal to new room value
    m_myMap.at(m_curRoom); // puts the index into m_Mymap
    delete m_curZombie; // deletes the zombie
    m_curZombie = nullptr;
    m_curZombie = RandomZombie(); // creates a new zombie
    return; // ends function
  }
}

// Attack
// Given an enemy zombie is in the room
// Indicates who wins and updates health(hp) as battle continues.
void Game::Attack() {

  // Conditional makes there is a zombie in the room
  if(m_curZombie != nullptr) {

    // Loops continues until the battle ends (plant or zombie hp drops to 0)
    while(m_myPlant->GetHealth() > 0 and m_curZombie->GetHealth() > 0) {
      int attack = 0; // initializes attack input value
      int plantAttack = 0; // initializes plantAttack value
      int zombieAttack = 0; // inntializes zombieAttack value

      cout << endl;
      cout << "1. Normal Attack" << endl;
      cout << "2. Special Attack" << endl;
      cin >> attack;

      // Loop occurs if user inputs invalid data type or value
      while(cin.fail() or attack > 2  or attack < 1) {
	cin.clear();
	cin.ignore(256, '\n');
	cout << "Enter either 1 or 2:" << endl;
	cin >> attack;
      }

      // Series of Conditionals depending on what attack the user chooses to use
      if(attack == 2) {

	// Checks to see if user still has special moves left
	if(m_numSpecial > 0) {
	  plantAttack = m_myPlant->SpecialAttack();
	  m_numSpecial -= 1;
	}

	// User has no specials and loses an attack turn
	else {
	  cout << "You have no speical attacks remaining!" << endl;
	  plantAttack = 0;
	}
      }

      // User chooses to use a normal attack
      else {
	plantAttack = m_myPlant->Attack();
      }

      // I kept having a problem with zombie and plant health becoming 100 when they go below zero
      // I made HP variables for plants and zombies to work around this problem

      int zombieHP = m_curZombie->GetHealth() - plantAttack; // intializes zombie HP value

      // Conditional checks if zombieHp is still above 0 if so calls SetHealth
      if(zombieHP > 0)
	m_curZombie->SetHealth(zombieHP);

      // Condition that zombie has no more health 
      else
	m_curZombie->SetHealth(0);

      int randNum = (rand() % (4) + 1); // Generates a random number between 1-4

      // Condtionals determine what type of attack zombie will use if 1 than its a special attack
      // Anything else is a normal attack
      if(randNum == 1) {
	zombieAttack = m_curZombie->SpecialAttack();
      }
      else {
	zombieAttack = m_curZombie->Attack();
      }

      int plantHP = m_myPlant->GetHealth() - zombieAttack; // initializes plant Hp value

      // Checks whether plant health is above 0 after zombie attack
      if(plantHP > 0) 
	m_myPlant->SetHealth(plantHP);

      // If plant HP below 1 than user HP set to zero
      else
	m_myPlant->SetHealth(0);

      // Conditional prints battle info if both parties have HP above 0
      if(m_myPlant->GetHealth() > 0 and m_curZombie->GetHealth() > 0) {
	cout << m_myPlant->GetName() << " Health: " << m_myPlant->GetHealth() << endl;
	cout << m_curZombie->GetName() << " Health: " << m_curZombie->GetHealth() << endl;
      }

      // Conditional if zombie's HP is below 1
      if(m_curZombie->GetHealth() <= 0) {
	cout << "You have defeated the " << m_curZombie->GetName() << endl;
      }

      // Conditional if user's HP is below 1
      if(m_myPlant->GetHealth() <= 0) {
	cout << "You have run out of health! Gameover!" << endl;
      }
      cout << endl;
    }
  }

  // Condition runs if m_CurZombie = nullptr
  else {
    cout << "There are no zombies to attack the room is empty!" << endl;
  }

  // Conditon runs if the zombie isn't already nullptr after the battle ends
  if(m_curZombie != nullptr) {
    
    // If the zombie's HP is lower than 0 the zombie is deaalocated
    if(m_curZombie->GetHealth() <= 0) {
      delete m_curZombie;
      m_curZombie = nullptr;
    }
  }
}

// Stats()
// Prints out users stats
void Game::Stats() {
  cout << endl;
  cout << "Name: " << m_myPlant->GetName() << endl;
  cout << "HP: " << m_myPlant->GetHealth() << endl;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
  cout << endl;
}
