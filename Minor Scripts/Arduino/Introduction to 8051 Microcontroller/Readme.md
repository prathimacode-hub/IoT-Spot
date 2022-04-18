## IoT Spot

## Introduction to 8051 Microcontroller

## Introduction

- A microcontroller is a highly integrated single chip, which consists of
    - On chip CPU (Central Processing Unit),
    - RAM (Random Access Memory),
    - EPROM/PROM/ROM (Erasable Programmable Read Only Memory),
    - I/O (input/output).
- Intel 8051 is an 8-bit microcontroller
- A very popular general purpose microcontroller widely used for small scale embedded systems.
- Many vendors such as Atmel, Philips, and Texas Instruments produce MCS 51 family
microcontroller chips.

## General Block Diagram of 8051

## Basic Definitions

- Bus:- It is a set/ bunch of wires used to pass information between modules. For 8051 data bus is of
size 8 bits and address bus is 16 bits.
- Port:- A physical connection between computer and its outside world. Information enters via input
port and exits via output port.
- Interface:- The hardware and software that combines to allow the computer to communicate with
the external hardware/devices. It is collection of all, ports as well as devices. Ex switch, sensors,
motor drivers etc.

Types of interfaces---

1. Parallel:- Binary data available simultaneously on a group of lines.
2. Serial:- Binary data available only one bit at a time on single line
3. Analog:- Data encoded as electrical voltage, current or power.


4. Timed:- Data encoded as a period, frequency, pulse width or phase shift.

## Salient Features of 8051

```
 8 - bit CPU with registers A and B.
 16 bit program counter and data pointer.
 8 Bit Program Status Word (PSW).
 8 Bit Stack Pointer.
 4K bytes of internal ROM and 128 bytes of on chip RAM. 64 K bytes of external program
memory address space and 64 K bytes of external data memory address space.
 32 bidirectional digital I/O lines, Full Duplex serial data receiver/transmitter.
 Two 16 Bit Timer/Counter :T0, T1.
 Control registers: TCON, TMOD, SCON, PCON, IP and IE.
 Two external and 3 internal interrupt sources.
 On chip oscillator and clock circuit.
```
## Pin Description

## Pin No. Description

```
Pins 1-
PORT 1
```
```
Each of these pins can be configured as an input or an output.
```
```
Pin 9
RESET
```
```
A logic one on this pin disables the microcontroller and clears the
contents of most registers (Reset). By applying logic zero, the
program starts execution from the beginning.
Pins10-
PORT 3
```
```
Each of these pins can serve as general input or output. All of them
have alternative functions.
Pin 11
TXD
```
```
Serial asynchronous communication output or Serial synchronous
communication clock output.
Pin 12 INT0 - External Interrupt 0 input
Pin 13 INT1 - External Interrupt 1 input
Pin 14 T0 - Counter 0 clock input
Pin 15 T1 - Counter 1 clock input
```

```
Pin 16 WR - Write to external RAM
Pin 18, 19 XTAL2, XTAL1 - Internal oscillator input and output. A quartz crystal
which specifies operating frequency is usually connected to these
pins.
Pin 20 GND - Ground.
Pin 21-
Port 2
```
```
If there is no intention to use external memory then these port pins
are configured as general inputs/outputs. In case external memory is
used, the higher address byte, i.e. addresses A8-A15 will appear on
this port.
Pin 29
PSEN
```
```
If external ROM is used for storing program then a logic zero (0)
appears on it every time the microcontroller reads a byte from
memory.
Pin 30 ALE - Prior to reading from external memory, the microcontroller puts
the lower address byte (A0-A7) on P0 and activates the ALE output.
Pin 31
EA
```
```
External access. By applying logic zero to this pin, P2 and P3 are used
for data and address transmission with no regard to whether there is
internal memory or not.
Pin 32- 39
PORT 0
```
```
Similar to P2, if external memory is not used, these pins can be used
as general inputs/outputs.
Pin 40 VCC - +5V power supply.
```
## Memory Organization

- The 8051 microcontroller has 128 bytes of Internal RAM. The RAM is also known as Data memory.
- The 8051 microcontroller has 4kB of on chip ROM known as program memory (Or Code memory).
The Code memory holds the actual 8051 program that is to be executed. In 8051 this memory is
limited to 64K. Code memory may be found on-chip, as ROM or EPROM.
- There is a provision of connecting both external RAM and ROM Memory and Program. The reason
-- complex programs written in high – level languages often tend to be larger and occupy more
memory.
- Some 8051 Microcontroller variants have 8K ROM and 256B of RAM. Also there were chips like
8031 or 8032, without any internal ROM.

## Internal RAM OF 8051- On-chip RAM

It is the fastest RAM available, and it is also the most flexible in terms of reading, writing, and
modifying it’s contents. This internal RAM is volatile.

The 128 bytes of internal RAM (General purpose registers)is organized as below:

1. Four register banks (R0-, R1, R2, R3) each of 8-bits (total 32- bytes).
2. The default bank register -- Bank0. The remaining Banks are selected with the help of RS
    and RS1 bits of PSW Register. Address is from 00h to 1Fh.
