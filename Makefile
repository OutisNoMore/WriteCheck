ODIR = bin
IDIR = src
CC = g++
FLAGS = -g -Wall -I $(ODIR) -I $(IDIR)

Check.exe: $(ODIR)/main.o $(ODIR)/WriteCheck.o
	$(CC) $(FLAGS) $^ -o $@

$(ODIR)/main.o: $(IDIR)/main.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(ODIR)/WriteCheck.o: $(IDIR)/WriteCheck.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(ODIR)/*.o Check.exe
