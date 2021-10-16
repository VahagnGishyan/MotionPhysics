#pragma once

namespace Engine
{
    namespace MapComponent
    {
	class Ordinate // Y
	{
	protected:
	    int	    m_ordinate;
	public:
	    Ordinate(int ord) : m_ordinate(ord) 
	    {
		//if (ord < 0)
		//    throw std::exception("The Map::Ordinate cannot be negative and zero");
		m_ordinate = ord;
	    }
	    Ordinate(const Ordinate& ord) : m_ordinate(ord.m_ordinate) {}
	    Ordinate(Ordinate&& ord) noexcept : m_ordinate(ord.m_ordinate) {}

	    //int	    getOrdinate() const { return m_ordinate; }
	    //void    changeOrdinate(int value) { m_ordinate = value; }

	    bool    isMatch(const Ordinate& obj) const { return (obj.m_ordinate == this->m_ordinate); }
	    bool    operator==(const Ordinate& obj) const { return (obj.m_ordinate == this->m_ordinate); }
	    operator int() const { return m_ordinate; }
	    Ordinate operator=(const Ordinate& ord) { m_ordinate = ord.m_ordinate; return *this; }
	    Ordinate operator=(Ordinate&& ord) noexcept { m_ordinate = ord.m_ordinate; return *this; }

	    //   bool    isWithin(const Engine::Maps::Height& height) const
	 //   {
		//return (m_ordinate >= 0 && m_ordinate < height.get());
	 //   }
	};

	using   Y = Ordinate;
    }
}
