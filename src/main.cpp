#include "Logic.h"
#ifdef ARDUINO_ARCH_RP2040
    #include "FileTransferModule.h"
#endif
#include "OpenKNX.h"
#ifdef ARDUINO_ARCH_RP2040
    #pragma message "Pico Core Version: " ARDUINO_PICO_VERSION_STR
#endif

void setup()
{
    const uint8_t firmwareRevision = 1;
    openknx.init(firmwareRevision);
    openknx.addModule(1, new Logic());
#ifdef ARDUINO_ARCH_RP2040
    openknx.addModule(2, new FileTransferModule());
#endif
    openknx.setup();
}

void loop()
{
    openknx.loop();
}
