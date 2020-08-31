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

    void loop() const;

    State getState() const;

    void setState(State state) const;
};
