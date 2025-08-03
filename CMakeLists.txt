# versão do cmake
cmake_minimum_required(VERSION 3.22.1)
# nome e descrição do projeto
project(darlingdle VERSION 1.0 DESCRIPTION "Simulation of the  game based on dlegame ." LANGUAGES CXX)

# versao do C++ a ser usada
set(CMAKE_CXX_STANDARD 17)
# ativa o uso de recursos do C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define o diretório de saída para os binários
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# ativa a geração de arquivos de compilação
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# nome do executável
set(APP_NAME "darlingdle")

# procura dos arquivos .cpp de forma recursiva no diretório src
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

# inclução do diretório de cabeçalhos biblioteca internos
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#inclução do diretório de cabeçalhos da biblioteca externa
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# criação do executável
add_executable(${APP_NAME} ${SOURCES})

# opções de compilação
target_compile_options(${APP_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wno-deprecated
    -O3
)
