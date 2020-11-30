# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(PacMen)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#
add_executable(PacMen App/main.cpp)

# Especificar onde estao os header files
include_directories(Include/Controllers)
include_directories(Include/Models)
include_directories(Include/Views)

# Adiciona SDL2 e SDL image no arquivo
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


# Bibliotecas locais (estaticas)
add_library(bolinha src/Models/bolinha/bolinha.cpp)
target_link_libraries(PacMen bolinha)

add_library(cenarioJogo src/Models/cenarioJogo/cenarioJogo.cpp)
target_link_libraries(PacMen cenarioJogo)

add_library(personagem src/Models/personagem/personagem.cpp)
target_link_libraries(PacMen personagem)

add_library(teclado src/Models/teclado/teclado.cpp)
target_link_libraries(PacMen teclado)

add_library(textura src/Models/textura/textura.cpp)
target_link_libraries(PacMen textura)


add_library(view src/Views/view.cpp)
target_link_libraries(PacMen view)


add_library(imageprocessing src/Controllers/imageprocessing/imageprocessing.cpp)
target_link_libraries(PacMen imageprocessing)

add_library(jogo src/Controllers/jogo/jogo.cpp)
target_link_libraries(PacMen jogo)



# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatizacao do Doxygen
find_package(Doxygen REQUIRED dot)

set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN EXTRACT_STATIC YES)
set(DOXYGEN_TEMPLATE_RELATIONS YES)
set(DOXYGEN_COLLABORATION_GRAPH YES)
set(DOXYGEN_UML_LOOK YES)
set(DOXYGEN_CLASS_GRAPH YES)

doxygen_add_docs(doc)