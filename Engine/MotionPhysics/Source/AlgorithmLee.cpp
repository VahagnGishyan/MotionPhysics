#include "../RoutePlanner.hpp"	

//struct MapPoint
//{
//    int     m_stepCount;
//    MapChar m_mapchar;
//
//};

constexpr unsigned int BigNumber = (static_cast<unsigned int>(-1));
using ExpectedPoints = std::list<Engine::Coordinate>;
using MatrixPoint = std::pair<unsigned int, Engine::MapComponent::Symbol>;
using MapMatrix = std::vector<std::vector<MatrixPoint>>;

static MapMatrix createMapMatrix(const Engine::Map& map)
{
    MapMatrix mat;

    mat.resize(map.getHeight());
    for (int index = 0; index < static_cast<int>(mat.size()); ++index)
        mat[index].resize(map.getLength(), { BigNumber, (Engine::MapComponent::Symbol)'-' });

    for (int start = 0; start < map.getHeight(); ++start)
    {
        for (int index = 0; index < map.getLength(); ++index)
        {
            if (map[start][index] != '-')
            {
                mat[start][index].second = map[start][index];
            }
        }
    }

    return mat;
}

//static void printMatrixStepCount(const MapMatrix& mat)
//{
//    std::cout<<std::endl;
//    for (int start = 0; start < mat.size(); ++start)
//    {
//        for (int index = 0; index < mat[index].size(); ++index)
//        {
//            std::cout << mat[start][index].first;
//        }
//    }
//    std::cout<<std::endl;
//}

static Engine::MapComponent::Symbol getMatrixChar(const MapMatrix& mat, const Engine::Coordinate& loc)
{
    if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
        return ('#');
    return(mat[loc.getOrdinate()][loc.getAbscissa()].second);
}

static unsigned int getMatrixStepCount(const MapMatrix& mat, const Engine::Coordinate& loc)
{
    //if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
    //    return ('#');
    return(mat[loc.getOrdinate()][loc.getAbscissa()].first);
}

static void changeMatrixStepCount(MapMatrix& mat, const Engine::Coordinate& loc, int value)
{
    //if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
    //    return ('#');
    mat[loc.getOrdinate()][loc.getAbscissa()].first = value;
}

static MatrixPoint getMatrixPoint(const MapMatrix& mat, const Engine::Coordinate& loc)
{
    //if (loc.getAbscissa() < 0 || loc.getOrdinate() < 0)
//    return ('#');
    return(mat[loc.getOrdinate()][loc.getAbscissa()]);
}

static Engine::Coordinate getNeighbourLocation(Engine::Coordinate loc, int command)
{

    // 
    //  8 4 6
    //  2 X 1
    //  7 3 5
    // 

    Engine::MotionPhysics::DoCommand(Engine::MotionPhysics::StepCommands(command), loc);
    return loc;
}

static Engine::Coordinate getNextLocation(ExpectedPoints& queue)
{
    Engine::Coordinate loc = queue.front();
    queue.pop_front();
    return loc;
}

static bool BreadthFirstSearch(MapMatrix& matrix, ExpectedPoints& queue, const Engine::Coordinate& end)
{
    if (queue.empty())
        return false;

    Engine::Coordinate start = getNextLocation(queue);

    if (getMatrixChar(matrix, start) == '#')
        return false; 

    if (start == end)
        return true;

    for (int index = (int)Engine::MotionPhysics::StepCommands::First; index <
        (int)Engine::MotionPhysics::StepCommands::End; ++index)
    {
        Engine::Coordinate neighbour = getNeighbourLocation(start, index);
        
        if (not Engine::MapUtility::isWithin(neighbour, Engine::MapComponent::Metrology::Length{ static_cast<int>(matrix[0].size()) },
            Engine::MapComponent::Metrology::Height{static_cast<int>(matrix.size())}))
            continue;
        if (getMatrixChar(matrix, neighbour) == '#')
            continue;
        if (neighbour == end)
            return true;
        if (getMatrixStepCount(matrix, neighbour) == BigNumber)
            queue.push_back(neighbour);
        if (getMatrixStepCount(matrix, neighbour) > (getMatrixStepCount(matrix, start) + 1))
            changeMatrixStepCount(matrix, neighbour, getMatrixStepCount(matrix, start) + 1);
    }

    return BreadthFirstSearch(matrix, queue, end);
}

static Engine::Coordinate MinNeighbour(const MapMatrix& matrix, const Engine::Coordinate& loc)
{
    Engine::Coordinate min = loc;
    for (int index = (int)Engine::MotionPhysics::StepCommands::First; index < 
        (int)Engine::MotionPhysics::StepCommands::End; ++index)
    {
        Engine::Coordinate neighbour = getNeighbourLocation(loc, index);

        if (not Engine::MapUtility::isWithin(neighbour, Engine::MapComponent::Metrology::Length{ static_cast<int>(matrix[0].size()) },
            Engine::MapComponent::Metrology::Height{ static_cast<int>(matrix.size()) }))
            continue;
        if(getMatrixStepCount(matrix, min) > getMatrixStepCount(matrix, neighbour))
            min = neighbour;
    }
    return (min);
}

static Engine::MotionPhysics::Route designRoadWithMapMatrix(const MapMatrix& mat, const Engine::Coordinate& start, const Engine::Coordinate& end)
{
    std::stack<Engine::MotionPhysics::StepCommands> commands; // we add StepCommands in the reverse order
    Engine::Coordinate location = end;

    while (location != start)
    {
        Engine::Coordinate minloc = MinNeighbour(mat, location);
        commands.push(Engine::MotionPhysics::defineCommand(minloc, location));
        location = minloc;
    }

    //we pass it to way in the correct sequence
    Engine::MotionPhysics::Route way;
    while (!commands.empty())
    {
        way.addCommand(commands.top());
        commands.pop();
    }

    return way;
}

Engine::MotionPhysics::Route Engine::MotionPhysics::RoutePlanner::Lee(const Engine::Map& map, const Engine::Coordinate& start, const Engine::Coordinate& end)
{
    Engine::MotionPhysics::Route way;
    
    //prepare map
    MapMatrix matrix = createMapMatrix(map);

    //matrix[start.getOrdinate()][start.getAbscissa()].first = 0;
    constexpr int StartStepCount = 0;
    changeMatrixStepCount(matrix, start, StartStepCount);
    ExpectedPoints queue{start};
    BreadthFirstSearch(matrix, queue, end);

    //find way with matrix
    way = designRoadWithMapMatrix(matrix, start, end);

    return way;
}
