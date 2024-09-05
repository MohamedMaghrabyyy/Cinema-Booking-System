#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include "OnlineAuth.h"

class NotRobot : public OnlineAuth {
public:
    void authorize() override;
};

#endif