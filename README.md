# NanoTekSpice

Second year Epitech project.

The NanoTekSpice is a basic electronic circuit simulator. It simulate basic operations and basic electronic circuit and components.

## Disclaimer

/!\ Cheating is forbidden, using source files of this repository for any Epitech project, do it at your own risks.

This project might be updated soon, with a graphic interface and new components.

## Requirements

- Makefile
- G++
- C++20

## Compilation and Installation

```bash
git clone git@github.com:444leod/NanoTekSpice.git
make
```

## Usage

```bash
./nanotekspice <file_name>
```

If the file given as parameter is not valid, an error message will be displayed.
Otherwise, the program is a shell. Here are the different commands:

* `exit` : closes the program.
* `display` : prints the value of all inputs and outputs.
* `input=value` : changes the value of an input. This ònly apply to `Input` and `Clock`.
* `simulate` : runs the simulation.
* `loop` : continuously runs the simulation until SIGINT is received.
* `sd` : runs the simulation once and prints the value of all inputs and outputs.

## Circuits

### How to build a circuit

A circuit is composed of two categories, the `.chipsets:` and the `.links:`.

You declare your components in the `.chipsets:` section. Several are available, basic one are input, output, clock, true and false, but more advanced gates are available like logic gates (and, or, xor), circuits (flip flops, counters, multiple and gates)..

You link components pins in the `.links:` section. All components have a certain number of pins, that correspond to either input, output or VSS VDD (power alimentation).

### Location

Some configuration files are located in the `./tests` & `./bonus/tests` directories. You can use one of them or create your own.

### Syntax

```
# Declare your components into the 'chipsets' section...
.chipsets:

# <chipset> <name>
# The name is up to you
# Example :
input   in_a
input   in_b
output  out
and    and_gate

# ...then link them within the 'links' section
.links:

# <chipset_name1>:<pin1> <chipset_name2>:<pin2>
# Example :
in_a:1 and_gate:1
in_b:1 and_gate:2
out:1 and_gate:3
```


## Authors

- [@444leod](https://www.github.com/leodumont444)
- [@ElliotKetchup](https://github.com/ElliotKetchup)

