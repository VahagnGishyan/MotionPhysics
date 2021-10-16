#pragma once

//#include <list>
#include <map>
#include <memory>
#include <utility>

#include "Object.hpp"
#include "ObjectVision.hpp"

constexpr int ObjectDie = -1;

namespace Engine
{
    namespace ObjectMultitude
    {
	using ObjectID = Engine::ObjectComponent::Identity::ObjectID;
	class Global
	{
	private:
	    using Location = Engine::ObjectComponent::Location;
	    using Identity = Engine::ObjectComponent::Identity;
	    using Status = Engine::ObjectComponent::Status;
	    using Behaviour = Engine::ObjectComponent::Behaviour;
	public:
	    using ObjectBase = Engine::Object;
	    using Vision = Engine::ObjectVision;
	    using ObjectPtr = std::unique_ptr<Vision>;
	    using ObjectsMultitude = std::map<ObjectID, ObjectPtr>;

	    //using GlobalObjectsMultitude = std::map<Engine::ObjectComponent::Identity::ObjectID, std::shared_ptr<Engine::ObjectVision>>;

	private:
	    static ObjectsMultitude s_globalObjectsMultitude;
	    static int s_objectCount;

	public:
	    static ObjectID make(const Location& loc, const Identity& id);
	    static ObjectID make(const Location& loc, const Identity& id, const Status& status);
	    static ObjectID make(const Location& loc, const Identity& id, const Behaviour& behaviour);
	    static ObjectID make(const Location& loc, const Identity& id, const Status& status, const Behaviour& behaviour);

	    static ObjectID make(Location&& loc, Identity&& id);
	    static ObjectID make(Location&& loc, Identity&& id, Status&& status);
	    static ObjectID make(Location&& loc, Identity&& id, Behaviour&& behaviour);
	    static ObjectID make(Location&& loc, Identity&& id, Status&& status, Behaviour&& behaviour);

	    static Vision& get(ObjectID id);
	    static const Vision& getc(ObjectID id);

	    static ObjectsMultitude::const_iterator const GlobalMultitudeBegin();
	    static ObjectsMultitude::const_iterator const GlobalMultitudeEnd();
	};
    }
}
