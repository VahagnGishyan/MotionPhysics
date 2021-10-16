#pragma once

#include <iostream>
#include <map>

#include "../Engine/Map.hpp"
#include "../Engine/ObjectsMultitude.hpp"
#include "../Game/Process.hpp"
#include "ConsoleCtrl.hpp"


namespace Visualization
{
    namespace Console
    {
	void	import(Engine::MapComponent::Features& mmap);

	void	print(Engine::ObjectMultitude::ObjectID obj);
	void	print(const Engine::ObjectVision& obj);
	void	print(const Engine::MapComponent::Location& loc, const Visualization::Console::Identity& id);
	//void	update();

	//void	updateObjectsState();
	//void	addObjectState(const Engine::Objects::Vision& loc);
	//void	deleteObjectState(const Engine::Objects::Vision& loc);
	//void	changeObjectState(const Engine::Objects::Vision& locLust);

	//void	printObject(const Engine::Objects::Vision& obj);
    }
}


