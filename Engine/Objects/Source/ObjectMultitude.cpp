#include "../../ObjectsMultitude.hpp"

using ObjectID = Engine::ObjectComponent::Identity::ObjectID;
using ObjectVision = Engine::ObjectVision;

ObjectID Engine::ObjectMultitude::Global::make(const Location& loc, const Identity& id)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id)));
    return (s_objectCount);
}
ObjectID Engine::ObjectMultitude::Global::make(const Location& loc, const Identity& id, const Status& status)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id, status)));
    return (s_objectCount);
}
ObjectID Engine::ObjectMultitude::Global::make(const Location& loc, const Identity& id, const Behaviour& behaviour)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id, behaviour)));
    return (s_objectCount);
}
ObjectID Engine::ObjectMultitude::Global::make(const Location& loc, const Identity& id, const Status& status, const Behaviour& behaviour)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id, status, behaviour)));
    return (s_objectCount);
}

ObjectID Engine::ObjectMultitude::Global::make(Location&& loc, Identity&& id)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id)));
    return (s_objectCount);
}
ObjectID Engine::ObjectMultitude::Global::make(Location&& loc, Identity&& id, Status&& status)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id, status)));
    return (s_objectCount);
}
ObjectID Engine::ObjectMultitude::Global::make(Location&& loc, Identity&& id, Behaviour&& behaviour)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id, behaviour)));
    return (s_objectCount);
}
ObjectID Engine::ObjectMultitude::Global::make(Location&& loc, Identity&& id, Status&& status, Behaviour&& behaviour)
{
    Engine::ObjectMultitude::Global::s_globalObjectsMultitude[++ObjectMultitude::Global::s_objectCount] =
	std::move(std::unique_ptr<ObjectMultitude::Global::Vision>
	    (new ObjectMultitude::Global::ObjectBase(loc, id, status, behaviour)));
    return (s_objectCount);
}

Engine::ObjectMultitude::Global::Vision& Engine::ObjectMultitude::Global::get(ObjectID id)
{
    return(*Engine::ObjectMultitude::Global::s_globalObjectsMultitude[id]);
}

const Engine::ObjectMultitude::Global::Vision& Engine::ObjectMultitude::Global::getc(ObjectID id)
{
    return(*Engine::ObjectMultitude::Global::s_globalObjectsMultitude[id]);
}

//
//void ObjectMultitude::addGlobal(const ObjectVision* obj)
//{
//    s_globalObjectsMultitude[obj->getIdentity().getObjectID()] = std::make_shared<GlobalObjectBase>(obj);
//}
////void ObjectMultitude::addGlobal(const ObjectVision& obj)
////{
////    ObjectMultitude::addGlobal(&obj);
////}
//void ObjectMultitude::removeGlobal(const ObjectVision* obj)
//{
//    //ObjectMultitude::removeGlobal(*obj);
//}
////void ObjectMultitude::removeGlobal(const ObjectVision& obj)
////{
////    s_globalObjectsMultitude.erase(obj.getIdentity().getObjectID());
////}
//
//ObjectMultitude::GlobalObjectsMultitude::const_iterator const ObjectMultitude::GlobalMultitudeBegin()
//{
//    return (s_globalObjectsMultitude.cbegin());
//}
//ObjectMultitude::GlobalObjectsMultitude::const_iterator const ObjectMultitude::GlobalMultitudeEnd()
//{
//    return (s_globalObjectsMultitude.cend());
//}