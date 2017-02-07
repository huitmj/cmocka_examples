#echo $LD_LIBRARY_PATH
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

all:
	gcc test_OverVoltage.c -lcmocka -Wl,--wrap=getAdcValue -I. -o test_OverVoltage

clean:
	rm -f *.o
