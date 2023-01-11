FLAGS = -w
C = g++
OUTDIR = build
LIBDIR = libs
OBJDIR = objs

all: final

final: main.o command_info.o times.o time_section.o 
	$(C) $(FLAGS) $(OBJDIR)/main.o $(OBJDIR)/command_info.o $(OBJDIR)/times.o $(OBJDIR)/time_section.o -o $(OUTDIR)/final.out


main.o: main.cpp
	$(C) $(FLAGS) -c main.cpp
	mv main.o $(OBJDIR)

command_info.o: $(LIBDIR)/command_info.cpp
	$(C) $(FLAGS) -c $(LIBDIR)/command_info.cpp
	mv command_info.o $(OBJDIR)

times.o: $(LIBDIR)/times.cpp
	$(C) $(FLAGS) -c $(LIBDIR)/times.cpp
	mv times.o $(OBJDIR)

time_section.o: $(LIBDIR)/time_section.cpp
	$(C) $(FLAGS) -c $(LIBDIR)/time_section.cpp
	mv time_section.o $(OBJDIR)

utils.o: $(LIBDIR)/utils.cpp
	$(C) $(FLAGS) -c $(LIBDIR)/utils.cpp
	mv utils.o $(OBJDIR)

clean:
	rm $(OBJDIR)/main.o $(OBJDIR)/command_info.o $(OBJDIR)/times.o $(OBJDIR)/time_section.o
