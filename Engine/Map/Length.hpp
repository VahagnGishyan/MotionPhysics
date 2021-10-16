#pragma once
#include <exception>

namespace Engine
{
    namespace MapComponent
    {
	namespace Metrology
	{
	    class	Length
	    {
	    protected:
		unsigned int	    m_length;

	    public:

		Length(int length)
		{
		    if (length <= 0)
			throw std::exception("The Map::Length cannot be negative and zero");
		    m_length = length;
		}
		Length(const Length& length) : m_length(length.m_length) {}
		Length(Length&& length) noexcept : m_length(length.m_length) {}

		operator int() const { return (int)m_length; }
		Length& operator=(Length length) { m_length = length.m_length; return *this; }
	    };

	    using   XLength = Length;
	}
    }
}