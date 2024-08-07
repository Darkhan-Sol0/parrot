CC = gcc

AUTOR = thucydil AKA Darkhan-Sol0

VERSION = 0.69
BRANCH = main

EXEC = parrot

SOURCE = main.c

CFLAGS = -lncurses

all: clean run

$(EXEC): $(SOURCE)
	$(CC) $^ -o $@ $(CFLAGS)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(EXEC)

commit:
	@read -p "Enter commit message: " input; \
	git add -A; \
	git commit -m "$$input - $(EXEC) v:$(VERSION) - $(shell date +'%Y-%m-%d %H:%M')"; \
	git push origin $(BRANCH)