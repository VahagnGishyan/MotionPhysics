#include "../../MotionPhysics.hpp"

static void addCommandsInWay(Engine::MotionPhysics::Route& way, int count, Engine::MotionPhysics::StepCommands command)
{
    //last
    for (int index = 0; index < count; ++index)
	way.addCommand(command);
}

Engine::MotionPhysics::Route Engine::MotionPhysics::RoutePlanner::OpenSpace(const Engine::Map & map, const Engine::Coordinate & start, const Engine::Coordinate & end)
{
    Engine::MotionPhysics::Route way;

    int xdif = end.getAbscissa() - start.getAbscissa();
    int ydif = end.getOrdinate() - start.getOrdinate();

    std::pair<int, int> minmax = std::minmax(std::abs(xdif), std::abs(ydif));

    addCommandsInWay(way, minmax.first, MotionPhysics::defineCommand(xdif, ydif));
    StepCommands command = (std::abs(xdif) < std::abs(ydif) ?
	MotionPhysics::defineCommandUpDown(ydif) :
	MotionPhysics::defineCommandRightLeft(xdif));
    addCommandsInWay(way, minmax.second - minmax.first, command);

    return way;
}