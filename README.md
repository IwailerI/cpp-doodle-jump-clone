# What is this?
This is a clone of a fairly popular mobile game [Doodle Jump](https://doodlejump.fun/). It was made solely for practice and tries to stay as close to the original as possible.

# Dependencies
This project uses [Allegro](https://liballeg.org/) for drawing and handling input. It must be installed in order to build from source. Some instruction can be found [here](https://github.com/liballeg/allegro_wiki/wiki/Quickstart). It should be on your include path.

# Building from source.


Run the cmake file using `cmake` (it must be installed, duh) and follow the native building instructions from there.

Example for Linux:

```sh
# if build/ does not exist:
mkdir build

# do not run cmake in root folder
cd build
cmake ..

# follow the native build instructions from here
# linux uses make
make

# game expects to be run from the root of the repo
# change back to root
cd ..

# run the game like so
./build/project
```
