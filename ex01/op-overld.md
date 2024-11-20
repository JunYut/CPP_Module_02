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
object1 = object2
```

## Non-member Function
For operators where the left-hand operand is not an instance of the class (like `<<`), you typically implement them as non-member functions, often as friend functions.

### `<<`
The `<<` operator in C++ is known as the stream insertion operator. It is primarily used for output operations, particularly with the `ostream` class, which includes `std::cout`. This operator allows you to send data to an output stream, such as the console or a file.

Common Usage:
- Standard Output: The most common use of the << operator is with std::cout to print data to the console.
- File Output: It can also be used with file streams (std::ofstream) to write data to files.

#### Implementation:
```
ostream &operator << (ostream &s, const Class &o)
{
	stream << o.member;
	return (stream);
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
cout <<
