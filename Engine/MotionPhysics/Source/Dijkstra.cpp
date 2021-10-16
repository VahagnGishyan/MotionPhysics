//#include "MotionPhysics.hpp"	
//
////struct MapPoint
////{
////    int     m_stepCount;
////    MapChar m_mapchar;
////
////};
//
//constexpr unsigned int BigNumber = (static_cast<unsigned int>(-1));
//using ExpectedPoints = std::list<MapCoordinate>;
//using MatrixPoint = std::pair<unsigned int, MapChar>;
//using MapMatrix = std::vector<std::vector<MatrixPoint>>;
//
//static MapMatrix createMapMatrix(const Map& map)
//{
//    MapMatrix mat;
//
//    mat.resize(map.getHeight());
//    for (int index = 0; index < static_cast<int>(mat.size()); ++index)
//        mat[index].resize(map.getLength(), { BigNumber, (MapChar)'-' });
//
//    for (int start = 0; start < map.getHeight(); ++start)
//    {
//        for (int index = 0; index < map.getLength(); ++index)
//        {
//            if (map[start][index] != '-')
//            {
//                mat[start][index].second = map[start][index];
//            }
//        }
//    }
//
//    return mat;
//}
//
////static void printMatrixStepCount(const MapMatrix& mat)
////{
////    std::cout<<std::endl;
////    for (int start = 0; start < mat.size(); ++start)
////    {
////        for (int index = 0; index < mat[index].size(); ++index)
////        {
////            std::cout << mat[start][index].first;
////        }
////    }
////    std::cout<<std::endl;
////}
//
//static MapChar getMatrixChar(const MapMatrix& mat, const MapCoordinate& loc)
//{
//    if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
//        return ('#');
//    return(mat[loc.getOrdinate()][loc.getAbscissa()].second);
//}
//
//static unsigned int getMatrixStepCount(const MapMatrix& mat, const MapCoordinate& loc)
//{
//    //if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
//    //    return ('#');
//    return(mat[loc.getOrdinate()][loc.getAbscissa()].first);
//}
//
//static void changeMatrixStepCount(MapMatrix& mat, const MapCoordinate& loc, int value)
//{
//    //if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
//    //    return ('#');
//    mat[loc.getOrdinate()][loc.getAbscissa()].first = value;
//}
//
//static MatrixPoint getMatrixPoint(const MapMatrix& mat, const MapCoordinate& loc)
//{
//    //if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
////    return ('#');
//    return(mat[loc.getOrdinate()][loc.getAbscissa()]);
//}
//
//static MapCoordinate getNeighbourLocation(MapCoordinate loc, int command)
//{
//
//    // 
//    //  8 4 6
//    //  2 X 1
//    //  7 3 5
//    // 
//
//    MotionPhysics::DoCommand(StepCommands(command), loc);
//    return loc;
//}
//
//static Location getNextLocation(ExpectedPoints& queue)
//{
//    Location loc = queue.front();
//    queue.pop_front();
//    return loc;
//}
//
//static bool BreadthFirstSearch(MapMatrix& matrix, ExpectedPoints& queue, const MapCoordinate& end)
//{
//    if (queue.empty())
//        return false;
//
//    Location start = getNextLocation(queue);
//
//    if (getMatrixChar(matrix, start) == '#')
//        return false; 
//
//    if (start == end)
//        return true;
//
//    for (int index = (int)StepCommands::First; index < (int)StepCommands::End; ++index)
//    {
//        MapCoordinate neighbour = getNeighbourLocation(start, index);
//        
//        if (not Location::Check({ static_cast<int>(matrix[0].size()),
//            static_cast<int>(matrix.size()) } ,neighbour))
//            continue;
//        if (getMatrixChar(matrix, neighbour) == '#')
//            continue;
//        if (neighbour == end)
//            return true;
//        if (getMatrixStepCount(matrix, neighbour) == BigNumber)
//            queue.push_back(neighbour);
//        if (getMatrixStepCount(matrix, neighbour) > (getMatrixStepCount(matrix, start) + 1))
//            changeMatrixStepCount(matrix, neighbour, getMatrixStepCount(matrix, start) + 1);
//    }
//
//    return BreadthFirstSearch(matrix, queue, end);
//}
//
//static Location MinNeighbour(const MapMatrix& mat, const Location& loc)
//{
//    Location min = loc;
//    for (int index = (int)StepCommands::First; index < (int)StepCommands::End; ++index)
//    {
//        Location neighbour = getNeighbourLocation(loc, index);
//
//        if (not Location::Check({ static_cast<int>(mat[0].size()),
//            static_cast<int>(mat.size()) }, neighbour))
//            continue;
//        if(getMatrixStepCount(mat, min) > getMatrixStepCount(mat, neighbour))
//            min = neighbour;
//    }
//    return (min);
//}
//
//static Way designRoadWithMapMatrix(const MapMatrix& mat, const Location& start, const Location& end)
//{
//    std::stack<StepCommands> commands; // we add StepCommands in the reverse order
//    Location location = end;
//
//    while (location != start)
//    {
//        Location minloc = MinNeighbour(mat, location);
//        commands.push(MotionPhysics::defineCommand(minloc, location));
//        location = minloc;
//    }
//
//    //we pass it to way in the correct sequence
//    Way way;
//    while (!commands.empty())
//    {
//        way.addCommand(commands.top());
//        commands.pop();
//    }
//
//    return way;
//}
//
//Way	MotionPhysics::RoutePlanner::WithBarrier(const Map& map, const MapCoordinate& start, const MapCoordinate& end)
//{
//    Way way;
//    
//    //prepare map
//    MapMatrix matrix = createMapMatrix(map);
//
//    //matrix[start.getOrdinate()][start.getAbscissa()].first = 0;
//    constexpr int StartStepCount = 0;
//    changeMatrixStepCount(matrix, start, StartStepCount);
//    ExpectedPoints queue{start};
//    BreadthFirstSearch(matrix, queue, end);
//
//    //find way with matrix
//    way = designRoadWithMapMatrix(matrix, start, end);
//
//    return way;
//}
