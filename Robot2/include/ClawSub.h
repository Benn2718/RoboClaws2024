#include "vex.h"
#include "Constants.h"

#ifndef CLAWSUB_H
#define CLAWSUB_H

class ClawSub
{
    private:
        
    public:
        /**
         * Moves the claw
         * @param claw a pointer to the digital_out claw made in the main.cpp file
         * @param on on(true) or off(false)
         */
        void moveClaw(vex::digital_out* claw, bool on);
};

#endif