3. 16 bytes of bit addressable area from 20h to 2Fh and
4. 80 bytes of general purpose area (Scratch pad memory) from 30h to 7Fh as shown in the
    diagram below. This area is also utilized by the microcontroller as a storage area for the
    operating stack.


SFR memory (128 bytes– 80H to FFH)

SFRs Memory addresses are only direct addressable. Out of these 128 bytes only 21 are assigned
special functions. Even though some of the addresses between 80H and FFH are not assigned to any
SFR, they cannot be used as additional RAM area.

## Internal RAM OF 8051- Memory map

## ROM OF 8051- On-chip +External

The 8051 microcontroller has 4kB of on chip ROM but it can be extended up to 64kB. (External
ROM).

For accessing both memories, the External Access Pin (EA Pin) must be pulled HIGH. When the EA
Pin is high, the CPU first fetches instructions from the Internal Program Memory in the address range
of 0000H to 0FFFFH and if the memory addresses exceed the limit, then the instructions are fetched
from the external ROM in the address range of 1000H to FFFFH.

## 8051 Microcontroller Architecture

It is an arrangement of the CPU with respect to the RAM and ROM. The Harvard and Von-Neumann
architecture are the two ways through which the micro controller CPU can be connected with RAM
and ROM.

```
Harvard Architecture Von Neumann Architecture
```

## Harvard and Von Neumann Architecture

### Sr.No. Point of Comparison Harvard Architecture Von-Neumann

### Architecture

```
1 Hardware
```
## requirement

```
It requires more hardware
since it will be requiring
separate data and address
```
## bus for each memory.

```
Requires less hardware
since only a common
memory needs to be
```
## reached.

## 2 Space requirement More space. Less space.

## 3 Speed of execution Faster because the

```
processor fetches data and
instructions
```
## simultaneously.

```
Slower since it cannot fetch
the data and instructions at
```
## the same time.

## 4 Space usage Space is wasted, if the

```
space is left in the data
memory then the
instructions memory
cannot use the space of the
data memory and
```
## vice versa.^

```
Space is not wasted because
the space of the data
memory can be utilized by
the instructions memory
```
## and vice-versa.

```
5 Controlling Controlling becomes
complex since data and
instructions are to be
fetched simultaneously.
```
```
Controlling becomes simpler
since either data or
instructions are to be FY
fetched at a time.
```
## Special Function Registers (SFRs)

- In 8051 microcontroller there are certain registers which use the RAM addresses from 80H to FFH
and they are meant for certain specific operations. (Upper 128 bytes).
- These registers are called Special function registers (SFRs).
- Some of these registers are bit and byte addressable.
- Some of SFRs are related to I/O ports (P0,P1,P2 and P3) and some are meant for control operations
(TCON,SCON, PCON..) and remaining are the auxiliary SFRs.
- SFRs Memory addresses are only direct addressable. Even though some of the addresses between
80H and FFH are not assigned to any SFR, they cannot be used as additional RAM area.
- Out of these 128 Memory Locations (80H to FFH), there are only 21 locations that are actually
assigned to SFRs.
- Each SFR has one Byte Address and also a unique name which specifies its purpose. Since the SFRs
are a part of the Internal RAM Structure, you can access SFRs as if you access the Internal RAM.

### Sr. No. Symbol Name of SFR Address (Hex)

```
1 ACC* Accumulator 0E
2 B* B-Register 0F
3 PSW* Program Status Word Register 0D
4 SP Stack Pointer Register 81
5 DPTR DPL Data Pointer Low Byte 82
```

```
DPH Data Pointer High Byte 83
6 P0* Port 0 80
7 P1* Port 1 90
8 P2* Port 2 0A
9 P3* Port 3 0B
10 IP* Interrupt Priority Control 0B
11 IE* Interrupt Enable Control 0A
12 TMOD Timer Mode Register 89
13 TCON* Timer Control Register 88
14 TH0 Timer 0 Higher byte 8C
15 TL0 Timer 0 Lower byte 8A
16 TH1 Timer 1 Higher byte 8D
17 TL1 Timer 1 Lower byte 8B
18 SCON* Serial Control Register 98
19 SBUF Serial Buffer Register 99
20 PCON Power Control Register 87
* Marked registers are bit and byte addressable, other registers are only byte addressable
```
## Program Status Word (PSW): D0H

- This is a vital SFR in the functioning of micro controller.
- This register reflects the status of the operation that is being carried out in the processor.
- PSW Register is both bit and byte addressable. The physical address of PSW starts from D0H. The
individual bits are then accessed using D1, D2 ... D7.

### Bit No Bit Symbol Direct Address Name Function

```
0 P D0 Parity This bit will be set if ACC has odd
number of 1’s after an operation. If
not, bit will remain cleared.
1 -- D1 User definable bit
2 OV D2 Overflow OV flag is set if there is a carry from
bit 6 for signed number operation,
but not from bit 7 of an Arithmetic
operation.
3 RS0 D3 Register
Bank select
```
```
LSB of the register bank select bit.
Bit 0
4 RS1 D4 Register
Bank select
```
```
MSB of the register bank select bits.
Bit 1
```

