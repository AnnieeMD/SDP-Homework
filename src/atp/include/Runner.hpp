#pragma once

#include "Commands.hpp"

class Runner {

private:

    Runner() {}
    Runner(const Runner&);
    Runner& operator=(const Runner&);

public:

    static Runner& getInstance() {
        static Runner instance;
        return instance;
    }

    void run();
};