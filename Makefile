build:
	g++ -w -std=c++14 -Wfatal-errors \
	./src/*.cpp \
	-o ./build_output/game \
	-I"./lib/lua" \
	-L"./lib/lua" \
	-llua5.4 \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

clean:
	rm ./game;

run:
	./game;
