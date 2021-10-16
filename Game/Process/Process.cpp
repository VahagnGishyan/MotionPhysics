#include "../Process.hpp"

void	Game::Process::Controller::import(Engine::MapComponent::Features& mmap)
{
    if (Game::Process::Controller::s_map)
	return;
    Game::Process::Controller::s_map = &mmap;
}

const Engine::MapComponent::Features* Game::Process::Controller::getMap()
{
    return (Game::Process::Controller::s_map);
}
