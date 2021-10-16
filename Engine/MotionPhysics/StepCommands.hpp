#pragma once

#include "../Map.hpp"



namespace Engine
{
    namespace MotionPhysics
    {
	enum class StepCommands
	{
	    StandStill,
	    Right,
	    First = Right,
	    Left,
	    Up,
	    Down,
	    RightUp,
	    RightDown,
	    LeftUp,
	    LeftDown,
	    End //for iterations
	};

	namespace StepUtility
	{
	    void Right(Coordinate& location);
	    void Left(Coordinate& location);
	    void Up(Coordinate& location);
	    void Down(Coordinate& location);

	    void RightUp(Coordinate& location);
	    void RightDown(Coordinate& location);
	    void LeftUp(Coordinate& location);
	    void LeftDown(Coordinate& location);
	}

	StepCommands defineCommandRightLeft(int xdif);
	StepCommands defineCommandUpDown(int ydif);
	StepCommands defineCommandDiagonal(int xdif, int ydif);

	StepCommands defineCommand(const Coordinate& start, const Coordinate& end);
	StepCommands defineCommand(int xdif, int ydif);

	void DoCommand(StepCommands command, Coordinate& location);
    }
}
