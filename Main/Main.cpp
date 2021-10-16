
#include <memory>
#include <map>

#include "../Engine/Resource.hpp"
#include "../Engine/ObjectsMultitude.hpp"
#include "../Engine/Map.hpp"
#include "../Visualization/Console.hpp"
#include "../Game/Content.hpp"
#include "../Engine/ObjectUtility.hpp"


Engine::MapComponent::Features* Game::Process::Controller::s_map = nullptr;
Engine::ObjectMultitude::Global::ObjectsMultitude  Engine::ObjectMultitude::Global::s_globalObjectsMultitude;
int Engine::ObjectMultitude::Global::s_objectCount = 0;

int main()
{
    std::unique_ptr<Engine::Map> map(Game::Content::MakeMap::longway());
    Visualization::Console::import(*map);

    Engine::ObjectComponent::Location locStart(Engine::MapComponent::Abscissa(0), Engine::MapComponent::Ordinate(0));
    Engine::ObjectComponent::Location locEnd(Engine::MapComponent::Abscissa(Game::Process::Controller::getMap()->getLength() - 1),
	Engine::MapComponent::Ordinate(Game::Process::Controller::getMap()->getHeight() - 1));

    Engine::ObjectComponent::Identity idHunter('X', Visualization::Console::Color::Red);
    Engine::ObjectComponent::Identity idAim('O', Visualization::Console::Color::Green);

    Engine::ObjectMultitude::ObjectID hunter = Engine::ObjectUtility::make(locStart, idHunter);
    Engine::ObjectMultitude::ObjectID aim = Engine::ObjectUtility::make(locEnd, idAim);

    Visualization::Console::print(hunter);
    Visualization::Console::print(aim);

    while (Engine::ObjectUtility::isalive(aim))
    {
	if (Engine::ObjectUtility::isRouteEmpty(hunter))
	{
	    Engine::ObjectUtility::RoutePlanner(*map, hunter, aim);
	}

	Sleep(150);
	Engine::ObjectUtility::nextStep(hunter);

	if (Engine::ObjectUtility::isLocationMatch(hunter, aim))
	    Engine::ObjectUtility::die(aim);
    }

    return 0;
}



    //Engine::Resource obj = Engine::ResourceManager::Make(4);

    //Engine::Food    food  = Engine::ResourceManager::Make(4);
    //Engine::Wood    wood  = Engine::ResourceManager::Make(4);
    //Engine::Stone   stone = Engine::ResourceManager::Make(4);
    //Engine::Coal    coal  = Engine::ResourceManager::Make(4);
    //Engine::Iron    iron  = Engine::ResourceManager::Make(4);
    //Engine::Gold    gold  = Engine::ResourceManager::Make(4);

    //std::cout << "food = " << food << std::endl;
    //std::cout << "wood = " << wood << std::endl;
    //std::cout << "stone = " << stone << std::endl;
    //std::cout << "coal = " << coal << std::endl;
    //std::cout << "iron = " << iron << std::endl;
    //std::cout << "gold = " << gold << std::endl;