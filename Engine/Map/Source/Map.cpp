#include "../../Map.hpp"

using namespace Engine;
using namespace Engine::MapComponent;
using namespace Engine::MapComponent::Metrology;

Engine::Map::Map(const Length& length, const Height& height) : Features(length, height)
{
    m_data.resize((int)height);
    for (std::vector<Symbol>&str : m_data)
    {
	str.resize((int)length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}
Engine::Map::Map(const Height& height, const Length& length) : Features(length, height)
{
    m_data.resize((int)height);
    for (std::vector<Symbol>& str : m_data)
    {
	str.resize((int)length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}
Engine::Map::Map(Length&& length, Height&& height) : Features(length, height)
{
    m_data.resize((int)height);
    for (std::vector<Symbol>& str : m_data)
    {
	str.resize((int)length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}
Engine::Map::Map(Height&& height, Length&& length) : Features(length, height)
{
    m_data.resize((int)height);
    for (std::vector<Symbol>& str : m_data)
    {
	str.resize((int)length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}

Engine::Map::Map(std::vector<std::string>& text) : Features(Engine::MapComponent::Metrology::Height(text.size()),
	Engine::MapComponent::Metrology::Length(text[0].size()))
{
    m_data.resize((int)m_height);
    for (unsigned int start = 0; start < (unsigned int)m_height; ++start)
    {
	m_data[start].resize((int)m_length);
	std::vector<Symbol>& line = m_data[start];
	for (unsigned int index = 0; index < (unsigned int)m_length; ++index)
	{
	    line[index] = text[start][index];
	}
    }
}

void Map::makeNew(Length length, Height height)
{
    m_length = length;
    m_height = height;
    m_data.resize((int)height);
    for (std::vector<Symbol>& str : m_data)
    {
	str.resize((int)length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}

void  Map::makeNew(Height height, Length length)
{
    m_length = length;
    m_height = height;
    m_data.resize((int)height);
    for (std::vector<Symbol>& str : m_data)
    {
	str.resize((int)length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}

void Map::makeNew(std::vector<std::string>& data)
{
    int length = data.size();
    int height = data[0].size();
    if (data.empty())
	return;
    m_length = Length(data[0].size());
    m_height = Height(data.size());
    m_data.resize(height);
    for (std::vector<Symbol>& str : m_data)
    {
	str.resize(length);
	for (Symbol& symbol : str)
	    symbol = '-';
    }
}

void Engine::Map::makeFrom(Map& rmap, std::vector<std::string>& text)
{
    for (unsigned int start = 0; start < text.size(); ++start)
    {
	std::vector<Symbol>& line = rmap[start];
	for (unsigned int index = 0; index < text[0].size(); ++index)
	{
	    line[index] = text[start][index];
	}
    }
}

