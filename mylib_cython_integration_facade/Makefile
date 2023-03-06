build_run:
	@cd ../mylib && make build
	@python3 setup.py build_ext --inplace 
	@LD_LIBRARY_PATH=../mylib python3 main.py
	@rm -R build *.so my_extension.cpp