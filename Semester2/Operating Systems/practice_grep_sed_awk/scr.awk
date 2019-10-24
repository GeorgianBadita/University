{
	for(i = 1; i<=NF; i++) SUM += $i
}

END{
	print SUM
}
