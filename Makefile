.PHONY: clean
.SUFFIXES:

#variables
ZIP = zip
TARGET = Listuino.zip
LIB_DIR = Listuino/
DEBUG = no
FLAGS = -r

#création de l'exécutable
all:
	$(ZIP) $(FLAGS) $(TARGET) $(LIB_DIR)
	@echo "Archive créee."

# clean
clean:
	rm -f Listuino.zip
