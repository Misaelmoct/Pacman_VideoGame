# Pacman_VideoGame

## Description

<p>This project was build using the open source C++ toolkit OpenFrameworks. The project was part of the 
course Advance Programming or also known as Object Oriented Programming course. <p/>


## Set Up Everything

> Only for Windows OS.  
<br>  

1. Go to the [OpenFrameworks](https://openframeworks.cc/download/) download section and look for the [setup guide for msys2](https://openframeworks.cc/setup/msys2/).
2. Follow the docs on how to install everything.
> If an error occur while compiling related to 'ofOpenALSoundPlayer.h' go to "libs/openFrameworks/sound/ofOpenALSoundPlayer.h" file and change 
>the line "typedef	struct SNDFILE_tag	SNDFILE;" for "typedef	struct sf_private_tag	SNDFILE;".

3. Clone the repo into the "your_oF_directory/apps/myApps" directory. It should look like this "your_oF_directory/apps/myApps/Pacman_VideoGame/src".
4. Open the workspace on Visual Studio Code, open the terminal and run the command **_make_**.
> It should start compiling, it would take a while.  
> After the program compile run the command **_make RunRelease_**. A window will pop up with the game. Enjoy!  

<br>  
<br>  


> ## Start Menu

![image](https://user-images.githubusercontent.com/70610617/189960905-375e9209-dbfa-4c15-a371-5254b9418502.png)

<br>  
<br>  

> ## Game 
> For moving Up: w, Down: s, Left: a, Right: d  
> Spawning new ghost: g


![image](https://user-images.githubusercontent.com/70610617/189960819-dc2c691b-5a64-4994-923b-3147a49ae528.png)

<br>  
<br>  

> ## Game Over

![image](https://user-images.githubusercontent.com/70610617/189960646-84a09a7a-cb32-4502-b8ef-90ea37be611d.png)
