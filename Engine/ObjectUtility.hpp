#pragma once

#include "Object.hpp"
#include "ObjectsMultitude.hpp"
#include "Objects/Behaviour.hpp"
#include "../Visualization/Console.hpp"
#include "MotionPhysics.hpp" 

namespace Engine
{
    class ObjectUtility
    {
    private:
	using ObjectID = ObjectMultitude::ObjectID;
	using Location	= Engine::ObjectComponent::Location;
	using Identity	= Engine::ObjectComponent::Identity;
	using Status	= Engine::ObjectComponent::Status;
	using Behaviour = Engine::ObjectComponent::Behaviour;
    public:
	static ObjectID make(const Location& loc, const Identity& id);
	static ObjectID make(const Location& loc, const Identity& id, const Status& status);
	static ObjectID make(const Location& loc, const Identity& id, const Behaviour& behaviour);
	static ObjectID make(const Location& loc, const Identity& id, const Status& status, const Behaviour& behaviour);

	static ObjectID make(Location&& loc, Identity&& id);
	static ObjectID make(Location&& loc, Identity&& id, Status&& status);
	static ObjectID make(Location&& loc, Identity&& id, Behaviour&& behaviour);
	static ObjectID make(Location&& loc, Identity&& id, Status&& status, Behaviour&& behaviour);

	static const Location& getLocation(ObjectID id);
	static const Identity& getIdentity(ObjectID id);
	static const Status& getStatus(ObjectID id);
	static const Behaviour& getBehaviour(ObjectID id);
    private:
	static Engine::Object& getObject(ObjectID id);
	static Location&   getLocationCtrl(ObjectID id);
	static Identity&   getIdentityCtrl(ObjectID id);
	static Status&	    getStatusCtrl(ObjectID id);
	static Behaviour&  getBehaviourCtrl(ObjectID id);
    public:
	static void changeLocation(ObjectID id, Location loc);
	//void changeIdentity(ObjectID id, Identity loc);
	static void changeStatus(ObjectID id, Status stat);
	static void changeBehaviour(ObjectID id, Behaviour beh);
	
	static bool isLocationMatch(ObjectID idL, ObjectID idR);
	static void die(ObjectID id);
	static bool isalive(ObjectID id);

	static bool isRouteEmpty(ObjectID id);
	static void nextStep(ObjectID id);

    private: 
	static Engine::MotionPhysics::Route RoutePlanner(const Map& map, const Coordinate& start, const Coordinate& end,
	    const Engine::MotionPhysics::funcRoutePlanner& func = Engine::MotionPhysics::RoutePlanner::Lee);
    public:
	static void RoutePlanner(const Map& map, const ObjectID& start, const ObjectID& end,
	    const Engine::MotionPhysics::funcRoutePlanner& func = Engine::MotionPhysics::RoutePlanner::Lee); 
	//void initObjects(Object* obj)
	//{
	//    Object::addObjectsMultitude(obj);
	//    obj->m_objectID = s_object_count++;
	//}

	//Object* Make(int abs, int ord, unsigned char symbol = '?', Color color = Color::Default)
	//{
	//    Object* obj = new Object(abs, ord, symbol, color);
	//    Object::InitObjects(obj);
	//    return (obj);
	//}

	//void	    Delete(Object* obj)
	//{
	//    if (obj == nullptr)
	//	return;
	//    Object::deleteObjectsMultitude(obj);
	//    //ConsoleVisualization::
	//    delete obj;
	//    obj = nullptr;
	//}

    };
}