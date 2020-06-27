FLAGS := `pkg-config gtk+-3.0 --cflags --libs`
FILE_O :=  $(patsubst src/%.cpp,bin/%.o, $(wildcard src/*.cpp))
HEADERS_DIR := headers/

app.exe: $(FILE_O)
	g++ -o app.exe -I $(HEADERS_DIR) $^ $(FLAGS)

bin/%.o: src/%.cpp
	mkdir -p bin
	g++ -c -I $(HEADERS_DIR) $^ -o $@ $(FLAGS)

run:
	./app.exe

clean:
	rm -f *.o *.exe *.out -r bin