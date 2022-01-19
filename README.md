 # Assignment 1 
 ## Objective
 The Objective of the assignment is to build and configure the embedded development environment for the raspberry pi.  In this assignment the goal is to learn the basics of hardware and software part of the raspberry pi and troubleshooting the problems that encountered during the initial set up.

 ## Procedure
 1. Set up the raspberry pi board with all the equipmemts provided starting with the box to encase, connecting fan, connecting to keyboard mouse to USB port. Connect to desktop(HDMI0) and power supply. 
 2. Inserting the MicroSD card after the first step.
 3. Switching on the power to the raspberry pi board. The MicroSD should have already be preloaded with NOOBS in it. But for me it was not working and I got the rainbow splash screen in the desktop. I ensured everything was connected properly.
 4. I referred to www.canakit.com/pi/recovery to get details on what needs to be done.
 5. Installed Raspberry pi Imager to install the Operating system Raspberry Pi OS 32-bit Bullseye version into the MicroSD card using my Mac.
 6. After OS has been installed to my MicroSD I connected that back to raspberry pi board and I got the first page in my desktop to select the Language and time zone. 
 7. Using $ sudo raspi -config command choose the console auto login option. 
 8. ![Alt text](/relative/path/to/img.jpg?raw=true "Optional Title")
 9. ![Getting started](./images/Console_auto_login.jpg)
 10. Now rebooting the board from dekstop menu.
 11. Next for setting up the WiFi I used the command $dmesg | more to check all the hardware connected. WiFi was not present. Then using command $ sudo nano /etc/network/interfaces edited the file using instruction given in configuration file by Professor. It did not work. I tried many commands found in internet but couldn't work it. After spending more than an hour I connected the WiFi using desktop GUI. 
 12. Changed target name using command $ sudo nano /etc/hosts and changes 127.0.1.1 raspberry pi to 127.0.1.1 ANUSHA0. Then modified the hostname file too. After all these steps save and reboot using $ sudo reboot.
 13. Updated the software using $sudo apt-get update followed by command $ sudo apt-get upgrade. After update restart.
 14. Using command @ sudo service --status --all checked if the ssh is working. 
 15. ![Getting started](Console_auto_login.jpg)

 ![Alt text](/relative/path/to/img.jpg?raw=true "Optional Title")


rtghrth
 ![alt text](https://github.com/anushamhegde/EE522_Assignment_1/tree/master//Console_auto_login.jpg?raw=true)
