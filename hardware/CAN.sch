EESchema Schematic File Version 4
LIBS:ECUS-FSE-07-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 8
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
L Device:C C48
U 1 1 5CCCD777
P 4750 900
AR Path="/5CABDA93/5CCCD777" Ref="C48"  Part="1" 
AR Path="/5CABE318/5CCCD777" Ref="C50"  Part="1" 
F 0 "C48" H 4800 1000 50  0000 L CNN
F 1 "100n" H 4800 800 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 4788 750 50  0001 C CNN
F 3 "" H 4750 900 50  0001 C CNN
F 4 "885012205037" H 0   0   50  0001 C CNN "mpn"
	1    4750 900 
	1    0    0    -1  
$EndComp
Text HLabel 2900 1650 0    50   Input ~ 0
TX
Text HLabel 3950 1750 0    50   Output ~ 0
RX
Text HLabel 7700 2200 2    50   BiDi ~ 0
L
Text HLabel 7700 1500 2    50   BiDi ~ 0
H
$Comp
L Interface_CAN_LIN:TJA1049T U8
U 1 1 5AF08343
P 4450 1850
AR Path="/5CABDA93/5AF08343" Ref="U8"  Part="1" 
AR Path="/5CABE318/5AF08343" Ref="U9"  Part="1" 
F 0 "U8" H 4150 2200 50  0000 C CNN
F 1 "TJA1049T" H 4700 2250 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4450 1350 50  0001 C CIN
F 3 "http://www.nxp.com/documents/data_sheet/TJA1049.pdf" H 4450 1850 50  0001 C CNN
F 4 "ef" H 0   0   50  0001 C CNN "mpn"
	1    4450 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0143
U 1 1 5AF083E1
P 4750 1050
AR Path="/5CABDA93/5AF083E1" Ref="#PWR0143"  Part="1" 
AR Path="/5CABE318/5AF083E1" Ref="#PWR0151"  Part="1" 
F 0 "#PWR0151" H 4750 800 50  0001 C CNN
F 1 "GND" H 4750 900 50  0000 C CNN
F 2 "" H 4750 1050 50  0001 C CNN
F 3 "" H 4750 1050 50  0001 C CNN
	1    4750 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0141
U 1 1 5AF087B7
P 4450 2250
AR Path="/5CABDA93/5AF087B7" Ref="#PWR0141"  Part="1" 
AR Path="/5CABE318/5AF087B7" Ref="#PWR0149"  Part="1" 
F 0 "#PWR0149" H 4450 2000 50  0001 C CNN
F 1 "GND" H 4450 2100 50  0000 C CNN
F 2 "" H 4450 2250 50  0001 C CNN
F 3 "" H 4450 2250 50  0001 C CNN
	1    4450 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:EMI_Filter_LL FL1
U 1 1 5AF0FFA2
P 6150 1850
AR Path="/5CABDA93/5AF0FFA2" Ref="FL1"  Part="1" 
AR Path="/5CABE318/5AF0FFA2" Ref="FL2"  Part="1" 
F 0 "FL1" H 6150 2200 50  0000 C CNN
F 1 "EMI_Filter_LL" H 6150 2100 50  0000 C CNN
F 2 "eforce_misc:DLW43" V 6150 1890 50  0001 C CNN
F 3 "http://www.murata.com/~/media/webrenewal/support/library/catalog/products/emc/emifil/c30e.ashx?la=en-gb" H 6150 2100 50  0001 C CNN
F 4 "DLW43SH510XK2L" H -800 0   50  0001 C CNN "mpn"
	1    6150 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0142
U 1 1 5AF1016B
P 4750 750
AR Path="/5CABDA93/5AF1016B" Ref="#PWR0142"  Part="1" 
AR Path="/5CABE318/5AF1016B" Ref="#PWR0150"  Part="1" 
F 0 "#PWR0150" H 4750 600 50  0001 C CNN
F 1 "+5V" H 4750 900 50  0000 C CNN
F 2 "" H 4750 750 50  0001 C CNN
F 3 "" H 4750 750 50  0001 C CNN
	1    4750 750 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0140
U 1 1 5AF10187
P 4450 1450
AR Path="/5CABDA93/5AF10187" Ref="#PWR0140"  Part="1" 
AR Path="/5CABE318/5AF10187" Ref="#PWR0148"  Part="1" 
F 0 "#PWR0148" H 4450 1300 50  0001 C CNN
F 1 "+5V" H 4450 1600 50  0000 C CNN
F 2 "" H 4450 1450 50  0001 C CNN
F 3 "" H 4450 1450 50  0001 C CNN
	1    4450 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 5AF10781
