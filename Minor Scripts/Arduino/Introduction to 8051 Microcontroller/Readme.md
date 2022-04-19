
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
<img width="359" alt="image" src="https://user-images.githubusercontent.com/85052056/163781875-eb09bcc0-633a-4b50-b7d6-ca3eafaf2ba2.png">


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
<img width="320" alt="image" src="https://user-images.githubusercontent.com/85052056/163782354-6fc2446b-36bd-47b9-8828-b1b067d4386a.png">


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
<img width="566" alt="image" src="https://user-images.githubusercontent.com/85052056/163782790-957b2474-1058-424a-936e-88b196d593d3.png">

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

- Harvard Architecture

<img width="324" alt="image" src="https://user-images.githubusercontent.com/85052056/163782970-9896717f-8dec-4aea-8cc9-8948b7e601a8.png">

- Von Neumann Architecture

<img width="329" alt="image" src="https://user-images.githubusercontent.com/85052056/163783110-2b621792-5eb7-43b4-a304-ca9c41e57a4b.png">


## Harvard and Von Neumann Architecture
<img width="599" alt="image" src="https://user-images.githubusercontent.com/85052056/163783450-5e9284e3-9caa-48de-b8b8-834dab8b157d.png">

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

<img width="460" alt="image" src="https://user-images.githubusercontent.com/85052056/163783672-9b400576-65d9-4a98-80bc-10142e1dbbfb.png">



## Program Status Word (PSW): D0H
<img width="551" alt="image" src="https://user-images.githubusercontent.com/85052056/163783898-671268eb-d2bc-44a1-8a43-a2d877ee9ae3.png">


- This is a vital SFR in the functioning of micro controller.
- This register reflects the status of the operation that is being carried out in the processor.
- PSW Register is both bit and byte addressable. The physical address of PSW starts from D0H. The
individual bits are then accessed using D1, D2 ... D7.

<img width="454" alt="image" src="https://user-images.githubusercontent.com/85052056/163784087-8526de7c-337b-41a2-8483-ca3417b3f267.png">

### The selection of the register Banks in PSW and their addresses
<img width="596" alt="image" src="https://user-images.githubusercontent.com/85052056/163784139-be975764-4a12-4f0d-90b1-56e27c48a1e1.png">


### RS1 RS0 Register Bank Address

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

<img width="599" alt="image" src="https://user-images.githubusercontent.com/85052056/163784407-de5ffd41-21b6-4e53-b7d2-61b187badf10.png">


## Interrupt

Interrupt is the event that temporarily suspends the main program, pass the control to the interrupt
service routine (ISR) and executes the task. Then the control goes to the main program where it had
left off. 8051 has 5 interrupts available. Some manufacturers also state Reset as one of the interrupt.

<img width="599" alt="image" src="https://user-images.githubusercontent.com/85052056/163784523-cb488d57-18bf-4b9a-a17e-b8993162d8a1.png">


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

## Summary
The 8051 Microcontroller is very much useful as it's cost efficient as well power efficient and can be used to satisfy multiple purpose needs. Also the in-depth study of the 8051 gives broader view of other microcontroller's as well. The 8051 Microcontroller is one of the most popular and most commonly used microcontrollers in various fields like embedded systems, consumer electronics, automobiles, etc. Thus the understanding and usage of 8051 is very important in day to day life.

### Author
Siddhant Pawar 
