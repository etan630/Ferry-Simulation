/*
 THOUGHT PROCESS FOR SOLVING:
 1) ask user how many test cases they want
 2) take in 2 integers, l: length of ferry and m: number of cars want to test
 3) convert length of ferry into centimeters
 4) given the length of car and bank of car -- it will be easier to assign right and left to 1 and 0 for testing
 4) create a num for amt of times ferry has to cross: add one depending on if next car is opposite of left or right OR add TWO if ferry is too small and next car is on same side as previous -- will need to think of a way on how to stores these numbers to output at the end
 5) initizlize starting position on left
 6) initialize left and right sides as empty in beginning
 7) how to load cars
        a) depending on where ferry is, load as many cars as possible onto ferry (whether if finished or if have to leave early bc of length)
        b) once switch direction, update ferry position
 */


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "functions.h"

int main(int argc,  char *argv[])
{
    
    int cases;
    int ferryLength;
    int carCases;
    int carSize;
    char bank[10];
    int num;
    Bank side;
    
    //get cases
    getCases(&cases);
    
    int results[cases];
    
    //iterate until finish with total of cases
    for (int iterator = 0; iterator < cases; iterator++)
    {
        //creating left side and right side
        QUEUE leftBank = queue_init_default();
        QUEUE rightBank = queue_init_default();
        
        
        //getting ferry length and num of cars for that case
        get_Ferry_Cars(&ferryLength, &carCases);
        //convert to centimeters
        ferryLength *= 100;
        
        
        //iterate until finish cars within that case
        for (int iterator2 = 0; iterator2 < carCases; iterator2++)
        {
            //getting length of car and side its on
            car_information(&carSize, bank);
            
            //setting side to left or right
            assignSide(bank, &side);
            
            //putting car to left or right bank
            if(side == LEFT)
            {
                queue_enqueue(leftBank, carSize);
            }
            else
            {
                queue_enqueue(rightBank, carSize);
            }
        }
        
        //count num of times ferry crosses
        num = crossings(leftBank, rightBank, ferryLength);
        //putting num into array to print at the end
        results[iterator] = num;
        
        //destroy queues
        queue_destroy(&leftBank);
        queue_destroy(&rightBank);
        
    }
    
    //print out all of the crossings
    for(int x = 0; x < cases; x++)
    {
        printf("Number of crosses for test case %d: %d\n", x+1, results[x]);
    }
    
    return 0;
}


