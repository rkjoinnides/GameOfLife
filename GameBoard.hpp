#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
#include <unistd.h>

#include "TerminalRenderer.hpp"

using std::vector;
using std::cout;
using std::string;
using std::unique_ptr;

class GameBoard
{
    private:

        //Game state variables
        vector<vector<char>> current_board;
        vector<vector<char>> next_board;
        int width;
        int height;
        char dead_char;
        unique_ptr<TerminalRenderer> rendering_engine;

        //Game functions
        void CreateRandomGameBoard();
        void AdvanceBoardState();

        //Helper functions
        bool IsInBounds(int targetRow, int targetColumn);
        int LivingNeighbors(int row, int column);
        void PrintBoard();
        
    
    public:
        GameBoard(int inputWidth, int inputHeight);
        ~GameBoard();
        void PlayGame(int simulation_steps);
};

#endif