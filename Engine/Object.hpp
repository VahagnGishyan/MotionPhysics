#pragma once

#include "ObjectVision.hpp"

// Object Vision = only read
// Object Base   = read and write

#include "Objects/Location.hpp"
#include "Objects/Status.hpp"
#include "Objects/Identity.hpp"
#include "Objects/Behaviour.hpp"

namespace Engine
{
    class Object : public Engine::ObjectVision
    {
    private:
	using Location = Engine::ObjectComponent::Location;
	using Identity = Engine::ObjectComponent::Identity;
	using Status = Engine::ObjectComponent::Status;
	using Behaviour = Engine::ObjectComponent::Behaviour;
    private:
	Engine::ObjectComponent::Location   m_location;
	Engine::ObjectComponent::Identity   m_identity;
	Engine::ObjectComponent::Status	    m_status;
	Engine::ObjectComponent::Behaviour  m_behaviour;

    public:
	Object(const Location& loc, const Identity& id) : m_location(loc), m_identity(id) {}
	Object(const Location& loc, const Identity& id, const Status& status) : m_location(loc), m_identity(id), m_status(status) {}
	Object(const Location& loc, const Identity& id, const Behaviour& behaviour) : m_location(loc), m_identity(id), m_behaviour(behaviour) {}
	Object(const Location& loc, const Identity& id, const Status& status, const Behaviour& behaviour) 
	    : m_location(loc), m_identity(id), m_status(status), m_behaviour(behaviour) {}

	Object(Location&& loc, Identity&& id) : m_location(loc), m_identity(id) {}
	Object(Location&& loc, Identity&& id, Status&& status) : m_location(loc), m_identity(id), m_status(status) {}
	Object(Location&& loc, Identity&& id, Behaviour&& behaviour) : m_location(loc), m_identity(id), m_behaviour(behaviour) {}
	Object(Location&& loc, Identity&& id, Status&& status, Behaviour&& behaviour) : m_location(loc), m_identity(id), m_status(status), m_behaviour(behaviour) {}
	
	~Object() override {}

	virtual const Location&	 getLocation()   const override;
	virtual const Identity&	 getIdentity()   const override;
	virtual const Status&	 getStatus()	const override;
	virtual const Behaviour& getBehaviour()  const override;

	Location& getLocation() { return m_location; }
	Identity& getIdentity() { return m_identity; }
	Status& getStatus() { return m_status; }
	Behaviour& getBehaviour() { return m_behaviour; }

	virtual const void	changeLocation(const Engine::ObjectComponent::Location&) override;
	virtual const void	changeStatus(const Engine::ObjectComponent::Status&) override;
	//virtual const void	changeIdentity(const Engine::ObjectComponent::Identity&)   override;
	virtual const void	changeBehaviour(const Engine::ObjectComponent::Behaviour&) override;

	//virtual Engine::Objects::Identity	    getIdentity()   const override;
    };
}

