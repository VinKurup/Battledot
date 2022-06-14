link_target = battledotnet
obj = main.o battledotnet.o player.o grid.o
rebuild = $(link_target) $(obj)
cc = g++

BattleDotNet: $(obj)
	$(cc) -pthread $(obj) -o $(link_target)

main.o: main.cpp battledotnet.cpp
	$(cc) -c main.cpp

battledotnet.o: battledotnet.h player.cpp grid.cpp
	$(cc) -c battledotnet.cpp

grid.o: grid.h
	$(cc) -c grid.cpp

player.o: player.h grid.cpp
	$(cc) -c player.cpp

clean:
	rm -f $(rebuild) $(fd)