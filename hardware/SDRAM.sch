EESchema Schematic File Version 4
LIBS:ECUS-FSE-07-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L eforce:IS42S16400 U7
U 1 1 5A2DD610
P 3000 4150
AR Path="/5BE5A62F/5A2DD610" Ref="U7"  Part="1" 
AR Path="/5D9ECACA/5A2DD610" Ref="U10"  Part="1" 
F 0 "U10" H 2400 5500 50  0000 C CNN
F 1 "IS42S16400" H 3600 5500 50  0000 C CNN
F 2 "eforce_misc:TSOP_II_54_10.16x22.22_Pitch0.8mm" H 3000 4250 50  0001 C CIN
F 3 "http://www.issiusa.com/pdf/42S16400.pdf" H 3000 4000 50  0001 C CNN
F 4 "IS42S16400J-7TL" H 0   0   50  0001 C CNN "mpn"
	1    3000 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4750 3950 4750
Wire Wire Line
	3950 4850 3800 4850
$Comp
L power:+3V3 #PWR0132
U 1 1 5A2E2D5A
P 3000 2650
AR Path="/5BE5A62F/5A2E2D5A" Ref="#PWR0132"  Part="1" 
AR Path="/5D9ECACA/5A2E2D5A" Ref="#PWR0165"  Part="1" 
F 0 "#PWR0165" H 3000 2500 50  0001 C CNN
F 1 "+3V3" H 3000 2800 50  0000 C CNN
F 2 "" H 3000 2650 50  0001 C CNN
F 3 "" H 3000 2650 50  0001 C CNN
	1    3000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2650 3000 2700
Wire Wire Line
	3000 2700 3000 2750
Wire Wire Line
	3100 2700 3100 2750
Connection ~ 3100 2700
Wire Wire Line
	3100 2700 3000 2700
Wire Wire Line
	3200 2700 3200 2750
Wire Wire Line
	3200 2700 3300 2700
Wire Wire Line
	3300 2700 3300 2750
Connection ~ 3200 2700
Wire Wire Line
	2700 2700 2700 2750
Wire Wire Line
	2800 2700 2800 2750
Connection ~ 2800 2700
Wire Wire Line
	2800 2700 2700 2700
Wire Wire Line
	2900 2700 2900 2750
$Comp
L power:GND #PWR0131
U 1 1 5A2EABF7
P 3000 5650
AR Path="/5BE5A62F/5A2EABF7" Ref="#PWR0131"  Part="1" 
AR Path="/5D9ECACA/5A2EABF7" Ref="#PWR0164"  Part="1" 
F 0 "#PWR0164" H 3000 5400 50  0001 C CNN
F 1 "GND" H 3000 5500 50  0000 C CNN
F 2 "" H 3000 5650 50  0001 C CNN
F 3 "" H 3000 5650 50  0001 C CNN
	1    3000 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 5650 3000 5600
Wire Wire Line
	3000 5600 3100 5600
Wire Wire Line
	3300 5600 3300 5550
Wire Wire Line
	2800 2700 2900 2700
Wire Wire Line
	3100 5550 3100 5600
Connection ~ 3100 5600
Wire Wire Line
	3100 5600 3200 5600
Wire Wire Line
	3200 5600 3200 5550
Connection ~ 3200 5600
Wire Wire Line
	3200 5600 3300 5600
Wire Wire Line
	3000 5550 3000 5600
Connection ~ 3000 5600
Wire Wire Line
	3000 5600 2900 5600
Wire Wire Line
	2900 5600 2900 5550
Wire Wire Line
	2900 5600 2800 5600
Wire Wire Line
	2800 5600 2800 5550
Connection ~ 2900 5600
Wire Wire Line
	2800 5600 2700 5600
Wire Wire Line
	2700 5600 2700 5550
Connection ~ 2800 5600
$Comp
L Device:C C41
U 1 1 5A2F33F2
P 2050 1950
AR Path="/5BE5A62F/5A2F33F2" Ref="C41"  Part="1" 
AR Path="/5D9ECACA/5A2F33F2" Ref="C52"  Part="1" 
F 0 "C52" H 2100 2050 50  0000 L CNN
F 1 "10n" H 2100 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 2088 1800 50  0001 C CNN
F 3 "" H 2050 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    2050 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0122
U 1 1 5A2F3498
P 2050 1800
AR Path="/5BE5A62F/5A2F3498" Ref="#PWR0122"  Part="1" 
AR Path="/5D9ECACA/5A2F3498" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 2050 1650 50  0001 C CNN
F 1 "+3V3" H 2050 1950 50  0000 C CNN
F 2 "" H 2050 1800 50  0001 C CNN
F 3 "" H 2050 1800 50  0001 C CNN
	1    2050 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5A2F4B0A
