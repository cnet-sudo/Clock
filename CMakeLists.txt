# Заявляем какой версией собирать проект 
cmake_minimum_required(VERSION 3.10)
# Имя проекта важно
project(Часы VERSION 0.0.1)
include_directories("C:\IT\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include")
link_directories("C:\IT\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\lib")
# Создаёт exe файл Myland из TestCmakeFileH.cpp
# Автоматом подтягивает файлы hieder заголовков MyFile.h 
# add_executable(MyLand TestCmakeFileH.cpp MyFile.cpp )
# Перечисляем все рабочие файлы и MyFile.h будет в дереве исходников
# add_executable(MyLand TestCmakeFileH.cpp MyFile.cpp MyFile.h )
# Можно сделать это через переменные
set(SOURCES
main.cpp
SFMLWorldTime.cpp
)
set(HEADERS
SFMLWorldTime.h
)
add_executable(Clock ${SOURCES} ${HEADERS})

target_link_libraries(Clock sfml-window sfml-graphics sfml-main sfml-system) 

# Добавление свойств к файлу MyLand
set_target_properties(
Clock PROPERTIES        # MyLand
CXX_STANDARD 14          # Собирать стандартом не ниже С++14
CXX_STANDARD_REQUIRED ON # Стандарт обязателен
)
