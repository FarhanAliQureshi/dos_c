# DOS C Programs and Utilities
I wrote these programs and utilities, when I was a teenager in the 90s, for MS-DOS 5.0 and MS-DOS 6.22 etc. I used Turbo C and later Turbo C++. I'll port each program to Open Watcom C/C++ 2.0, add comments, maybe refactor code, and add a Makefile. After testing programs in FreeDOS or DOSBox, I'll add it here.

## Projects
| Project | Name | Notes |
| --- | --- | --- |
| [EvenOdd](evenodd/) | Even or Odd Number | Prints out whether a number is an even number or an odd number. |
| [RandNum](randnum/) | Random Number Generator | Prints out a random number. |
| [PrimeNum](primenum/) | Naive Prime Number Finder | A very naive method to determine whether a number is a prime number or not. |
| [CelsFahr](celsfahr/) | Celsius and Fahrenheit Converter | Celsius to Fahrenheit converter and vice versa. |
| [DistConv](distconv/) | Mile and Kilometer Converter | Mile to Kilometer converter and vice versa. |
| [StpWatch](stpwatch/) | Stopwatch | A simple stopwatch. |
| [StpWtch2](stpwtch2/) [📷](#stopwatch-v2-with-elapsed-time) | Stopwatch v2 | A simple stopwatch but the elapsed time is displayed while the stopwatch is running. |
| [GuessNum](guessnum/) [📷](#guess-the-number-game) | Guess Number Game | A simple Guess the Number game. |
| [Today](today/) [📷](#today-current-date-and-time) | Current Date and Time | Displays current date and time in Pakistani-British style. <br /><br />Before we started using Windows 95, this was the last program to execute in the `AUTOEXEC.BAT` file. |
| [Weekday](weekday/) [📷](#calculate-weekday-of-a-date) | Calculate Weekday from Date | Displays weekday of the given date. <br /><br />We used it during planning events etc, to check the weekday of any future date. |
| [BismKey](bismkey/) | Bismillah with key wait | Displays text-based Bimillah calligraphy, and wait for the user to press any key to exit. |
| [Bism](bism/) [📷](#bismillah-text-based-calligraphy) | Bismillah with timer | Displays text-based Bimillah calligraphy, and wait for timer or any key to exit. The default timer is 3 seconds, but a new timer can be supplied through command-line arguments. For example, `BISM.EXE 0.5` for half a second timer. <br /><br />In the old days, before adopting Windows 95, this was executed as the second-last program in `AUTOEXEC.BAT`, before `TODAY.EXE` was executed. |
| [Allah](allah/) [📷](#name-of-allah-text-based-calligraphy) | Name of Allah | Displays text-based name of Allah calligraphy, with sparkles in background. |
| [AsciiChr](asciichr/) | ASCII Character-set | Display Extended ASCII Character-set, from character 0 to character 255. |
| [AsciiTbl](asciitbl/) [📷](#ascii-character-set-table) | ASCII Character-set Table | Display Extended ASCII Character-set in a tabular format in 16 columns, from character 0 to character 255. |
| [SortNum](sortnum/) | Sort Numbers Array | Sorts an array of integer numbers using `QSORT()` function. |
| [SortStr](sortstr/) | Sort Strings Array | Sorts an array of strings using `QSORT()` function. |
| [NoiseClr](noiseclr/) [📷](#tv-colored-white-noise) | TV Color Noise | Inspired from old school CRT TV White-Noise/Snow. I was very intrigued by TV's White Noise so I tried to replicate it. |
| [NoiseBw](noisebw/) [📷](#tv-black--white-white-noise) | TV Black & White Noise | Inspired from old school CRT TV White-Noise/Snow. Instead of the colored version (as mentioned above), I tried black, white, and gray-scale colors to mimic the TV's white-noise. |
| [TicTacTo](tictacto/) [📷](#text-based-tic-tac-toe-game) | Text-based Tic Tac Toe Game | Text-based Tic Tac Toe. It allows playing human vs human, and human vs computer games. It was from my early teen years, therefore, instead of using the minimax algorithm, I just brute-forced most of the move combinations for computer play. |
| [PhoneDb](phonedb/) [📷](#telephone-directory-database) | Telephone Directory Database | Telephone directory with rudimentary struct based database (binary) file. User can add, edit, and delete records. User can also search records using ID number, name, telephone, address, and notes. To view details of a record, use search by ID to view full record data. <br /><br />If I recall correctly, it was used to store about 40 or 50 records. I was writing an upgraded version in C++ with a better UI, before abandoning the project and writing it in FoxPro for DOS. |
| [Clock24h](clock24h/) [📷](#simple-24-hours-digital-clock) | 24 Hours Digital Clock | Displays 24-hours digital clock in HH:MM:SS format in large font (using `#` as base character). |
| [Clck24h2](clck24h2/) [📷](#enhanced-24-hours-digital-clock) | Enhanced 24 Hours Digital Clock | Displays 24-hours digital clock in HH:MM:SS format in large font (using extended ASCII characters). The separators `:` blinks with each second. <br /><br />It was the most used version among digital clocks that I wrote. Imagine a world where there were no mobile phones, only wristwatches and wall clocks to tell the time. When getting away from the computer, I would run this program to display the clock on the monitor screen, so that anyone can view the current time from a distance. |
| [Clk24hXl](clk24hxl/) [📷](#extra-large-24-hours-digital-clock) | Extra Large 24 Hours Digital Clock | Displays 24-hours digital clock in HH:MM format in extra-large font (using extended ASCII characters). The separator `:` blinks with each second. |

## Screenshots
#### Stopwatch v2 (with Elapsed Time)
![GIF of Stopwatch](/assets/images/stpwtch2.gif)

#### Guess The Number (Game)
![Screenshot of Guess The Number Game](/assets/images/guess_number.png)

#### Today (Current Date and Time)
This was the last program to run in `AUTOEXEC.BAT` (before migrating to Windows 95). The `AUTOEXEC.BAT` structure would be as following:
```batch
@ECHO OFF
REM ...settings, programs, drivers, and utilities...
BISM.EXE
CLS
TODAY.EXE
```

![Screenshot of Today's Current Date and Time](/assets/images/today.png)

#### Calculate Weekday of a Date
![Screenshot of Weekday of a Date](/assets/images/weekday.png)

#### Bismillah (Text-based Calligraphy)
There was a version of this program without my name on it, which I compiled as a Tiny memory model (.COM file). I built it for my dad's office computer. Soon it was circulating in many offices and businesses' computers in Islamabad. On our home computer, this was the second-last program to run in `AUTOEXEC.BAT` before migrating to Windows 95.

![Screenshot of Bismillah Calligraphy](/assets/images/bismillah.png)

#### Name of Allah (Text-based Calligraphy)
> [!NOTE]
> I couldn't find the `gettext()` function (Turbo C's `CONIO.H`) or similar function in Open Watcom C/C++. Therefore, I rewrite that piece of code by directly accessing memory of Text-mode screen memory. However, I tried to keep the vibe of the original code.

![GIF of Name of Allah Calligraphy](/assets/images/allah.gif)

#### ASCII Character-set Table
![Screenshot of ASCII Table](/assets/images/ascii_table.png)

#### TV Colored White-Noise
![GIF of TV Colored White-Noise](/assets/images/noiseclr.gif)

#### TV Black & White White-Noise
![GIF of TV Black & White White-Noise](/assets/images/noisebw.gif)

#### Text-based Tic Tac Toe (Game)
**Main Menu**

![Screenshot of Tic Tac Toe Menu](/assets/images/tictactoe_menu.png)

**Gameplay of Human vs Human**

![GIF of Tic Tac Toe, Gameplay of Human vs Human](/assets/images/tictacto_human_vs_human.gif)

**Gameplay of Human vs Computer**

![GIF of Tic Tac Toe, Gameplay of Human vs Computer](/assets/images/tictacto_human_vs_computer.gif)

#### Telephone Directory Database
**Menu**

![Screenshot of Telephone Directory's Menu](/assets/images/phonedb_menu.png)

**Add Record**

![Screenshot of Telephone Directory's Add Record](/assets/images/phonedb_add.png)

**Edit Record**

![Screenshot of Telephone Directory's Edit Record](/assets/images/phonedb_edit.png)

**Delete Record**

![Screenshot of Telephone Directory's Delete Record](/assets/images/phonedb_delete.png)

**Search by Name**

![Screenshot of Telephone Directory's Search in Names](/assets/images/phonedb_search_name.png)

**Database Information**

![Screenshot of Telephone Directory's Database Information](/assets/images/phonedb_database_info.png)

#### Simple 24 Hours Digital Clock
![GIF of Simple 24 Hours Digital Clock](/assets/images/clock24h.gif)

#### Enhanced 24 Hours Digital Clock
![GIF of Enhanced 24 Hours Digital Clock](/assets/images/clck24h2.gif)

#### Extra Large 24 Hours Digital Clock
![GIF of Extra Large 24 Hours Digital Clock](/assets/images/clk24hxl.gif)

## Why I ported all projects to Open Watcom?
Turbo C/C++ is no longer maintained. I searched for a FOSS C/C++ compiler which is still in active development, and can produce 16-bit x86 real-mode executables. 

DGJPP is a really good project and I acknowledge the efforts to bring modern versions of GCC to DOS. However, it produces 32-bit DOS executable files, targeting Intel 80386 or later processors.

The Open Watcom C/C++ is close enough to Turbo C/C++. There are some differences in libraries, and some functions are missing, however, I was able to work around the obstacles. Though, I had to refactor and rewrite code during the porting process. However, I am glad that I put in the effort. Now anyone can compile and produce executable files which can still work in DOS on Intel 80286 (and earlier processors). If anyone wishes then they can extend functionality using later versions of C (specifically C99, or perhaps in future, newer versions of C).

**Note:** I have admiration for Watcom C/C++, when in the 90s, I learned that one of my favorite games, DOOM, was written using it. 

## Build Tools
Download Open Watcom v2.0 (or later) from [https://openwatcom.org/](https://openwatcom.org/) official website, or from [https://github.com/open-watcom/open-watcom-v2/](https://github.com/open-watcom/open-watcom-v2/) official GitHub repository. Most likely the projects will compile with Open Watcom v1.9, however, it is not tested as I used v2.0 for compiling and testing.

* **Open Watcom C/C++16 Compile and Link Utility (`WCL.EXE`):** 
I used the `WCL` for simple compilation in the `Makefile`. I used v2.0 Beta 1 of `WCL`.

* **Open Watcom Make (`WMAKE.EXE`):** 
I used the `WMake` utility for the `Makefile`. I wrote a simple `MAKE.BAT` file because I have a habit of writing `make` instead of `wmake`. I used v2.0 Beta 1 of `WMake`.

* **Open Watcom Debugger (`WD.EXE`):** 
I used v2.0 Beta 1 of the `WD` for debugging.

> [!CAUTION]
> If you want to use Visual Studio Code (or any other modern editor) to modify any source file then I'll recommend changing the encoding of (reopening and saving) that source file to `DOS CP-437`. Especially when the source code is using extended ASCII characters.

> [!TIP]
> In the Visual Studio Code, click on the `UTF-8` (or similar current file encoding) in the lower-right corner of the status bar to change the reopening and saving encoding of the currently opened file.

## How to build?
Each project directory has its own `Makefile` in it. Run `MAKE.BAT` to run `WMake` (or directly run `WMake`) to build the targets in the `Makefile`.

#### Source Files
In a project's directory, the source files and header files are in the `SRC` sub-directory.

#### Compile a Debug Executable
In a project's directory, run command `make` to build a debuggable executable file using the `Makefile`. The executable file will be in the `BUILD` sub-directory.

#### Run the Executable
In a project's directory, run command `make run` to run the executable file. If the executable file doesn't exist then the `Make` utility will try to first build the executable and then run it.

#### Debug the Executable
In a project's directory, run command `make debug` to launch the executable file in the Watcom Debugger. If the executable file doesn't exist then the `Make` utility will try to first build the executable before launching Watcom Debugger.

> [!NOTE]
> You can debug a release version of the executable. However, debuggable executable will be much easier, as it will include source code and other information, which will help to add proper breakpoints and watches.

#### Strip the Executable
In a project's directory, run command `make strip` to run `WSTRIP.EXE` on the executable file. It will strip away debuggable and unnecessary information from the executable file (for example from the debuggable executable file. If the executable file doesn't exist then the `Make` utility will try to first build the executable and then run `WStrip` on it.

> [!NOTE]
> `Strip` will automatically execute when the target `Release` is run (see below).

#### Compile a Release Executable
In a project's directory, run command `make release` to build a production ready executable. All the debugging and any other excess information will be stripped away from the final executable. The executable file will be in the `BUILD` sub-directory.

#### Clean
In a project's directory, run command `make clean` to clean all files which were generated from the source files (executable file, OBJ files, and other files generated during compilation and linking).

## Lost Projects
There are many projects files which are probably lost forever due to corrupted copies of backup. I'll try to search and look in other backups. If I find more source code then I'll add them here.

## License
Copyright © 1990-2025 by Farhan Ali Qureshi. View the [MIT LICENSE](LICENSE) file for details.
