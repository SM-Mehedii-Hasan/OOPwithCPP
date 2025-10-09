🔹 What is Polymorphism?
Polymorphism means "many forms".
It allows one interface (function or operator) to act differently based on the object type that is using it.
In C++, polymorphism allows you to perform a single action in different ways — for example,
calling the same function name but performing different tasks depending on the object.
🔸 Types of Polymorphism in C++
C++ supports two main types of polymorphism:
| Type                                      | When it happens          | Achieved By                                |
| ----------------------------------------- | ------------------------ | ------------------------------------------ |
| **1. Compile-time (Static) Polymorphism** | During compilation       | Function Overloading, Operator Overloading |
| **2. Run-time (Dynamic) Polymorphism**    | During program execution | Virtual Functions (Function Overriding)    |

______________________________________________________________________________________________________________________________________________________________________

| Type                                      | Description                                                                | Example                                    |
| ----------------------------------------- | -------------------------------------------------------------------------- | ------------------------------------------ |
| **1. Compile-time (Static) Polymorphism** | The function call is resolved at **compile time**.                         | Function Overloading, Operator Overloading |
| **2. Run-time (Dynamic) Polymorphism**    | The function call is resolved at **run time** using **virtual functions**. | Virtual Function (Method Overriding)       |



Compile-Time Polymorphism in C++ (also known as Static Polymorphism)
🧩 Definition:
Compile-time polymorphism occurs when the function call is resolved at compile time.
That means the compiler knows which function to call during compilation — before the program runs.
✅ Ways to Achieve Compile-Time Polymorphism:
There are two main ways to implement it in C++:
Function Overloading
Operator Overloading
⚡ Why It's Called Compile-Time Polymorphism:
Because:
The function or operator to be invoked is decided by the compiler.
There’s no need for runtime binding (like in virtual functions).



🔹 Runtime Polymorphism in C++ (also known as Dynamic Polymorphism)
🧩 Definition:
Runtime polymorphism occurs when the function call is resolved at runtime, not during compilation.
This allows one interface (like a base class pointer or reference) to represent different types of objects.
✅ Achieved By:
👉 Function Overriding using the virtual keyword.

| Feature      | Compile-time Polymorphism       | Runtime Polymorphism     |
| ------------ | ------------------------------- | ------------------------ |
| Binding Time | Compile Time                    | Run Time                 |
| Achieved By  | Function & Operator Overloading | Function Overriding      |
| Performance  | Faster                          | Slightly Slower          |
| Keyword Used | —                               | `virtual` keyword        |
| Example      | `add(int, int)`, `operator+()`  | `virtual void display()` |
