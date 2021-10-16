#include "../StepCommands.hpp"

void Engine::MotionPhysics::StepUtility::Right(Coordinate& location)
{
    location.changeAbscissa(location.getAbscissa() + 1);
}

void Engine::MotionPhysics::StepUtility::Left(Coordinate& location)
{
    location.changeAbscissa(location.getAbscissa() - 1);
}

void Engine::MotionPhysics::StepUtility::Up(Coordinate& location)
{
    location.changeOrdinate(location.getOrdinate() + 1);
}

void Engine::MotionPhysics::StepUtility::Down(Coordinate& location)
{
    location.changeOrdinate(location.getOrdinate() - 1);
}

void Engine::MotionPhysics::StepUtility::RightUp(Coordinate& location)
{
    location.changeAbscissa(location.getAbscissa() + 1);
    location.changeOrdinate(location.getOrdinate() + 1);
}

void Engine::MotionPhysics::StepUtility::RightDown(Coordinate& location)
{
    location.changeAbscissa(location.getAbscissa() + 1);
    location.changeOrdinate(location.getOrdinate() - 1);
}

void Engine::MotionPhysics::StepUtility::LeftUp(Coordinate& location)
{
    location.changeAbscissa(location.getAbscissa() - 1);
    location.changeOrdinate(location.getOrdinate() + 1);
}

void Engine::MotionPhysics::StepUtility::LeftDown(Coordinate& location)
{
    location.changeAbscissa(location.getAbscissa() - 1);
    location.changeOrdinate(location.getOrdinate() - 1);
}

Engine::MotionPhysics::StepCommands Engine::MotionPhysics::defineCommandRightLeft(int xdif)
{
    return (xdif > 0 ? StepCommands::Right : StepCommands::Left);
}

Engine::MotionPhysics::StepCommands Engine::MotionPhysics::defineCommandUpDown(int ydif)
{
    return (ydif > 0 ? StepCommands::Up : StepCommands::Down);
}

Engine::MotionPhysics::StepCommands Engine::MotionPhysics::defineCommandDiagonal(int xdif, int ydif)
{
    if (defineCommandRightLeft(xdif) == StepCommands::Right)   // if Right
    {
	if (defineCommandUpDown(ydif) == StepCommands::Up)	    //	and if Up 
	    return (StepCommands::RightUp);		    //	    return RightUp
	else //						    //	and if Down
	    return(StepCommands::RightDown);		    //	    return RightDown
    }
    else						    // if Left
    {
	if (defineCommandUpDown(ydif) == StepCommands::Up)	    //	and if Up 
	    return (StepCommands::LeftUp);		    //	    return LeftUp
	else //						    //	and if Down
	    return(StepCommands::LeftDown);		    //	    return LeftDown
    }
}

Engine::MotionPhysics::StepCommands Engine::MotionPhysics::defineCommand(const Engine::Coordinate& start, const Engine::Coordinate& end)
{
    int xdif = end.getAbscissa() - start.getAbscissa();
    int ydif = end.getOrdinate() - start.getOrdinate();
    return (defineCommand(xdif, ydif));
}

Engine::MotionPhysics::StepCommands Engine::MotionPhysics::defineCommand(int xdif, int ydif)
{
    if (xdif == 0 && ydif == 0)
	return StepCommands::StandStill;

    if (xdif == 0)
	return (MotionPhysics::defineCommandUpDown(ydif));
    if (ydif == 0)
	return (MotionPhysics::defineCommandRightLeft(xdif));

    return (MotionPhysics::defineCommandDiagonal(xdif, ydif));
}


void Engine::MotionPhysics::DoCommand(StepCommands command, Engine::Coordinate& location)
{
    switch (command)
    {
    case StepCommands::Right:
	MotionPhysics::StepUtility::Right(location);
	break;
    case StepCommands::Left:
	MotionPhysics::StepUtility::Left(location);
	break;
    case StepCommands::Up:
	MotionPhysics::StepUtility::Up(location);
	break;
    case StepCommands::Down:
	MotionPhysics::StepUtility::Down(location);
	break;
    case StepCommands::RightUp:
	MotionPhysics::StepUtility::RightUp(location);
	break;
    case StepCommands::RightDown:
	MotionPhysics::StepUtility::RightDown(location);
	break;
    case StepCommands::LeftUp:
	MotionPhysics::StepUtility::LeftUp(location);
	break;
    case StepCommands::LeftDown:
	MotionPhysics::StepUtility::LeftDown(location);
	break;
    }
}