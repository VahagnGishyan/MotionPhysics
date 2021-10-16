#include "../../Object.hpp"

using Location	= Engine::ObjectComponent::Location;
using Identity	= Engine::ObjectComponent::Identity;
using Status	= Engine::ObjectComponent::Status;
using Behaviour	= Engine::ObjectComponent::Behaviour;

const Location&    Engine::Object::getLocation()   const
{
    return (m_location);
}
const Identity&    Engine::Object::getIdentity()   const
{
    return (m_identity);
}
const Status&	    Engine::Object::getStatus()	    const
{
    return (m_status);
}
const Behaviour&   Engine::Object::getBehaviour()  const
{
    return (m_behaviour);
}

const void	Engine::Object::changeLocation(const Engine::ObjectComponent::Location& loc)
{
    m_location = loc;
}
const void	Engine::Object::changeStatus(const Engine::ObjectComponent::Status& status)
{
    m_status = status;
}
//virtual const void	changeIdentity(const Engine::ObjectComponent::Identity&)   override;
const void	Engine::Object::changeBehaviour(const Engine::ObjectComponent::Behaviour& beh)
{
    m_behaviour = beh;
}