```
5 F0 D5 Flag 0 User defined flag
6 AC D6 Auxiliary
carry
```
```
This bit is set if data is coming out
from bit 3 to bit 4 of Acc during an
Arithmetic operation.
7 CY D7 Carry Is set if data is coming out of bit 7 of
Acc during an Arithmetic operation.
```
### The selection of the register Banks in PSW and their addresses

### RS1 RS0 Register Bank Address

# 0 0 Bank 0 00H-07H

# 0 1 Bank 1 08H-0FH

# 1 0 Bank 2 10H-17H

```
1 1 Bank 3 18H-1FH
```
###  CY -- Carry flag

```
This flag is set whenever there is a carry out from the D7 bit. This flag bit is affected after an
8-bit addition or subtraction. It can also be set to 1 or 0 directly by an instruction such as
“SETB C” and “CLR C” where “SETB C” stands for “set bit carry” and “CLR C” for “clear carry”.
```
###  AC -- Auxiliary carry

```
This flag If there is a carry from D3 to D4 during an ADD or SUB operation, this bit is set;
otherwise, it is cleared. This flag is used by instructions that perform BCD (binary coded
decimal) arithmetic.
```
###  P -- Parity flag

```
The parity flag reflects the number of 1 s in the A (accumulator) register only. If the A
register contains an odd number of Is, then P = 1. Therefore, P = 0 if A has an even number
of Is.
```
###  OV -- Overflow flag

```
This flag is set whenever the result of a signed number operation is large, causing the high-
order bit to overflow into the sign bit. In general, the carry flag is used to detect errors in
unsigned arithmetic operations. The overflow flag is only used to detect errors in signed
arithmetic operations.
```
## Timer/Counters

```
 Two 16-bit up counters, named T0 and T1, are provided for the general use of the
programmer.
 Each counter may be programmed to count internal clock pulses, acting as a timer, or
programmed to count external pulses as a counter.
 The counters are divided into two 8-bit registers called the timer low (TL0,TL1) and high
(TH0, TH1) bytes.
 All counter action is controlled by bit states in the timer mode control register (TMOD), the
timer/counter control register (TCON) and certain program instructions.
 TMOD is dedicated to the two timers and can be considered as two 4-bit registers, each of
which controls the action of the timers.
 TCON has control bits and flags for the timers in the upper control nibble and flags for the
external interrupts in the lower nibble.
```

### Timer/Counters: comparison

### Timer Counter

```
The register incremented for every machine
```
### cycle.

```
The register is incremented considering 1 to 0
transition at its corresponding external input pin
```
### (T0, T1).

```
Maximum count rate is 1/12 of the oscillator
```
### frequency.

```
Maximum count rate is 1/24 of the oscillator
```
### frequency.

```
A timer uses the frequency of the internal clock,
```
### and generates delay.

```
A counter uses an external signal to count
```
### pulses.

## Interrupt

Interrupt is the event that temporarily suspends the main program, pass the control to the interrupt
service routine (ISR) and executes the task. Then the control goes to the main program where it had
left off. 8051 has 5 interrupts available. Some manufacturers also state Reset as one of the interrupt.

### Interrupt Sources ROM location (Vector table)

# Reset 0000 H

# External hardware Interrupt 0 INT0 (IE0) 0003 H

# Timer 0 interrupt (TF0) 000B H

# External hardware Interrupt 1 INT1 (IE1) 0013 H

# Timer 1 interrupt (TF1) 001B H

# Serial COM Port interrupt (RI/TI) 0023 H

## Power down and Idle mode

Power down and Idle mode features are used to save power in microcontrollers. 8051 has an inbuilt
power-saving feature which is useful in embedded applications where power consumption is the
main constraint.

- 8051 has two power-saving modes. Power saved in power-down mode is more than in idle mode.
    - Power Down Mode.
    - Idle Mode.
- Power saving modes are set using PCON SFR.

## Instruction Groups

Based on the operation they perform, all the instructions in the 8051 Microcontroller Instruction Set
are divided into five groups. They are:

1. Data Transfer Instructions.
2. Arithmetic Instructions.
3. Logical Instructions.
4. Boolean or Bit Manipulation Instructions.
5. Program Branching Instructions.


## Instruction structure

8051 Instruction consists of an OPCODE (Operation – Code) followed by Operand(s) of size Zero
Byte, One Byte or Two Bytes.

- The OPCODE part of the instruction contains the Mnemonic, which specifies the type of operation
to be performed.
- All mnemonics or the OPCODE part of the instruction are of One Byte size.
- Operand part of the instruction-- It defines the data being processed by the instructions. The
operand can be any of the following:
    1. No Operand.
    2. Data value.
    3. I/O Port.
    4. Memory Location.
    5. CPU register.

## Addressing Modes

An Addressing Mode is a way to locate a target Data, which is also called as Operand. The 8051
Family of Microcontrollers allows five types of addressing modes for addressing the Operands.

Types of Addressing Modes

1. Immediate Addressing.
2. Register Addressing.
3. Direct Addressing.
4. Register – Indirect Addressing.
5. Indexed Addressing.