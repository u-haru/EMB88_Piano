#include "Notes.h"
const PROGMEM unsigned char track1[][2]={{G5,12},{0,6},{G5,6},{E5,12},{C5,12},{A5,11},{0,1},{A5,12},{G5,12},{0,12},{F5,11},{0,1},{F5,12},{E5,12},{D5,6},{C5,6},{D5,12},{0,36},{G5,17},{0,1},{G5,6},{E5,12},{C5,12},{A5,11},{0,1},{A5,12},{G5,18},{0,6},{F5,11},{0,1},{F5,12},{E5,12},{D5,6},{C5,6},{D5,42},{0,6},{E5,17},{0,1},{E5,6},{D5,12},{C5,12},{F5,11},{0,1},{F5,12},{D5,18},{0,6},{E5,12},{G5,12},{B5,12},{A5,12},{G5,42},{0,6},{C6,12},{C5,6},{C6,6},{B5,12},{A5,12},{G5,12},{E5,12},{A5,18},{0,6},{G5,11},{0,1},{G5,12},{E5,12},{C5,12},{D5,42},{0,6},{E5,5},{0,1},{E5,12},{D5,6},{C5,12},{E5,6},{G5,6},{C6,24},{A5,18},{0,6},{G5,17},{0,1},{G5,5},{0,1},{G5,12},{E5,6},{D5,6},{C5,42},{0,6},{D5,9},{0,1},{D5,1},{0,1},{D5,5},{0,1},{D5,5},{0,1},{D5,6},{E5,6},{F5,12},{E5,10},{F5,2},{G5,6},{A5,6},{G5,12},{0,12},{E5,10},{G5,1},{0,1},{G5,5},{0,1},{G5,5},{0,1},{G5,10},{A5,1},{0,1},{A5,5},{0,1},{A5,6},{B5,10},{C6,2},{B5,6},{A5,6},{B5,18},{0,6},{C6,17},{0,1},{C6,5},{0,1},{C6,11},{0,1},{C6,12},{D6,12},{C6,12},{G5,18},{0,6},{A5,17},{0,1},{A5,6},{C6,12},{B5,6},{A5,6},{G5,42},{0,6},{E5,24},{D5,24},{C5,10},{D5,2},{E5,6},{F5,6},{G5,18},{0,6},{A5,9},{0,1},{A5,1},{0,1},{A5,5},{0,1},{A5,6},{B5,12},{D6,12},{C6,48}};
const PROGMEM unsigned char track2[][2]={{C4,12},{G4,12},{C4,12},{G4,12},{C4,12},{A4,12},{C4,12},{G4,12},{C4,12},{F4,12},{C4,12},{E4,12},{C4,12},{G4,12},{F4,12},{D4,12},{C4,12},{G4,12},{C4,12},{G4,12},{C4,12},{A4,12},{C4,12},{G4,12},{C4,12},{F4,12},{C4,12},{E4,12},{B3,12},{G4,12},{D4,12},{B3,12},{C4,12},{E4,12},{C4,12},{E4,12},{C4,12},{F4,12},{B3,12},{E4,12},{C4,12},{G4,12},{C4,12},{G4,12},{C4,12},{G4,12},{A4,12},{G4,12},{F4S,12},{0,12},{D4,12},{A4,12},{G4,12},{B4,12},{C4,12},{E4,12},{D4,12},{G4,12},{C4,12},{E4,12},{B3,12},{G4,12},{F4,12},{D4,12},{C4,12},{G4,12},{C4,12},{G4,12},{F4,12},{C5,12},{F4,12},{C5,12},{C4,12},{G4,12},{D4,12},{F4,12},{E4,12},{D4,12},{C4,12},{E4,12},{D4,11},{0,1},{D4,11},{0,1},{D4,11},{0,1},{D4,12},{E4,11},{0,1},{E4,11},{0,1},{E4,11},{0,1},{E4,12},{D4,11},{0,1},{D4,11},{0,1},{D4,11},{0,1},{D4,12},{F4,11},{0,1},{F4,12},{G4,6},{F4,6},{D4,12},{D4S,6},{G4,6},{A4,6},{G4,6},{E4,6},{G4,6},{A4,6},{G4,6},{F4,6},{A4,6},{C5,6},{A4,6},{G4,6},{F4,6},{E4,12},{F4,6},{A4,6},{C5,6},{A4,6},{F4,6},{A4,6},{F4,6},{C4,6},{B3,6},{D4,6},{G4,6},{F4,6},{E4,6},{D4,6},{C4,11},{0,1},{C4,12},{E4,12},{B3,12},{F4,12},{C4,12},{G4,12},{E4,12},{G4,12},{F4,12},{C5,12},{D5,12},{F5,12},{C5,12},{G3,12},{C4,24}};

#define spd 24
#define ncmax 300
// #define fwaon
#define tc 2
unsigned char vols[tc]={100,50};