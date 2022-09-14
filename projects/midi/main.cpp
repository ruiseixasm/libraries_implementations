#include "..\..\includes\computer\rtmidi\RtMidi.h"

/**
 * @brief An example program for midi devices.
 * 
 * @return Returns 0 when execution completes successfully.
 */

int main()
{
    try {
        RtMidiIn midiin;
    } catch (RtMidiError &error) {
        // Handle the exception here
        error.printMessage();
    }
    return 0;
}