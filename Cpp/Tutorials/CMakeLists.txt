#CM_LIB= -L/home/matous/Work/Root6/build/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
#ROOT_PATH=/home/matous/Work/Root6/build/include



#set( ROOT_DIR /home/matous/Work/Root6/ )
#inc, lib, include 

#Required version
cmake_minimum_required( VERSION 3.4 )

#This will not work on older versions of CMake
set (CMAKE_CXX_STANDARD 11)


#Required project name
project( Tutorials )


#Creating shared library (*.so file)
#add_library( MyLibrary SHARED mylib.h mylib.cxx )
#add_library( MyLibrary SHARED ${CM_LIB} )
#target_include_directories( MyLibrary PUBLIC ${ROOT_DIR}/lib )
#target_include_directories( MyLibrary PUBLIC ${CMAKE_SOURCE_DIR}/lib )


add_executable( allaboutpointers AllAboutPointers/AllAboutPointers.cxx )

#target_link_libraries( myexe MyLibrary )





