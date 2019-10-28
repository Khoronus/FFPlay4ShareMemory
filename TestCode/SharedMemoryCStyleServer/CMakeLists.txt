###############################################################################
cmake_minimum_required(VERSION 3.14)
project (SharedMemoryCStyleServer)

###############################################################################
# OpenCV
find_package(OpenCV REQUIRED PATHS "D:/src/opencv_3.4/sources/vs2017x64")
# Please set "target_link_libraries( ${PROJ_NAME}  ${OpenCV_LIBS})"

######################################################################
# Boost
SET(BOOST_ROOT "C:/local/boost")
SET(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib/x64/lib")
set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost REQUIRED COMPONENTS system thread regex filesystem date_time)
message("Boost_LIBRARY_DIR: " ${Boost_LIBRARIES})

######################################################################
# Add Shared Paths

add_subdirectory (code)
