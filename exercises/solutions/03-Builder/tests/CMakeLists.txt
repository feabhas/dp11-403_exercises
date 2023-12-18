
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# find_package(googletest REQUIRED)
# include(googletest)

set(SUPPORT_FILES ${CMAKE_SOURCE_DIR}/src/EventLog.cpp ${CMAKE_SOURCE_DIR}/src/DateTime.cpp)

add_executable(ELParser el_parser_tests.cpp ${CMAKE_SOURCE_DIR}/src/EventLogParser.cpp ${SUPPORT_FILES})

target_include_directories(ELParser PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/inc
 )

target_link_libraries(ELParser GTest::gtest_main gmock)

include(GoogleTest)
gtest_discover_tests(ELParser)