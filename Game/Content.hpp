#pragma once

#include "../Engine/Map.hpp"
#include "../Engine/ObjectsMultitude.hpp"
#include "../Engine/ObjectUtility.hpp"
#include <exception>


namespace Game
{
    /*class Level
    {
    private:

    public:
	static Levels
    }*/
    namespace Content
    {
	class MakeMap
	{
	public:
	    static Engine::Map* cleanSlate(Engine::MapComponent::Metrology::Length length,
		Engine::MapComponent::Metrology::Height height);
	    static Engine::Map* cleanSlate(int, int) = delete;
	    static Engine::Map* createFrom(std::vector<std::string>& tmap);
	    static Engine::Map* withPrimitiveBarrier();
	    static Engine::Map* longway();
	    static Engine::Map* labirint();
	    static Engine::Map* village();
	    static Engine::Map* city();
	};

	namespace AxHunter
	{
	    Engine::ObjectMultitude::ObjectID HunterDefault();
	    //Engine::ObjectMultitude::ObjectID HunterDefault(const Engine::MapComponent::Location& loc,
	    //	const Engine::ObjectComponent::Identity& id);
	    //static ObjectID make(const Location& loc, const Identity& id, const Status& status);
	    //static ObjectID make(const Location& loc, const Identity& id, const Behaviour& behaviour);
	    //static ObjectID make(const Location& loc, const Identity& id, const Status& status, const Behaviour& behaviour);

	    //static ObjectID make(Location&& loc, Identity&& id);
	    //static ObjectID make(Location&& loc, Identity&& id, Status&& status);
	    //static ObjectID make(Location&& loc, Identity&& id, Behaviour&& behaviour);
	    //static ObjectID make(Location&& loc, Identity&& id, Status&& status, Behaviour&& behaviour);
	}
    }
}