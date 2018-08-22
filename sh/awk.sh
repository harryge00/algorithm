echo $1
awk -F ' ' 'BEGIN {sum += $2+$3+$4; print $0, sum}  END {print sum}' $1

awk '{average=($4+$2+$3)/3} {
	if (average >= 80) {
		result = "A"
	} else if (average >= 60 ) {
		result = "B"
	} else if (average >= 50 ) {
		result = "C"
	} else {
		result = "FAIL"
	}
} { print $0, ":", average, result}' students.txt