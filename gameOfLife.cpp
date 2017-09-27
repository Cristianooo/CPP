//import the header file
#include <iostream>
#include <fstream>
#include <cmath>  
#include <random>
#include <algorithm>
    
    
#include "GameOfLifeHeader.h"   
using namespace std;
    
GameOfLife::GameOfLife()                //constructor 
{
    
}
GameOfLife::~GameOfLife()           //destructor
{
        
}
//generate board with null values
char** GameOfLife::setBoard(int height, int width, char gameType)
{
    char** gameBoard = new char*[height];
    for(int i = 0; i < height; ++i)
        gameBoard[i] = new char[width];
         
    for(int i=0; i<height; ++i)
    {
        for (int j=0; j<=width;++j)
        {
            gameBoard[i][j]=0;
        }
    }
    if(gameType=='r')  
        RandomDrawBoard(height, width, gameBoard);
    else if(gameType=='f')
        RegDrawBoard(height, width, gameBoard)  
}
//generate board with our needed values
void GameOfLife::RandomDrawBoard(int height, int width, char**& gameBoard, double popDens)
/*
Draws a random board based on the user's input for height, width, and population density.
*/
{
        
    for (int i=0;i<height;++i)
    {
        for (int j=0;i<width;++j)
        {   
            double randomNum=random();
            randomNum=randomNum/RAND_MAX;
            if(randomNum<=popDens)
                gameBoard[i][j]='X';
            else
                gameBoard[i][j]='-';        
        }
    }   
}
    
