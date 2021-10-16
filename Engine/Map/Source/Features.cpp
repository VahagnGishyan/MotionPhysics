#include "../Features.hpp"

using namespace Engine;
using namespace Engine::MapComponent;
using namespace Engine::MapComponent::Metrology;

void Features::makeNew(Length length, Height height)
{
    m_length = length;
    m_height = height;
}

void  Features::makeNew(Height height, Length length)
{
    m_length = length;
    m_height = height;
}

void Features::makeNew(std::vector<std::string>& data)
{
    if (data.empty())
	return;
    m_length = Length(data[0].size());
    m_height = Height(data.size());
}