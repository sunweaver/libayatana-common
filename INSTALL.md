# Build and installation instructions

## For end-users and packagers

```
mkdir build
cd build
cmake ..
make
sudo make install
```
## For testers - unit tests only

```
mkdir build
cd build
cmake .. -DENABLE_TESTS=ON
make
make test
```
## For testers - both unit tests and code coverage

```
mkdir build
cd build
cmake .. -DENABLE_COVERAGE=ON
make
make test
make coverage
```
**The install prefix defaults to `/usr`, change it with `-DCMAKE_INSTALL_PREFIX=/some/path`**
