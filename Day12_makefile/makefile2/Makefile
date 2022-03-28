$(CC)=gcc

appln: main.o calc_mean.o cal_sub.o
	$(CC) main.o calc_mean.o cal_sub.o -o appln11
main.o: main.c calc_mean.h
	$(CC) -c main.c
calc_mean.o: calc_mean.c calc_mean.h
	$(CC) -c calc_mean.c
cal_sub.o: cal_sub.c calc_mean.h
	$(CC) -c cal_sub.c
clean:
	rm -f *.o