P 7500 1650
AR Path="/5CABDA93/5AF10781" Ref="R17"  Part="1" 
AR Path="/5CABE318/5AF10781" Ref="R19"  Part="1" 
F 0 "R17" H 7550 1700 50  0000 L CNN
F 1 "60" H 7550 1600 50  0000 L CNN
F 2 "eforce_misc:R_0603_larger_pads" V 7430 1650 50  0001 C CNN
F 3 "" H 7500 1650 50  0001 C CNN
F 4 "ef" H 2250 0   50  0001 C CNN "mpn"
	1    7500 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 5AF10931
P 7500 2050
AR Path="/5CABDA93/5AF10931" Ref="R18"  Part="1" 
AR Path="/5CABE318/5AF10931" Ref="R20"  Part="1" 
F 0 "R18" H 7550 2100 50  0000 L CNN
F 1 "60" H 7550 2000 50  0000 L CNN
F 2 "eforce_misc:R_0603_larger_pads" V 7430 2050 50  0001 C CNN
F 3 "" H 7500 2050 50  0001 C CNN
F 4 "ef" H 2250 0   50  0001 C CNN "mpn"
	1    7500 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1850 7500 1850
Wire Wire Line
	7500 1850 7500 1800
Wire Wire Line
	7500 1850 7500 1900
Connection ~ 7500 1850
Wire Wire Line
	4950 1750 5050 1750
Wire Wire Line
	5050 1750 5050 1500
Wire Wire Line
	4950 1950 5050 1950
Wire Wire Line
	5050 1950 5050 2200
Wire Wire Line
	5950 1750 5800 1750
Wire Wire Line
	5800 1750 5800 1500
Wire Wire Line
	5950 1950 5800 1950
Wire Wire Line
	5800 1950 5800 2200
Wire Wire Line
	6500 1500 6500 1750
Wire Wire Line
	6350 1750 6500 1750
Wire Wire Line
	6350 1950 6500 1950
Wire Wire Line
	6500 1950 6500 2200
$Comp
L Device:C C49
U 1 1 5A3745D2
P 7900 1850
AR Path="/5CABDA93/5A3745D2" Ref="C49"  Part="1" 
AR Path="/5CABE318/5A3745D2" Ref="C51"  Part="1" 
F 0 "C49" H 8050 1950 50  0000 L CNN
F 1 "10n" H 8050 1800 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 7938 1700 50  0001 C CNN
F 3 "" H 7900 1850 50  0001 C CNN
F 4 "885012205031" H 2250 0   50  0001 C CNN "mpn"
	1    7900 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1850 7700 1850
Wire Wire Line
	7700 1850 7700 1700
Wire Wire Line
	7700 1700 7900 1700
$Comp
L power:GND #PWR0144
U 1 1 5A375771
P 7900 2000
AR Path="/5CABDA93/5A375771" Ref="#PWR0144"  Part="1" 
AR Path="/5CABE318/5A375771" Ref="#PWR0152"  Part="1" 
F 0 "#PWR0152" H 7900 1750 50  0001 C CNN
F 1 "GND" H 7900 1850 50  0000 C CNN
F 2 "" H 7900 2000 50  0001 C CNN
F 3 "" H 7900 2000 50  0001 C CNN
	1    7900 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0139
U 1 1 5A382A70
P 3900 2250
AR Path="/5CABDA93/5A382A70" Ref="#PWR0139"  Part="1" 
AR Path="/5CABE318/5A382A70" Ref="#PWR0147"  Part="1" 
F 0 "#PWR0147" H 3900 2000 50  0001 C CNN
F 1 "GND" H 3900 2100 50  0000 C CNN
F 2 "" H 3900 2250 50  0001 C CNN
F 3 "" H 3900 2250 50  0001 C CNN
	1    3900 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2250 3900 2050
Wire Wire Line
	3900 2050 3950 2050
$Comp
L power:GND #PWR0145
U 1 1 5A375DE2
P 7000 1850
AR Path="/5CABDA93/5A375DE2" Ref="#PWR0145"  Part="1" 
AR Path="/5CABE318/5A375DE2" Ref="#PWR0153"  Part="1" 
F 0 "#PWR0153" H 7000 1600 50  0001 C CNN
F 1 "GND" H 7000 1700 50  0000 C CNN
F 2 "" H 7000 1850 50  0001 C CNN
F 3 "" H 7000 1850 50  0001 C CNN
	1    7000 1850
	1    0    0    -1  
