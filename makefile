.ONESHELL:
.PHONY: clean build

build:
	cmake -S . -B ./build -G "Visual Studio 16 2019" -A x64
	cmake --build ./build

release:
	cmake --build ./build --config Release

clean:
	- rmdir /s /q build
	- rmdir /s /q CMakeFiles