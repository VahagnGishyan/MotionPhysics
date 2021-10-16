#pragma once

namespace Engine
{
    namespace MapComponent
    {
	class Abscissa
	{
	protected:
	    int	    m_abscissa;
	public:
	    Abscissa(int abs) : m_abscissa(abs)
	    {
		//if (abs < 0)
		//    throw std::exception("The Map::Abscissa cannot be negative and zero");
		m_abscissa = abs;
	    }
	    Abscissa(const Abscissa& abs) : m_abscissa(abs.m_abscissa) {}
	    Abscissa(Abscissa&& abs) noexcept : m_abscissa(abs.m_abscissa) {}

	    bool    isMatch(const Abscissa& obj) const { return (obj.m_abscissa == this->m_abscissa); }
	    bool    operator==(const Abscissa& obj) const { return (obj.m_abscissa == this->m_abscissa); }
	    Abscissa operator=(const Abscissa& abs) { m_abscissa = abs.m_abscissa; return *this; }
	    Abscissa operator=(Abscissa&& abs) noexcept { m_abscissa = abs.m_abscissa; return *this; }
	    operator int() const { return m_abscissa; }
	 //   bool    isWithin(const Engine::Maps::Length& length) const
	 //   {
		//return (m_abscissa >= 0 && m_abscissa < length.get());
	 //   }
	};
	
	using   X = Abscissa;
    }
}
