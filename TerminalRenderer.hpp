#ifndef TERMINALRENDERER_HPP
#define TERMINALRENDERER_HPP

#include <ncurses.h>

class TerminalRenderer
{

    private:
        WINDOW * w;

    public:
        TerminalRenderer(int width, int height);
        ~TerminalRenderer(); 
        void PlaceChar(int column, int row, char character);
        void Draw();
};

#endif
