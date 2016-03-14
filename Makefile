# Asteroids 3D
EXE=main

# Main target
all: $(EXE)
#  Link
main: bullet
	./src/qmake && make

#  Clean
clean:
	./src/make/clean
cleanall: clean cleanBullet

# Clean and make
cleanmake: clean main

# Get and build bullet
bullet:
	./bScript.sh

cleanBullet:
	rm -rf bullet3-2.83.6 2.83.6.zip
