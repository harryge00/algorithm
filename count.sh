 #! /bin/sh
if [ $# -eq 0 ]
	then
	echo "filename required"
	exit
fi
i=1
totalCh=0
totalWd=0
totalLn=0
for file in $*; do
	echo "file$i stats:"
	if [ ! -f $file ]
		then
		echo "no such file"
	else
		ch=$(wc $file|awk '{print $3}')
		echo "Number characters $ch"
		wn=$(wc $file|awk '{print $2}')
		echo "Number words $wn"
		ln=$(wc $file|awk '{print $1}')
		echo "Number lines $ln"
		totalLn=`expr $ln + $totalLn`
		totalCh=`expr $ch + $totalCh`
		totalWd=`expr $wn + $totalWd`
	fi
	i=`expr $i + 1`
done
echo "$totalCh $totalWd $totalLn"
