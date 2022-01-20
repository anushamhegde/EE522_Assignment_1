  ```
  Anusha Hegde
  anuhegde@uw.edu
  ```
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
  ![auto login](./images/Console_auto_login.jpg)
 8.  Now rebooting the board from dekstop menu.
  ![Rebooting system](./images/Reboot.JPG)
 9. Next for setting up the WiFi I used the command $dmesg | more to check all the hardware connected. WiFi was not present. Then using command ```$sudo nano /etc/network/interfaces``` edited the file using instruction given in configuration file by Professor. It did not work. I tried many commands found in internet but couldn't work it. After spending more than an hour I connected the WiFi using desktop GUI. 
  ![WiFi](./images/WiFi.JPG)
 10. Changed target name using command $ sudo nano /etc/hosts and changes
``` 127.0.1.1 raspberry pi``` to ```127.0.1.1 ANUSHA0``` Then modified the hostname file too. After all these steps save and reboot using $ sudo reboot.
  ![Changing hostname](./images/Changing_hostname.JPG)
 11. Updated the software using ```$sudo apt-get``` update followed by command ```$sudo apt-get upgrade```. After update restart.
 12. ![Upgrade image](./images/Upgrade.JPG)
 13. Using command ```$sudo service --status --all``` checked if the ssh is working. 
   ![Enabling ssh](./images/ssh_enable.JPG)
   ![Working ssh](./images/Working_ssh.JPG)
   ![Verification](./images/ssh_username_verification.JPG)
 14. Verification to check the overall process ![Code for hello world](./images/Hello_world.JPG)

##  Road blocks

### Installing operating system

After connecting all the hardware components I inserted the MicroSD card which was preloaded with OS. I started seeing rainbow splash screen. I ensured my desktop is connected properly to the HDMI0 and power supply cable. Then I ensured if the MicroSD card is inserted all the way in the slot but raspberry pi did not boot. Finally I reinstalled the operating system to the MicroSD using Raspberry pi Imager.

### WiFi issues 

I faced some issues while connecting to the WiFi. I tried different approaches listed in the reference by adding wpa_spplicant.conf file with/without adding coutry code and text code given in the configuration file by professor. Then I tried using system configuration. After many tries I decided to set up the WiFi in GUI, unfortunately even that method did not work(my WiFi name wasn't coming up). Hence I reinstalled the operating system to the MicroSD and configured the raspberry pi from beginning. At last I set up the WiFi using GUI. (Forgot to take the screenshot of setting up WiFi using GUI)


## Conclusion

Configuration of raspberry pi 4 is has been sucessfully done.I faced some problems throughout the process but it was interesting and fun to do it since this was my first time working on hands on project.I have created the repository in github for this course and assignment. I am new to github so it took 4-5 hours to create and write in md file. It took around 3 hours to configure the raspberry pi. Excited and eager to learn more and explore the raspberry pi.

 

## References

1. https://www.tomshardware.com/reviews/raspberry-pi-set-up-how-to,6029.html
2. https://raspberrytips.com/raspberry-pi-wifi-setup/
3. https://www.seeedstudio.com/blog/2021/01/25/three-methods-to-configure-raspberry-pi-wifi/
4. https://howchoo.com/g/ndy1zte2yjn/how-to-set-up-wifi-on-your-raspberry-pi-without-ethernet
5. https://jamesjdavis.medium.com/how-to-update-raspberry-pi-just-follow-these-easy-steps-ac507cf70238


