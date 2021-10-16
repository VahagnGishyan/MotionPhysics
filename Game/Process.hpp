#pragma once

#include "../Engine/Map.hpp"

namespace Game
{
    namespace Process
    {
	class Controller
	{
	private:
	    static Engine::MapComponent::Features*		s_map;
	public:
	    static void	import(Engine::MapComponent::Features&	mmap);
	    static const Engine::MapComponent::Features* getMap();
	};
    }
}