# GardenEncoding-Qt-GUI

Univeristy C++ project in Qt GUI

---

## Utility
Program encodes a field of objects (here radishes) into short code.

Decoding comes in opposite way.

## Description
Field is represented as square, which side is equal 2^n. 

In manual mode n can be from 1 to 6.

In field modes n can be from 1 to 15(this value may be heigher but calcualtions becomes slower).

## Algorithm

To code a field we follow some rules:

* Start from the biggest square with 2^n side, if on all places are "1" write 1 to the code, analogously if all places are empty write 0 to code.
* If not all places are the same -> write # to code and run alg recusively for 4 squares with 2^(n-1) side
* Stop when square has side equal to 2

## 3 ways of usage
* **Manual**

  In this mode you can click on the radishes to change the field appearance.
  Also you can write code in edit text.
  
* **Files with multiple fields/codes**

  Reads fields or codes from file -> saves result to file and show it in GUI
  
* **Files with one field/code**

## Example

### File with field should look like:
* The first line is the power
* Next lines should emit field layout
```
2
1100
1100
1111
1111
```

The output will be:
* The first character is the power
* Then space and code
```
2 #1011
```

### File with multifields should look like:
* The first line is the power
* Next lines should emit field layout
* Enter and repeat
```
2
1100
1100
1111
1111

1
00
11

1
00
00
```

The output will be:
* The first character is the power
* Then space and code
* Enter and repeat
```
2 #1011
1 #0011
1 0
```


## Screenshots
![Imgur](https://i.imgur.com/OHq6A9S.png "Manual tab")
Manual encoding

![Imgur](https://i.imgur.com/CLUu3Ph.png)
Manual Decoding

![Imgur](https://i.imgur.com/mVTYGBX.png)
File encoding
