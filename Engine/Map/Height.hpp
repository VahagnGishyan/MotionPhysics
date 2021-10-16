#pragma once

namespace Engine
{
    namespace MapComponent
    {
	namespace Metrology
	{
	    class	Height
	    {
	    protected:
		int	    m_height;

	    public:

		Height(int height)
		{
		    if (height <= 0)
			throw std::exception("The Map::Height cannot be negative and zero");
		    m_height = height;
		}
		Height(const Height& height) : m_height(height.m_height) {}
		Height(Height&& height) noexcept : m_height(height.m_height) {}

		operator int() const { return m_height; }
		Height& operator=(Height height) { m_height = height.m_height; return *this; }

	    };

	    using   YLength = Height;
	}
    }
}



