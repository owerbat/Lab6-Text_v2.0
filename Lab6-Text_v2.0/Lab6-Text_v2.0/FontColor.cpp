#include "FontColor.h"

void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, (WORD)((background << 4) | text));
}