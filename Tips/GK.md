# () and {}
In C++, the statement MyTemplate<int> obj1(); can be easily misinterpreted as a function declaration instead of an object declaration. This is known as the most vexing parse or the most vexing syntax.

To avoid this confusion, you can add an additional pair of parentheses after the object name. Here's an example:

cpp
Copy code
MyTemplate<int> obj1{};
By using {} instead of (), you explicitly invoke the default constructor and create an object of MyTemplate<int>.

Alternatively, you can also remove the empty parentheses altogether:

cpp
Copy code
MyTemplate<int> obj1;
This will also invoke the default constructor and create an object of MyTemplate<int>.

Remember, if you use () after an object name, it will be treated as a function declaration instead of an object declaration.

#