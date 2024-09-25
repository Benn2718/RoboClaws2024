#include "vex.h";
#include "ClawSub.h"

using namespace vex;

void ClawSub::moveClaw(vex::digital_out* claw, bool on)
{
    claw->set(on);
}