P 2050 2100
AR Path="/5BE5A62F/5A2F4B0A" Ref="#PWR0123"  Part="1" 
AR Path="/5D9ECACA/5A2F4B0A" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 2050 1850 50  0001 C CNN
F 1 "GND" H 2050 1950 50  0000 C CNN
F 2 "" H 2050 2100 50  0001 C CNN
F 3 "" H 2050 2100 50  0001 C CNN
	1    2050 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C42
U 1 1 5A2F62B7
P 2350 1950
AR Path="/5BE5A62F/5A2F62B7" Ref="C42"  Part="1" 
AR Path="/5D9ECACA/5A2F62B7" Ref="C53"  Part="1" 
F 0 "C53" H 2400 2050 50  0000 L CNN
F 1 "10n" H 2400 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 2388 1800 50  0001 C CNN
F 3 "" H 2350 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    2350 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0124
U 1 1 5A2F62BD
P 2350 1800
AR Path="/5BE5A62F/5A2F62BD" Ref="#PWR0124"  Part="1" 
AR Path="/5D9ECACA/5A2F62BD" Ref="#PWR0157"  Part="1" 
F 0 "#PWR0157" H 2350 1650 50  0001 C CNN
F 1 "+3V3" H 2350 1950 50  0000 C CNN
F 2 "" H 2350 1800 50  0001 C CNN
F 3 "" H 2350 1800 50  0001 C CNN
	1    2350 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5A2F62C3
P 2350 2100
AR Path="/5BE5A62F/5A2F62C3" Ref="#PWR0125"  Part="1" 
AR Path="/5D9ECACA/5A2F62C3" Ref="#PWR0158"  Part="1" 
F 0 "#PWR0158" H 2350 1850 50  0001 C CNN
F 1 "GND" H 2350 1950 50  0000 C CNN
F 2 "" H 2350 2100 50  0001 C CNN
F 3 "" H 2350 2100 50  0001 C CNN
	1    2350 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C43
U 1 1 5A2F796A
P 2650 1950
AR Path="/5BE5A62F/5A2F796A" Ref="C43"  Part="1" 
AR Path="/5D9ECACA/5A2F796A" Ref="C54"  Part="1" 
F 0 "C54" H 2700 2050 50  0000 L CNN
F 1 "10n" H 2700 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 2688 1800 50  0001 C CNN
F 3 "" H 2650 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    2650 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0126
U 1 1 5A2F7970
P 2650 1800
AR Path="/5BE5A62F/5A2F7970" Ref="#PWR0126"  Part="1" 
AR Path="/5D9ECACA/5A2F7970" Ref="#PWR0159"  Part="1" 
F 0 "#PWR0159" H 2650 1650 50  0001 C CNN
F 1 "+3V3" H 2650 1950 50  0000 C CNN
F 2 "" H 2650 1800 50  0001 C CNN
F 3 "" H 2650 1800 50  0001 C CNN
	1    2650 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5A2F7976
P 2650 2100
AR Path="/5BE5A62F/5A2F7976" Ref="#PWR0127"  Part="1" 
AR Path="/5D9ECACA/5A2F7976" Ref="#PWR0160"  Part="1" 
F 0 "#PWR0160" H 2650 1850 50  0001 C CNN
F 1 "GND" H 2650 1950 50  0000 C CNN
F 2 "" H 2650 2100 50  0001 C CNN
F 3 "" H 2650 2100 50  0001 C CNN
	1    2650 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C44
