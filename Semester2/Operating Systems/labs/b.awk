
NR == 1 {
	min = $5
	max = $5
	sum = sum +$5
}

NR > 1{
	sum = sum + $5
}

END {
	print((sum-min-max))/(NR-2)
}
find lab2_os type f -exec  ls -l {}\; | awk -f b.awk
