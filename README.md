# FFPlay4ShareMemory
A modified version of ffplay project to build and to support shared memory on Windows.

# How to start
Clone a ffmpeg build project for windows from the following link
https://github.com/mcmtroffaes/ffmpeg-msvc-build
or from an older fork
https://github.com/Khoronus/ffmpeg-msvc-build

Follow the instruction about requirements and how to build.
If mysis cannot execute build.sh:
 - edit set_env.bat and modify APPVEYOR_BUILD_FOLDER with the current location.
 - open a console, and change the directory to the current location.
 - set_env.bat
 - build.bat
 - C:\msys64\usr\bin\bash      (msys64 it is expected to be located at that path)
 - "$APPVEYOR_BUILD_FOLDER/build.sh"

It is possible that it is not necessary to build the code from source.

# Additional requirements
Download the Simple Directmedia Layer (SDL2) libraries (binary and development) libraries.
https://www.libsdl.org/download-2.0.php


# Additional link
Please, consider to check the following project to build ffmpeg under Windows.
https://github.com/m-ab-s/media-autobuild_suite


# Useful references for C/C++ mixing code
https://www.oracle.com/technical-resources/articles/it-infrastructure/mixing-c-and-cplusplus.html
https://stackoverflow.com/questions/2744181/how-to-call-c-function-from-c

# Check the network usage (Win)
Win+R and type Resmon.exe (Resource Monitor)

# License
Please refer to the FFMpeg project for the license information (FFmpeg codebase is mainly LGPL-licensed with optional components licensed under GPL) 
https://www.ffmpeg.org
https://github.com/FFmpeg/FFmpeg 

