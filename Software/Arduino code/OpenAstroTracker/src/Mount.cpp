#include "Mount.hpp"
#include <log4arduino.h>

Mount::Mount()
{
    state = State::PARKED;
}

Mount::~Mount()
{
}

void Mount::loop()
{
}

void Mount::setState(State state)
{
    LOG("Setting mount state to %i", state);
}

Mount::State Mount::getState()
{
    return state;
}
