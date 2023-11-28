sudo pacman -Sy wget unzip catch2
cd ~ 
mkdir test 
cd test 
wget https://bitbucket.org/HR_ELEKTRO/ems30/raw/master/Programmas/breuk-test.zip 
unzip breuk-test.zip 
cd breuk-test 
mkdir build 
cd build 
cmake .. 
make ./test_breuk