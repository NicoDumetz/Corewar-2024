# Corewar ⚔️

Corewar is a game where players write programs (called "warriors") that fight for control of the memory of a virtual machine. Each warrior tries to eliminate the others by making them execute invalid instructions.

## Usage
```
make
./corewar -h
```
**-dump nbr_cycles**

Dumps the memory after the specified number of cycles (if the round isn’t already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...).

**-n prog_number**

Sets the next program’s number. By default, the first free number in the parameter order is used

**-a load_address**

Sets the next program’s loading address. When no address is specified, the addresses are optimized so that the processes are distributed evenly.

## How to run

```
make
./corewar champ.cor champ.cor -dump 50
```
# Explanations of multiple concepts

### Process (Warriors)

A process (also known as a champion) in Corewar is a program written in assembly-like language that competes for control of the virtual machine's memory. Each process executes instructions, manipulates memory, and interacts with other processes to achieve victory.

### Carry
The carry is a flag used to indicate the success or failure of certain operations. Many instructions, such as ld, add, and sub, modify the carry. The state of the carry flag can affect the behavior of other instructions, like zjmp.

### Program Counter (PC)

The Program Counter (PC) is a register that holds the address of the next instruction to be executed. It increments as instructions are executed and can be modified by jump instructions like zjmp and fork.

### IDX_MOD
**IDX_MOD** is a modulo value used to limit the range of memory addressing. When performing certain operations, such as calculating memory addresses for loading or storing data, the IDX_MOD value is applied to ensure that the address stays within a specific range.

### Parameter Types

- **Register**: Registers are small storage locations within the virtual machine that can hold data. They are often used as operands in instructions.
  
- **Direct**: Direct values are immediate constants specified in the instruction itself. They are prefixed with a `%` symbol and can be used for immediate addressing.
  
- **Indirect**: Indirect values refer to memory locations. The address is calculated based on a specified value, often involving the PC or another base address. This type is useful for relative addressing.


# Instructions

| Instructions     | Parameters                                                      | Effects                                                                                                                                                                                                                                                                               |
|--------------|-----------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `0x01 (live)`| 1 parameter: 4 bytes (integer)                                  | Indicates that the player is alive                                                                                                                                                                                                                                                    |
| `0x02 (ld)`  | 2 parameters: value (integer/direct/indirect), register         | Loads the value of the first parameter into the second parameter, which must be a register. This operation modifies the carry. Example: `ld 34, r3` loads the REG_SIZE bytes starting at the address PC + 34 % IDX_MOD into r3                                                       |
| `0x03 (st)`  | 2 parameters: register, value (register/direct/indirect)        | Stores the first parameter’s value (which is a register) into the second (whether a register or a number). Example: `st r4, 34` stores the content of r4 at the address PC + 34 % IDX_MOD. `st r3, r8` copies the content of r3 into r8                                              |
| `0x04 (add)` | 3 parameters: register, register, register                      | Adds the content of the first two and puts the sum into the third one (which must be a register). This operation modifies the carry. Example: `add r2, r3, r5` adds the content of r2 and r3 and puts the result into r5                                                              |
| `0x05 (sub)` | 3 parameters: register, register, register                      | Similar to add, but performs a subtraction                                                                                                                                                                                                                                            |
| `0x06 (and)` | 3 parameters: value (integer/direct/indirect), value (integer/direct/indirect), register | Performs a binary AND between the first two parameters and stores the result into the third one (which must be a register). This operation modifies the carry. Example: `and r2, %0, r3` puts r2 & 0 into r3                                                                           |
| `0x07 (or)`  | 3 parameters: value (integer/direct/indirect), value (integer/direct/indirect), register | Similar to and, but performs a binary OR                                                                                                                                                                                                                                              |
| `0x08 (xor)` | 3 parameters: value (integer/direct/indirect), value (integer/direct/indirect), register | Similar to and, but performs a binary XOR (exclusive OR)                                                                                                                                                                                                                               |
| `0x09 (zjmp)`| 1 parameter: index (integer/direct)                             | Jumps to this index if the carry is 1. Otherwise, it does nothing but consumes the same time. Example: `zjmp %23` puts, if carry equals 1, PC + 23 % IDX_MOD into the PC                                                                                                               |
| `0x0a (ldi)` | 3 parameters: index (integer/direct/indirect), index (integer/direct/indirect), register | The first two must be indexes or registers, the third one must be a register. This operation modifies the carry. Example: `ldi 3, %4, r1` reads IND_SIZE bytes from the address PC + 3 % IDX_MOD, adds 4 to this value. The sum is named S. REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1 |
| `0x0b (sti)` | 3 parameters: register, value (integer/direct/indirect), value (integer/direct/indirect) | The first one must be a register. The other two can be indexes or registers. Example: `sti r2, %4, %5` copies the content of r2 into the address PC + (4+5) % IDX_MOD                                                                                                                  |
| `0x0c (fork)`| 1 parameter: index (integer/direct)                             | Creates a new program that inherits different states from the parent. This program is executed at the address PC + first parameter % IDX_MOD                                                                                                                                           |
| `0x0d (lld)` | 2 parameters: value (integer/direct/indirect), register         | Similar to ld without the % IDX_MOD. This operation modifies the carry                                                                                                                                                                                                                 |
| `0x0e (lldi)`| 3 parameters: index (integer/direct/indirect), index (integer/direct/indirect), register | Similar to ldi without the % IDX_MOD. This operation modifies the carry                                                                                                                                                                                                                |
| `0x0f (lfork)`| 1 parameter: index (integer/direct)                            | Similar to fork without the % IDX_MOD                                                                                                                                                                                                                                                  |
| `0x10 (aff)` | 1 parameter: register                                           | Displays on the standard output the character whose ASCII code is the content of the register (in base 10). A 256 modulo is applied to this ASCII code. Example: `aff r3` displays ‘*’ if r3 contains 42                                                                               |

## How to Build Your Own Warriors 🌟

### Creates an .s file
```
touch XxDEMON_CHAMP_KIKOOxX.s
```

### Write your warriors
here's an example of a champion:

```
    .name "Nicolas Dumetz"
    .comment "Very bad at combat but better at code"


            sti r1, %:matisse, %1
matisse:    live %0
            ld %0, r6
            zjmp %:matisse
```
(you understand that this champion is really bad)

### Compiled your .s
```
tests/binaires/asm/asm XxDEMON_CHAMP_KIKOOxX.s
```
GG Your .cor will then be created

# How to launch Corewar in 3D 🤩

## Installation OPENGL
### Linux (Fedora)
```
sudo dnf update
sudo dnf install @development-tools
sudo dnf install mesa-libGL-devel
sudo dnf install mesa-libGLU-devel
sudo dnf install freeglut-devel
sudo dnf install glfw-devel
```

### Windows
#### MinGW
Download and install MinGW from MinGW.org. Be sure to include the compiler packages for C.
#### GLFW
Download GLFW binaries for Windows from GLFW.org and extract them to an accessible directory.

## How to run
The program takes exactly the same parameters as the basic binary
```
cd /bonus
make
./corewar champ.cor champ.cor
```
