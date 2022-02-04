  ```
  Anusha Hegde
  anuhegde@uw.edu
  https://github.com/anushamhegde/EE522_Assignments
  ```
 # Assignment 2

 ## Objective
The objective of this assignment is to understand the theoretical capabilities of the raspberry pi board that includes understanding of the software and hardware features, its options,performance and limitations of the board. In this assignment the goal is to characterize the board, learn more about the capabilities and build the next steps of the exploration of the raspberry pi. 

## Installing library

I installed the BCM2835 pin library using link provided in the assignment ``` http://www.airspayce.com/mikem/bcm2835/bcm2835-1.50.tar.gz```. It was working fine until the sudo make check, I got the error ![Library error](./images/Library_error.PNG)<br/><br/>  ![Library error](./images/Lib_error.PNG)<br/><br/>
To resolved that I referred to reference 7 and could not fix it. Then after installing the latest version of the library problem was solved. ![Library configuration ](./images/Configuring_lib.PNG)<br/><br/> ![Make](./images/Make_lib.PNG)<br/><br/>

## Questions
1. ###  What size caches are present? 
I started by running some linux commands to get the cache size of the raspberry pi 4. At first I used command ```$getconf -a | grep CACHE``` and the result was showing cache size zero. So I used ```$dmesg | grep cache``` to get the cache details. Using reference 1, I confirmed the cache size for this particular processor.<br/><br/>
![Image showing cache zeros](./images/cache_zeros.PNG)  <br/><br/>
![Image showing cache size from one of the references](./images/cache_size.PNG) <br/><br/>

2. ### What is the pin layout of this specific version of the target board?
Using reference 2,the pin layout of raspberry pi 4 model B is shown in below image with GPIO pins

![Pin layout of raspberry pi](./images/Pin_layout.PNG)  <br/><br/>
![GPIO pin](./images/GPIO.WebP)<br/><br/>

3. ###  How much memory is available on the board?
Using command free -h the total memory,used and available memory is found.
![Memory info](./images/Memory.PNG)<br/><br/>

4. ### How many different types of memory are on the board?
There are 4 types of memory in raspberry pi overall. RAM(2GB/4GB/8GB),L1(32KB) and L2(512KB) cache memory,and MicroSD of variable sizes. <br/><br/>

5. ### What is the name and release version of the Operating System used on the target board?
![Version](./images/Current_version.PNG)<br/><br/>

6. ### Processors detail of the raspberry pi
 ![details](./images/Hardware_version.PNG)  <br/><br/>

7. ### How long does it take for a context switch?
A context switch could take anywhere from a few 100 nanoseconds to few microseconds depending upon the CPU architecture and the size of the context that is to be saved and restored. <br/><br/>

8. ### How much time does it take to copy 1 KB, 1 MB, and 1GB in bytes, half words, and words in RAM?
I used the reference 3 to understand how to get the speed of copy to the RAM.  <br/><br/>
a. Checking speed for 1K of data using command ```$sysbench --test=memory --memory-block-size=1K --memory-total-size=1K run``` <br/><br/>![Checking speed for 1K of data](./images/Speed_1K.PNG)  <br/><br/>
    
b. Checking speed for 1MB of data using command ```$sysbench --test=memory --memory-block-size=1K --memory-total-size=1G run``` <br/><br/>![Checking speed for 1MB of data](./images/Speed_1M.PNG)  <br/><br/>

c. Checking speed for 1GB of data using command ```$sysbench --test=memory --memory-block-size=1K --memory-total-size=1G run``` <br/><br/>![Checking speed for 1GB of data](./images/Speed_1GB.PNG)  <br/><br/>

d. Checking speed for 10GB of data using command ```$sysbench --test=memory --memory-block-size=1M --memory-total-size=10G run``` <br/><br/>![Checking speed for 10GB of data](./images/Speed_10GB.PNG)  <br/><br/>


9. ### How long does raspberry pi takes to boot from fresh?
Boot time depends on many factors including speed of the SD card using,clock speed of raspberry pi, power provided to pi and interfaces etc. In general it takes around 10-15 seconds to boot. For me when connecting through ssh it takes only 2 seconds to connect.   <br/><br/>

