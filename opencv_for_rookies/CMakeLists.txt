#g++ src.cpp src2.cpp -o excecutable `pkg-config opencv --cflags --libs`

cmake_minimum_required(VERSION 2.8)

project( Computer_Vision_Training )
set(
CMAKE_RUNTIME_OUTPUT_DIRECTORY 
../bin#${CMAKE_HOME_DIRECTORY}/bin
)

#find_package(OpenCV 3.2 REQUIRED)
find_package(OpenCV 2 REQUIRED)

add_executable( display_image display_image.cpp )
add_executable( video video.cpp )
add_executable( roi roi.cpp )
add_executable( salt_pepper salt_pepper.cpp )
add_executable( kinect kinect.cpp )
add_executable( mat mat.cpp )
add_executable( colorDetection colorDetection.cpp colordetector.cpp)
add_executable( photos photos.cpp)
add_executable( histo1d histo1d.cpp)
add_executable( negative negative.cpp)
add_executable( canny histograma.cpp canny.cpp)
add_executable( hdpe hdpe.cpp histograma.cpp)

add_executable( blancos blancos.cpp histograma.cpp)
add_executable( pony pony.cpp histograma.cpp)
add_executable( 7up 7up.cpp histograma.cpp)
add_executable( crop crop.cpp)

add_executable( polycolor algo/detector.cpp algo/polycolor.cpp algo/space.cpp)

target_link_libraries( polycolor ${OpenCV_LIBS} )

target_link_libraries( crop ${OpenCV_LIBS} )
target_link_libraries( 7up ${OpenCV_LIBS} )
target_link_libraries( pony ${OpenCV_LIBS} )
target_link_libraries( blancos ${OpenCV_LIBS} )
target_link_libraries( hdpe ${OpenCV_LIBS} )
target_link_libraries( canny ${OpenCV_LIBS} )
target_link_libraries( negative ${OpenCV_LIBS} )
target_link_libraries( histo1d ${OpenCV_LIBS} )
target_link_libraries( photos ${OpenCV_LIBS} )
target_link_libraries( colorDetection ${OpenCV_LIBS} )
target_link_libraries( mat ${OpenCV_LIBS} )
target_link_libraries( kinect ${OpenCV_LIBS} )
target_link_libraries( salt_pepper ${OpenCV_LIBS} )
target_link_libraries( roi ${OpenCV_LIBS} )
target_link_libraries( video ${OpenCV_LIBS} )
target_link_libraries( display_image ${OpenCV_LIBS} )
