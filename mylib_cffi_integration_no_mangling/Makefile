build_run:
	@g++ -o ./mylib_wrapper.so ./mylib_wrapper.cpp -fPIC -shared -I../mylib -L../mylib -lmylib
	@LD_LIBRARY_PATH=../mylib python3 main.py
	@rm mylib_wrapper.so