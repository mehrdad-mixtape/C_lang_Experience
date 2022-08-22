/** Available Types: **/
int // Stores a regular integer, defaulting to 32 bits in size.
double // Holds a large floating-point number.
float // Holds a smaller floating-point number.
char // Holds a single 1-byte character.
void // Indicates "no type" and is used to say that a function returns nothing, or a pointer has no type.
enum /* Enumerated types, which work as and convert to integers, but give you symbolic names for sets.
* Some compilers will warn you when you don't cover all elements of an enum in switch-statements.
*/

/** Type Modifiers: **/
unsigned // Changes the type so that it doesn't have negative numbers, giving you a larger upper bound but nothing lower then 0.
signed // Gives you negative and positive numbers, but halves your upper bound in exchange for the same lower bound negative.
long // Uses a larger storage for the type so that it can hold bigger numbers, usually doubling the current size.
short // Uses smaller storage for the type so it stores less, but takes half the space.

/** Type Qualifiers: **/
const // Indicate that the variable won't change after being initialized.
volatile /* Indicates that all bets are off, and the compiler should leave this alone and try not to do any fancy optimizations to it.
* You usually only need this of you're doing really weird stuff to your variables.
*/
register /* Forces the complier to keep this variable in a register, and the compiler can just ignore you.
* These days compilers are better t figuring out where to put variables, so only use this if you can actually
measure an improvement in speed.
*/

/** Type Conversion: **/
long double
double
float
int (but only char and short int)
long

/** Type size: **/
//(u)int(BITs) #include stdint.h
int8_t // 8 bit signed int.
uint8_t // 8 bit unsigned int.
int16_t
uint16_t
int32_t
uint32_t
int64_t
uint64_t

int_least(N)_t // Holds at least (N)bits=8, 16, 32, 64, 128.
uint_least(N)_t // Unsigned int_least(N).
int_fast(N)_t // Similar to int_least(N)_t but asking for the "fastest" with at least that precision.
uint_fast(N)_t // Unsigned int_fast.
intptr_t // Signed int large enough to hold a pointer.
uintptr_t // Unsigned intptr_t.
intmax_t // Biggest number possible on that system.
uintmax_t // Unsigned intmax_t
