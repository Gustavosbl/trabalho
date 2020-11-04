SOURCES = App/main.cpp src/Controllers/jogo/jogo.cpp src/Models/personagem/personagem.cpp src/Models/cenarioJogo/cenarioJogo.cpp src/Models/textura/textura.cpp src/Models/teclado/teclado.cpp src/Views/view.cpp -lSDL2 -lSDL2_image

main:
	g++ -g -Wall -o main $(SOURCES)

test: main
	./main

zip: main
	zip -R ex3.zip Makefile *.cpp *.hpp *.png *jpeg

clean:
	rm -rf *.zip ./main