U 1 1 5A2F797C
P 2950 1950
AR Path="/5BE5A62F/5A2F797C" Ref="C44"  Part="1" 
AR Path="/5D9ECACA/5A2F797C" Ref="C55"  Part="1" 
F 0 "C55" H 3000 2050 50  0000 L CNN
F 1 "10n" H 3000 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 2988 1800 50  0001 C CNN
F 3 "" H 2950 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    2950 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0129
U 1 1 5A2F7982
P 2950 1800
AR Path="/5BE5A62F/5A2F7982" Ref="#PWR0129"  Part="1" 
AR Path="/5D9ECACA/5A2F7982" Ref="#PWR0162"  Part="1" 
F 0 "#PWR0162" H 2950 1650 50  0001 C CNN
F 1 "+3V3" H 2950 1950 50  0000 C CNN
F 2 "" H 2950 1800 50  0001 C CNN
F 3 "" H 2950 1800 50  0001 C CNN
	1    2950 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0130
U 1 1 5A2F7988
P 2950 2100
AR Path="/5BE5A62F/5A2F7988" Ref="#PWR0130"  Part="1" 
AR Path="/5D9ECACA/5A2F7988" Ref="#PWR0163"  Part="1" 
F 0 "#PWR0163" H 2950 1850 50  0001 C CNN
F 1 "GND" H 2950 1950 50  0000 C CNN
F 2 "" H 2950 2100 50  0001 C CNN
F 3 "" H 2950 2100 50  0001 C CNN
	1    2950 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C45
U 1 1 5A2F90AB
P 3200 1950
AR Path="/5BE5A62F/5A2F90AB" Ref="C45"  Part="1" 
AR Path="/5D9ECACA/5A2F90AB" Ref="C56"  Part="1" 
F 0 "C56" H 3250 2050 50  0000 L CNN
F 1 "10n" H 3250 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 3238 1800 50  0001 C CNN
F 3 "" H 3200 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    3200 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0133
U 1 1 5A2F90B1
P 3200 1800
AR Path="/5BE5A62F/5A2F90B1" Ref="#PWR0133"  Part="1" 
AR Path="/5D9ECACA/5A2F90B1" Ref="#PWR0166"  Part="1" 
F 0 "#PWR0166" H 3200 1650 50  0001 C CNN
F 1 "+3V3" H 3200 1950 50  0000 C CNN
F 2 "" H 3200 1800 50  0001 C CNN
F 3 "" H 3200 1800 50  0001 C CNN
	1    3200 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 5A2F90B7
P 3200 2100
AR Path="/5BE5A62F/5A2F90B7" Ref="#PWR0134"  Part="1" 
AR Path="/5D9ECACA/5A2F90B7" Ref="#PWR0167"  Part="1" 
F 0 "#PWR0167" H 3200 1850 50  0001 C CNN
F 1 "GND" H 3200 1950 50  0000 C CNN
F 2 "" H 3200 2100 50  0001 C CNN
F 3 "" H 3200 2100 50  0001 C CNN
	1    3200 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C46
U 1 1 5A2F90BD
P 3500 1950
AR Path="/5BE5A62F/5A2F90BD" Ref="C46"  Part="1" 
AR Path="/5D9ECACA/5A2F90BD" Ref="C57"  Part="1" 
F 0 "C57" H 3550 2050 50  0000 L CNN
F 1 "10n" H 3550 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 3538 1800 50  0001 C CNN
F 3 "" H 3500 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    3500 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0135
U 1 1 5A2F90C3
P 3500 1800
AR Path="/5BE5A62F/5A2F90C3" Ref="#PWR0135"  Part="1" 
AR Path="/5D9ECACA/5A2F90C3" Ref="#PWR0168"  Part="1" 
F 0 "#PWR0168" H 3500 1650 50  0001 C CNN
F 1 "+3V3" H 3500 1950 50  0000 C CNN
F 2 "" H 3500 1800 50  0001 C CNN
F 3 "" H 3500 1800 50  0001 C CNN
	1    3500 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5A2F90C9
P 3500 2100
AR Path="/5BE5A62F/5A2F90C9" Ref="#PWR0136"  Part="1" 
AR Path="/5D9ECACA/5A2F90C9" Ref="#PWR0169"  Part="1" 
F 0 "#PWR0169" H 3500 1850 50  0001 C CNN
F 1 "GND" H 3500 1950 50  0000 C CNN
F 2 "" H 3500 2100 50  0001 C CNN
F 3 "" H 3500 2100 50  0001 C CNN
	1    3500 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C47
