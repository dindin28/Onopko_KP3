cmake_minimum_required(VERSION 3.10)

project(KP3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#========================
#PVS-Studio option
#========================
option(ANALYZE "Analyze code with PVS-Studio" OFF)

#========================
#Option to show constructors
#========================
option(CONSTRUCTORS "Option to show creating and destroying classes" OFF)

#========================
#Headers
#========================
set(headers_path "${PROJECT_SOURCE_DIR}/include")

#========================
#Sources
#========================
file(GLOB srcs "src/*.cpp")

#========================
#Building executable
#========================
add_executable(${PROJECT_NAME} ${srcs})

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
    ${headers_path}
)

if(CONSTRUCTORS)
  add_compile_definitions(${PROJECT_NAME} PRIVATE CONSTRUCTORS)
endif()

if(ANALYZE)
  include(PVS-Studio.cmake)
  pvs_studio_add_target(TARGET example1.analyze ALL
                        OUTPUT FORMAT errorfile
                        ANALYZE ${PROJECT_NAME}
                        MODE GA:1,2
                        LOG target.err)
endif()