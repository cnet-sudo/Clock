# Analog Clock with SFML

[Русский](README.md) | **English**

![C++](https://img.shields.io/badge/C%2B%2B-14-00599C?logo=cplusplus)
![SFML](https://img.shields.io/badge/SFML-2.6.x-8CC445)

An educational application that displays the current local time in both
digital and analog form. The hand positions are calculated from the system
clock, while the entire clock face is drawn with SFML.

## What This Example Demonstrates

- reading local time through Windows CRT functions;
- drawing circles, rectangles, and text;
- placing marks and numbers on a circle with `sin` and `cos`;
- smooth minute- and hour-hand movement;
- isolating time-related logic in the `SFMLWorldTime` class.

## Structure

- `main.cpp` — window, clock face, and three hands;
- `SFMLWorldTime.*` — system-time access and digital clock;
- `Image` — application icon;
- `lib` — clock-face fonts.

## Requirements

- Windows and Visual Studio 2022, or another compatible compiler;
- CMake 3.21+;
- Git and an internet connection for the first CMake configuration.

## Building with CMake

SFML 2.6.x is downloaded automatically through `FetchContent`.

```powershell
cmake -S . -B build -DBUILD_SHARED_LIBS=OFF
cmake --build build --config Release
./build/Release/Clock.exe
```

The `Image` and `lib` directories are copied next to the executable
automatically.

## Building the Existing Solution

Open `Часы.sln`, select **x64**, and update the SFML paths in the project
properties if your library is not installed in the directory recorded in the
`.vcxproj` file.

## Controls

No controls are required. Close the window with the standard **×** button.

## Status

Complete educational example. It could be extended with an alarm clock, time
zone selection, scaling, and multiple visual themes.
