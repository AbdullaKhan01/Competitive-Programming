export MallocNanoZone=0
for((i=1;i<100;i++));do
	echo $i
	./tester > input
	./sol < input > output1
	./stupid < input > output2
	diff -w output1 output2 || break 
done