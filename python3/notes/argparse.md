# Argparse Python3

* It is a parser for command line arguments, options and subcommands.
* Why use it ? The argparse module makes it easy to write user-friendly command-line interfaces. 
* The program defines what arguments it requires, and argparse will figure out how
to parse those out of sys.argv. The argparse module also automatically generates help and usage messages and
issues errors when users give the program invalid arguments.

```python
import argparse
parser = argparse.ArgumentParser()
parser.parse_args()
```
* even though we didnt specify any help arguments in our
script, its still giving us a nice help message.
This is the only option we get for free.

## Positional Arguments
* Whenever we want to specify which command-line options the program will accept,
we use the "add_argument()" method. 
```python
import argsparse

parser = argsparse.ArgumentParser()
parser.add_argument("echo") # naming it "echo"
args = parser.parse_args() # returns data from the options specified (echo)
print(args.echo)
```
```shell
$ python program.py

usage: program.py [-h] echo
program.py: error: too few arguments

$ python program.py echo
echo

#Using the --help option
$ python program.py --help
usage: program.py [-h] echo

positional arguments:
  echo

optional arguments:
  -h, --help  show this help message and exit
```

## Extending the help text
```python
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("echo", help="echo the string you use here")
args = parser.parse_args()
print(args.echo)
```
```shell
$ python program.py --help
usage: program.py [-h] echo

positional arguments:
  echo        echo the string you use here

optional arguments:
  -h, --help  show this help message and exit
```
Argparse treats the options we give as a string, but we can change that. 

# Running the code with the type set to Integer

```python
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("sqaure", help = "display a square of a given number", type=int)
args = parser.parse_args()
print(args.square**2)
```
```shell
$ python program.py -h
usage: program.py [-h] square

positional arguments:
  square      display a square of a given number

optional arguments:
  -h, --help  show this help message and exit

$ python program.py 4
16

$ python program.py 10
100

# If we would use a string instead of a number, the program will return an error
$ python program.py four

usage: program.py [-h] square

program.py: error: argument square: invalid int value: 'four'
```
## Optional Arguments
```python
import agrparse
parser = agrparse.ArgumentParser()
parser.add_argument("--verbose", help="increase output verbosity", action = "store_true")
args = parser.parse_args()
if(args.verbosev):
	print("verbosity turned on")
```
An optional argument (or option) is (by default) given None as a value when its
not being used.

Using the --verbosity option, only two values are actually useful, True or False. 

The keyword "action" is being given the value "store_true" which means that if
the option is specifed, then assign the value "True" to args.verbose

Not specifying the option implies False.

If we run the program with the  --help option, we can see:

```bash
$ python program.py -h
usage: program.py [-h] [--verbose]

optional arguments:
  -h, --help  show this help message and exit
  --verbose   increase output verbosity
```
Run the program using the --verbose option
```bash
$ python program.py --verbose
verbosity turned on
```
## Short options
Using short versions of the options is as easy as:
```python
parser.add_argument("-v", "--verbose", help="increase output verbosity", action="store_true")
```
The help text will updated with the short version.