cmake_minimum_required(VERSION 3.6.0 FATAL_ERROR)
project(FFPlay4ShareMemory)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set ( CMAKE_EXE_LINKER_FLAGS_RELEASE  "${CMAKE_EXE_LINKER_FLAGS_RELEASE} ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -std=c++11 -Wall ")
set ( CMAKE_EXE_LINKER_FLAGS_DEBUG  "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined ")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -std=c++11 -Wall -O0 -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -D__FORTIFY_SOURCE=2 -rdynamic -DDEBUG")

include(CMakeToolsHelpers OPTIONAL)

include_directories(${OpenCV_INCLUDE_DIRS} 
  "D:/workspace/programs/ThirdPartyProg/ffmpeg-msvc-build/ffmpeg"
  "D:/workspace/programs/ThirdPartyProg/ffmpeg-msvc-build/ffmpeg/fftools"
  "D:/workspace/programs/ThirdPartyLib/SDL2-2.0.10/include"
  "D:/workspace/university/todai/BirdView3D/src/Memory/SharedMemoryCStyle/code"
)

add_executable(FFPlay4ShareMemory main.c "D:/workspace/programs/ThirdPartyProg/ffmpeg-msvc-build/FFmpeg/fftools/cmdutils.c")
target_compile_options(FFPlay4ShareMemory PRIVATE "/TC")

set(AVLIB 
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/avdevice.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/avcodec.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/avformat.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/avutil.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/avfilter.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/swscale.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/swresample.lib"
  "D:/workspace/programs/ThirdPartyLib/ffmpeg-20190926-525de95-win64-dev/lib/postproc.lib"
)

set(SDL2LIBRARY 
  "D:/workspace/programs/ThirdPartyLib/SDL2-2.0.10/lib/x64/sdl2.lib" 
  "D:/workspace/programs/ThirdPartyLib/SDL2-2.0.10/lib/x64/sdl2main.lib"
)

set(SHAREDSTYLE
  "D:/workspace/university/todai/BirdView3D/src/Memory/SharedMemoryCStyle/build/code/release/SharedMemoryCStyle.lib"
)

target_link_libraries(FFPlay4ShareMemory ${OpenCV_LIBRARIES} ${AVLIB} ${SDL2LIBRARY} ${SHAREDSTYLE})
