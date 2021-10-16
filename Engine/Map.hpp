#pragma once

#include "Map/Location.hpp"
#include "Map/Features.hpp"
#include "Map/MapUtility.hpp"

namespace Engine
{
    class Map : public MapComponent::Features
    {
    private:
	std::vector<std::vector<Engine::MapComponent::Symbol>> m_data;

    public:

	Map(const Engine::MapComponent::Metrology::Length& length, const Engine::MapComponent::Metrology::Height& height);
	Map(const Engine::MapComponent::Metrology::Height& height, const Engine::MapComponent::Metrology::Length& length);

	Map(Engine::MapComponent::Metrology::Length&& length, Engine::MapComponent::Metrology::Height&& height);
	Map(Engine::MapComponent::Metrology::Height&& height, Engine::MapComponent::Metrology::Length&& length);

	Map(int, int) = delete;
	Map(std::vector<std::string>& text);
    
	virtual std::vector<Engine::MapComponent::Symbol> operator[](int index) const override { return (m_data[index]); }
	virtual std::vector<Engine::MapComponent::Symbol>& operator[](int index) override { return (m_data[index]); }

	void makeNew(Engine::MapComponent::Metrology::Length, Engine::MapComponent::Metrology::Height);
	void makeNew(Engine::MapComponent::Metrology::Height, Engine::MapComponent::Metrology::Length);
	void makeNew(std::vector<std::string>& data);

	static void makeFrom(Map& rmap, std::vector<std::string>& text);
    };
}




//class Point : public Location
//{
//    MapProjectionID	m_value;	//Content
//
//public:
//    Point(int abs = 0, int ord = 0, MapProjectionID value = '?');
//    Point operator=(const Point& copy);
//    bool operator==(const Point& obj) { return (isLocationMatch(obj) && m_value == obj.m_value); }
//
//    MapChar getMapChar() const { return m_value; }
//    bool isPointMatch(const Point& obj) const { return (isLocationMatch(obj) && (m_value == obj.m_value)); }
//};




