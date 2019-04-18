CC := g++
FLAGS := -std=c++17 -Wall -Werror

%.o: %.cpp *.h *.hpp
	$(CC) $(FLAGS) -c $<

app.exe: main.o
	$(CC) -o $@ $^

run: app.exe clean
	./app.exe

clean:
	rm *.o
