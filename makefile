ProjAlgoProg.o: ProjAlgoProg.c FctProjAlgoProg.h
	gcc -c ProjAlgoProg.c

FctProjAlgoProg.o: FctProjAlgoProg.c FctProjAlgoProg.h
	gcc -c FctProjAlgoProg.c

ProjAlgoProg: ProjAlgoProg.o FctProjAlgoProg.o
	gcc ProjAlgoProg.o FctProjAlgoProg.o -o ProjAlgoProg -lm