U 1 1 5A2F90CF
P 3800 1950
AR Path="/5BE5A62F/5A2F90CF" Ref="C47"  Part="1" 
AR Path="/5D9ECACA/5A2F90CF" Ref="C58"  Part="1" 
F 0 "C58" H 3850 2050 50  0000 L CNN
F 1 "10n" H 3850 1850 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 3838 1800 50  0001 C CNN
F 3 "" H 3800 1950 50  0001 C CNN
F 4 "885012205031" H 0   0   50  0001 C CNN "mpn"
	1    3800 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0137
U 1 1 5A2F90D5
P 3800 1800
AR Path="/5BE5A62F/5A2F90D5" Ref="#PWR0137"  Part="1" 
AR Path="/5D9ECACA/5A2F90D5" Ref="#PWR0170"  Part="1" 
F 0 "#PWR0170" H 3800 1650 50  0001 C CNN
F 1 "+3V3" H 3800 1950 50  0000 C CNN
F 2 "" H 3800 1800 50  0001 C CNN
F 3 "" H 3800 1800 50  0001 C CNN
	1    3800 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0138
U 1 1 5A2F90DB
P 3800 2100
AR Path="/5BE5A62F/5A2F90DB" Ref="#PWR0138"  Part="1" 
AR Path="/5D9ECACA/5A2F90DB" Ref="#PWR0171"  Part="1" 
F 0 "#PWR0171" H 3800 1850 50  0001 C CNN
F 1 "GND" H 3800 1950 50  0000 C CNN
F 2 "" H 3800 2100 50  0001 C CNN
F 3 "" H 3800 2100 50  0001 C CNN
	1    3800 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 2950 3950 2950
Wire Wire Line
	3800 3050 3950 3050
Wire Wire Line
	3800 3150 3950 3150
Wire Wire Line
	3800 3250 3950 3250
Wire Wire Line
	3800 3350 3950 3350
Wire Wire Line
	3800 3450 3950 3450
Wire Wire Line
	3800 3550 3950 3550
Wire Wire Line
	3800 3650 3950 3650
Wire Wire Line
	3800 3750 3950 3750
Wire Wire Line
	3800 3850 3950 3850
Wire Wire Line
	3800 3950 3950 3950
Wire Wire Line
	3800 4050 3950 4050
Wire Wire Line
	3800 4150 3950 4150
Wire Wire Line
	3800 4250 3950 4250
Wire Wire Line
	3800 4350 3950 4350
Wire Wire Line
	3800 4450 3950 4450
Wire Wire Line
	2200 2950 2050 2950
Wire Wire Line
	2200 3050 2050 3050
Wire Wire Line
	2200 3150 2050 3150
Wire Wire Line
	2200 3250 2050 3250
Wire Wire Line
	2200 3350 2050 3350
Wire Wire Line
	2200 3450 2050 3450
Wire Wire Line
	2200 3550 2050 3550
Wire Wire Line
	2200 3650 2050 3650
Wire Wire Line
	2200 3750 2050 3750
Wire Wire Line
	2200 3850 2050 3850
Wire Wire Line
	2200 3950 2050 3950
Wire Wire Line
	2200 4050 2050 4050
Wire Wire Line
	2200 4150 2050 4150
Wire Wire Line
	2200 4250 2050 4250
Wire Wire Line
	2200 4450 2050 4450
Wire Wire Line
	2200 4550 2050 4550
Wire Wire Line
	2200 4750 2050 4750
Wire Wire Line
	2200 4850 2050 4850
Wire Wire Line
	2200 5050 2050 5050
Wire Wire Line
	2200 5150 2050 5150
Wire Wire Line
	2200 5250 2050 5250
Wire Wire Line
	2200 5350 2050 5350
Entry Wire Line
	1950 3050 2050 3150
Entry Wire Line
	1950 2850 2050 2950
Entry Wire Line
	1950 2950 2050 3050
Entry Wire Line
	1950 3350 2050 3450
Entry Wire Line
	1950 3150 2050 3250
Entry Wire Line
	1950 3250 2050 3350
Entry Wire Line
	1950 3650 2050 3750
Entry Wire Line
	1950 3450 2050 3550
Entry Wire Line
	1950 3550 2050 3650
Entry Wire Line
	1950 3750 2050 3850
Entry Wire Line
	1950 4150 2050 4250
Entry Wire Line
	1950 3950 2050 4050
