#pragma once

namespace Engine
{
    namespace ObjectComponent
    {
	class Status
	{
	private:
	    //int m_health;
	    bool m_health;

	public:
	    Status() :m_health(true) {}
	    Status(bool t) :m_health(t) {}

	    bool isalive() const { return m_health; }
	    void die() { m_health = false; }
	};
    }
}