void GameOfLife::RegDrawBoard(string fileName)
/*
Creates a game board based on a text file given to the program by the user.
*/
{
    string line;
    ifstream infile(fileName + ".txt");
    int lineCount=0;
    char gameBoard[height][width];
    while (getline(infile,line))
    {   
        lineCount++;
        if(lineCount>2) 
        {
                
            for(int i=0; i<=height;++i)
            {
                for(int j=0; j<=width;++j)
                {
                    gameBoard[i][j]=line[i];
                }   
            }
        }
                
    }
}
void GameOfLife::classicMode(int height, int width, string gameType)
{
         
        
    for(int i=0;i<=height;++i)
    {
        for(int j=0;j<=width;++i)
        {
        int aliveCounter=0;
            if(i==0 && j==0)                //If statements for the corner indices
            {
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;             
            }   
            else if(i==height && j==0)
            {
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;     
            }
            else if(i==0 && j==width)
            {
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++; 
            }
            else if(i==height && j==width)
            {
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;                 
            }
                
            else if(i==0)               //If statements for the edge indices
            {
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
            }
            else if(i==height)
            {
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
            }
            else if(j==0)
            {
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;                 
            }
            else if(j==width)
            {
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;                         
            }
            else                        //If statements for any of the middle indices
            {
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
            }
            if(aliveCounter<=1)						//Checks to see which live and which die
                gameBoard[i][j]='-';
            else if(aliveCounter==3)
                gameBoard[i][j]='X';
            else if(aliveCounter>=4)
                gameBoard[i][j]='-';
        }
                
    }
        
}
void GameOfLife::doughnutMode(int height, int width, double popDens)
{
    char** gameBoard = new char*[height];
    for(int i = 0; i < height; ++i)
        gameBoard[i] = new char[width];
    for(int i=0;i<=height;i++)
    {
        for(int j=0;j<=width;j++)
        {
            int aliveCounter=0;
                
            if(i==0 && j==0)                    //If statements for the corner indices
            {
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][width]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][width]=='X')
                    aliveCounter++;
                if(gameBoard[height][j]=='X')
                    aliveCounter++;
                if(gameBoard[height][j+1]=='X')
                    aliveCounter++;
            }
            else if(i==0 && j==width)
            {
                if(gameBoard[i][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][width]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][width]=='X')
                    aliveCounter++;
                if(gameBoard[i][0]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][0]=='X')
                    aliveCounter++;
            }
            else if(i==height && j==0)
            {
                if(gameBoard[height][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[0][0]=='X')
                    aliveCounter++;
                if(gameBoard[0][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[height][width]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][width]=='X')
                    aliveCounter++;             
            }
            else if(i==height && j==width)
            {
                if(gameBoard[height][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][width]=='X')
                    aliveCounter++;
                if(gameBoard[height][0]=='X')
                    aliveCounter++;
                if(gameBoard[height-1][0]=='X')
                    aliveCounter++;
                if(gameBoard[0][width]=='X')
                    aliveCounter++;
                if(gameBoard[0][width-1]=='X')
                    aliveCounter++;
            }
            else if(i==0)                       //If statements for the edge indices
            {
                if(gameBoard[i+(height-1)][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+(height-1)][j]=='X')
                    aliveCounter++;
                if(gameBoard[i+(height-1)][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
            }
            else if(i==height)
            {
                if(gameBoard[i-(height-1)][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-(height-1)][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-(height-1)][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
            }
            else if(j==0)
            {
                if(gameBoard[i-1][j+(width-1)]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+(width-1)]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+(width-1)]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
            }
            else if(j==width)
            {
                if(gameBoard[i-1][j-(width-1)]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j-(width-1)]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-(width-1)]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;             
            }
                
            else                                //If statement for any of the middle indices
            {
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
            }
            if(aliveCounter<=1)						//Checks to see which live and which die
                gameBoard[i][j]='-';
            else if(aliveCounter==3)
                gameBoard[i][j]='X';
            else if(aliveCounter>=4)
                gameBoard[i][j]='-';
        }
    }
    
}
void GameOfLife::mirrorMode(int height, int width, double popDens)
{
    char** gameBoard = new char*[height];
    for(int i = 0; i < height; ++i)
        gameBoard[i] = new char[width];
         
    for(int i=0;i<=height;i++)
    {
        for(int j=0;j<=width;j++)
        {
            int aliveCounter=0;
            if(i==0 && j==0)
            {
                if(gameBoard[i+1][j]== 'X')         //If statements for the corner indices
                    aliveCounter++;
                if(gameBoard[i+1][j+1]== 'X')
                    aliveCounter++;
                if(gameBoard[i][j+1]== 'X')
                    aliveCounter++;
                if(gameBoard[i][width]== 'X')
                    aliveCounter++;
                if(gameBoard[i][width-1]== 'X')
                    aliveCounter++;
                if(gameBoard[i+1][width-1]== 'X')
                    aliveCounter++;
                if(gameBoard[i+1][width]== 'X')
                    aliveCounter++;
            }
            else if(i==0 && j==width)
            {
                if(gameBoard[i][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][width-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][width]=='X')
                    aliveCounter++;
                if(gameBoard[0][0]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-(width+2)]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-(width+2)]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][0]=='X')
                    aliveCounter++;
            }
            else if(i==height && j==0)
            {
                if(gameBoard[height-1][j]== 'X')
                    aliveCounter++; 
                if(gameBoard[height-1][j+1]== 'X')
                    aliveCounter++; 
                if(gameBoard[height][j+1]== 'X')
                    aliveCounter++;
                if(gameBoard[height][width]== 'X')
                    aliveCounter++;
                if(gameBoard[height][width-1]== 'X')
                    aliveCounter++;
                if(gameBoard[height-1][width-1]== 'X')
                    aliveCounter++;
                if(gameBoard[height-1][width]== 'X')
                    aliveCounter++;
            }
            else if(i==height && j==width)
            {
                if(gameBoard[i][width-1]== 'X')
                    aliveCounter++;
                if(gameBoard[i-1][width-1]== 'X')
                    aliveCounter++;
                if(gameBoard[i-1][width]== 'X')
                    aliveCounter++;
                if(gameBoard[height][0]== 'X')
                    aliveCounter++;
                if(gameBoard[height-1][0]== 'X')
                    aliveCounter++;
                if(gameBoard[height-1][j-(width+2)]== 'X')
                    aliveCounter++;
                if(gameBoard[height][j-(width+2)]== 'X')
                    aliveCounter++;
            }
            else if(i==0)                           //if statements for sides of indices
            {
                if(gameBoard[i][j-1]=='X')                      //Regular Indices to check
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                       
                if(j<width/2)                                    //Mirror Indices to check
                {  
                    if(gameBoard[i][j+(width-(j+1)-j)]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i][j+(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i][j+(width-(j)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+(width-(j+1)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+(width-(j)-j)]== 'X')
                        aliveCounter++;
                }   
                else if(j>width/2)
                {
                    if(gameBoard[i][j-(width-(j+1)-j)]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i][j-(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i][j-(width-(j)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+1][j-(width-(j+1)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+1][j-(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+1][j-(width-(j)-j)]== 'X')
                        aliveCounter++;             
                }
                else
                {													//Check the middle box of side
                    if(gameBoard[i][j-1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j-1]=='X')
                        aliveCounter++;
                    if(gameBoard[i][j-1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i][j+1]=='X')
                        aliveCounter++;
                }     
            }
            else if(j==0)                
            {
                if(gameBoard[i-1][j]=='X')                          //Regular Indices to check
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;  
     
                if(i<height/2)                                       //Mirror Indices to check
                {
                    if(gameBoard[i+(height-(i+1)-i)][j]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i+(height-(i+2)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i+1)-i)][j+1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i+2)-i)][j+1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i)-i)][j+1]== 'X')
                        aliveCounter++;
                }
                else if(i>height/2)
                {
                    if(gameBoard[i-(height-(i+1)-i)][j]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i-(height-(i+2)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i+1)-i)][j+1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i+2)-i)][j+1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i)-i)][j+1]== 'X')
                        aliveCounter++;
                }
                else
                {											//Check the middle box of side
                    if(gameBoard[i-1][j]=='X')                          
                        aliveCounter++;
                    if(gameBoard[i-1][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j]=='X')
                        aliveCounter++;
                }
            }
            else if(i==height)									
            {
            	if(gameBoard[i][j-1]=='X')					//Regular Indices to check	
                    aliveCounter++;
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                    
                if(j<width/2)                                    //Mirror Indices to check
                {  
                    if(gameBoard[i][j+(width-(j+1)-j)]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i][j+(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i][j+(width-(j)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-1][j+(width-(j+1)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-1][j+(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-1][j+(width-(j)-j)]== 'X')
                        aliveCounter++;
                }   
                else if(j>width/2)
                {
                    if(gameBoard[i][j-(width-(j+1)-j)]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i][j-(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i][j-(width-(j)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-1][j-(width-(j+1)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-1][j-(width-(j+2)-j)]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-1][j-(width-(j)-j)]== 'X')
                        aliveCounter++;             
                }
                else
                {												//Check the middle box of side
                    if(gameBoard[i][j-1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j-1]=='X')
                        aliveCounter++;
                    if(gameBoard[i][j-1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i][j+1]=='X')
                        aliveCounter++;
            }
            else if(j==width)
            {
            	if(gameBoard[i-1][j]=='X')						//Regular Indices to check	
                    aliveCounter++;
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;
                    
                if(i<height/2)                                       //Mirror Indices to check
                {
                    if(gameBoard[i+(height-(i+1)-i)][j]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i+(height-(i+2)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i+1)-i)][j-1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i+2)-i)][j-1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i+(height-(i)-i)][j-1]== 'X')
                        aliveCounter++;
                }
                else if(i>height/2)
                {
                    if(gameBoard[i-(height-(i+1)-i)][j]== 'X')       
                        aliveCounter++;
                    if(gameBoard[i-(height-(i+2)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i)-i)][j]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i+1)-i)][j-1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i+2)-i)][j-1]== 'X')
                        aliveCounter++;
                    if(gameBoard[i-(height-(i)-i)][j-1]== 'X')
                        aliveCounter++;
                }
                else
                {												//Check the middle box of side
                    if(gameBoard[i-1][j]=='X')                          
                        aliveCounter++;
                    if(gameBoard[i-1][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j+1]=='X')
                        aliveCounter++;
                    if(gameBoard[i+1][j]=='X')
                        aliveCounter++;  
            }
            else                        //If statements for any of the middle indices
            {
                if(gameBoard[i-1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i-1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j+1]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j]=='X')
                    aliveCounter++;
                if(gameBoard[i+1][j-1]=='X')
                    aliveCounter++;
                if(gameBoard[i][j-1]=='X')
                    aliveCounter++;
            }
            if(aliveCounter<=1)						//Checks to see which live and which die
                gameBoard[i][j]='-';
            else if(aliveCounter==3)
                gameBoard[i][j]='X';
            else if(aliveCounter>=4)
                gameBoard[i][j]='-';
            }
            
        }
    }
    
}
char GameOfLife::getGameMode()
{
    char mode;
    while (true)
    {
        cout << "There are three modes that you can play. /n Enter ‘c’ if you want to play in classic mode /n Enter ‘d’ if you want to play in doughnut mode /n Enter ‘m’ if you want to play in mirror mode" << endl;
        cin>> mode;
        mode= tolower(mode);
        if (mode =='c' || mode == 'd' || mode == 'm')
        {
            break;
        }
        else
            cout<< "Incorrect value! Please try again" << endl;
    }
        return mode;
}
void GameOfLife::ContinueOrOutput()
{
    char answer2; 
    cout << "If you want to continue the simulation press any key to continue except for 'o' /n If you want to output the information into a file enter 'o'"<< endl;
    cin >> answer2;
    if (answer2 == 'o')
    {
        string fileName;
        cout << "Please enter the fileName you want the file to use: " << endl;
        cin >> fileName;
        ofstream outfile(fileName);
    }
    else
    {
        cout<< "Please press enter to continue" << endl;
        cin.ignore();
        cin.get();
    }
}