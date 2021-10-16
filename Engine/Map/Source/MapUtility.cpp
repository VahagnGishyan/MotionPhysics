#include "../MapUtility.hpp"

bool Engine::MapUtility::isWithin(const Engine::Coordinate& loc, const Engine::MapComponent::Features& mmap)
{
    return ((loc.getAbscissa() >= 0 && loc.getAbscissa() < mmap.getLength()) &&
	(loc.getOrdinate() >= 0 && loc.getOrdinate() < mmap.getHeight()));
}
bool Engine::MapUtility::isWithin(const Engine::Coordinate& loc, Engine::MapComponent::Metrology::Length m_length,
    Engine::MapComponent::Metrology::Height m_height)
{
    return ((loc.getAbscissa() >= 0 && loc.getAbscissa() < m_length) &&
	(loc.getOrdinate() >= 0 && loc.getOrdinate() < m_height));
}
bool Engine::MapUtility::isWithin(const Engine::Coordinate& loc, Engine::MapComponent::Metrology::Height m_height,
    Engine::MapComponent::Metrology::Length m_length)
{
    return ((loc.getAbscissa() >= 0 && loc.getAbscissa() < m_length) &&
	(loc.getOrdinate() >= 0 && loc.getOrdinate() < m_height));
}
bool Engine::MapUtility::isLocationMatch(const Engine::Coordinate& objLeft, const Engine::Coordinate& objRight)
{
    return (objLeft == objRight);
}


