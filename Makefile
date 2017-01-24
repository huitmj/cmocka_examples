all:
	gcc test_OverVoltage.c -lcmocka -Wl,--wrap=getAdcValue -I. -o test_OverVoltage

clean:
	rm -f *.o
