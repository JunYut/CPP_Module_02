# Operator Overloading
## Unary Operators
### Prefix Increment & Prefix Decrement Operators
`Member Function`: takes `no` arguments \
`Return`: a reference to the object to allow for chaining
- `++i`
- `--i`

### Postfix Increment & Postfix Decrement Operators
`Member Function`: takes `1` argument \
`Return`: a copy of the object before modification
- `i++`
- `i--`

## Binary Operators
### Arithmetic Operators
`Member Function`: takes `1` argument, the `Right-hand Operand` \
`Return`: typically a new object that is the result of the operation 
- `+`
- `-`
- `*`
- `/`
- `%`

### Relational Operators
`Member Function`: takes `1` argument, the `Right-hand Operand` \
`Return`: typically a boolean value indicating the result of the comparison 
- `==`
- `!=`
- `<`
- `>`
- `<=`
- `>=`

### Assignment Operators
`Member Function`: takes `1` argument, the `Right-hand Operand` \
`Return`: typically a reference to the left operand to allow for chained assignments
- `=`
- `+=`
- `-=`
- `*=`
- `/=`
- `%=`

## Special Operators
### Subscript Operator
- `[]`

`Member Function`: takes `1` argument, the `Right-hand Operand` \
`Return`: a reference to the element at the specified index

### Function Call Operator
- `()`

`Member Function`: takes a `variable number` of arguments \
`Return`: the result of the function call

### Stream Insertion & Extraction Operators
- `<<` \

`Non-Member Functions *`: takes `2` arguments \
`Arg 1`: Left-hand Operand \
`Arg 2`: Right-hand Operand \
`Return`: a reference to the output stream to allow for chaining

- `>>` \

`Non-Member Functions *`: takes `2` arguments \
`Arg 1`: Left-hand Operand \
`Arg 2`: Right-hand Operand \
`Return`: a reference to the input stream to allow for chaining

## Chaining
Chaining works by ensuring that the overloaded operators return a reference to
an object that allows subsequent operations to be applied to the same object 
or stream. This is commonly used with assignment operators, arithmetic operators, and stream insertion/extraction operators.

### Assignment Operators
```
a = b = c;
```
1. The expression is evaluated from right to left
2. `b = c` is evaluated. `=` returns a reference to `b`
3. `a = b` is evaluated. `=` returns a reference to `a`

### Stream Insertion Operators
```
cout << a << b << c;
```
1. The expression is evaluated rom left to right
2. `cout << a` is evaluated. `<<` returns a reference to `cout`
3. `cout << b` is evaluated. `<<` returns a reference to `cout`
4. `cout << c` is evaluated. `<<` returns a reference to `cout`

### Arithmetic Operators
```
d = a + b + c;
```
1. The expression is evaluated rom left to right
2. `a + b` is evaluated. `+` returns a new object
3. The reslut of `a + b` is added to `c`. `+` returns a new object
4. The result is assigned to `d`

## FAQ
### Why `<<` and `>>` are implemented as `Non-Member Function`s ?
1. **Chaining Different Data Types** \
Allows chaining of multiple stream operations involving both built-in types 
and user-defined types.
2. **Flexibility** \
Don't need to modify the stream classes to support new user-defined types.
3. **Symmetry and Consistency** \
The left-hand operand can be a standard stream object and the right-hand 
object can be a user-defined type.
4. **Access to Private Members** \
By declaring the non-member operator functions as friends of the class, they 
can access private and protected members of the class.
