#include "../ConsoleCtrl.hpp"

using namespace Visualization::Console;

void Visualization::Console::PrintColors()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, (int)Color::Blue);
    std::cout << "Blue" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Green);
    std::cout << "Green" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Aqua);
    std::cout << "Aqua" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Red);
    std::cout << "Red" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Purple);
    std::cout << "Purple" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Yellow);
    std::cout << "Yellow" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::White);
    std::cout << "White" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Gray);
    std::cout << "Gray" << std::endl;

    SetConsoleTextAttribute(hConsole, (int)Color::Default);
}
void Visualization::Console::ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
	hStdOut,
	(TCHAR)' ',
	cellCount,
	homeCoords,
	&count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
	hStdOut,
	csbi.wAttributes,
	cellCount,
	homeCoords,
	&count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

void	Visualization::Console::print(Console::Symbol symbol)
{
    std::cout << symbol;
}
void	Visualization::Console::print(const Console::Identity& id)
{
    Visualization::Console::changeColor(id.getColor());
    Visualization::Console::print(id.getSymbol());
    Visualization::Console::changeColorDefault();
}

void Visualization::Console::moveCursor(const Engine::MapComponent::Ordinate& line, const Engine::MapComponent::Abscissa index)
//void Visualization::Console::moveCursor(int line, int index)
{
    int iline = static_cast<int>(line) + 1;
    int iindex = static_cast<int>(index) + 1;

    static HANDLE h_mvCursos = NULL;
    if (!h_mvCursos)
	h_mvCursos = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { (SHORT)iindex, (SHORT)iline };
    SetConsoleCursorPosition(h_mvCursos, c);
}
void Visualization::Console::moveCursor(const Engine::MapComponent::Location& loc)
{
    int line = (int)(loc.getOrdinate()) + 1;
    int index = (int)(loc.getAbscissa()) + 1;

    static HANDLE h_mvCursos = NULL;
    if (!h_mvCursos)
	h_mvCursos = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { (SHORT)(index), (SHORT)(line) };
    SetConsoleCursorPosition(h_mvCursos, c);
}
void	Visualization::Console::moveCursorDefault()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int height = (int) Game::Process::Controller::getMap()->getHeight();
    Visualization::Console::moveCursor((height + 1), (0));
}

void	Visualization::Console::changeColor(Visualization::Console::Color color)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (int)color);
}
void	Visualization::Console::changeColorDefault()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (int)Color::Default);
}