Entry Wire Line
	1950 4050 2050 4150
Wire Bus Line
	1600 2850 1950 2850
Text Label 1600 2850 0    50   ~ 0
A[0..13]
Entry Wire Line
	3950 2950 4050 2850
Entry Wire Line
	3950 3050 4050 2950
Entry Wire Line
	3950 4250 4050 4150
Entry Wire Line
	3950 4450 4050 4350
Entry Wire Line
	3950 4350 4050 4250
Entry Wire Line
	3950 3950 4050 3850
Entry Wire Line
	3950 4150 4050 4050
Entry Wire Line
	3950 4050 4050 3950
Entry Wire Line
	3950 3650 4050 3550
Entry Wire Line
	3950 3850 4050 3750
Entry Wire Line
	3950 3750 4050 3650
Entry Wire Line
	3950 3550 4050 3450
Entry Wire Line
	3950 3450 4050 3350
Entry Wire Line
	3950 3150 4050 3050
Entry Wire Line
	3950 3350 4050 3250
Entry Wire Line
	3950 3250 4050 3150
Entry Wire Line
	1950 3850 2050 3950
Wire Bus Line
	4050 2850 4450 2850
Text Label 4450 2850 2    56   ~ 0
D[0..15]
Text HLabel 2050 4450 0    50   Input ~ 0
BA0
Text HLabel 2050 4550 0    50   Input ~ 0
BA1
Text HLabel 2050 4750 0    50   Input ~ 0
CLK
Text HLabel 2050 4850 0    50   Input ~ 0
CKE
Text HLabel 2050 5050 0    50   Input ~ 0
~RAS~
Text HLabel 2050 5150 0    50   Input ~ 0
~CAS~
Text HLabel 2050 5250 0    50   Input ~ 0
~WE~
Text HLabel 2050 5350 0    50   Input ~ 0
~CS~
Text HLabel 3950 4750 2    50   Input ~ 0
DQL
Text HLabel 3950 4850 2    50   Input ~ 0
DQH
Text HLabel 1600 2850 0    50   Input ~ 0
A[0..13]
Text HLabel 4450 2850 2    50   BiDi ~ 0
D[0..15]
Text Label 2050 2950 0    50   ~ 0
A0
Text Label 2050 3050 0    50   ~ 0
A1
Text Label 2050 3150 0    50   ~ 0
A2
Text Label 2050 3250 0    50   ~ 0
A3
Text Label 2050 3350 0    50   ~ 0
A4
Text Label 2050 3450 0    50   ~ 0
A5
Text Label 2050 3550 0    50   ~ 0
A6
Text Label 2050 3650 0    50   ~ 0
A7
Text Label 2050 3750 0    50   ~ 0
A8
Text Label 2050 3850 0    50   ~ 0
A9
Text Label 2050 3950 0    50   ~ 0
A10
Text Label 2050 4050 0    50   ~ 0
A11
Text Label 2050 4150 0    50   ~ 0
A12
Text Label 2050 4250 0    50   ~ 0
A13
Text Label 3800 2950 0    50   ~ 0
D0
Text Label 3800 3050 0    50   ~ 0
D1
Text Label 3800 3150 0    50   ~ 0
D2
Text Label 3800 3250 0    50   ~ 0
D3
Text Label 3800 3350 0    50   ~ 0
D4
Text Label 3800 3450 0    50   ~ 0
D5
Text Label 3800 3550 0    50   ~ 0
D6
Text Label 3800 3650 0    50   ~ 0
D7
Text Label 3800 3750 0    50   ~ 0
D8
Text Label 3800 3850 0    50   ~ 0
D9
Text Label 3800 3950 0    50   ~ 0
D10
Text Label 3800 4050 0    50   ~ 0
D11
Text Label 3800 4150 0    50   ~ 0
D12
Text Label 3800 4250 0    50   ~ 0
D13
Text Label 3800 4350 0    50   ~ 0
D14
Text Label 3800 4450 0    50   ~ 0
D15
Wire Wire Line
	3000 2700 2900 2700
Connection ~ 3000 2700
Connection ~ 2900 2700
Wire Wire Line
	3100 2700 3200 2700
Wire Bus Line
	1950 2850 1950 4150
Wire Bus Line
	4050 2850 4050 4350
$EndSCHEMATC
