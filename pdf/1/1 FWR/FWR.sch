EESchema Schematic File Version 2  date 12/15/2014 4:18:40 PM
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:analogSpice
LIBS:analogXSpice
LIBS:convergenceAidSpice
LIBS:converterSpice
LIBS:digitalSpice
LIBS:digitalXSpice
LIBS:linearSpice
LIBS:measurementSpice
LIBS:portSpice
LIBS:sourcesSpice
LIBS:FWR-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "15 dec 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 5200 5050
Wire Wire Line
	5800 5050 2250 5050
Wire Wire Line
	5800 5050 5800 4000
Connection ~ 3550 5050
Connection ~ 1950 4750
Wire Wire Line
	5200 4350 5200 4000
Wire Wire Line
	2250 5050 2250 4050
Connection ~ 2550 4050
Wire Wire Line
	2250 4050 2550 4050
Wire Wire Line
	1950 4750 3400 4750
Connection ~ 3400 4300
Wire Wire Line
	3400 4750 3400 4300
Wire Wire Line
	2750 4300 2550 4300
Wire Wire Line
	2550 4300 2550 3800
Wire Wire Line
	2550 3800 2750 3800
Wire Wire Line
	3150 3800 3650 3800
Wire Wire Line
	4050 3800 4200 3800
Wire Wire Line
	4200 3800 4200 4300
Wire Wire Line
	4200 4300 4050 4300
Wire Wire Line
	3150 4300 3650 4300
Wire Wire Line
	3400 3800 3400 3350
Connection ~ 3400 3800
Wire Wire Line
	5200 4000 4200 4000
Connection ~ 4200 4000
Wire Wire Line
	3400 3350 1950 3350
Wire Wire Line
	1950 3350 1950 3600
Wire Wire Line
	5200 5050 5200 4850
Connection ~ 2100 4750
Connection ~ 4100 5050
Wire Wire Line
	1950 4500 1950 5150
$Comp
L VPLOT8 U2
U 1 1 548EB9B9
P 5500 4000
F 0 "U2" H 5350 4100 50  0000 C CNN
F 1 "VPLOT8" H 5650 4100 50  0000 C CNN
	1    5500 4000
	1    0    0    -1  
$EndComp
$Comp
L SINE v1
U 1 1 548EB552
P 1950 4050
F 0 "v1" H 1750 4150 60  0000 C CNN
F 1 "SINE" H 1750 4000 60  0000 C CNN
F 2 "R1" H 1650 4050 60  0000 C CNN
	1    1950 4050
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG01
U 1 1 548EB534
P 2100 4750
F 0 "#FLG01" H 2100 5020 30  0001 C CNN
F 1 "PWR_FLAG" H 2100 4980 30  0000 C CNN
	1    2100 4750
	1    0    0    -1  
$EndComp
$Comp
L VPLOT8_1 U1
U 1 1 548EB307
P 1950 3050
F 0 "U1" H 1800 3150 50  0000 C CNN
F 1 "VPLOT8_1" H 2100 3150 50  0000 C CNN
	1    1950 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 548EB261
P 1950 5150
F 0 "#PWR02" H 1950 5150 30  0001 C CNN
F 1 "GND" H 1950 5080 30  0001 C CNN
	1    1950 5150
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 548EB228
P 5200 4600
F 0 "R1" V 5280 4600 50  0000 C CNN
F 1 "10k" V 5200 4600 50  0000 C CNN
	1    5200 4600
	1    0    0    -1  
$EndComp
$Comp
L DIODE D4
U 1 1 548EB19F
P 3850 4300
F 0 "D4" H 3850 4400 40  0000 C CNN
F 1 "1n4007" H 3850 4200 40  0000 C CNN
	1    3850 4300
	1    0    0    -1  
$EndComp
$Comp
L DIODE D3
U 1 1 548EB19B
P 2950 4300
F 0 "D3" H 2950 4400 40  0000 C CNN
F 1 "1n4007" H 2950 4200 40  0000 C CNN
	1    2950 4300
	1    0    0    -1  
$EndComp
$Comp
L DIODE D2
U 1 1 548EB198
P 3850 3800
F 0 "D2" H 3850 3900 40  0000 C CNN
F 1 "1n4007" H 3850 3700 40  0000 C CNN
	1    3850 3800
	1    0    0    -1  
$EndComp
$Comp
L DIODE D1
U 1 1 548EB195
P 2950 3800
F 0 "D1" H 2950 3900 40  0000 C CNN
F 1 "1n4007" H 2950 3700 40  0000 C CNN
	1    2950 3800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
