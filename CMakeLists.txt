CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Find wxWidgets and check for required modules
FIND_PACKAGE(wxWidgets REQUIRED core base)
IF(wxWidgets_FOUND)

    # Include wxWidgets macros
    INCLUDE(${wxWidgets_USE_FILE})

    # Set some specific wx options
    SET (wxWidgets_WXCONFIG_OPTS "--static=yes")

    # Our project is called 'wxstartup' this is how it will be called in
    # visual studio, and in our makefiles.
    PROJECT(wxstartup)

    # We define the include paths here, our wxtest source dir is one,
    # and also the include dirs defined by wxWidgets
    INCLUDE_DIRECTORIES(
        ${wxtest_SOURCE_DIR} 
        ${wxWidgets_INCLUDE_DIRS}
    )

    # For convenience we define the sources as a variable. You can add
    # header files and cpp / c files and CMake will sort them out
    # SET(SRCS wxtest.cpp )
    file (GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        [^.]*.cpp
        [^.]*.h
    )

    # If we build for windows systems, we also include the resource file
    # containing the manifest, icon and other resources
    IF(WIN32)
        SET(SRCS ${SRCS} wxtest.rc)
    ENDIF(WIN32)

    # Here we define the executable wxtest.exe or wxtest on other systems
    # the above paths and defines will be used in this build
    ADD_EXECUTABLE(wxtest WIN32 ${SRCS})
    GET_TARGET_PROPERTY(MyExecutable_PATH wxtest LOCATION)

    # create bundle on apple compiles
    IF (APPLE)
        ADD_EXECUTABLE(wxtest MACOSX_BUNDLE ${SRCS} )
    ELSE (APPLE)
        ADD_EXECUTABLE(wxtest ${SRCS} )
    ENDIF (APPLE)

    # We add to our target 'wxtest' the wxWidgets libraries. These are
    # set for us by the find script. If you need other libraries, you
    # can add them here as well.
    TARGET_LINK_LIBRARIES(wxtest ${wxWidgets_LIBRARIES} )

ELSE(wxWidgets_FOUND)
    # For convenience. When we cannot continue, inform the user
    MESSAGE("wxWidgets not found!")
ENDIF(wxWidgets_FOUND)
