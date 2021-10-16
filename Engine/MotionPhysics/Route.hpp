#pragma once

#include <queue>
#include "StepCommands.hpp"

namespace Engine
{
    namespace MotionPhysics
    {
	class Route
	{
	private:
	    std::queue<StepCommands> m_commands;

	public:
	    bool isempty() const { return (m_commands.size() == 0); }
	    int	 length() const { return m_commands.size(); }
	    void addCommand(StepCommands command) { m_commands.push(command); }
	    StepCommands getCommand() { StepCommands command = m_commands.front(); m_commands.pop(); return (command); }
	    StepCommands ReadCommand() const { return (m_commands.front()); }
	    void resetCommands()
	    {
		std::queue<StepCommands> empty;
		std::swap(m_commands, empty);
	    }
	};
    }
}
