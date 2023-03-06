build_run:
	@cd ../mylib && make build
	@g++ -shared -o mylib_wrapper.so -fPIC -I../mylib mylib_wrapper.cpp -L../mylib -lmylib
	@LD_LIBRARY_PATH=../mylib python3 main.py
	@rm mylib_wrapper.so