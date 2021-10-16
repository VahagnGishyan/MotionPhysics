#include "../../ObjectUtility.hpp"

using namespace Engine;

ObjectMultitude::ObjectID Engine::ObjectUtility::make(const Location& loc, const Identity& id)
{
    return (ObjectMultitude::Global::make(loc, id));
}
ObjectMultitude::ObjectID Engine::ObjectUtility::make(const Location& loc, const Identity& id, const Status& status)
{
    return (ObjectMultitude::Global::make(loc, id, status));
}
ObjectMultitude::ObjectID Engine::ObjectUtility::make(const Location& loc, const Identity& id, const Behaviour& behaviour)
{
    return (ObjectMultitude::Global::make(loc, id, behaviour));
}
ObjectMultitude::ObjectID Engine::ObjectUtility::make(const Location& loc, const Identity& id, const Status& status, const Behaviour& behaviour)
{
    return (ObjectMultitude::Global::make(loc, id, status, behaviour));
}

ObjectMultitude::ObjectID Engine::ObjectUtility::make(Location&& loc, Identity&& id)
{
    return (ObjectMultitude::Global::make(loc, id));
}
ObjectMultitude::ObjectID Engine::ObjectUtility::make(Location&& loc, Identity&& id, Status&& status)
{
    return (ObjectMultitude::Global::make(loc, id, status));
}
ObjectMultitude::ObjectID Engine::ObjectUtility::make(Location&& loc, Identity&& id, Behaviour&& behaviour)
{
    return (ObjectMultitude::Global::make(loc, id, behaviour));
}
ObjectMultitude::ObjectID Engine::ObjectUtility::make(Location&& loc, Identity&& id, Status&& status, Behaviour&& behaviour)
{
    return (ObjectMultitude::Global::make(loc, id, status, behaviour));
}

const ObjectUtility::Location& Engine::ObjectUtility::getLocation(ObjectID id) 
{ 
    return (Engine::ObjectMultitude::Global::get(id).getLocation()); 
}
const ObjectUtility::Identity& Engine::ObjectUtility::getIdentity(ObjectID id)
{ 
    return (Engine::ObjectMultitude::Global::get(id).getIdentity()); 
}
const ObjectUtility::Status& Engine::ObjectUtility::getStatus(ObjectID id)
{ 
    return (Engine::ObjectMultitude::Global::get(id).getStatus()); 
}
const ObjectUtility::Behaviour& Engine::ObjectUtility::getBehaviour(ObjectID id)
{ 
    return (Engine::ObjectMultitude::Global::get(id).getBehaviour()); 
}
Engine::Object& Engine::ObjectUtility::getObject(ObjectID id)
{
    return(dynamic_cast<Object&>(Engine::ObjectMultitude::Global::get(id)));
}
ObjectUtility::Location& Engine::ObjectUtility::getLocationCtrl(ObjectID id)
{
    return(dynamic_cast<Object&>(Engine::ObjectMultitude::Global::get(id)).getLocation());
}
ObjectUtility::Identity& Engine::ObjectUtility::getIdentityCtrl(ObjectID id)
{
    return(dynamic_cast<Object&>(Engine::ObjectMultitude::Global::get(id)).getIdentity());
}
ObjectUtility::Status& Engine::ObjectUtility::getStatusCtrl(ObjectID id)
{
    return(dynamic_cast<Object&>(Engine::ObjectMultitude::Global::get(id)).getStatus());
}
ObjectUtility::Behaviour& Engine::ObjectUtility::getBehaviourCtrl(ObjectID id)
{
    return(dynamic_cast<Object&>(Engine::ObjectMultitude::Global::get(id)).getBehaviour());
}

void Engine::ObjectUtility::changeLocation(ObjectID id, Location loc) 
{ 
    Engine::ObjectMultitude::Global::get(id).changeLocation(loc); 
}
//void changeIdentity(ObjectID id, Identity loc) { Engine::ObjectMultitude::Global::get(id).changeIdentity(loc); }
void Engine::ObjectUtility::changeStatus(ObjectID id, Status stat) 
{ 
    Engine::ObjectMultitude::Global::get(id).changeStatus(stat); 
}
void Engine::ObjectUtility::changeBehaviour(ObjectID id, Behaviour beh) 
{ 
    Engine::ObjectMultitude::Global::get(id).changeBehaviour(beh); 
}

bool Engine::ObjectUtility::isLocationMatch(ObjectID idL, ObjectID idR)
{
    return (Engine::MapUtility::isLocationMatch(getLocation(idL), getLocation(idR)));
}
void Engine::ObjectUtility::die(ObjectID id)
{
    changeStatus(id, false);
}
bool Engine::ObjectUtility::isalive(ObjectID id)
{
    return (getStatus(id).isalive());
}

bool Engine::ObjectUtility::isRouteEmpty(ObjectID id)
{
    return (Engine::ObjectMultitude::Global::get(id).getBehaviour().m_way.isempty());
}
void Engine::ObjectUtility::nextStep(ObjectID id)
{
    Engine::Object& obj = Engine::ObjectUtility::getObject(id);

    Engine::MotionPhysics::StepCommands command = obj.getBehaviour().m_way.getCommand();
    if (command == Engine::MotionPhysics::StepCommands::StandStill)
    {
	obj.getBehaviour().m_way.resetCommands();
	return;
    }

    const Engine::ObjectComponent::Identity def('-', Visualization::Console::Color::Default);
    Visualization::Console::print(obj.getLocation(), def);
    Engine::MotionPhysics::DoCommand(command, obj.getLocation());
    Visualization::Console::print(obj);
}

Engine::MotionPhysics::Route Engine::ObjectUtility::RoutePlanner(const Map& map, const Coordinate& start,
    const Coordinate& end, const Engine::MotionPhysics::funcRoutePlanner& func)
{
    return func(map, start, end);
}

void  Engine::ObjectUtility::RoutePlanner(const Map& map, const ObjectID& start, const ObjectID& end,
    const Engine::MotionPhysics::funcRoutePlanner& func)
{
    Engine::Object& obj = Engine::ObjectUtility::getObject(start);
    obj.getBehaviour().m_way = 	func(map, Engine::ObjectUtility::getLocation(start), Engine::ObjectUtility::getLocation(end));
}
