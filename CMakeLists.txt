cmake_minimum_required(VERSION 3.5)

ADD_COMPILE_OPTIONS(-g)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LOCAL_W_FLAGS} ${LOCAL_C_FLAGS} -std=c++11 -fPIC")

SET(COMMON_HEADER_DIR common)
SET(THREAD_HEADER_DIR pthread/mutex
                      pthread/condition)
SET(IPC_HEADER_DIR ipc/pipe)

INCLUDE_DIRECTORIES(${COMMON_HEADER_DIR}/
                    ${THREAD_HEADER_DIR}/
                    ${IPC_HEADER_DIR}/)

ADD_SUBDIRECTORY(pthread/)
ADD_SUBDIRECTORY(ipc/)