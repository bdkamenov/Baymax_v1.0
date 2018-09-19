cmake_minimum_required(VERSION 2.8)
project(Baymax)

set(CMAKE_CXX_STANDARD 14)

# used to set the build type to be a release/debug build
set(CMAKE_BUILD_TYPE Debug)

# used to bring the header files into the build environment
include_directories(/usr/include/ baymax_core/graphics/ baymax_core/maths/)

# | Can manually add the sources using the set command as follows:
# | set(SOURCES engine_core/main.cpp)

# However, the file(GLOB...) allows for wildcard additions:
file(
GLOB MATH_SOURCES
"baymax_core/maths/*.cpp")

file(
GLOB GRAPHICS_SOURCES
"baymax_core/graphics/*.cpp")

set(GLEW_STATIC_LIB libGLEW.a)
set (GLFW_STATIC_LIB libglfw3.a)
set(GL_LIBRARY glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread)

link_directories(~/Programming/libs//glew-2.1.0/lib)
link_directories(~/Programming/libs/glfw-3.2.1/build/src)

#---------- Adding an executable ----------#
# | The first argument to the add_executable() function
# | is the name of the executable to be built,
# | and the second argument is the source file
# | from which to build the executable.
add_executable(Baymax.exe baymax_core/baymax.cpp ${MATH_SOURCES} ${GRAPHICS_SOURCES})
#------------------------------------------#

target_link_libraries(Baymax.exe ${GLEW_STATIC_LIB} ${GLFW_STATIC_LIB} ${CMAKE_DL_LIBS} ${GL_LIBRARY} )

#---------- Generating a shared or static library example ----------#
# | Generate the shared library from the sources.
# | built as a shared library using the SHARED flag
# | (other options are: STATIC or MODULE),
# | and the <name> name is used as the name of the shared library.
# | add_library(<name> SHARED ${SOURCES})
# |
# | Set the location for library installation -- i.e., /usr/lib in this case
# | not really necessary in this example. Use "sudo make install" to apply.
# | Deployment is invoked using a call to sudo make install in this case.
# | install(TARGETS <name> DESTINATION /usr/lib)
#-------------------------------------------------------------------#


#---------- Using a shared or static library example ----------#
# | For the shared library:
# | set ( PROJECT_LINK_LIBS libtestStudent.so )
# | link_directories( ~/exploringBB/extras/cmake/studentlib_shared/build )

# | For the static library:
# | set ( PROJECT_LINK_LIBS libtestStudent.a )
# | link_directories( ~/exploringBB/extras/cmake/studentlib_static/build )

# include_directories(~/exploringBB/extras/cmake/studentlib_shared/include)

# add_executable(libtest libtest.cpp)
# target_link_libraries(libtest ${PROJECT_LINK_LIBS} )
#--------------------------------------------------------------#

include_directories(tests)
ENABLE_TESTING()
ADD_EXECUTABLE(Math_Tests tests/math_test.cpp ${MATH_SOURCES})
ADD_TEST(Math_Tests Math_Tests)