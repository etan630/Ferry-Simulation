#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "status.h"
#include "queue.h"

void clear_keyboard_buffer(void);
//get total number of cases
void getCases(int* cases);
//get ferry size and cars
void get_Ferry_Cars(int* lengthFerry, int* numCars);
//get car length and side
void car_information(int* carSize, char* userBank);
//get which side car is on
Status carSide(char* userBank);
//compare strings
Boolean compareStrings(char string1[], char string2[]);
//assign side to bank
Status assignSide(char* userBank, Bank* side);
//get total amount ferry crosses
int crossings(QUEUE leftBank, QUEUE rightBank, int sizeOfFerry);

#endif /* functions_h */
