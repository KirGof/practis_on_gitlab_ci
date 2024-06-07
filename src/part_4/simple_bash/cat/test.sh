    

    for arg in -v -n -b -t -e 
    do
	./s21_cat $arg 1.txt > my_file.txt
	cat $arg 1.txt > cat_file.txt
	res=`diff -s my_file.txt cat_file.txt`
    rm my_file.txt cat_file.txt
    if [[ $res != "Files my_file.txt and cat_file.txt are identical" ]]; then exit 1; fi
    done