$EndComp
$Comp
L eforce:D_TVS_x2_AAC D10
U 1 1 5A37650C
P 6900 1850
AR Path="/5CABDA93/5A37650C" Ref="D10"  Part="1" 
AR Path="/5CABE318/5A37650C" Ref="D13"  Part="1" 
F 0 "D10" V 6750 1850 50  0000 C CNN
F 1 "NUP2105L" V 6900 1550 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" V 6800 1650 50  0001 C CNN
F 3 "https://en.wikipedia.org/wiki/Transient-voltage-suppression_diode" V 6800 1650 50  0001 C CNN
F 4 "SZNUP2105LT1G" H -800 0   50  0001 C CNN "mpn"
	1    6900 1850
	0    1    -1   0   
$EndComp
$Comp
L Device:C C61
U 1 1 5A563F84
P 6500 2350
AR Path="/5CABDA93/5A563F84" Ref="C61"  Part="1" 
AR Path="/5CABE318/5A563F84" Ref="C65"  Part="1" 
F 0 "C61" H 6550 2450 50  0000 L CNN
F 1 "Can" H 6550 2250 50  0000 L CNN
F 2 "legacy:C_0805_2012Metric_legacy" H 6538 2200 50  0001 C CNN
F 3 "" H 6500 2350 50  0001 C CNN
F 4 "dnp/ef" H -800 0   50  0001 C CNN "mpn"
	1    6500 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0154
U 1 1 5A563F8A
P 6500 2500
AR Path="/5CABDA93/5A563F8A" Ref="#PWR0154"  Part="1" 
AR Path="/5CABE318/5A563F8A" Ref="#PWR0177"  Part="1" 
F 0 "#PWR0177" H 6500 2250 50  0001 C CNN
F 1 "GND" H 6500 2350 50  0000 C CNN
F 2 "" H 6500 2500 50  0001 C CNN
F 3 "" H 6500 2500 50  0001 C CNN
	1    6500 2500
	1    0    0    -1  
$EndComp
Connection ~ 6500 2200
$Comp
L Device:C C59
U 1 1 5A564AF7
P 5800 2350
AR Path="/5CABDA93/5A564AF7" Ref="C59"  Part="1" 
AR Path="/5CABE318/5A564AF7" Ref="C63"  Part="1" 
F 0 "C59" H 5850 2450 50  0000 L CNN
F 1 "Can" H 5850 2250 50  0000 L CNN
F 2 "legacy:C_0805_2012Metric_legacy" H 5838 2200 50  0001 C CNN
F 3 "" H 5800 2350 50  0001 C CNN
F 4 "dnp/ef" H -800 0   50  0001 C CNN "mpn"
	1    5800 2350
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR048
U 1 1 5A564AFD
P 5800 2500
AR Path="/5CABDA93/5A564AFD" Ref="#PWR048"  Part="1" 
AR Path="/5CABE318/5A564AFD" Ref="#PWR0175"  Part="1" 
F 0 "#PWR0175" H 5800 2250 50  0001 C CNN
F 1 "GND" H 5800 2350 50  0000 C CNN
F 2 "" H 5800 2500 50  0001 C CNN
F 3 "" H 5800 2500 50  0001 C CNN
	1    5800 2500
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C60
U 1 1 5A565351
P 6500 1350
AR Path="/5CABDA93/5A565351" Ref="C60"  Part="1" 
AR Path="/5CABE318/5A565351" Ref="C64"  Part="1" 
F 0 "C60" H 6550 1450 50  0000 L CNN
F 1 "Can" H 6550 1250 50  0000 L CNN
F 2 "legacy:C_0805_2012Metric_legacy" H 6538 1200 50  0001 C CNN
F 3 "" H 6500 1350 50  0001 C CNN
F 4 "dnp/ef" H -800 0   50  0001 C CNN "mpn"
	1    6500 1350
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0146
U 1 1 5A565357
P 6500 1200
AR Path="/5CABDA93/5A565357" Ref="#PWR0146"  Part="1" 
AR Path="/5CABE318/5A565357" Ref="#PWR0176"  Part="1" 
F 0 "#PWR0176" H 6500 950 50  0001 C CNN
F 1 "GND" H 6500 1050 50  0000 C CNN
F 2 "" H 6500 1200 50  0001 C CNN
F 3 "" H 6500 1200 50  0001 C CNN
	1    6500 1200
	1    0    0    1   
