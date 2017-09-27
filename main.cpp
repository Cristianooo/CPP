#include "GameOfLifeHeader.h"   
#include <iostream>
#include <fstream>        //be able to read in from a file and print into another file
#include <string>
#include <cmath> 
 
using namespace std;
 
int main (int argc, char** argv)
{
    cout<< "Welcome to the game of life!"<< endl;
     
    cout<<"The rules are: "<<endl;
    cout<< "1. A location that has one or fewer neighbors will be empty in the next generation. If a cell was in that location, it dies of loneliness."<<endl;
     
    cout<< "2. A location with two neighbors remains stable. If there was a cell, there’s still a cell. If it was empty, it’s still empty. "<< endl;
     
    cout<< "3. A location with three neighbors will contain a cell in the next generation. If it currently has a cell, the cell lives on. If it’s empty, a new cell is born." << endl;
     
    cout<< "4.A location with four or more neighbors will be empty in the next generation due to overcrowding." << endl;
     
    cout<< "Do you want to start with a random configuration, or provide a map for configuration?"<< endl;
     
 
    GameOfLife myLife;
    while (true)
    {
        cout<< "Enter 'r' for random and ‘f’  for a flatline and ’e’ to exit game" << endl;
        char configAnswer;
        cin>> configAnswer;
        configAnswer = tolower(configAnswer);
        if (configAnswer == 'r')
        {
            cout<< "Choose the random configuration" << endl;
            int height;
            int width;
            double popDens;
            cout<< "Please input the height: " << endl;
            cin>> height;
            cout<< "Please input the width: " << endl;
            cin>> width;
            cout << "Please input a number between 0-1 for the population density: " << endl;
            cin>> popDens;
             
            char gameMode=myLife.getGameMode();
            gameMode= tolower(gameMode);
            if(gameMode=='c')
            {
                cout<< "You choose to play the classic mode!"<< endl;
                myLife.classicMode(height, width, popDens);
                 
            }
            else if(gameMode=='d')
            {
                cout<< "You choose to play the doughnut mode!" << endl;
                myLife.doughnutMode(height, width, popDens);
            }
            else
            {
                cout<< "You choose to play the mirror mode!" << endl;
                myLife.mirrorMode(height, width, popDens);
            } 
 			break;
        } 
        else if(configAnswer=='f')
        {
            string line;
            int lineCount=0;
            int height;
            int width;
            string fileName;
            cout<< "Please input the file name: " << endl;
            cin>> fileName;
             
            ifstream infile(fileName + ".txt");
            while (getline(infile,line))
            {   
                lineCount++;
                if(lineCount==1)
                {
                    height=stoi(line);  
                }
                else if(lineCount==2)
                {
                    width=stoi(line);
                }
                else
                    break;  
            }
            break;
        }
        else if(configAnswer =='e')
        {
            break;
        } 
        else
            cout<< "Incorrect input /n Please try again" << endl; 
    }   
}