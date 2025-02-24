# Clock
A little clock app You can use inside your console

## Installation
```
git clone https://github.com/trzeciak20p/clock
cd clock
g++ main.cpp src/display.cpp src/settings.cpp -o clock
```

## Usage
Simply run `clock` followed by `[flags]` of Your own choosing
### Flags
|Flag| Description 
|----|------------
|-h, -help| displays help
|-d, -date| enable date display
|ns, -no-seconds| hides seconds
|-m, -mode \<mode>| changes the looks <br> <text, small, digital, analog>
