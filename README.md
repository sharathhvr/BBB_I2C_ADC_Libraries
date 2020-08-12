# BBB_I2C_ADC_Libraries
I2C and ADC libraries for the Beagle Bone Black REV C running Debian 10 

**Note, you have to enable the ADC by loading the device tree overlay  
To load the device tree overlay for Beagle Bone Black running Debian 10 (4.19.94-ti-r42 kernel)  
Step1: sudo nano /boot/uEnv.txt  
Step2: Add "uboot_overlay_addr3=/lib/firmware/BB-ADC-00A0.dtbo"   
Step3: Save and Reboot. 
