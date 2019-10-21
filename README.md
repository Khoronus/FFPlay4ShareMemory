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

# Additional requirements
Download the Simple Directmedia Layer (SDL2) libraries (binary and development) libraries.
https://www.libsdl.org/download-2.0.php




# Additional link
Please, consider to check the following project to build ffmpeg under Windows.
https://github.com/m-ab-s/media-autobuild_suite

