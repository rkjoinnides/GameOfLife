#include "GameBoard.hpp"

GameBoard::GameBoard(int inputWidth, int inputHeight)
{
    this->width = inputWidth;
    this->height = inputHeight;
    this->CreateRandomGameBoard();
    this->rendering_engine = unique_ptr<TerminalRenderer>(new TerminalRenderer(this->width, this->height));
}   


void GameBoard::PlayGame(int simulation_steps)
{

    for (int i=0; i<simulation_steps;++i)
    {
        AdvanceBoardState();
        PrintBoard();
        sleep(1);
    }
}

void GameBoard::CreateRandomGameBoard()
{
    srand(time(NULL));

    char val;

    for(int h=0; h<this->height; h++)
    {
        this->current_board.push_back(vector<char>());
        this->next_board.push_back(vector<char>());

        for(int w=0; w<this->width; w++)
        {
            if (rand()%10+1 < 7)
            {
                val = '+';
            }
            else
            {
                val = ' ';
            }

            this->current_board[h].push_back(val);
            this->next_board[h].push_back(val);
        }
    }
}

void GameBoard::AdvanceBoardState()
{

    int living_neighbors;

    vector<vector<char>>::iterator rItr;
    vector<char>::iterator cItr;

    for(int i=0; i<(int)this->current_board.size();++i)
    {
        for (int j=0; j<(int)this->current_board[i].size();++j)
        {
            living_neighbors = this->LivingNeighbors(i, j);
            
            //cell is alive
            if(current_board[i][j] != ' ')
            {
                if (living_neighbors < 2)
                {
                    next_board[i][j] = ' '; 
                }
                else if(living_neighbors == 2 || living_neighbors == 3)
                {
                    next_board[i][j] = '+';
                }
                else
                {
                    next_board[i][j] = ' ';
                }
            }

            //cell is dead
            else
            {
                if (living_neighbors == 3)
                {
                    next_board[i][j] = '+';
                }
            }
        }
    }

    for(int i=0; i<(int)this->current_board.size();++i)
    {
        for (int j=0; j<(int)this->current_board[i].size();++j)
        {
            this->current_board[i][j] = this->next_board[i][j];
        }
    } 
}

bool GameBoard::IsInBounds(int targetRow, int targetColumn)
{
    bool in_bounds = true;
    
    bool row_in_bounds = (targetRow < this->height-1 && targetRow > 0);
    bool column_in_bounds = (targetColumn < this->width-1 && targetColumn > 0);
    
    if (!row_in_bounds || !column_in_bounds )
    {
        in_bounds = false;
    } 

    return in_bounds;
}

int GameBoard::LivingNeighbors(int row, int column)
{
    int living_neighbors = 0;
    for(int i=-1; i<2; ++i)
    {
        for (int j=-1; j<2; ++j)
        {
            if (this->IsInBounds(row+i, column+j) && !(i == 0 && j == 0))
            {
                if (this->current_board[row+i][column+j] != ' ')
                {
                    living_neighbors += 1;
                }
            }
        }
    }
    
    return living_neighbors;
}

void GameBoard::PrintBoard()
{
    for(int i=0; i<(int)this->current_board.size(); ++i)
    {
        for(int j=0; j<(int)this->current_board[i].size(); ++j)
        {
            rendering_engine->PlaceChar(i, j, this->current_board[i][j]);
            // if(this->current_board[i][j] != this->next_board[i][j])
            // {
            //     rendering_engine->PlaceChar(i, j, this->next_board[i][j]);
            // }
        }
    }
    rendering_engine->Draw();

    // string output = "";
    // for(int i=0; i<(int)this->current_board.size(); ++i)
    // {
    //     for(int j=0; j<(int)this->current_board[i].size(); ++j)
    //     {
    //         output += current_board[i][j];
    //     }
    //     output += "\n";
    // }
    // cout << output;
}

GameBoard::~GameBoard()
{
    this->rendering_engine.release();
}