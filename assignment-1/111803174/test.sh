#!/bin/bash

#writing 100 bytes to file
touch /tmp/file1.txt
chmod 644 /tmp/file1.txt
cc w100byte.c -o w100byte
./w100byte data.txt
chmod 644 ./data.txt
cc write_data.c -o write_data 
./write_data data.txt /tmp/file1.txt
if [ $? -eq 1 ]
then
if cmp -s "./data.txt" "/tmp/file1.txt";
then
    echo "read100 pass"
else
    echo "read100 failed"
fi
else
    echo "write_data.c Failed" 
fi

#test read510

cc read510.c -o read510
readData=$(./read510 data.txt)
echo $readData > readed5bytes.txt
awk '{print substr($1, 5, 5)}' data.txt > bytesfromdata.txt
diff readed5bytes.txt bytesfromdata.txt
if [ $? -eq 0 ]
then
echo "read510 pass"
else
echo "read510 failed"
fi
rm bytesfromdata.txt
rm readed5bytes.txt


#test for append 10 bytes

cc write10end.c -o write10end
appendedData=$(./write10end a.txt)
echo $appendedData > appendeddata.txt
{
    readlast10=$(tail -c 10)
} < a.txt
echo $readlast10 > readeddata.txt

diff appendeddata.txt readeddata.txt
if [ $? -eq 0 ]
then 
echo "write10end pass"
else
echo "write10end failed"
fi
rm appendeddata.txt
rm readeddata.txt

#test for copy
touch /tmp/copyoffile.txt
chmod 644 /tmp/copyoffile.txt
cc copy.c -o copy
./copy existingfile.txt /tmp/copyoffile.txt
if [ $? -eq 0 ]
	then
	diff existingfile.txt /tmp/copyoffile.txt
		if [ $? -eq 0 ]
		then
		    echo "copy pass"
		else
		    echo "copy failed"
		fi
else
    echo "copy.c Failed"
fi

#test for rename
cc rename.c -o rename
./rename existingfile.txt renamedfile.txt
if [ $? -eq 1 ]
then
	diff existingfile.txt renamedfile.txt
		if [ $? -eq 0 ]
		then
		    rm existingfile.txt
		    echo "rename pass"
		else
		    echo "rename failed"
		fi
else
    echo "rename.c Failed"
fi



















# ./read510 read510.txt
# head -c10 read510.txt|tail -c5 >output
# cat output

# if [ $? -eq 0 ]
# then
#     echo "read510 Pass"
# else
#     echo "read510 Fail"
# fi



# ./copy copy.txt
# if [ $? -eq 0 ]
# then
#     echo "copy Pass"
# else
#     echo "copy Fail"
# fi

# a= wc -c a.txt
# echo $a
# ./write10end a.txt


# ./rename renamedfile.txt
# diff SEM6/Operating\ System/existingfile.txt  renamedfile.txt
# if [ $? -eq 0 ]
# then
#     echo "rename Pass"
# else
#     echo "rename Fail"
# fi