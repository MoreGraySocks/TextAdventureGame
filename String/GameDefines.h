#pragma once
#include "Point2D.h"

const char* const ESC = "\x1b";
const char* const CSI = "\x1b[";

const char* const INDENT = "\x1b[5C";
const char* const UNDERLINE = "\x1b[4m";
const char* const NO_UNDERLINE = "\x1b[24m";
const char* const RED = "\x1b[91m";
const char* const GREEN = "\x1b[92m";
const char* const YELLOW = "\x1b[93m";
const char* const BLUE = "\x1b[94m";
const char* const MAGENTA = "\x1b[95m";
const char* const CYAN = "\x1b[96m";
const char* const CYAN_ = "\x1b[36m"; //desaturated cyan
const char* const WHITE = "\x1b[97m";
const char* const BASE = "\x1b[37m"; //default text colour / desaturated white
const char* const RESET_COLOUR = "\x1b[0m";
const char* const RESET_CURSOR_POS = "\x1b[0;0H";

const Point2D EXIT = { 1,0 };
const Point2D POOL = { 0,1 };
const Point2D START = { 1,1 };
const Point2D OBSERVATORY = { 2,1 };
const Point2D KITCHEN = { 0,2 };
const Point2D PANTRY = { 0,3 };
const Point2D STUDY = { 2,2 };
const Point2D BEDROOM = { 2,3 };
const Point2D HALLWAY_NORTH = { 1,2 };
const Point2D HALLWAY_SOUTH = { 1,3 };

const int MAP_HEIGHT = 4;
const int MAP_WIDTH = 3;

const int NORTH = 8;
const int EAST = 6;
const int WEST = 4;
const int SOUTH = 2;

const int HELP = 1;          //shows a list of commands
const int FIND_SPELL = 3;    //used to find a certain spell (for assessment)

const int USE = 9;               //use and item from your inventory
const int PICKUP = 10;           //pick up an item from the room you are in
const int DROP = 11;             //drop an item 
const int LOOKAT = 12;           //get a description of things
const int TALK = 13;             //talk to the monster
const int INVENTORY = 14;        //view the items in your inventory
const int SPELLBOOK = 15;        //view the spells you have access to
const int HINT = 16;             //get a hint on where to go next
const int QUIT = 17;             //exits the game

const int TORCH = 20;
const int POTATO = 21;
const int MEAT = 22;
const int SOUP = 23;
const int FLAME = 24;



