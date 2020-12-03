#include "simulator.hpp"

void Simulator::loop()
{
	while (event->isWork())
	{
		event->update();
		window->render();
	}
}
