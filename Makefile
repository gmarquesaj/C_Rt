all:
	clear
	clang main.c -o app -Wall
	./app
	convert imagem.ppm imagem.png
#	xdg-open imagem.ppm
	xdg-open imagem.png

