#pragma once

// Object Vision = only read
// Object Base   = read and write

#include "Objects/Location.hpp"
#include "Objects/Status.hpp"
#include "Objects/Identity.hpp"
#include "Objects/Behaviour.hpp"

namespace Engine 
{
    class ObjectVision
    {
    public:
	    virtual const Engine::ObjectComponent::Location&	getLocation()   const = 0;
	    virtual const Engine::ObjectComponent::Status&	getStatus()	const = 0;
	    virtual const Engine::ObjectComponent::Identity&	getIdentity()   const = 0;
	    virtual const Engine::ObjectComponent::Behaviour&	getBehaviour()  const = 0;

	    virtual const void	changeLocation(const Engine::ObjectComponent::Location&)    = 0;
	    virtual const void	changeStatus(const Engine::ObjectComponent::Status&)	    = 0;
	    //virtual const void	changeIdentity(const Engine::ObjectComponent::Identity&)    = 0;
	    virtual const void	changeBehaviour(const Engine::ObjectComponent::Behaviour&)   = 0;

	    //ObjectVision(const ObjectVision* obj) {}
	    virtual ~ObjectVision() {}
    };
}

/*

    class ObjectInterface
    {
    public:
	virtual Engine::ObjectComponent::Location	getLocation()   const;
	virtual Engine::ObjectComponent::Status		getStatus()	const;
	virtual Engine::ObjectComponent::Identity	getIdentity()   const;
	virtual Engine::ObjectComponent::Behaviour	getBehaviour()  const;

	//ObjectVision(const ObjectVision* obj) {}
	virtual ~ObjectInterface() {}
    };
    class ObjectVision : public ObjectInterface
    {
	virtual ~ObjectVision()  {}
    };

*/