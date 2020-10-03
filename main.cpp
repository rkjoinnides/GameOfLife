#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <cstring>

#include "GameBoard.hpp"
#include "TerminalRenderer.hpp"

using std::fstream;
using std::ofstream;
using std::string;

void MakeRandomGameBoard(int x, int y);
void TerminalPractice();
void color_printer();


int main()
{
    
    MakeRandomGameBoard(100, 100);
    GameBoard gb(15, 30);
    //gb.PlayGame(100);
    color_printer();
    //TerminalPractice();

    return 0;
}


void color_printer()
{
    initscr();
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);

    attron(COLOR_PAIR(1));
    printw("This should be printed in black with a red background!\n");

    attron(COLOR_PAIR(2));
    printw("And this in a green background!\n");
    refresh();

    getch();

    endwin();
}

void MakeRandomGameBoard(int width, int height)
{
    ofstream gameboard;
    gameboard.open("RandomGameBoard.txt");

    string output = "";

    srand(time(NULL));

    for(int h=0; h<height; h++)
    {
        for(int w=0; w<height; w++)
        {
            if (rand()%10+1 < 7)
            {
                output += "+";
            }
            else
            {
                output += " ";
            }
        }
        output+="\n";
    }
    gameboard<<output;
    gameboard.close();
}