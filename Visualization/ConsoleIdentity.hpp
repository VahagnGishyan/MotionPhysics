#pragma once

namespace Visualization
{
    namespace Console
    {
	enum class Color
	{
	    Blue = 1,
	    Green = 2,
	    Aqua = 3,
	    Red = 4,
	    Purple = 5,
	    Yellow = 6,
	    White = 7,
	    Default = 7,
	    Gray = 8
	};

	using Symbol = unsigned char;

	class Identity
	{
	private:
	    Visualization::Console::Symbol	m_symbol;
	    Visualization::Console::Color	m_color;
	public:
	    Identity(Visualization::Console::Symbol symbol, Visualization::Console::Color color) 
		: m_symbol(symbol), m_color(color) {}
	    Identity(const Identity& id) : m_symbol(id.m_symbol), m_color(id.m_color)	    {}
	    Identity(Identity&& id) noexcept : m_symbol(id.m_symbol), m_color(id.m_color)   {}

	    Visualization::Console::Symbol  getSymbol() const { return(m_symbol); }
	    Visualization::Console::Color   getColor() const { return (m_color); }

	protected:
	    void changeSymbol(Visualization::Console::Symbol symbol) { m_symbol = symbol; }
	    void changeColor(Visualization::Console::Color color) { m_color = color; }
	};
    }
}