#include "Mount.hpp"
#include <log4arduino.h>

Mount::Mount()
{
    state = State::PARKED;
}

Mount::~Mount()
{
}

void Mount::loop() const
{
}

void Mount::setState(State state) const
{
    LOG("Setting mount state to %i", state);
}

Mount::State Mount::getState() const
{
    return state;
}
