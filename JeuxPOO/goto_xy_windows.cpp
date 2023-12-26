#include <windows.h>
#include "goto_xy_windows.h"

void goto_xy(int x, int y)
{
  HANDLE handle;
  COORD coordinates;
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(handle, coordinates);
}