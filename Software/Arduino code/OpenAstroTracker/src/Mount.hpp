#pragma once

class Mount
{
public:

    enum class State
    {
        PARKED = 0,
        TRACKING = 1
    };

private:
    State state;
    
public:
    Mount();
    ~Mount();

    void loop();

    State getState();

    void setState(State state);
};
