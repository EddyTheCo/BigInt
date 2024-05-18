cmake_minimum_required(VERSION 3.11)
include(${CMAKE_CURRENT_BINARY_DIR}/local_conf.cmake OPTIONAL)

include(FetchContent)
FetchContent_Declare(
  ccommon
  GIT_REPOSITORY https://github.com/EddyTheCo/Common.git
  GIT_TAG v0.4.0)
FetchContent_MakeAvailable(ccommon)
version_from_git(LOG OFF TIMESTAMP "%Y%m%d%H%M%S")

project(
  QtbigInt
  VERSION ${VERSION}
  DESCRIPTION "uint256 uint128 library "
  LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
include(GNUInstallDirs)

find_package(Qt6 COMPONENTS Core)
if(Qt6_FOUND)
  qt_standard_project_setup()

  add_library(qbigint qbigint.cpp include/qbigint.hpp include/arith_uint256.h
                      src/arith_uint256.cpp)
  add_library(${PROJECT_NAME}::qbigint ALIAS qbigint)
  set_target_properties(qbigint PROPERTIES VERSION ${VERSION} SOVERSION
                                                              ${VERSION_MAJOR})

  target_link_libraries(qbigint PUBLIC Qt6::Core)

  target_include_directories(
    qbigint PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                   "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/Esterv/>")

  install(
    TARGETS qbigint
    EXPORT ${PROJECT_NAME}-config
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    COMPONENT bigint
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT bigint)
  install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Esterv
    COMPONENT ${PROJECT_NAME})

  build_exports()
  if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    build_cpack()
    if(BUILD_TESTING)
      include(CTest)
      add_subdirectory(tests)
    endif(BUILD_TESTING)
  endif(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
endif(Qt6_FOUND)
if(BUILD_DOCS)
  build_docs()
endif()
