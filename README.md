<b>***  We have released v1.2.2 that fixes OTAA RX2 Join problem, click on [release](https://github.com/gimasi/GMX_LR1_AT_MODEM/releases) to download the binary ***</b>
<br/>
<br/>

# GMX_LR1_AT_MODEM

This is LoRaWAN stack & AT Modem implementation for the GMX-LR1 node. 
It is based on [ST I-CUBE LRWAN](http://www.st.com/en/embedded-software/i-cube-lrwan.html), which in turn is based on [Semtech](https://github.com/Lora-net/LoRaMac-node) code.<br>

The GMX-LR1 module is used with the multiprotocol IoT [Tuino 1] development board but if you want you can use it also with your hardware.
Here a picture of the module:<br/>
<br/>
![GMX-LR1](/docs/img/gmxfoto1.png?raw=true)
<br/>
<b>The full source is coming very soon...</b> for now we are publishing the binaries for firmaware updates.
<br/>
# Using the module with the Tuino 1 
The full source code and documentation of the client library for the Tuino 1 is [here](https://github.com/gimasi/TUINO_ONE/tree/master/tuino_libs/gmx/gmx_lr).<br/>
<br/>
We will be adding also a repository on client code for a general STM32 micro ( that should work also with other microcontrollers being pure C ) so to give an example on how to drive the GMX-LR1 module in your custom hardware project.<br/>
<br/>
We are thinking also of putting together an Arduino Shield and Raspberry Pie shield for the GMX bus so that you can use the module also with other boards, please give us feedback on this.<br/>
<br>

# Updating the GMX-LR1 firmware with the Tuino 1
To update the firmware of the module via the USB cable of the Tuino you need:
* to upload the bootloader script on the Tuino 1 board, which is the [firmware_update/tuino1-gmax-lr1-bootloader](firmware_update/tuino1-gmax-lr1-bootloader) folder. This code simply makes a passthrough on the two serials of the Tuino 1 connecting the GMX-LR1 serial to the USB port, and at the same time booting the module in the STM32 bootloader mode.
*  the excellent STM32 Bootloader utility from Tomasz Watorowski, since the [ST](http://www.st.com/en/development-tools/flasher-stm32.html) original one dosen't really work well. 
The original project is here [STBootLib](https://github.com/MightyDevices/STBootLib) but for convenience we copied the binaries in [firmware_update/STM32FlashLoader](firmware_update/STM32FlashLoader) folder.<br/>

Once you have uploaded the tuino1-gmax-lr1-bootloader sketch on the Tuino 1 board you have to launch the STM32FlashLoader.<br/>
<br/>
![STM32Flash](/docs/img/Stm32FlashLoader.png?raw=true)
<br/>
<br/>
1. Choose the COM port where your TUINO is connected (usually the last COM port in the list).
2. Set the page size to 128 ( using the pulldown and not writing directly the number).
3. Select the .bin file from the directory where you have downloaded it.
4. Press "Write Firmware & Jump".
5. When the "Programming" action is reaching 100% the LED's on the green LoRaWAN module will flash. If they don't flash, it means something went wrong and please repeat the procedure, first resetting the Tuino 1 board.
6. Install your own use case again on the Tuino 1 board via the Arduino IDE

