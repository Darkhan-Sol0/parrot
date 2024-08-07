CC = gcc

AUTOR = thucydil AKA Darkhan-Sol0

VERSION = 0.69
BRANCH = main

EXEC = parrot

SOURCE = main.c

CFLAGS = -lncurses

all: clean install

$(EXEC): $(SOURCE)
	$(CC) $^ -o $@ $(CFLAGS)

run: $(EXEC)
	~/parrot/$(EXEC)

install: $(EXEC)
	mkdir -p ~/$(EXEC)
	install -D $(EXEC) ~/$(EXEC)/
	cp -r ./frames ~/$(EXEC)/
	echo "~/\$(EXEC)/\$(EXEC)" >> ~/.bashrc

uninstall:
	rm -rf ~/parrot

clean: uninstall
	rm -rf $(EXEC)

commit:
	@read -p "Enter commit message: " input; \
	git add -A; \
	git commit -m "$$input - $(EXEC) v:$(VERSION) - $(shell date +'%Y-%m-%d %H:%M')"; \
	git push origin $(BRANCH)