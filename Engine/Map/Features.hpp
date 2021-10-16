#pragma once

#include <vector>
#include <string>
#include "Length.hpp"
#include "Height.hpp"

namespace Engine
{
    namespace MapComponent
    {
	using Symbol = unsigned char;

	class Features
	{
	protected:
	    Engine::MapComponent::Metrology::Length    m_length;
	    Engine::MapComponent::Metrology::Height    m_height;
	public:

	    Features(const Metrology::Length& length, const Metrology::Height& height) : m_length(length), m_height(height) {}
	    Features(const Metrology::Height& height, const Metrology::Length& length) : m_length(length), m_height(height) {}

	    Features(Metrology::Length&& length, Metrology::Height&& height) : m_length(length), m_height(height) {}
	    Features(Metrology::Height&& height, Metrology::Length&& length) : m_length(length), m_height(height) {}

	    virtual std::vector<Engine::MapComponent::Symbol> operator[](int) const = 0;
	    virtual std::vector<Engine::MapComponent::Symbol>& operator[](int) = 0;

	    Metrology::Length  getLength() const { return (m_length); }
	    Metrology::Height  getHeight() const { return (m_height); }

	    void makeNew(Engine::MapComponent::Metrology::Length, Engine::MapComponent::Metrology::Height);
	    void makeNew(Engine::MapComponent::Metrology::Height, Engine::MapComponent::Metrology::Length);
	    void makeNew(std::vector<std::string>& data);
	};
    }
}

