# Extensible Programming Language

*XPL or X++ is a programming language that is designed to be easy to use and easy to learn. It is a compiled language that is designed to be compiled into C++ code. It is designed to be a general-purpose language that can be used for anything yet is leveraging the power of C++ to make it easier to make API calls and create simple programs with NICE interfaces.*

Our goal is to create a truly unique Cross(X) platform language that can be used to create anything from a simple task manager to a full-blown game engine.

It is a high-level scripting language, that is attempting to be a true programming language.
Not optimized for compilation speed yet for ease of use and readability.  It is considered a Mark-up Language with advanced features that allow it to be leveraged as a programming language.

Although we are not focusing on speed, we are focusing on the ability to create *fast* programs that can be used on any platform.  In the future, we plan on implementing a JIT compiler to make it even faster, as well as Garbage Collection, and a Memory Management System.

XPL uses the [K&R](https://en.wikipedia.org/wiki/Indentation_style#K&R_style), [Style indentation](https://en.wikipedia.org/wiki/Indentation_style).

When following K&R, each function has its opening brace at the next line on the same indentation level as its header, the statements within the braces are indented, and the closing brace at the end is on the same indentation level as the header of the function at a line of its own. 

We use [ ] instead of { } to make it easier to read and write. As we believe { } should be used for JSON and other data structures.

The same applies to the IF, GRAB : FOR, and LOOP : WHILE statements.

````
    IF (condition)[
        Logic();
    ]
````