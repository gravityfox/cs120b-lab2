# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


# Add tests below

test "PINA: 0x00, PINB: 0x00, PINC: 0x00 => PORTD: 0x00"
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 2
expectPORTD 0x00
checkResult

test "PINA: 0x10, PINB: 0x10, PINC: 0x10 => PORTD: 0x30"
setPINA 0x10
setPINB 0x10
setPINC 0x10
continue 2
expectPORTD 0x30
checkResult

test "PINA: 0x40, PINB: 0x40, PINC: 0x40 => PORTD: 0xc1"
setPINA 0x40
setPINB 0x40
setPINC 0x40
continue 2
expectPORTD 0xc1
checkResult

test "PINA: 0x60, PINB: 0x08, PINC: 0x04 => PORTD: 0x6e"
setPINA 0x60
setPINB 0x08
setPINC 0x04
continue 2
expectPORTD 0x6e
checkResult

test "PINA: 0x04, PINB: 0x08, PINC: 0x60 => PORTD: 0x6e"
setPINA 0x04
setPINB 0x08
setPINC 0x60
continue 2
expectPORTD 0x6e
checkResult

test "PINA: 0x80, PINB: 0x40, PINC: 0x08 => PORTD: 0xcb"
setPINA 0x80
setPINB 0x40
setPINC 0x08
continue 2
expectPORTD 0xcb
checkResult

test "PINA: 0x80, PINB: 0x80, PINC: 0x80 => PORTD: 0xfd"
setPINA 0x80
setPINB 0x80
setPINC 0x80
continue 2
expectPORTD 0xfd
checkResult




# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
