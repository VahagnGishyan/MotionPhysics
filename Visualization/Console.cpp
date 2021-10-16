#include "Console.hpp"

static void printBorderWall(int length)
{
    if (length <= 0)
	throw(std::exception("Visualization::Console::printBorderWall(...), arg length < 0"));
    length += 2;
    for (int index = 0; index < length; ++index)
	std::cout << '#';
    std::cout << std::endl;
}

void	Visualization::Console::import(Engine::MapComponent::Features& map)
{
    Game::Process::Controller::import(map);

    int length = (int)map.getLength();
    int height = (int)map.getHeight();

    Visualization::Console::ClearScreen();

    printBorderWall(length);

    for (int start = 0; start < height; ++start)
    {
	std::cout << '#';
	for (int index = 0; index < length; ++index)
	{
	    std::cout << map[start][index];
	}
	std::cout << '#' << std::endl;
    }

    printBorderWall(length);
}

void	Visualization::Console::print(Engine::ObjectMultitude::ObjectID obj)
{
    Visualization::Console::print(Engine::ObjectMultitude::Global::get(obj));
}

void	Visualization::Console::print(const Engine::ObjectVision& obj)
{
    Visualization::Console::moveCursor(obj.getLocation());
    Visualization::Console::print(obj.getIdentity());
    Visualization::Console::moveCursorDefault();
}

void	Visualization::Console::print(const Engine::MapComponent::Location& loc, const Visualization::Console::Identity& id)
{
    Visualization::Console::moveCursor(loc);
    Visualization::Console::print(id);
    Visualization::Console::moveCursorDefault();
}
