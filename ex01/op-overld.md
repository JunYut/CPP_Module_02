# Operator Overloading
Allows custom behavior for operator when they are used with user-defined types (such as classes). This can make user-defined types more intuitive to use and integrate seamlessly with standard C++ syntax.

## Member Function
For operators that modify the left-hand operand(like `=`), you typically implement as member functions.

### `=`

#### Implementation:
```
Class &operator = (const Class &other)
{
	if (this != &other)
		member = other.member;
	return (*this);
}
```

#### Usage:
```
obj1 = obj2
```

**left-hand operand**: `Class & = obj1`
**right-hand operand**: `const Class &other = obj2`

## Non-member Function
For operators where the left-hand operand is not an instance of the class (like `<<`), you typically implement them as non-member functions, often as friend functions.

### `<<`
The `<<` operator in C++ is known as the stream insertion operator. It is primarily used for output operations, particularly with the `ostream` class, which includes `std::cout`. This operator allows you to send data to an output stream, such as the console or a file.

Common Usage:
- `Standard Output`: The most common use of the << operator is with std::cout to print data to the console.
- `File Output`: It can also be used with file streams (std::ofstream) to write data to files.

#### Implementation:
```
ostream &operator << (ostream &s, const Class &o)
{
	s << o.member;
	return (s);
}
```

#### Usage:
```
cout << object
```

**left-hand operand**: `ostream &s = cout`

**right-hand operand**: `const Class &o = object`

**return type**: `ostream &` - allows for chaining

#### Chaining:
```
cout << obj1 << obj2 << obj3;
```
#### First Operation: cout << obj1
The operator<< function is called with cout as the s parameter and obj1 as the o parameter.
Inside the function, s << o.member is executed, which inserts the member of obj1 into the cout stream.
The function then returns the cout stream (s).

#### Second Operation: cout << obj1 << obj2
The returned cout stream from the first operation is now used as the left-hand operand for the next << operation.
The operator<< function is called again, this time with the cout stream as the s parameter and obj2 as the o parameter.
Inside the function, s << o.member is executed, which inserts the member of obj2 into the cout stream.
The function then returns the cout stream (s).

#### Third Operation: cout << obj1 << obj2 << obj3
The returned cout stream from the second operation is now used as the left-hand operand for the next << operation.
The operator<< function is called again, this time with the cout stream as the s parameter and obj3 as the o parameter.
Inside the function, s << o.member is executed, which inserts the member of obj3 into the cout stream.
The function then returns the cout stream (s).

#### Summary
The chaining works because each call to the operator<< function returns the ostream reference (s). This allows the next << operation to use the same stream, enabling multiple insertions in a single statement. The final result is that the member of each object (obj1, obj2, obj3) is inserted into the cout stream in sequence.
