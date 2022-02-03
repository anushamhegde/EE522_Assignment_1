## Questions
1. ###  What size caches are present? 
I started by running some linux commands to get the cache size of the raspberry pi 4. At first I used command getconf -a | grep CACHE and the result was showing cache size zero. So I used dmesg | grep cache to get the cache details. Using reference 1, I confirmed the cache size for this particular processor.
![Rebooting system](./images/cache_zeros.PNG)  <br/><br/>
![Rebooting system](./images/cache_size.PNG)

2. ### What is the pin layout of this specific version of the target board?
Using reference 2,the pin layout of raspberry pi 4 model B is shown in below image with GPIO pins

![Rebooting system](./images/Pin_layout.PNG)  <br/><br/>
![Rebooting system](./images/GPIO.WebP)

3. ###  How much memory is available on the board?
Using command free -h the total memory,used and available memory is found.
![Rebooting system](./images/Memory.PNG)

4. ### How many different types of memory are on the board?


5. ### What is the name and release version of the Operating System used on the target board?
![Rebooting system](./images/Current_version.PNG)
6. ### What is the hardware version of the raspberry pi?
Hardware version of my raspberry pi 4 is ![Hardware Version](./images/Hardware_version.PNG)  <br/><br/>

7.   How long does it take for a context switch?
8. ### How much time does it take to copy 1 KB, 1 MB, and 1GB in bytes, half words, and words in RAM?
I used the reference 3 to understand how to get the speed of copy to the RAM.  <br/><br/>
a. Checking speed for 1K of data using command ```$sysbench --test=memory --memory-block-size=1K --memory-total-size=1K run``` ![Checking speed for 1K of data](./images/Speed_1K.PNG)  <br/><br/>
    
b. Checking speed for 1MB of data using command ```$sysbench --test=memory --memory-block-size=1K --memory-total-size=1G run``` ![Checking speed for 1MB of data](./images/Speed_1M.PNG)  <br/><br/>

c. Checking speed for 1GB of data using command ```$sysbench --test=memory --memory-block-size=1K --memory-total-size=1G run``` ![Checking speed for 1GB of data](./images/Speed_1GB.PNG)  <br/><br/>

d. Checking speed for 10GB of data using command ```$sysbench --test=memory --memory-block-size=1M --memory-total-size=10G run``` ![Checking speed for 10GB of data](./images/Speed_10GB.PNG)  <br/><br/>


9. ### How long does raspberry pi takes to boot from fresh?
Boot time very much depends on many factors including speed of the SD card using,clock speed of raspberry pi, power provided to pi and interfaces etc. In general it takes around 10-15 seconds to boot. For me when connecting through ssh it takes only 5 seconds to connect. 

9.  ### Understanding sudo halt and sudo shutdown
Its always a good practice to shutdown the board properly. Board can be shutdown using ```$sudo shutdown -h now``` or ```$sudo halt ``` .These commands will send SIGTERM to all running processes, notifying them to save their data and exit. It then sends SIGKILL to all remaining processes to halt the system, followed by finally unmounting all filesystems. The screen will then show System Halted and you can pull the plug. I have found in few articles that the sudo halt and sudo shutdown are almost the same since sudo halt will stop the power running in the device.    

10. ### What are the operating temperature ranges of raspberry pi 4 model b?
Operating temperature range is from -40 degree Celsius to 85 degree Celsius

11. ### Find and run some benchmarks? <br/><br/>
a. Using sysbench tool ran the command ```$sysbench --test=cpu --cpu-max-prime=10000 run``` 
![sysbench](./images/Benchmark_sysbench.PNG) <br/><br/>

b. Using sysbench with different command ```$sysbench cpu --threads=2 run``` ![sysbench](./images/sysbench_2.PNG) <br/><br/>

c. Using S-tui : S-tui is a CPU resource monitor that uses a terminal based graphical interface to display data and graphs(stress test). ```$s-tui``` to launch it. [S-tui](./images/S-tui.PNG) <br/><br/>

d. Using 7-Zip : Single threaded benchmark [7-zip ](./images/7-zip.PNG) <br/><br/>
multi-thread benchmark [7-zip multi thread ](./images/7-zip-multi_thread.PNG)

12. ### What would be a useful stress test to determine reliability?
A stress test that would max out specfic component of the system(CPU,GPU,RAM,storage,network card) for prolonged period of time and also monitoring the module being tested (such as performance,temperature etc) would help determining reliablity of componeny. Alternatively we can use stress test which would touch up on all these aspects to  determine reliablity of the overall  board. One such example is S-tui test for CPU testing. 











# References
1. http://sandsoftwaresound.net/raspberry-pi-4-arm-cortex-a72-processor/ 
2. https://www.etechnophiles.com/raspberry-pi-4-gpio-pinout-specifications-and-schematic/
3. https://www.cloudsavvyit.com/2521/how-to-test-your-unix-servers-disk-and-ram-speed/
4. https://linuxhint.com/useful_linux_stress_test_benchmark_cpu_perf/
5. 