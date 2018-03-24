#include "TText.h"
#include <Windows.h>
#include <conio.h>

void clrscr(void);
void clreol(void);
void gotoxy(int x, int y);

TMem TLink::mem;
int LinkCount = 100;

int main() {
	TLink::InitMem(LinkCount);

	char fileName[] = "C:\\Users\\User\\Documents\\GitHub projects\\Lab6-Text\\Source.txt";
	TText text;
	char s;
	char buf[80];

	cout << "i - info\n";

	while(true){
		SetColor(ConsoleColor::LightGreen, ConsoleColor::Black);
		cout << "user: ";
		SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
		s = _getch();
		cout << s << endl;
		
		switch (s) {
		case 'i': cout << "r - read\np - print\ns - save\nc - copy\nq - quit\ne - clear\nf - print free\na - go to previous link\nz - go to next link\nx - " << 
						  "go to down link\n1 - insert next line\n2 - insert next section\n3 - insert down line\n4 - insert down section\n" << 
						  "5 - delete next link\n6 - delete down link\n"; break;
		case 'r': text.Read(fileName); break;
		case 'p': text.Print(); break;
		case 's': text.Save("C:\\Users\\User\\Documents\\GitHub projects\\Lab6-Text\\SavedText.txt"); break;
		//case 'c': TText tmp; tmp.Save("C:\\Users\\User\\Documents\\GitHub projects\\Lab6-Text\\Copy.txt"); break;
		case 'e': clrscr(); cout << "i - info\n"; break;
		case 'f': TLink::PrintFree(); break;
		case 'q': TLink::MemClear(text); exit(0);
		case 'a': text.GoPrevLink(); text.Print(); break;
		case 'z': text.GoNextLink(); text.Print(); break;
		case 'x': text.GoDownLink(); text.Print(); break;
		case '1': cout << "Enter your line: "; cin >> buf; text.InsNextLine(buf); text.Print(); break;
		case '2': cout << "Enter your line: "; cin >> buf; text.InsNextSection(buf); text.Print(); break;
		case '3': cout << "Enter your line: "; cin >> buf; text.InsDownLine(buf); text.Print(); break;
		case '4': cout << "Enter your line: "; cin >> buf; text.InsDownSection(buf); text.Print(); break;
		case '5': text.DelNext(); text.Print(); break;
		case '6': text.DelDown(); text.Print(); break;
		default: cout << "Input error\n";
		}
	}

	return 0;
}




void clrscr(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console) return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	DWORD Count;

	COORD zpos;
	zpos.X = 0;
	zpos.Y = 0;

	FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X * buf.dwSize.Y, zpos, &Count);
	SetConsoleCursorPosition(Console, zpos);
}

void clreol(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	WORD Attr;
	DWORD Count;

	COORD zpos = buf.dwCursorPosition;

	zpos.X = buf.dwCursorPosition.X + 1;
	zpos.Y = buf.dwCursorPosition.Y;

	FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X - buf.dwCursorPosition.X - 1, zpos, &Count);
	SetConsoleCursorPosition(Console, buf.dwCursorPosition);
}

void gotoxy(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)return;

	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(Console, pos);
}
