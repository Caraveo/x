
# Define a Variable TYPE

A variable should be defined with a type.
Generally, you can define and set a variable by using the following syntax:

````
<TYPE> <NAME>: <VALUE>
````
TYPE is the type of variable you are defining. NAME is the name of the variable. VALUE is what you want the variable to be set to.
  
This can be any of the following:

---

# STRING

Define a String Variable
````
STRING Welcome: "Hello World!"
````


---

# INDEX

Array/Dictionary/LIST type.  Can be used as an index.
````
INDEX Greetings: ["Hello", "Hey!", "Hi!"]
````

---

# FLOAT

Extended Float High Precision - Memory intensive
````
FLOAT Float: 12.0
````

---

# INTEGER

Define and Assign an integer.
````
INTEGER Int: 10
````

---

# BOOL

Bool Check with Safe Check.
````
BOOL Check: TRUE/FALSE/EXIST
````

---

# OBJECT

JSON Object-like based Indexing System
````
OBJECT Obj: { "Key": "Value" }
````

---

Required: Types should be ALL-Caps and should be defined before the variable name. The variable should be defined in Camel-Case: Meaning first letter capitalized and the rest lowercase, while spaces should NOT be used when defining variable names.
