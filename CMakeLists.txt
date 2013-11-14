CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(wxwidgets_demo)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

# Find wxWidgets and check for required modules
FIND_PACKAGE(wxWidgets REQUIRED core base gl)
INCLUDE(${wxWidgets_USE_FILE})
SET (wxWidgets_WXCONFIG_OPTS "--static=yes")
# We define the include paths here, our wxstartapp source dir is one,
# and also the include dirs defined by wxWidgets
INCLUDE_DIRECTORIES(
    ${wxstartapp_SOURCE_DIR} 
    ${wxWidgets_INCLUDE_DIRS}
)

message("-- Check for GLUT (optional)")
if (APPLE)
  add_definitions(-DAPPLE)
# As Apple default GLUT doesn't support scroll event, we'll use FreeGLUT
# instead. You can enable this statement, if you have some trouble with it.
# set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -framework GLUT")
  set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL")
  find_package(FREEGLUT REQUIRED)
else (APPLE) # Linux, not so much
  find_package(OpenGL REQUIRED)
  find_package(FREEGLUT REQUIRED)
  include_directories(${OPENGL_INCLUDE_DIRS} ${FREEGLUT_INCLUDE_DIRS})
endif (APPLE)

ADD_EXECUTABLE(wx_gltest main_gl.cpp)
TARGET_LINK_LIBRARIES(wx_gltest ${wxWidgets_LIBRARIES} ${OPENGL_LIBRARIES} ${FREEGLUT_LIBRARY})

ADD_EXECUTABLE(wx_hello main.cpp)
TARGET_LINK_LIBRARIES(wx_hello ${wxWidgets_LIBRARIES})
