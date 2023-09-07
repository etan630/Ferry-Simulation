#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

//keyboard buffer
void clear_keyboard_buffer(void)
{
    char c;
    int noc;
    do
    {
        noc = scanf("%c", &c);
    } while(noc == 1 && c!='\n');
}


//get total number of cases
void getCases(int* cases)
{
    //get initial case
    scanf("%d", cases);
    
    //results in error if there are negative case numbers
    while (cases < 0)
    {
        printf("Enter a valid number of cases\n");
        clear_keyboard_buffer();
        scanf("%d", cases);
    }
}


//get ferry size and cars
void get_Ferry_Cars(int* lengthFerry, int* numCars)
{
    //get initial length and cars
    scanf("%d %d", lengthFerry, numCars);
    
    //results in error if there are 0 or negative numbers
    while(lengthFerry <= 0 || numCars <= 0)
    {
        printf("Enter a valid number of cases\n");
        clear_keyboard_buffer();
        scanf("%d %d", lengthFerry, numCars);
    }
}


//get car length and side
void car_information(int* carSize, char* userBank)
{
    //get initial car size and bank
    scanf("%d %s", carSize, userBank);
    
    //results in error if there are invalid inputs
    while(carSize <= 0 || carSide(userBank) == FAILURE)
    {
        printf("Please enter a car size greater than 0 and 'left' or 'right'\n");
        scanf("%d %s", carSize, userBank);
        clear_keyboard_buffer();
    }
}


//get which side car is on
Status carSide(char* userBank)
{
    //accepts lowercase or uppercase for bank side
    char left[] = "left";
    char right[] = "right";
    char LEFT1[] = "LEFT";
    char RIGHT1[] = "RIGHT";
    
    //returns success if the banks entered by user are valid
    if(compareStrings(userBank, right) == TRUE || compareStrings(userBank, RIGHT1) == TRUE)
    {
        return SUCCESS;
    }
    
    else if(compareStrings(userBank, left) == TRUE || compareStrings(userBank, LEFT1) == TRUE)
    {
        return SUCCESS;
    }
    
    return FAILURE;
}

       
//compare strings
Boolean compareStrings(char string1[], char string2[])
{
    //basic implementation on how to compare strings without string.h
    int i = 0;
    while (string1[i] == string2[i])
    {
        if (string1[i] == '\0' || string2[i] == '\0')
        {
            break;
        }
        i++;
    }
    
    if (string1[i] == '\0' && string2[i] == '\0')
    {
        return TRUE;
    }
    
    return FALSE;
}


//assign side to bank
Status assignSide(char* userBank, Bank* side)
{
    char left[] = "left";
    char right[] = "right";
    char LEFT1[] = "LEFT";
    char RIGHT1[] = "RIGHT";
    
    //if user bank is right then assign that car to right
    if(compareStrings(userBank, right) == TRUE || compareStrings(userBank, RIGHT1) == TRUE)
    {
        *side = RIGHT;
        return SUCCESS;
    }
    
    
    //if user bank is left then assign that car to left
    if(compareStrings(userBank, left) == TRUE || compareStrings(userBank, LEFT1) == TRUE)
    {
        *side = LEFT;
        return FAILURE;
    }
    
    //return
    return FAILURE;
}

//get total amount ferry crosses
int crossings(QUEUE leftBank, QUEUE rightBank, int sizeOfFerry)
{
    //casting to known types
    Queue* pLeft = (Queue*) leftBank;
    Queue* pRight = (Queue*) rightBank;
    
    //starts at left bank every time
    Bank bank = LEFT;
    int crosses = 0;
    
    //length of car that is currently on ferry
    int carSum;
    
    //wants to iterate until either bank is empty because after car is on ferry we take it out of that bank
    while(!queue_is_empty(pLeft) || !queue_is_empty(pRight))
    {
        //set to 0 because once all of the cars are dropped off then crosses go up and car sum resets
        carSum = 0;
        
        //runs depending on which side the ferry is on
        if (bank == LEFT)
        {
            //if ferry is overloaded and had to cross even if there were still cars on that side, it will cross again because of queue_front
            while(carSum + queue_front(pLeft, NULL) <= sizeOfFerry && !queue_is_empty(pLeft))
            {
                carSum += queue_front(pLeft, NULL);
                queue_dequeue(pLeft);
            }
        }
        
        else if (bank == RIGHT)
        {
            while(carSum + queue_front(pRight, NULL) <= sizeOfFerry && !queue_is_empty(pRight))
            {
                carSum += queue_front(pRight, NULL);
                queue_dequeue(pRight);
            }
        }
        
        crosses++;
        //ferry goes to other side
        bank = !bank;
    }
    return crosses;
}

