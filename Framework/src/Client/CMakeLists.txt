find_package(OpenSSL REQUIRED)

set(CMAKE_C_FLAGS "-pthread -g -O0 -fPIC -Wno-unused-variable -Wall -Wno-unused-function -fstack-protector-all")
set(CMAKE_CXX_FLAGS "-pthread -g -O0 -fPIC -Wno-unused-variable -Wall -Wno-unused-function -fstack-protector-all")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_executable(Client ${CLIENT_DIR}/Client.cpp)
target_include_directories(Client PRIVATE ${CLIENT_DIR} ${FRAMEWORK_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR})
target_link_libraries(Client ${LIB_UNTRUSTED} ${OPENSSL_CRYPTO_LIBRARY})
