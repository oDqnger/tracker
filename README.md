# tracker
A program that tracks how much time you spend sitting at your ass in front of a computer all day.

the code might be kinda shit idk im new to c

# installation
btw this proly only works on any unix machine cuz the code used to calculate the time only works on unix gcc compilers and i use arch btw.

clone this repo, run `gcc -lm main.c -o program` to compile the code and then do `./program` to run it. obv this program is designed to run in the background so do `./program &`. you can check to see if its running by doing `ps -e` or doing `jobs` and if you want to kill the task just simply find the pid of the process and do `kill [pid]`.

now this is obv designed to run as soon as your turn on your computer and there are many ways to achieve this and i feel like this is dependent on ur distribution, wm or de. i personally use hyprland so i use the hyprland config file to make the program run on startup everytime.

# how to use
to check the time spent on your computer, there is a config txt file in the folder that the main.c file is located. all the info is stored there so simply do `cat config.txt` to see whats in it. this will only show your time spent for every session u start and not in total HOWEVER i will make that functionality very soon.
