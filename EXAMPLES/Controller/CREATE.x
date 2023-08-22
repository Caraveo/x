CREATE X[
    STRING Welcome: Hello + ' World!'
    INDEX Cats:["Pixie!", "Diva", "Chance"]
    FLOAT Value: 12.0
    INTEGER Int: 0
    BOOL Check: EXIST
]

NEW X2 X() #Instantiate

X2.Welcome # Returns string "Hello World!" Again
X2.Cats[0] # Returns string "Pixie!"
X2.Value # Returns 12.0
X2.Int # Returns 0
X2.Check # Returns !NULL