    
    for arg in -i -v -l -n -s -o 
    do
    ./s21_grep $arg ./2.txt ./s21_grep.c > s21_grep.txt
	grep $arg ./2.txt ./s21_grep.c > grep.txt
	res=`diff -s s21_grep.txt grep.txt`
    echo $res
    rm s21_grep.txt grep.txt
    if [[ $res != "Files s21_grep.txt and grep.txt are identical" ]]; then exit 1; fi
    done