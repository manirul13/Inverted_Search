a.out : main.o create_database.o display_database.o file_list.o insert_last.o save_database.o search.o update_database.o
	gcc -o a.out main.o create_database.o display_database.o file_list.o insert_last.o save_database.o search.o update_database.o

main.o : main.c
	gcc -c main.c

create_database.o : create_database.c
	gcc -c create_database.c

display_database.o : display_database.c
	gcc -c display_database.c

file_list.o : file_list.c
	gcc -c file_list.c

insert_last.o : insert_last.c
	gcc -c insert_last.c

save_database.o : save_database.c
	gcc -c save_database.c

search.o : search.c
	gcc -c search.c

update_database.o : update_database.c
	gcc -c update_database.c

clean:
	rm -f *.out *.o
