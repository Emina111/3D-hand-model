projekat:
	g++ -o projekat -I/usr/include/GL main.cpp -lGL -lGLU -lglut


.PHONY: clean
clean:
	rm -rf *.o projekat