$EndComp
$Comp
L Device:C C23
U 1 1 5A56535D
P 5800 1350
AR Path="/5CABDA93/5A56535D" Ref="C23"  Part="1" 
AR Path="/5CABE318/5A56535D" Ref="C62"  Part="1" 
F 0 "C23" H 5850 1450 50  0000 L CNN
F 1 "Can" H 5850 1250 50  0000 L CNN
F 2 "legacy:C_0805_2012Metric_legacy" H 5838 1200 50  0001 C CNN
F 3 "" H 5800 1350 50  0001 C CNN
F 4 "dnp/ef" H -800 0   50  0001 C CNN "mpn"
	1    5800 1350
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR047
U 1 1 5A565363
P 5800 1200
AR Path="/5CABDA93/5A565363" Ref="#PWR047"  Part="1" 
AR Path="/5CABE318/5A565363" Ref="#PWR0174"  Part="1" 
F 0 "#PWR0174" H 5800 950 50  0001 C CNN
F 1 "GND" H 5800 1050 50  0000 C CNN
F 2 "" H 5800 1200 50  0001 C CNN
F 3 "" H 5800 1200 50  0001 C CNN
	1    5800 1200
	-1   0    0    1   
$EndComp
Connection ~ 6500 1500
Connection ~ 6500 1950
Connection ~ 6500 1750
$Comp
L power:GND #PWR0161
U 1 1 5AB1FFB0
P 5300 1850
AR Path="/5CABE318/5AB1FFB0" Ref="#PWR0161"  Part="1" 
AR Path="/5CABDA93/5AB1FFB0" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0161" H 5300 1600 50  0001 C CNN
F 1 "GND" H 5300 1700 50  0000 C CNN
F 2 "" H 5300 1850 50  0001 C CNN
F 3 "" H 5300 1850 50  0001 C CNN
	1    5300 1850
	-1   0    0    -1  
$EndComp
$Comp
L eforce:D_TVS_x2_AAC D15
U 1 1 5AB1FFB6
P 5400 1850
AR Path="/5CABE318/5AB1FFB6" Ref="D15"  Part="1" 
AR Path="/5CABDA93/5AB1FFB6" Ref="D14"  Part="1" 
F 0 "D14" V 5250 1850 50  0000 C CNN
F 1 "NUP2105L" V 5400 1550 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" V 5300 1650 50  0001 C CNN
F 3 "https://en.wikipedia.org/wiki/Transient-voltage-suppression_diode" V 5300 1650 50  0001 C CNN
F 4 "SZNUP2105LT1G" H -800 0   50  0001 C CNN "mpn"
	1    5400 1850
	0    -1   1    0   
$EndComp
Connection ~ 5800 1750
Connection ~ 5800 1950
$Comp
L Device:R R31
U 1 1 5B1ADB33
P 3000 1400
AR Path="/5CABDA93/5B1ADB33" Ref="R31"  Part="1" 
AR Path="/5CABE318/5B1ADB33" Ref="R32"  Part="1" 
F 0 "R31" H 3050 1450 50  0000 L CNN
F 1 "1k" H 3050 1350 50  0000 L CNN
F 2 "eforce_misc:R_0603_larger_pads" V 2930 1400 50  0001 C CNN
F 3 "" H 3000 1400 50  0001 C CNN
F 4 "ef" H -2250 -250 50  0001 C CNN "mpn"
	1    3000 1400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3000 1550 3000 1650
$Comp
L Device:C C21
U 1 1 5ABFB818
P 3350 900
AR Path="/5CABDA93/5ABFB818" Ref="C21"  Part="1" 
AR Path="/5CABE318/5ABFB818" Ref="C22"  Part="1" 
F 0 "C21" H 3400 1000 50  0000 L CNN
F 1 "100n" H 3400 800 50  0000 L CNN
F 2 "legacy:C_0402_1005Metric_legacy" H 3388 750 50  0001 C CNN
F 3 "" H 3350 900 50  0001 C CNN
F 4 "885012205037" H -1400 0   50  0001 C CNN "mpn"
	1    3350 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR043
