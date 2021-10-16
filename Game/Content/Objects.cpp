#include "../Content.hpp"

Engine::ObjectMultitude::ObjectID Game::Content::AxHunter::HunterDefault()
{
    Engine::ObjectComponent::Location locStart(Engine::MapComponent::Abscissa(0), Engine::MapComponent::Ordinate(0));
    Engine::ObjectComponent::Identity id('X', Visualization::Console::Color::Red);
    return(Engine::ObjectUtility::make(locStart, id));
}