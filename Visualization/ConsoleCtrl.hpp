#pragma once

#include <iostream>
#include <windows.h> 
#include "../Engine/Map.hpp"
#include "../Game/Process.hpp"
#include "ConsoleIdentity.hpp"

namespace Visualization
{

    namespace Console
    {
	void	PrintColors();
	void	ClearScreen();

	void	print(Console::Symbol symbol);
	void	print(const Console::Identity& id);

	void	moveCursor(const Engine::MapComponent::Ordinate& line, const Engine::MapComponent::Abscissa index);
	void	moveCursor(const Engine::MapComponent::Location& loc);
	void	moveCursorDefault();

	void	changeColor(Visualization::Console::Color color);
	void	changeColorDefault();
    }
}
