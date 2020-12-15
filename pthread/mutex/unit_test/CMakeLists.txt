
ADD_COMPILE_OPTIONS(-fno-access-control)
aux_source_directory(../  MUTEX_SRC)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
ADD_EXECUTABLE(mutex_unit_test  mutex_unit_test.cpp ${MUTEX_SRC})
TARGET_LINK_LIBRARIES(mutex_unit_test -lpthread)
ADD_TEST(NAME mutex_unit_test COMMAND mutex_unit_test)