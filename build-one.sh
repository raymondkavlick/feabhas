rm -f src/*.cpp
rm -f src/*.h

# if [ "$1" != "" ]; then
#     echo '$1 = ' $1
# else
#     echo "Positional parameter 1 is empty"
# fi

case "$1" in
  0)  echo "reset project"
      cp ./init_src/*.* src/
  ;;
  1)  echo "01_Command_line"
      cp ../../solutions/01_Command_line/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  2)  echo "02_Stream_IO"
      cp ../../solutions/02_Stream_IO/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  3)  echo "03_Pointers"
      cp ../../solutions/03_Pointers/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  4)  echo "04_Hardware_Manipulation"
      cp ../../solutions/04_Hardware_Manipulation/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  5)  echo "05_Functions"
      cp ../../solutions/05_Functions/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  6)  echo "06_Structuring_Code"
      cp ../../solutions/06_Structuring_Code/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  7)  echo "07_Structures_and_Tuples"
      cp ../../solutions/07_Structures_and_Tuples/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  8)  echo "08_Arrays"
      cp ../../solutions/08_Arrays/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  9)  echo "09_Creating_Objects"
      cp ../../solutions/09_Creating_Objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  10)  echo "10_Initialising_Objects"
      cp ../../solutions/10_Initialising_Objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  11)  echo "11_Objects_and_Functions"
      cp ../../solutions/11_Objects_and_Functions/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  12)  echo "12_HW_Manipulation_with_Objects"
      cp ../../solutions/12_HW_Manipulation_with_Objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  13)  echo "13_Complex_Objects"
      cp ../../solutions/13_Complex_Objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  14)  echo "14_Connecting_Objects"
      cp ../../solutions/14_Connecting_Objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  15)  echo "15_Overriding"
      cp ../../solutions/15_Overriding/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  16)  echo "16_Realising_Interfaces"
      cp ../../solutions/16_Realising_Interfaces/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  17)  echo "17_Interrupts"
      cp ../../solutions/17_Interrupts/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  18)  echo "18_Creating_Concurrent_Objects"
      cp ../../solutions/18_Creating_Concurrent_Objects/*.* src/
      scons --rtos || { echo 'build failed' ; exit 1; }
  ;;
  19)  echo "19_Mutual_Exclusion"
      cp ../../solutions/19_Mutual_Exclusion/*.* src/
      scons --rtos || { echo 'build failed' ; exit 1; }
  ;;
  20)  echo "20_Thread_Synchronisation"
      cp ../../solutions/20_Thread_Synchronisation/*.* src/
      scons --rtos || { echo 'build failed' ; exit 1; }
  ;;
  *)  echo "Incorrect Solution option 1-20"
  ;;
esac
