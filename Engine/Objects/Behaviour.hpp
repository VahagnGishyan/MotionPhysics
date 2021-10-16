#pragma once

#include "../MotionPhysics.hpp"

namespace Engine
{
    namespace ObjectComponent
    {
	struct Behaviour
	{
	    Engine::MotionPhysics::Route m_way;
	};
	//class Action
	//{
	//    virtual Action& operator=(Action*) = 0;
	//};

	//class Behaviour
	//{
	//private:
	//    std::unique_ptr<Action> m_activeAction;
	//public:
	//    Behaviour() {}
	//    Behaviour(const Action& obj);
	//    void setAction(Action*);
	//    void resetActiveAction();
	//};
    }
}