# getting started
* install and extract
* this command does not work
```
g++ -std=c++17 -Wall -Wextra -pthread -Ilib/googletest/googletest/include -Llib/googletest/googletest -lgtest -lgtest_main test/test_main.cpp -o test/test_main
```
But this work (copy content of \lib\googletest\build\lib in mingw lib)
```
g++ -std=c++17 -Wall -Wextra -pthread -Ilib/googletest/googletest/include test/test_main.cpp -Llib/googletest/googletest -lgtest -lgtest_main -o test/test_main
```

But perfect command would be (without copy content of \lib\googletest\build\lib in mingw lib):
````
g++ -std=c++17 -Wall -Wextra -pthread -Ilib/googletest/googletest/include test/test_main.cpp -Llib/googletest/build/lib -lgtest -lgtest_main -o test/test_main
````
* Create a directory called "build" inside the extracted folder.
Move to the "build" directory.

* Execute the following commands:
For Linux/macOS:
````
cmake ..
make
````
For Windows (using MinGW):
````
cmake -G "MinGW Makefiles" ..
mingw32-make
````
* 