10.   ### Understanding sudo halt and sudo shutdown
Its always a good practice to shutdown the board properly. Board can be shutdown using ```$sudo shutdown -h now``` or ```$sudo halt ``` .These commands will send SIGTERM to all running processes, notifying them to save their data and exit. It then sends SIGKILL to all remaining processes to halt the system, followed by finally unmounting all filesystems. The screen will then show System Halted and you can pull the plug. I have found in few articles that the sudo halt and sudo shutdown are almost the same since sudo halt will stop the power running in the device.   <br/><br/> 

11.  ### What are the operating temperature ranges of raspberry pi 4 model b?
Operating temperature range is from -40 degree Celsius to 85 degree Celsius. <br/><br/>

12. ### Find and run some benchmarks? <br/><br/>
a. Using sysbench tool ran the command ```$sysbench --test=cpu --cpu-max-prime=10000 run``` 
 <br/><br/>![sysbench](./images/Benchmark_sysbench.PNG) <br/><br/>

b. Using sysbench with different command ```$sysbench cpu --threads=2 run``` <br/><br/> ![sysbench](./images/sysbench_2.PNG) <br/><br/>

c. Using S-tui : S-tui is a CPU resource monitor that uses a terminal based graphical interface to display data and graphs(stress test). ```$s-tui``` to launch it.<br/><br/> ![S-tui](./images/S-tui.PNG) <br/><br/>

d. Using 7-Zip : Single threaded benchmark ![7-zip ](./images/7-zip.PNG) <br/><br/>
multi-thread benchmark <br/><br/> ![7-zip multi thread ](./images/7-zip_multi_thread.PNG) <br/><br/>

13. ### What would be a useful stress test to determine reliability?
A stress test that would max out specfic component of the system(CPU,GPU,RAM,storage,network card) for prolonged period of time and also monitoring the module being tested (such as performance,temperature etc) would help determining reliability of component. Alternatively we can use stress test which would touch up on all these aspects to determine reliability of the overall  board. One such example is S-tui test for CPU testing.  <br/><br/>

14. ### Is active cooling neccessary to maintain performance.

By looking at the difference between the performace of the CPU in the below images we can see the CPU throttling. When the fan was attached to the board the frequency of operation was high (1800MHz). When the fan and heat sink was removed the operating frequency has decreased significantly. 
![With cooling device ](./images/With_fan.PNG)
![Without cooling ](./images/Without_fan.PNG)   <br/><br/>

15. ### What is the compiler name and version?
![Compiler name and version](./images/Compiler_version.PNG) <br/><br/>

16. ### Reading from moisture sensor
As a start to my final project, I began with reading from moisture sensor using C and python with WiringPi library. Since I am new to C ,I started coding with python to help understand the process of reading sensor. I have attached my python code below. <br/><br/>![Python code to read moisture sensor data](./images/Python_code.PNG) <br/><br/>
C code is shown below <br/><br/>![C code to read moisture sensor data](./images/C_code.PNG)  
Output of the C code <br/><br/>![C code output of moisture sensor](./images/C_output.PNG)<br/><br/>

![Image of moisture sensor connected with raspberry pi](./images/Prototype_img_1.JPG) <br/><br/>
![Image of moisture sensor connected with raspberry pi](./images/Prototype_img_2.JPG)

## Conclusion 

Characterization of the board is achieved with understanding of the features of raspberry pi 4 board and running some code in C and python. Time taken was around 8-9 hours. If the prototype is scaled up to 1000 or 10000 units,3-4 moisture sensors can be accomodated in one raspberry pi, and sensors are not expensive. Only major cost contribution would be from the raspberry pi boards. From this assignment I learned more about raspberry pi features and how to work with it using few examples. Hoping to explore more in next few weeks. 





## References
1. http://sandsoftwaresound.net/raspberry-pi-4-arm-cortex-a72-processor/ 
2. https://www.etechnophiles.com/raspberry-pi-4-gpio-pinout-specifications-and-schematic/
3. https://www.cloudsavvyit.com/2521/how-to-test-your-unix-servers-disk-and-ram-speed/
4. https://linuxhint.com/useful_linux_stress_test_benchmark_cpu_perf/
5. https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf
6. https://community.element14.com/products/raspberry-pi/b/blog/posts/how-hot-is-too-hot-for-raspberry-pi
7. https://groups.google.com/g/bcm2835/c/BwZXVsDRtwI
8. http://wiringpi.com/reference/core-functions/
9. https://bob.cs.sonoma.edu/IntroCompOrg-RPi/sec-cgpio.html