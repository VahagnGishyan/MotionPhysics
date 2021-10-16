#pragma once

#include <list>
#include <stack>
#include <functional>

#include "Route.hpp"
#include "../Map.hpp"

namespace Engine
{
    namespace MotionPhysics
    {
	using funcRoutePlanner = std::function<Route(const Map& map, const Coordinate& start, const Coordinate& end)>;
	namespace RoutePlanner
	{
	    Route 	OpenSpace(const Map& map, const Coordinate& start, const Coordinate& end);
	    Route 	Lee(const Map& map, const Coordinate& start, const Coordinate& end);		// breadthFirstSearch
	    Route 	Dijkstra(const Map& map, const Coordinate& start, const Coordinate& end);	// Greedy algorithm
	    Route 	AStar(const Map& map, const Coordinate& start, const Coordinate& end);		// dijkstra modifications
	    Route 	FloydWarshall(const Map& map, const Coordinate& start, const Coordinate& end);
	    Route 	BellmanFord(const Map& map, const Coordinate& start, const Coordinate& end);
	}
    }
}
