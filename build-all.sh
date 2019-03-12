
echo "+++++ BUILDING EX1 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/01_Command_line/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX2 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/02_Stream_IO/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX3 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/03_Pointers/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX4 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/04_Hardware_Manipulation/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX5 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/05_Functions/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX6 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/06_Structuring_Code/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX7 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/07_Structures_and_Tuples/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX8 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/08_Arrays/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX9 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/09_Creating_Objects/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX10 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/10_Initialising_Objects/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX11 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/11_Objects_and_Functions/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX12 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/12_HW_Manipulation_with_Objects/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX13 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/13_Complex_Objects/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX14 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/14_Connecting_Objects/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX15 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/15_Overriding/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX16 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/16_Realising_Interfaces/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX17 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/17_Interrupts/*.* src/
scons || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX18 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/18_Creating_Concurrent_Objects/*.* src/
scons --rtos || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX19 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/19_Mutual_Exclusion/*.* src/
scons --rtos || { echo 'build failed' ; exit 1; }

echo "+++++ BUILDING EX20 ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp ../../solutions/20_Thread_Synchronisation/*.* src/
scons --rtos || { echo 'build failed' ; exit 1; }

echo "+++++ Finished ++++++"
rm -f src/*.cpp
rm -f src/*.h
cp -f init_src/main.cpp src/main.cpp
