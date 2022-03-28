all: s21_matrix_oop.a test

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib $@
	cp $@ lib$@
	ranlib lib$@

s21_matrix_oop.o: s21_matrix_oop.cpp
	g++ -c -o s21_matrix_oop.o s21_matrix_oop.cpp

test: s21_matrix_oop.a
	g++ --coverage s21_matrix_oop.cpp test.cpp -o test -lgtest
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d ./
	genhtml -o report test.info
	open -a "Safari" ./report/index.html

check:
	cp ../materials/linters/CPPLINT.cfg . && python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h
	rm -f CPPLINT.cfg
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction *.cpp *.h

clean:
	rm -rf ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./report *.info ./*.info report ./Test
