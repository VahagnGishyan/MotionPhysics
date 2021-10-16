#pragma once

#include "Features.hpp"
#include "Location.hpp"

namespace Engine
{
    namespace MapUtility
    {
	bool isWithin(const Engine::Coordinate& loc, const Engine::MapComponent::Features& mmap);
	bool isWithin(const Engine::Coordinate& loc, Engine::MapComponent::Metrology::Length m_length,
	    Engine::MapComponent::Metrology::Height m_height);
	bool isWithin(const Engine::Coordinate& loc, Engine::MapComponent::Metrology::Height m_height,
	    Engine::MapComponent::Metrology::Length m_length);
	bool isLocationMatch(const Engine::Coordinate& objLeft, const Engine::Coordinate& objRight);
    }
}