U 1 1 5ABFB81E
P 3350 1050
AR Path="/5CABDA93/5ABFB81E" Ref="#PWR043"  Part="1" 
AR Path="/5CABE318/5ABFB81E" Ref="#PWR0199"  Part="1" 
F 0 "#PWR0199" H 3350 800 50  0001 C CNN
F 1 "GND" H 3350 900 50  0000 C CNN
F 2 "" H 3350 1050 50  0001 C CNN
F 3 "" H 3350 1050 50  0001 C CNN
	1    3350 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR044
U 1 1 5ABFB824
P 3350 750
AR Path="/5CABDA93/5ABFB824" Ref="#PWR044"  Part="1" 
AR Path="/5CABE318/5ABFB824" Ref="#PWR0200"  Part="1" 
F 0 "#PWR0200" H 3350 600 50  0001 C CNN
F 1 "+5V" H 3350 900 50  0000 C CNN
F 2 "" H 3350 750 50  0001 C CNN
F 3 "" H 3350 750 50  0001 C CNN
	1    3350 750 
	1    0    0    -1  
$EndComp
$Comp
L eforce:74LVC1G17 U12
U 1 1 5ABFD0C2
P 3400 1650
AR Path="/5CABDA93/5ABFD0C2" Ref="U12"  Part="1" 
AR Path="/5CABE318/5ABFD0C2" Ref="U13"  Part="1" 
F 0 "U12" H 3150 1800 50  0000 C CNN
F 1 "74LVC1G17" H 3250 1350 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 3400 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 3400 1650 50  0001 C CNN
F 4 "Si" H 0   0   50  0001 C CNN "mpn"
	1    3400 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR045
U 1 1 5ABFD24D
P 3600 1550
AR Path="/5CABDA93/5ABFD24D" Ref="#PWR045"  Part="1" 
AR Path="/5CABE318/5ABFD24D" Ref="#PWR0201"  Part="1" 
F 0 "#PWR0201" H 3600 1400 50  0001 C CNN
F 1 "+5V" H 3600 1700 50  0000 C CNN
F 2 "" H 3600 1550 50  0001 C CNN
F 3 "" H 3600 1550 50  0001 C CNN
	1    3600 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 1550 3500 1550
$Comp
L power:GND #PWR046
U 1 1 5ABFDA2A
P 3600 1750
AR Path="/5CABDA93/5ABFDA2A" Ref="#PWR046"  Part="1" 
AR Path="/5CABE318/5ABFDA2A" Ref="#PWR0202"  Part="1" 
F 0 "#PWR0202" H 3600 1500 50  0001 C CNN
F 1 "GND" H 3600 1600 50  0000 C CNN
F 2 "" H 3600 1750 50  0001 C CNN
F 3 "" H 3600 1750 50  0001 C CNN
	1    3600 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1750 3600 1750
Wire Wire Line
	3650 1650 3950 1650
Wire Wire Line
	3100 1650 3000 1650
Connection ~ 3000 1650
Wire Wire Line
	3000 1650 2900 1650
$Comp
L power:+5V #PWR0189
U 1 1 5AC0183A
P 3000 1250
AR Path="/5CABDA93/5AC0183A" Ref="#PWR0189"  Part="1" 
AR Path="/5CABE318/5AC0183A" Ref="#PWR0203"  Part="1" 
F 0 "#PWR0203" H 3000 1100 50  0001 C CNN
F 1 "+5V" H 3000 1400 50  0000 C CNN
F 2 "" H 3000 1250 50  0001 C CNN
F 3 "" H 3000 1250 50  0001 C CNN
	1    3000 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1500 5800 1500
Connection ~ 5800 1500
Wire Wire Line
	5800 2200 5050 2200
Connection ~ 5800 2200
Wire Wire Line
	7700 2200 7500 2200
Connection ~ 7500 2200
Wire Wire Line
	6500 2200 7500 2200
Wire Wire Line
	6500 1500 7500 1500
Wire Wire Line
	7500 1500 7700 1500
Connection ~ 7500 1500
Wire Wire Line
	7200 1850 7200 2800
Wire Wire Line
	7200 2800 5150 2800
Wire Wire Line
	5150 2800 5150 1850
Wire Wire Line
	5150 1850 4950 1850
Text Notes 6800 1400 0    50   ~ 0
https://www.nxp.com/docs/en/application-note/AN00020.pdf\n\n4.2\n\nIf priority is to enhance immunity,\nit is recommended to place the capacitors between\nthe transceiver and the common mode choke.\n\nIf, on the other hand, the aim is emission reduction,\nit is recommended to place the capacitors between \nthe choke and the split termination.
$EndSCHEMATC