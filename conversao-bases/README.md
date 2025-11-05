# Conversor de bases em C

Como método de estudo para cnoversão de bases (e também para não ter que fazer á mão),
esse mini projeto tem o objetivo de automatizar a conversão de números entre as bases:
- Decimal
- Octal
- Hexadecimal
- Binária


BIN

OCT

DEC

HEX


101 2 10 --> 5


101 (2) --> 5 (10)


func1: x_to_decimal
func2: decimal_to_x
func3: chunker
func4: decimal_to_decimal (workaround)
---------------------------------------------------

BIN = b
HEX = h
DEC = d
OCT = o



func1 = b and d or (o and h or o and d or o and b) or h and d or h and o or h and b

func2 = o and h or o and b or d and h or d and o or d and b or h and o or h and b

func3 = b and h or b and o or o and h or h and o

func4 = b and d or o and d or d and o or d and b



func1 simplified = b and d or o and (h or d or b) or h and (d or o or b)

func2 simplified = o and (h or b) or h and (o or b)

func3 simplified = b and (h or o) or o and h or h and o

func4 simplified = (b or o) and d



BIN to HEX --> chunker
BIN to DEC --> func1 func4
BIN to OCT --> chunker

OCT to HEX --> func1 func2 chunker
OCT to DEC --> func1 func4
OCT to BIN --> func1 func2

DEC to HEX --> func4 func2
DEC to OCT --> func4 func2
DEC to BIN --> func4 func2

HEX to DEC --> func1 func4
HEX to OCT --> func1 func2 chunker
HEX to BIN --> func1 func2



# groups and conditions

if (
  target_base == 10 ||
  current_base == 2 ||
  current_base == 16
) { 1
  
  value = x_to_decimal(target_base);
  if (target_base == 10) { 2
    value = dec_to_x(10);
    return;
  }
  else if (target_base == 2) { 4
    value = dec_to_x(2);
  }
  else if (target_base == 8) { 5
    value = x_t_dec(chunk);
    
  }
  
}