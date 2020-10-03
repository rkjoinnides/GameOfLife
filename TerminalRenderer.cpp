#include "TerminalRenderer.hpp"


TerminalRenderer::TerminalRenderer(int width, int height)
{
    this->w = initscr();
}

void TerminalRenderer::PlaceChar(int column, int row, char character)
{
    mvaddch(row, column, character);
}

void TerminalRenderer::Draw()
{
    refresh();
}

TerminalRenderer::~TerminalRenderer()
{
    endwin();
}