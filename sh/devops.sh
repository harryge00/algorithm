1)
cat 1.log|awk '{print $1}'| uniq -c|wc -l
cat 2.log|awk '{print $1}'| uniq -c|wc -l
2)
comm -13 <(sort -u 1.log|awk '{print $1}') <(sort -u 2.log|awk '{print $1}')

3)
#merge files:
cat 2.log >> 1.log
#count usernames
cat merged.log|awk '{print $2}'| uniq -c
# count IP numbers by usernames
cat merged.log|awk '{print '


awk '
		{
			users[$2]++
			if(!map[$1 $2]) {
				map[$1 $2]=1
				count[$2]++
			}
			
		}
		END{
			for(username in count) {
				print username, count[username]
			}
			print "now is the user count"
			for(username in users) {
				print username, users[username]
			}
		}
	'