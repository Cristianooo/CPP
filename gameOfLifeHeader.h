#include <iostream>
using namespace std;

class GameOfLife
{
	private:
		int height;
		int width;
		double popDensity;
		string fileName;
	public:
		GameOfLife();
		~GameOfLife();
		string getFile();
		char** GameOfLife::setBoard(int height, int width, char gameType)
		void RandomDrawBoard(int height, int width, char**& gameBoard, double popDens);
		void RegDrawBoard(int height, int width, char**& gameBoard, string fileName);
		void classicMode(int height, int width, double popDens);
		void doughnutMode(int height, int width, double popDens);
		void mirrorMode(int height, int width, double popDens);
		char getGameMode();
		void ContinueOrOutput();

		
};
