all:
	clear
	clang main.c -o app -Wall
#	./app
	./app > imagem.ppm
	xdg-open imagem.ppm
