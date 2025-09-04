# DOS C Programs and Utilities
I wrote these programs and utilities, when I was a teenager in the 90s, for MS-DOS 5.0 and MS-DOS 6.22 etc. I used Turbo C and later Turbo C++. I'll port each program to Open Watcom C 2.0, add comments, and refactor code. Add a Makefile, and after testing them using FreeDOS or DOSBox, I'll add it here.

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
![Screenshot of Today's Current Date and Time](/assets/images/today.png)

#### Calculate Weekday of a Date
![Screenshot of Weekday of a Date](/assets/images/weekday.png)

#### Bismillah (Text-based Calligraphy)
![Screenshot of Bismillah Calligraphy](/assets/images/bismillah.png)

#### Name of Allah (Text-based Calligraphy)
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

**Search in Names**

![Screenshot of Telephone Directory's Search in Names](/assets/images/phonedb_search_name.png)

**Database Information**

![Screenshot of Telephone Directory's Database Information](/assets/images/phonedb_database_info.png)

#### Simple 24 Hours Digital Clock
![GIF of Simple 24 Hours Digital Clock](/assets/images/clock24h.gif)

#### Enhanced 24 Hours Digital Clock
![GIF of Enhanced 24 Hours Digital Clock](/assets/images/clck24h2.gif)

#### Extra Large 24 Hours Digital Clock
![GIF of Extra Large 24 Hours Digital Clock](/assets/images/clk24hxl.gif)

## Lost Projects
There are many projects files which are probably lost forever due to corrupted copies of backup. I'll try to search and look in other backups. If I find more source code then I'll add them here.
