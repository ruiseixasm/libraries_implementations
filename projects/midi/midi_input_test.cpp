// #include "..\..\includes\computer\rtmidi\RtMidi.h"
// #include "C:\Users\rui\Documents\GitHub\repositories\computer\rtmidi\RtMidi.h"
#include "RtMidi.h"

/**
 * @brief An example program for midi devices.
 * 
 * @return Returns 0 when execution completes successfully.
 */

RtMidiIn *midiin1;

int main()
{

    midiin1 = new RtMidiIn(RtMidi::UNSPECIFIED, "RtMidi Input Client", 100);
	delete midiin1;
	
    RtMidiIn midiin2;

    // try {
    //     RtMidiIn midiin;
    // } catch (RtMidiError &error) {
    //     // Handle the exception here
    //     error.printMessage();
    // }
    return 0;
}
