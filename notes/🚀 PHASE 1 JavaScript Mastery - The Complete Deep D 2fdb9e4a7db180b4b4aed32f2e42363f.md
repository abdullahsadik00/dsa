# 🚀 PHASE 1: JavaScript Mastery - The Complete Deep Dive

## 📋 Phase 1 Overview

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         PHASE 1: JAVASCRIPT CORE                            │
│                         Duration: 4-6 Weeks                                 │
│                         Goal: Master JavaScript from Ground Up              │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  Week 1-2: Execution Context, Hoisting, Scope, Closures, this               │
│  Week 3-4: Prototypes, Event Loop, Promises, Async/Await                    │
│  Week 5-6: Advanced Patterns, Array Methods, Error Handling                 │
│                                                                             │
│  Each Topic Contains:                                                       │
│  ├── 📚 Theory (Deep Conceptual Understanding)                              │
│  ├── 💻 Practical (Code Examples & Implementations)                         │
│  ├── 🌍 Real-Life Scenarios (Interview & Production Cases)                  │
│  └── 📝 Practice Questions (Easy → Medium → Hard)                           │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘

```

---

# 📘 MODULE 1: Execution Context & Call Stack

## 📚 THEORY

### What is Execution Context?

An **Execution Context** is an abstract concept that holds information about the environment within which the current code is being executed. Think of it as a "container" or "wrapper" that stores variables, functions, and the scope chain.

```markdown
┌────────────────────────────────────────────────────────────────────────────┐
│                         EXECUTION CONTEXT                                  │
├────────────────────────────────────────────────────────────────────────────┤
│                                                                            │
│  ┌─────────────────────────────────────────────────────────────────────┐   │
│  │                    MEMORY COMPONENT                                 │   │
│  │                    (Variable Environment)                           │   │
│  │                                                                     │   │
│  │    ┌──────────────────┬────────────────────────────────┐            │   │
│  │    │    Variable      │           Value                │            │   │
│  │    ├──────────────────┼────────────────────────────────┤            │   │
│  │    │    a             │           undefined → 10       │            │   │
│  │    │    b             │           undefined → 20       │            │   │
│  │    │    sum           │           <function>           │            │   │
│  │    └──────────────────┴────────────────────────────────┘            │   │
│  └─────────────────────────────────────────────────────────────────────┘   │
│                                                                            │
│  ┌─────────────────────────────────────────────────────────────────────┐   │
│  │                    CODE COMPONENT                                   │   │
│  │                    (Thread of Execution)                            │   │
│  │                                                                     │   │
│  │    Line 1: var a = 10;          ← Currently Executing               │   │
│  │    Line 2: var b = 20;                                              │   │
│  │    Line 3: function sum() {...}                                     │   │
│  │    Line 4: sum();                                                   │   │
│  │                                                                     │   │
│  └─────────────────────────────────────────────────────────────────────┘   │
│                                                                            │
└────────────────────────────────────────────────────────────────────────────┘

```

### Types of Execution Context

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                    TYPES OF EXECUTION CONTEXT                               │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  1. GLOBAL EXECUTION CONTEXT (GEC)                                          │
│     ├── Created when JavaScript file first runs                             │
│     ├── Only ONE GEC per program                                            │
│     ├── Creates: Global Object (window in browser, global in Node)          │
│     └── Creates: 'this' binding (points to global object)                   │
│                                                                             │
│  2. FUNCTION EXECUTION CONTEXT (FEC)                                        │
│     ├── Created EACH TIME a function is invoked                             │
│     ├── Can have MULTIPLE FECs                                              │
│     ├── Has access to arguments object                                      │
│     └── Creates its own 'this' binding                                      │
│                                                                             │
│  3. EVAL EXECUTION CONTEXT                                                  │
│     ├── Created when code runs inside eval()                                │
│     └── (Rarely used, avoid in production)                                  │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Phases of Execution Context

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                    TWO PHASES OF EXECUTION                                  │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  PHASE 1: CREATION PHASE (Memory Allocation)                                │
│  ════════════════════════════════════════════                               │
│  │                                                                          │
│  ├── JavaScript engine goes through code line by line                       │
│  ├── Allocates memory for ALL variables and functions                       │
│  ├── Variables (var) → initialized to 'undefined'                           │
│  ├── Variables (let/const) → remain uninitialized (TDZ)                     │
│  └── Functions → entire function code is stored                             │
│                                                                             │
│  PHASE 2: EXECUTION PHASE (Code Execution)                                  │
│  ════════════════════════════════════════════                               │
│  │                                                                          │
│  ├── JavaScript executes code line by line                                  │
│  ├── Variables get their actual values assigned                             │
│  ├── Function calls create new Execution Contexts                           │
│  └── Expressions are evaluated                                              │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### The Call Stack

```jsx
┌────────────────────────────────────────────────────────────────────────────┐
│                         CALL STACK                                         │
│                    (Execution Context Stack)                               │
├────────────────────────────────────────────────────────────────────────────┤
│                                                                            │
│  Definition: A LIFO (Last In, First Out) data structure that               │
│              keeps track of the order of execution contexts                │
│                                                                            │
│  ┌─────────────────────────────────────────────────────────────────────┐   │
│  │                                                                     │   │
│  │         ┌───────────────────┐                                       │   │
│  │         │ innerFunction()   │  ← TOP (Currently Executing)          │   │
│  │         ├───────────────────┤                                       │   │
│  │         │ outerFunction()   │                                       │   │
│  │         ├───────────────────┤                                       │   │
│  │         │ Global Execution  │  ← BOTTOM (Always Present)            │   │
│  │         │     Context       │                                       │   │
│  │         └───────────────────┘                                       │   │
│  │                                                                     │   │
│  │  PUSH: When function is called, its EC is pushed                    │   │
│  │  POP:  When function returns, its EC is popped                      │   │
│  │                                                                     │   │
│  └─────────────────────────────────────────────────────────────────────┘   │
│                                                                            │
└────────────────────────────────────────────────────────────────────────────┘
```

## 💻 PRACTICAL EXAMPLES

### Example 1: Step-by-Step Execution

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Understanding Execution Context Step by Step
// ═══════════════════════════════════════════════════════════════

var name= "Tiasha";
var age= 25;

function greet() {
    var greeting= "Hello";
    console.log(greeting+ " " + name);
}

function introduce() {
    var intro= "I am";
    greet();
    console.log(intro+ " " + age+ " years old");
}

introduce();

// ═══════════════════════════════════════════════════════════════
// STEP-BY-STEP BREAKDOWN
// ═══════════════════════════════════════════════════════════════

/*
STEP 1: Global Execution Context Created
═════════════════════════════════════════

┌─────────────────────────────────────────────────────────────┐
│ CREATION PHASE - Global EC                                  │
├─────────────────────────────────────────────────────────────┤
│ Memory:                                                     │
│   name: undefined                                           │
│   age: undefined                                            │
│   greet: function greet() {...}                             │
│   introduce: function introduce() {...}                     │
├─────────────────────────────────────────────────────────────┤
│ Call Stack: [Global EC]                                     │
└─────────────────────────────────────────────────────────────┘

STEP 2: Execution Phase Begins
══════════════════════════════

Line 1: name = "Tiasha"     → name is now "Tiasha"
Line 2: age = 25            → age is now 25
Line 3-5: greet function    → Already stored (skipped)
Line 7-11: introduce        → Already stored (skipped)
Line 13: introduce()        → NEW EXECUTION CONTEXT!

STEP 3: introduce() Execution Context
═════════════════════════════════════

┌─────────────────────────────────────────────────────────────┐
│ CREATION PHASE - introduce EC                               │
├─────────────────────────────────────────────────────────────┤
│ Memory:                                                     │
│   intro: undefined                                          │
│   arguments: {}                                             │
├─────────────────────────────────────────────────────────────┤
│ Call Stack: [Global EC, introduce EC]                       │
└─────────────────────────────────────────────────────────────┘

STEP 4: Inside introduce() - Execution
══════════════════════════════════════

Line 8: intro = "I am"      → intro is now "I am"
Line 9: greet()             → NEW EXECUTION CONTEXT!

STEP 5: greet() Execution Context
═════════════════════════════════

┌─────────────────────────────────────────────────────────────┐
│ CREATION PHASE - greet EC                                   │
├─────────────────────────────────────────────────────────────┤
│ Memory:                                                     │
│   greeting: undefined                                       │
│   arguments: {}                                             │
├─────────────────────────────────────────────────────────────┤
│ Call Stack: [Global EC, introduce EC, greet EC]             │
└─────────────────────────────────────────────────────────────┘

STEP 6: Inside greet() - Execution
══════════════════════════════════

Line 4: greeting = "Hello"  → greeting is now "Hello"
Line 5: console.log(...)    → Output: "Hello Tiasha"
        (name found in Global EC via scope chain)

STEP 7: greet() Returns
═══════════════════════

┌─────────────────────────────────────────────────────────────┐
│ greet EC is POPPED from Call Stack                          │
├─────────────────────────────────────────────────────────────┤
│ Call Stack: [Global EC, introduce EC]                       │
└─────────────────────────────────────────────────────────────┘

STEP 8: Back to introduce()
═══════════════════════════

Line 10: console.log(...)   → Output: "I am 25 years old"

STEP 9: introduce() Returns
═══════════════════════════

┌─────────────────────────────────────────────────────────────┐
│ introduce EC is POPPED from Call Stack                      │
├─────────────────────────────────────────────────────────────┤
│ Call Stack: [Global EC]                                     │
└─────────────────────────────────────────────────────────────┘

STEP 10: Program Ends
════════════════════

Global EC is popped. Call Stack is empty.

*/
```

### Example 2: Stack Overflow Demonstration

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Stack Overflow - What happens when Call Stack overflows
// ═══════════════════════════════════════════════════════════════

function recursiveFunction() {
    console.log("Function called");
    recursiveFunction();// Calls itself infinitely
}

// recursiveFunction(); // Uncomment to see: "RangeError: Maximum call stack size exceeded"

/*
VISUAL REPRESENTATION:

Call Stack keeps growing:
┌───────────────────┐
│ recursiveFunction │  ← 10,000th call
├───────────────────┤
│ recursiveFunction │  ← 9,999th call
├───────────────────┤
│       ...         │
├───────────────────┤
│ recursiveFunction │  ← 2nd call
├───────────────────┤
│ recursiveFunction │  ← 1st call
├───────────────────┤
│    Global EC      │
└───────────────────┘

Eventually → STACK OVERFLOW ERROR!
The browser has a limit (usually ~10,000-20,000 frames)
*/

// PROPER RECURSION WITH BASE CASE:
function countdown(n) {
    if (n<= 0) {// BASE CASE - stops recursion
        console.log("Done!");
        return;
    }
    console.log(n);
    countdown(n- 1);
}

countdown(5);
// Output: 5, 4, 3, 2, 1, Done!

/*
Call Stack visualization for countdown(3):

Step 1: countdown(3) pushed
        [Global, countdown(3)]

Step 2: countdown(2) pushed
        [Global, countdown(3), countdown(2)]

Step 3: countdown(1) pushed
        [Global, countdown(3), countdown(2), countdown(1)]

Step 4: countdown(0) pushed
        [Global, countdown(3), countdown(2), countdown(1), countdown(0)]
        Base case hit! Returns.

Step 5: countdown(0) popped
        [Global, countdown(3), countdown(2), countdown(1)]

Step 6: countdown(1) popped
        [Global, countdown(3), countdown(2)]

Step 7: countdown(2) popped
        [Global, countdown(3)]

Step 8: countdown(3) popped
        [Global]
*/
```

### Example 3: Execution Context with Return Values

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: How return values work with Execution Context
// ═══════════════════════════════════════════════════════════════

function multiply(a,b) {
    var result= a* b;
    return result;
}

function square(n) {
    var squared= multiply(n, n);
    return squared;
}

function cube(n) {
    var cubed= square(n)* n;
    return cubed;
}

var answer= cube(3);
console.log(answer);// 27

/*
DETAILED TRACE:

1. Global EC Created:
   Memory: { multiply: fn, square: fn, cube: fn, answer: undefined }

2. cube(3) called:
   - New EC for cube
   - n = 3
   - cubed = square(3) * 3  ← Need to evaluate square(3) first

3. square(3) called:
   - New EC for square
   - n = 3
   - squared = multiply(3, 3)  ← Need to evaluate multiply(3, 3) first

4. multiply(3, 3) called:
   - New EC for multiply
   - a = 3, b = 3
   - result = 9
   - RETURN 9  ← multiply EC popped

5. Back in square:
   - squared = 9
   - RETURN 9  ← square EC popped

6. Back in cube:
   - cubed = 9 * 3 = 27
   - RETURN 27  ← cube EC popped

7. Back in Global:
   - answer = 27

Final Output: 27
*/
```

## 🌍 REAL-LIFE SCENARIOS

### Scenario 1: Debugging in Production

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Debugging a Stack Trace in Production
// ═══════════════════════════════════════════════════════════════

// In production, you receive this error stack trace:
/*
Error: User not found
    at getUserDetails (api/users.js:45:11)
    at processOrder (api/orders.js:23:15)
    at checkout (api/cart.js:67:9)
    at handlePayment (api/payment.js:12:5)
    at Object.<anonymous> (server.js:89:1)
*/

// This IS the Call Stack! Reading bottom to top:
// 1. server.js called handlePayment
// 2. handlePayment called checkout
// 3. checkout called processOrder
// 4. processOrder called getUserDetails
// 5. getUserDetails threw an error

// SIMULATING THIS SCENARIO:
function getUserDetails(userId) {
    // Simulating database call
    const users = {1:"Alice",2:"Bob" };
    if (!users[userId]) {
        throw new Error(`User ${userId} not found`);
    }
    return users[userId];
}

function processOrder(userId,orderId) {
    const user = getUserDetails(userId);// Error happens here
    return { user, orderId, status:"processed" };
}

function checkout(userId,items) {
    const orderId = Date.now();
    return processOrder(userId, orderId);
}

function handlePayment(userId,items,paymentMethod) {
    console.log("Processing payment...");
    const result = checkout(userId, items);
    return {...result, paymentMethod };
}

// This will throw an error with full stack trace
try {
    handlePayment(999, ["item1","item2"],"credit_card");
}catch (error) {
    console.error("Error:", error.message);
    console.error("Stack:", error.stack);
}

// Understanding the stack trace helps you:
// 1. Find the exact line where error occurred
// 2. Understand the sequence of function calls
// 3. Debug the issue efficiently
```

### Scenario 2: Interview Question - What's Wrong Here?

```jsx
// ═══════════════════════════════════════════════════════════════
// INTERVIEW SCENARIO: PhonePe/Mercor Style Question
// ═══════════════════════════════════════════════════════════════

// Interviewer: "What will this code output and why?"

console.log("Start");

function first() {
    console.log("First");
    second();
    console.log("First End");
}

function second() {
    console.log("Second");
    third();
    console.log("Second End");
}

function third() {
    console.log("Third");
}

first();

console.log("End");

/*
YOUR ANSWER SHOULD BE:

Output:
Start
First
Second
Third
Second End
First End
End

EXPLANATION (What interviewer wants to hear):

1. "Start" logs first - it's in global execution
2. first() is called, creating new execution context
3. "First" logs
4. second() is called, creating another execution context
   (first's EC is NOT popped yet, it's waiting)
5. "Second" logs
6. third() is called, creating another execution context
7. "Third" logs
8. third() returns, its EC is popped
9. Back in second(), "Second End" logs
10. second() returns, its EC is popped
11. Back in first(), "First End" logs
12. first() returns, its EC is popped
13. "End" logs in global execution

This demonstrates SYNCHRONOUS execution and LIFO nature of call stack.
*/
```

### Scenario 3: Memory Leak Detection

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Understanding Memory in Execution Context
// ═══════════════════════════════════════════════════════════════

// PROBLEM: Memory Leak in Event Handlers
function setupButtons() {
    const hugeData = new Array(1000000).fill("x");// Large data

    document.getElementById("btn").addEventListener("click",function() {
        // This closure keeps reference to hugeData!
        console.log(hugeData.length);
    });
}

// Even after setupButtons() finishes, hugeData stays in memory
// because the event listener's execution context references it!

// SOLUTION: Clean up references
function setupButtonsFixed() {
    let hugeData= new Array(1000000).fill("x");
    const length = hugeData.length;// Extract what you need

    hugeData= null;// Allow garbage collection

    document.getElementById("btn").addEventListener("click",function() {
        console.log(length);// Only keeps the primitive value
    });
}

// KEY INSIGHT:
// Execution contexts hold references to variables
// These references prevent garbage collection
// Understanding this helps prevent memory leaks
```

## 📝 PRACTICE QUESTIONS

### 🟢 EASY QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// EASY Q1: Predict the output
// ═══════════════════════════════════════════════════════════════

var x= 10;

function outer() {
    var y= 20;
    console.log(x+ y);
}

outer();
console.log(x);
// console.log(y); // What happens if uncommented?

/*
YOUR ANSWER:
_______________

EXPECTED OUTPUT:
30
10
ReferenceError: y is not defined (if uncommented)

EXPLANATION:
- outer() has access to x from global scope (scope chain)
- y is local to outer(), not accessible outside
*/

// ═══════════════════════════════════════════════════════════════
// EASY Q2: Order of execution
// ═══════════════════════════════════════════════════════════════

function a() {
    console.log("A");
}

function b() {
    console.log("B");
}

function c() {
    console.log("C");
}

a();
b();
c();

/*
YOUR ANSWER:
_______________

EXPECTED OUTPUT:
A
B
C

EXPLANATION:
- Each function creates its own EC
- They execute synchronously, one after another
- Call Stack: [Global] → [Global, a] → [Global] → [Global, b] → [Global] → [Global, c] → [Global]
*/

// ═══════════════════════════════════════════════════════════════
// EASY Q3: Return value tracing
// ═══════════════════════════════════════════════════════════════

function add(a,b) {
    return a+ b;
}

function double(x) {
    return add(x, x);
}

var result= double(5);
console.log(result);

/*
YOUR ANSWER:
_______________

EXPECTED OUTPUT:
10

TRACE:
1. double(5) called → x = 5
2. add(5, 5) called → a = 5, b = 5
3. add returns 10
4. double returns 10
5. result = 10
*/
```

### 🟡 MEDIUM QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// MEDIUM Q1: Nested function calls with side effects
// ═══════════════════════════════════════════════════════════════

var counter= 0;

function increment() {
    counter++;
    console.log("Increment:", counter);
}

function process() {
    console.log("Process Start");
    increment();
    console.log("Process Middle");
    increment();
    console.log("Process End");
}

function main() {
    console.log("Main Start");
    process();
    console.log("Main End");
    increment();
}

main();
console.log("Final Counter:", counter);

/*
YOUR ANSWER (write the complete output):
_______________
_______________
_______________
_______________
_______________
_______________
_______________
_______________
_______________

EXPECTED OUTPUT:
Main Start
Process Start
Increment: 1
Process Middle
Increment: 2
Process End
Main End
Increment: 3
Final Counter: 3
*/

// ═══════════════════════════════════════════════════════════════
// MEDIUM Q2: Understanding this in different contexts
// ═══════════════════════════════════════════════════════════════

var name= "Global";

function showName() {
    console.log(this.name);
}

var obj= {
    name:"Object",
    show: showName
};

showName();// Output 1: ?
obj.show();// Output 2: ?
showName.call(obj);// Output 3: ?

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________
Output 3: _______________

EXPECTED:
Output 1: Global (or undefined in strict mode)
Output 2: Object
Output 3: Object

EXPLANATION:
- showName() - 'this' is global/window
- obj.show() - 'this' is obj (method invocation)
- showName.call(obj) - 'this' is explicitly set to obj
*/

// ═══════════════════════════════════════════════════════════════
// MEDIUM Q3: Execution Context with conditionals
// ═══════════════════════════════════════════════════════════════

var value= 1;

function check() {
    console.log("Value:", value);

    if (value=== 1) {
        var value= 2;// What happens here?
        console.log("Inside if:", value);
    }

    console.log("After if:", value);
}

check();

/*
YOUR ANSWER:
_______________
_______________
_______________

EXPECTED OUTPUT:
Value: undefined
Inside if: 2
After if: 2

EXPLANATION:
- var is function-scoped, hoisted to top of check()
- During creation phase, local 'value' is undefined
- This local 'value' shadows the global 'value'
- First log shows undefined (not 1!)
- After assignment, value becomes 2
*/
```

### 🔴 HARD QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// HARD Q1: Complex execution order (PhonePe Interview Style)
// ═══════════════════════════════════════════════════════════════

console.log("1");

function outer() {
    console.log("2");
    inner();
    console.log("3");

    function inner() {
        console.log("4");
        innermost();
        console.log("5");

        function innermost() {
            console.log("6");
        }
    }
}

console.log("7");
outer();
console.log("8");

/*
YOUR ANSWER (write all outputs in order):
_______________

EXPECTED OUTPUT:
1
7
2
4
6
5
3
8

TRACE THE CALL STACK:
1. Global: log "1"
2. Global: log "7"
3. outer() called
   - Stack: [Global, outer]
   - log "2"
   - inner() called
     - Stack: [Global, outer, inner]
     - log "4"
     - innermost() called
       - Stack: [Global, outer, inner, innermost]
       - log "6"
       - innermost returns
     - Stack: [Global, outer, inner]
     - log "5"
     - inner returns
   - Stack: [Global, outer]
   - log "3"
   - outer returns
4. Stack: [Global]
5. log "8"
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q2: Recursion with execution context tracking
// ═══════════════════════════════════════════════════════════════

function factorial(n) {
    console.log(`Entering factorial(${n})`);

    if (n<= 1) {
        console.log(`Base case reached for factorial(${n}), returning 1`);
        return 1;
    }

    var result= n* factorial(n- 1);
    console.log(`factorial(${n}) = ${n} * factorial(${n-1}) = ${result}`);
    return result;
}

console.log("Final result:",factorial(4));

/*
YOUR ANSWER (write complete output):
_______________
_______________
_______________
_______________
_______________
_______________
_______________
_______________
_______________

EXPECTED OUTPUT:
Entering factorial(4)
Entering factorial(3)
Entering factorial(2)
Entering factorial(1)
Base case reached for factorial(1), returning 1
factorial(2) = 2 * factorial(1) = 2
factorial(3) = 3 * factorial(2) = 6
factorial(4) = 4 * factorial(3) = 24
Final result: 24

CALL STACK AT DEEPEST POINT:
[Global, factorial(4), factorial(3), factorial(2), factorial(1)]
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q3: Execution context with closures and async
// ═══════════════════════════════════════════════════════════════

function createCounter() {
    var count= 0;

    console.log("Counter created");

    return {
        increment:function() {
            count++;
            console.log("Count:", count);
            return count;
        },
        getCount:function() {
            return count;
        }
    };
}

console.log("Start");

var counter1= createCounter();
var counter2= createCounter();

console.log("Counters created");

counter1.increment();
counter1.increment();
counter2.increment();

console.log("Counter1:", counter1.getCount());
console.log("Counter2:", counter2.getCount());

/*
YOUR ANSWER:
_______________
_______________
_______________
_______________
_______________
_______________
_______________
_______________
_______________

EXPECTED OUTPUT:
Start
Counter created
Counter created
Counters created
Count: 1
Count: 2
Count: 1
Counter1: 2
Counter2: 1

EXPLANATION:
- Each createCounter() call creates NEW execution context
- Each has its OWN 'count' variable in its closure
- counter1 and counter2 have SEPARATE count variables
- They don't share state!
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q4: Interview Question - Find the bug
// ═══════════════════════════════════════════════════════════════

// This code has a bug. Find it and explain using execution context.

for (var i= 1; i<= 3; i++) {
    setTimeout(function() {
        console.log("Timer " + i);
    }, i* 1000);
}

/*
QUESTION:
What's the output? What's the bug? How to fix it?

YOUR ANSWER:
Expected by developer: Timer 1, Timer 2, Timer 3
Actual output: _______________

Bug explanation:
_______________

Fix:
_______________

EXPECTED ANSWER:
Actual output: Timer 4, Timer 4, Timer 4

Bug explanation:
- var is function-scoped, not block-scoped
- There's only ONE 'i' in the global execution context
- By the time setTimeout callbacks run, the loop has finished
- At that point, i = 4 (loop exit condition)
- All callbacks reference the SAME 'i'

Fix 1 - Use let:
for (let i = 1; i <= 3; i++) {
    setTimeout(function() {
        console.log("Timer " + i);
    }, i * 1000);
}

Fix 2 - Use closure (IIFE):
for (var i = 1; i <= 3; i++) {
    (function(j) {
        setTimeout(function() {
            console.log("Timer " + j);
        }, j * 1000);
    })(i);
}
*/
```

---

# 📘 MODULE 2: Hoisting

## 📚 THEORY

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                              HOISTING                                       │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  DEFINITION:                                                                │
│  Hoisting is JavaScript's default behavior of moving declarations           │
│  to the top of their scope during the CREATION PHASE of execution           │
│  context.                                                                   │
│                                                                             │
│  IMPORTANT: Only DECLARATIONS are hoisted, NOT initializations!             │
│                                                                             │
│  ┌──────────────────────────────────────────────────────────────────────┐   │
│  │              WHAT GETS HOISTED AND HOW                               │   │
│  ├──────────────────────────────────────────────────────────────────────┤   │
│  │                                                                      │   │
│  │  var declarations     → Hoisted with value 'undefined'               │   │
│  │                                                                      │   │
│  │  function declarations → Hoisted with FULL function body             │   │
│  │                                                                      │   │
│  │  let/const declarations → Hoisted but NOT initialized (TDZ)          │   │
│  │                                                                      │   │
│  │  function expressions → Only variable name hoisted (as undefined)    │   │
│  │                                                                      │   │
│  │  Arrow functions      → Only variable name hoisted (as undefined)    │   │
│  │                                                                      │   │
│  │  class declarations   → Hoisted but NOT initialized (TDZ)            │   │
│  │                                                                      │   │
│  └──────────────────────────────────────────────────────────────────────┘   │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Temporal Dead Zone (TDZ)

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                        TEMPORAL DEAD ZONE (TDZ)                             │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  The TDZ is the period between entering a scope and the variable            │
│  being declared/initialized.                                                │
│                                                                             │
│  ┌─────────────────────────────────────────────────────────────────────┐    │
│  │  {                                                                  │    │
│  │      // TDZ for 'x' starts here ─────────────────────────┐          │    │
│  │      console.log(x); // ReferenceError!                  │          │    │
│  │                                                          │ TDZ      │    │
│  │      // Still in TDZ                                     │          │    │
│  │      let x = 10; // TDZ ends here ───────────────────────┘          │    │
│  │                                                                     │    │
│  │      console.log(x); // 10 - Works fine!                            │    │
│  │  }                                                                  │    │
│  └─────────────────────────────────────────────────────────────────────┘    │
│                                                                             │
│  WHY TDZ EXISTS:                                                            │
│  - Helps catch programming errors                                           │
│  - Makes code more predictable                                              │
│  - Prevents accessing variables before they're ready                        │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### var vs let vs const Hoisting Comparison

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                    HOISTING COMPARISON TABLE                                │
├──────────────┬───────────────────────┬──────────────────────────────────────┤
│   Feature    │        var            │         let / const                  │
├──────────────┼───────────────────────┼──────────────────────────────────────┤
│   Hoisted?   │        Yes            │         Yes (but differently)        │
├──────────────┼───────────────────────┼──────────────────────────────────────┤
│  Initialized │   undefined           │   Not initialized (TDZ)              │
├──────────────┼───────────────────────┼──────────────────────────────────────┤
│  Access      │   Returns undefined   │   ReferenceError                     │
│  before      │   (silently fails)    │   (explicit error)                   │
│  declaration │                       │                                      │
├──────────────┼───────────────────────┼──────────────────────────────────────┤
│    Scope     │   Function-scoped     │   Block-scoped                       │
├──────────────┼───────────────────────┼──────────────────────────────────────┤
│  Redeclare   │   Allowed             │   Not allowed in same scope          │
├──────────────┼───────────────────────┼──────────────────────────────────────┤
│  Window      │   Attached            │   Not attached                       │
│  property    │   (in global scope)   │                                      │
└──────────────┴───────────────────────┴──────────────────────────────────────┘
```

## 💻 PRACTICAL EXAMPLES

### Example 1: var Hoisting

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: How var hoisting works
// ═══════════════════════════════════════════════════════════════

// WHAT YOU WRITE:
console.log(name);// undefined
var name= "Tiasha";
console.log(name);// "Tiasha"

// WHAT JAVASCRIPT SEES (after hoisting):
/*
var name;           // Declaration hoisted
console.log(name);  // undefined (declared but not initialized)
name = "Tiasha";    // Initialization stays in place
console.log(name);  // "Tiasha"
*/

// ═══════════════════════════════════════════════════════════════
// MORE COMPLEX EXAMPLE
// ═══════════════════════════════════════════════════════════════

console.log(a);// undefined
console.log(b);// undefined
console.log(c);// undefined

var a= 1;
var b= 2;
var c= a+ b;

console.log(a);// 1
console.log(b);// 2
console.log(c);// 3

// HOISTED VERSION:
/*
var a;
var b;
var c;

console.log(a);  // undefined
console.log(b);  // undefined
console.log(c);  // undefined

a = 1;
b = 2;
c = a + b;

console.log(a);  // 1
console.log(b);  // 2
console.log(c);  // 3
*/

```

### Example 2: Function Hoisting

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Function Declaration Hoisting
// ═══════════════════════════════════════════════════════════════

// This works! Function declarations are fully hoisted
sayHello();// "Hello!"

function sayHello() {
    console.log("Hello!");
}

// WHAT JAVASCRIPT SEES:
/*
function sayHello() {    // Entire function is hoisted
    console.log("Hello!");
}

sayHello();  // Now we can call it
*/

// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Function Expression Hoisting
// ═══════════════════════════════════════════════════════════════

// This FAILS!
// sayGoodbye(); // TypeError: sayGoodbye is not a function

var sayGoodbye = function() {
    console.log("Goodbye!");
};

sayGoodbye();// "Goodbye!" - Works after definition

// WHAT JAVASCRIPT SEES:
/*
var sayGoodbye;  // Only the variable is hoisted, not the function!

// sayGoodbye(); // At this point, sayGoodbye is undefined!

sayGoodbye = function() {
    console.log("Goodbye!");
};

sayGoodbye();  // Now it works
*/

// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Arrow Function Hoisting
// ═══════════════════════════════════════════════════════════════

// greet(); // TypeError: greet is not a function

const greet = ()=> {
    console.log("Hi there!");
};

greet();// "Hi there!"

// Arrow functions behave like function expressions
// The variable is hoisted, but it's in the TDZ until initialized

```

### Example 3: let and const with TDZ

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Temporal Dead Zone in action
// ═══════════════════════════════════════════════════════════════

// ❌ This throws ReferenceError
// console.log(myLet); // ReferenceError: Cannot access 'myLet' before initialization

let myLet= "I am let";
console.log(myLet);// "I am let"

// ❌ Same with const
// console.log(myConst); // ReferenceError

const myConst = "I am const";
console.log(myConst);// "I am const"

// ═══════════════════════════════════════════════════════════════
// EXAMPLE: TDZ is temporal (time-based), not positional
// ═══════════════════════════════════════════════════════════════

function checkTDZ() {
    // TDZ for 'value' starts here

    const printValue = ()=> {
        console.log(value);// This is fine because function is called later
    };

    // Still in TDZ here

    let value= "Hello";// TDZ ends

    printValue();// "Hello" - Works because value is now initialized
}

checkTDZ();

// ═══════════════════════════════════════════════════════════════
// EXAMPLE: TDZ with typeof
// ═══════════════════════════════════════════════════════════════

// For undeclared variables, typeof returns "undefined"
console.log(typeof undeclaredVar);// "undefined" - No error!

// But for let/const in TDZ, it throws!
// console.log(typeof myVariable);  // ReferenceError!
let myVariable= "exists";
console.log(typeof myVariable);// "string"

```

### Example 4: Hoisting in Different Scopes

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Hoisting within function scope
// ═══════════════════════════════════════════════════════════════

var globalVar= "I'm global";

function testScope() {
    console.log(globalVar);// undefined (NOT "I'm global"!)

    var globalVar= "I'm local";// This shadows the global variable

    console.log(globalVar);// "I'm local"
}

testScope();
console.log(globalVar);// "I'm global" (unchanged)

// WHAT JAVASCRIPT SEES:
/*
var globalVar = "I'm global";

function testScope() {
    var globalVar;  // Local variable hoisted to top of function

    console.log(globalVar);  // undefined (accessing local, not global!)

    globalVar = "I'm local";

    console.log(globalVar);  // "I'm local"
}
*/

// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Block scope with let
// ═══════════════════════════════════════════════════════════════

let blockVar= "outer";

{
    // New block scope
    // console.log(blockVar);  // ReferenceError - TDZ!

    let blockVar= "inner";// Different variable, block-scoped
    console.log(blockVar);// "inner"
}

console.log(blockVar);// "outer" (outer variable unchanged)

```

## 🌍 REAL-LIFE SCENARIOS

### Scenario 1: Common Bug in Production

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Bug due to hoisting
// ═══════════════════════════════════════════════════════════════

// Developer writes this code expecting it to work:
function processUserData(user) {
    if (user.isAdmin) {
        var accessLevel= "admin";
        var permissions= getAllPermissions();
    }

    // Bug: Developer expects this to throw error if not admin
    // But it doesn't! accessLevel is undefined, not an error
    console.log("Access level:", accessLevel);// undefined for non-admin

    // This could cause security issues!
    if (accessLevel=== "admin") {
        // Grant admin access
    }
}

// CORRECT VERSION using let:
function processUserDataFixed(user) {
    if (user.isAdmin) {
        let accessLevel= "admin";
        let permissions= getAllPermissions();

        console.log("Access level:", accessLevel);
        // accessLevel is only accessible within this block
    }

    // console.log(accessLevel); // ReferenceError - Caught early!
}

```

### Scenario 2: Interview Code Review

```jsx
// ═══════════════════════════════════════════════════════════════
// INTERVIEW SCENARIO: "Review this code and find issues"
// ═══════════════════════════════════════════════════════════════

// Code to review:
function calculateTotal(items) {
    var total= 0;

    for (var i= 0; i< items.length; i++) {
        var itemPrice= items[i].price;
        var discount= getDiscount(items[i]);
        total+= itemPrice- discount;
    }

    // Bug 1: These variables are accessible here (var hoisting)
    console.log("Last item price:", itemPrice);// Accessible!
    console.log("Last index:", i);// Accessible!

    return total;
}

// ISSUES TO IDENTIFY:
/*
1. var creates function-scoped variables
   - itemPrice, discount, i are accessible outside the loop
   - This is usually unintended and can lead to bugs

2. If items is empty:
   - i = 0 (never incremented)
   - itemPrice = undefined (never assigned)
   - Could cause unexpected behavior

3. Better version:
*/

function calculateTotalFixed(items) {
    let total= 0;

    for (let i= 0; i< items.length; i++) {
        const itemPrice = items[i].price;
        const discount = getDiscount(items[i]);
        total+= itemPrice- discount;
    }

    // console.log(itemPrice); // ReferenceError - Good! Caught early
    // console.log(i);         // ReferenceError - Good! Caught early

    return total;
}

```

### Scenario 3: Module Pattern and Hoisting

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Using hoisting for clean code organization
// ═══════════════════════════════════════════════════════════════

// PUBLIC API AT THE TOP (thanks to hoisting)
const UserModule = {
    createUser,
    deleteUser,
    updateUser,
    getUser
};

// IMPLEMENTATION DETAILS BELOW
function createUser(data) {
    validateData(data);
    const user = formatUser(data);
    return saveToDatabase(user);
}

function deleteUser(id) {
    const user = getUser(id);
    if (user) {
        return removeFromDatabase(id);
    }
    throw new Error("User not found");
}

function updateUser(id,data) {
    validateData(data);
    return updateInDatabase(id, data);
}

function getUser(id) {
    return fetchFromDatabase(id);
}

// PRIVATE HELPER FUNCTIONS
function validateData(data) {
    if (!data.name|| !data.email) {
        throw new Error("Invalid data");
    }
}

function formatUser(data) {
    return {
        ...data,
        createdAt:new Date(),
        id:generateId()
    };
}

// This pattern works because function declarations are hoisted!
// You can organize code with public API at top, implementation below
```

## 📝 PRACTICE QUESTIONS

### 🟢 EASY QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// EASY Q1: Basic var hoisting
// ═══════════════════════════════════════════════════════════════

console.log(x);
var x= 5;
console.log(x);

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________

EXPECTED:
Output 1: undefined
Output 2: 5
*/

// ═══════════════════════════════════════════════════════════════
// EASY Q2: Function declaration hoisting
// ═══════════════════════════════════════════════════════════════

greet();

function greet() {
    console.log("Hello!");
}

/*
YOUR ANSWER:
Output: _______________

EXPECTED:
Output: Hello!
(Function declarations are fully hoisted)
*/

// ═══════════════════════════════════════════════════════════════
// EASY Q3: let vs var
// ═══════════════════════════════════════════════════════════════

console.log(a);// Line 1
var a= 10;

console.log(b);// Line 2
let b= 20;

/*
YOUR ANSWER:
Line 1 output: _______________
Line 2 output: _______________

EXPECTED:
Line 1: undefined
Line 2: ReferenceError: Cannot access 'b' before initialization
*/
```

### 🟡 MEDIUM QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// MEDIUM Q1: Function expression vs declaration
// ═══════════════════════════════════════════════════════════════

console.log(foo);
console.log(bar);

function foo() {
    return "foo";
}

var bar = function() {
    return "bar";
};

console.log(foo());
console.log(bar());

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________
Output 3: _______________
Output 4: _______________

EXPECTED:
Output 1: [Function: foo] (entire function)
Output 2: undefined (only var declaration hoisted)
Output 3: "foo"
Output 4: "bar"
*/

// ═══════════════════════════════════════════════════════════════
// MEDIUM Q2: Hoisting with same name
// ═══════════════════════════════════════════════════════════════

var myVar= "global";

function test() {
    console.log(myVar);// ?
    var myVar= "local";
    console.log(myVar);// ?
}

test();
console.log(myVar);// ?

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________
Output 3: _______________

EXPECTED:
Output 1: undefined (local myVar is hoisted, shadows global)
Output 2: "local"
Output 3: "global" (global unchanged)
*/

// ═══════════════════════════════════════════════════════════════
// MEDIUM Q3: Multiple declarations
// ═══════════════════════════════════════════════════════════════

function example() {
    console.log(a);
    console.log(b);
    console.log(c);

    var a= 1;
    let b= 2;
    const c = 3;

    console.log(a);
    console.log(b);
    console.log(c);
}

example();

/*
YOUR ANSWER:
What happens and why?
_______________

EXPECTED:
- First console.log(a) → undefined
- First console.log(b) → ReferenceError (TDZ)
The code stops at the ReferenceError before reaching other logs
*/

```

### 🔴 HARD QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// HARD Q1: Hoisting with conditionals
// ═══════════════════════════════════════════════════════════════

console.log(typeof foo);

if (true) {
    function foo() {
        return "inside if";
    }
}

console.log(typeof foo);
console.log(foo());

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________
Output 3: _______________

EXPECTED (behavior varies by engine, in most modern browsers):
Output 1: "undefined" (function inside block not hoisted to top)
Output 2: "function"
Output 3: "inside if"

Note: This behavior is complex and engine-dependent.
Best practice: Don't declare functions inside blocks.
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q2: Hoisting in IIFE
// ═══════════════════════════════════════════════════════════════

var result= (function() {
    console.log(a);
    console.log(foo());

    var a= 10;

    function foo() {
        return "foo called";
    }

    return a+ 20;
})();

console.log(result);

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________
Output 3: _______________

EXPECTED:
Output 1: undefined (var a is hoisted)
Output 2: "foo called" (function foo is hoisted)
Output 3: 30
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q3: Class hoisting
// ═══════════════════════════════════════════════════════════════

// const instance = new MyClass(); // What happens?

class MyClass {
    constructor() {
        this.name= "MyClass";
    }
}

const instance = new MyClass();
console.log(instance.name);

/*
YOUR ANSWER:
What happens if we uncomment the first line?
_______________

EXPECTED:
ReferenceError: Cannot access 'MyClass' before initialization

Classes are hoisted but remain in TDZ until evaluated.
This is intentional to catch errors early.
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q4: Complex hoisting scenario (Interview favorite!)
// ═══════════════════════════════════════════════════════════════

var a= 1;
function b() {
    a= 10;
    return;
    function a() {}
}
b();
console.log(a);

/*
YOUR ANSWER:
Output: _______________

EXPECTED:
Output: 1

EXPLANATION:
Inside function b():
1. function a() {} is hoisted to top of b()
2. This creates a LOCAL variable 'a' that shadows global 'a'
3. a = 10 modifies the LOCAL 'a', not the global one
4. The global 'a' remains 1

How JavaScript sees it:
function b() {
    function a() {}  // Local 'a' created
    a = 10;          // Modifies local 'a'
    return;
}
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q5: Parameter and variable hoisting
// ═══════════════════════════════════════════════════════════════

function test(a) {
    console.log(a);
    var a= 100;
    console.log(a);
}

test(10);

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________

EXPECTED:
Output 1: 10 (parameter value)
Output 2: 100

EXPLANATION:
- Parameter 'a' is like 'var a = 10' at the start
- var a = 100 is hoisted, but since 'a' already exists,
  it doesn't create a new variable
- First log uses parameter value (10)
- After assignment, a becomes 100
*/
```

---

# 📘 MODULE 3: Scope & Scope Chain

## 📚 THEORY

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                               SCOPE                                         │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  DEFINITION:                                                                │
│  Scope determines the accessibility (visibility) of variables.              │
│  It defines where variables can be accessed in your code.                   │
│                                                                             │
│  ┌──────────────────────────────────────────────────────────────────────┐   │
│  │                    TYPES OF SCOPE                                    │   │
│  ├──────────────────────────────────────────────────────────────────────┤   │
│  │                                                                      │   │
│  │  1. GLOBAL SCOPE                                                     │   │
│  │     ├── Variables declared outside any function/block                │   │
│  │     ├── Accessible from anywhere in the code                         │   │
│  │     └── Lives for the entire program duration                        │   │
│  │                                                                      │   │
│  │  2. FUNCTION SCOPE (Local Scope)                                     │   │
│  │     ├── Variables declared inside a function                         │   │
│  │     ├── Only accessible within that function                         │   │
│  │     └── Created when function is called, destroyed when it returns   │   │
│  │                                                                      │   │
│  │  3. BLOCK SCOPE (ES6+)                                               │   │
│  │     ├── Variables declared with let/const inside { }                 │   │
│  │     ├── Only accessible within that block                            │   │
│  │     └── Includes if, for, while, try/catch blocks                    │   │
│  │                                                                      │   │
│  │  4. LEXICAL SCOPE (Static Scope)                                     │   │
│  │     ├── Scope is determined at write time, not runtime               │   │
│  │     ├── Inner functions have access to outer function variables      │   │
│  │     └── This is the foundation of closures                           │   │
│  │                                                                      │   │
│  └──────────────────────────────────────────────────────────────────────┘   │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Visual Representation of Scopes

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                           SCOPE HIERARCHY                                   │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  ┌──────────────────────────────────────────────────────────────────────┐   │
│  │  GLOBAL SCOPE                                                        │   │
│  │  ├── var globalVar = "I'm global"                                    │   │
│  │  ├── let globalLet = "I'm also global"                               │   │
│  │  │                                                                   │   │
│  │  │   ┌──────────────────────────────────────────────────────────┐    │   │
│  │  │   │  FUNCTION SCOPE (outerFunction)                          │    │   │
│  │  │   │  ├── var outerVar = "I'm in outer"                       │    │   │
│  │  │   │  ├── Can access: globalVar, globalLet, outerVar          │    │   │
│  │  │   │  │                                                       │    │   │
│  │  │   │  │   ┌──────────────────────────────────────────────┐    │    │   │
│  │  │   │  │   │  FUNCTION SCOPE (innerFunction)              │    │    │   │
│  │  │   │  │   │  ├── var innerVar = "I'm in inner"           │    │    │   │
│  │  │   │  │   │  ├── Can access: ALL above + innerVar        │    │    │   │
│  │  │   │  │   │  │                                           │    │    │   │
│  │  │   │  │   │  │   ┌──────────────────────────────────┐    │    │    │   │
│  │  │   │  │   │  │   │  BLOCK SCOPE (if block)          │    │    │    │   │
│  │  │   │  │   │  │   │  ├── let blockVar = "block"      │    │    │    │   │
│  │  │   │  │   │  │   │  └── Can access: ALL above       │    │    │    │   │
│  │  │   │  │   │  │   └──────────────────────────────────┘    │    │    │   │
│  │  │   │  │   │  │                                           │    │    │   │
│  │  │   │  │   └──┴───────────────────────────────────────────┘    │    │   │
│  │  │   │  │                                                       │    │   │
│  │  │   └──┴───────────────────────────────────────────────────────┘    │   │
│  │  │                                                                   │   │
│  └──┴───────────────────────────────────────────────────────────────────┘   │
│                                                                             │
│  ACCESS DIRECTION: Inner scope can access outer scope (not vice versa)      │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Scope Chain

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                            SCOPE CHAIN                                      │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  DEFINITION:                                                                │
│  The scope chain is a list of all the scopes that are accessible            │
│  from the current execution context.                                        │
│                                                                             │
│  HOW IT WORKS:                                                              │
│  When JavaScript needs to find a variable:                                  │
│  1. First looks in current (local) scope                                    │
│  2. If not found, looks in parent scope                                     │
│  3. Continues up the chain until global scope                               │
│  4. If not found in global, throws ReferenceError                           │
│                                                                             │
│  ┌──────────────────────────────────────────────────────────────────────┐   │
│  │                     LOOKUP PROCESS                                   │   │
│  │                                                                      │   │
│  │    innerFunction needs 'x'                                           │   │
│  │           │                                                          │   │
│  │           ▼                                                          │   │
│  │    ┌──────────────┐                                                  │   │
│  │    │ innerFunction│ ──→ Is 'x' here? NO                              │   │
│  │    │    Scope     │     │                                            │   │
│  │    └──────────────┘     ▼                                            │   │
│  │           │      ┌──────────────┐                                    │   │
│  │           └─────►│ outerFunction│ ──→ Is 'x' here? NO                │   │
│  │                  │    Scope     │     │                              │   │
│  │                  └──────────────┘     ▼                              │   │
│  │                         │      ┌──────────────┐                      │   │
│  │                         └─────►│   Global     │ ──→ Is 'x' here?     │   │
│  │                                │   Scope      │     YES! Use it.     │   │
│  │                                └──────────────┘                      │   │
│  │                                                                      │   │
│  └──────────────────────────────────────────────────────────────────────┘   │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

## 💻 PRACTICAL EXAMPLES

### Example 1: All Types of Scope

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Global, Function, and Block Scope
// ═══════════════════════════════════════════════════════════════

// GLOBAL SCOPE
var globalVar= "I am global (var)";
let globalLet= "I am global (let)";
const globalConst = "I am global (const)";

function demonstrateScopes() {
    // FUNCTION SCOPE
    var functionVar= "I am function-scoped";
    let functionLet= "I am also function-scoped";

    console.log("Inside function:");
    console.log(globalVar);// ✅ Accessible
    console.log(functionVar);// ✅ Accessible

    if (true) {
        // BLOCK SCOPE
        var blockVar= "I am var in block";// Still function-scoped!
        let blockLet= "I am let in block";// Block-scoped
        const blockConst = "I am const in block";// Block-scoped

        console.log("\nInside block:");
        console.log(globalVar);// ✅ Accessible
        console.log(functionVar);// ✅ Accessible
        console.log(blockVar);// ✅ Accessible
        console.log(blockLet);// ✅ Accessible
    }

    console.log("\nAfter block:");
    console.log(blockVar);// ✅ Accessible (var ignores block scope!)
    // console.log(blockLet);  // ❌ ReferenceError
    // console.log(blockConst);// ❌ ReferenceError
}

demonstrateScopes();

console.log("\nOutside function:");
console.log(globalVar);// ✅ Accessible
// console.log(functionVar); // ❌ ReferenceError
// console.log(blockVar);    // ❌ ReferenceError

```

### Example 2: Scope Chain in Action

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Scope Chain Lookup
// ═══════════════════════════════════════════════════════════════

const global = "I am global";

function outer() {
    const outer = "I am outer";

    function middle() {
        const middle = "I am middle";

        function inner() {
            const inner = "I am inner";

            // Scope chain: inner → middle → outer → global
            console.log(inner);// Found in inner scope
            console.log(middle);// Found in middle scope (1 level up)
            console.log(outer);// Found in outer scope (2 levels up)
            console.log(global);// Found in global scope (3 levels up)
        }

        inner();
    }

    middle();
}

outer();

/*
OUTPUT:
I am inner
I am middle
I am outer
I am global

SCOPE CHAIN VISUALIZATION:

When inner() runs, its scope chain is:
┌────────────────────────────────────────┐
│ inner Scope                            │
│ └── inner = "I am inner"               │
├────────────────────────────────────────┤
│ middle Scope                           │
│ └── middle = "I am middle"             │
├────────────────────────────────────────┤
│ outer Scope                            │
│ └── outer = "I am outer"               │
├────────────────────────────────────────┤
│ Global Scope                           │
│ └── global = "I am global"             │
└────────────────────────────────────────┘
*/
```

### Example 3: Variable Shadowing

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Variable Shadowing
// ═══════════════════════════════════════════════════════════════

const name = "Global Name";

function outer() {
    const name = "Outer Name";// Shadows global 'name'

    function inner() {
        const name = "Inner Name";// Shadows outer 'name'
        console.log(name);// "Inner Name"
    }

    console.log(name);// "Outer Name"
    inner();
}

console.log(name);// "Global Name"
outer();

/*
OUTPUT:
Global Name
Outer Name
Inner Name

Each function creates its own 'name' variable that shadows
the outer one. The outer variables still exist, but they're
not accessible when shadowed.
*/

// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Accessing shadowed variable (You can't directly!)
// ═══════════════════════════════════════════════════════════════

var globalValue= 100;

function test() {
    var globalValue= 200;// Shadows global

    console.log(globalValue);// 200 (local)
    console.log(window.globalValue);// 100 (global, in browser)
    // Note: This only works for var in global scope
}

test();
```

### Example 4: Lexical Scope

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Lexical (Static) Scope
// ═══════════════════════════════════════════════════════════════

// Scope is determined by WHERE the function is WRITTEN,
// not where it's CALLED.

const value = "Global";

function outer() {
    const value = "Outer";

    function inner() {
        console.log(value);// What will this log?
    }

    return inner;
}

function caller() {
    const value = "Caller";
    const innerFn = outer();// Get the inner function
    innerFn();// Call it from here
}

caller();

/*
OUTPUT:
Outer

EXPLANATION:
Even though inner() is CALLED inside caller(),
it accesses 'value' from where it was DEFINED (outer function).
This is lexical scoping - scope is determined at write time.

If JavaScript used dynamic scope:
- Output would be "Caller"
- Scope would be determined by call location
But JavaScript uses LEXICAL scope, so output is "Outer"
*/

// ═══════════════════════════════════════════════════════════════
// ANOTHER EXAMPLE: Function returned and called elsewhere
// ═══════════════════════════════════════════════════════════════

function createGreeter(greeting) {
    // 'greeting' is in this scope

    return function(name) {
        // This function remembers 'greeting' from its lexical scope
        console.log(`${greeting}, ${name}!`);
    };
}

const sayHello = createGreeter("Hello");
const sayHi = createGreeter("Hi");

// Even though createGreeter has finished executing,
// the returned functions remember their lexical scope!
sayHello("Tiasha");// "Hello, Tiasha!"
sayHi("World");// "Hi, World!"
```

## 🌍 REAL-LIFE SCENARIOS

### Scenario 1: Avoiding Global Pollution

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Module Pattern to avoid global pollution
// ═══════════════════════════════════════════════════════════════

// BAD: Polluting global scope
var userCount= 0;
var adminCount= 0;
function createUser() {/* ... */ }
function deleteUser() {/* ... */ }
// Any other script can accidentally overwrite these!

// GOOD: Using module pattern (IIFE + scope)
const UserModule = (function() {
    // PRIVATE - not accessible outside
    let userCount= 0;
    let adminCount= 0;
    const users = [];

    // PRIVATE HELPER
    function validateUser(user) {
        return user.name&& user.email;
    }

    // PUBLIC API
    return {
        createUser:function(user) {
            if (validateUser(user)) {
                users.push(user);
                userCount++;
                console.log(`User created. Total: ${userCount}`);
                return true;
            }
            return false;
        },

        deleteUser:function(email) {
            const index = users.findIndex(u => u.email=== email);
            if (index!== -1) {
                users.splice(index,1);
                userCount--;
                console.log(`User deleted. Total: ${userCount}`);
                return true;
            }
            return false;
        },

        getCount:function() {
            return userCount;
        }
    };
})();

// Usage:
UserModule.createUser({ name:"Tiasha", email:"tiasha@example.com" });
UserModule.createUser({ name:"John", email:"john@example.com" });
console.log("Total users:", UserModule.getCount());// 2

// Can't access private variables:
// console.log(UserModule.users);       // undefined
// console.log(UserModule.userCount);   // undefined
// UserModule.validateUser();           // TypeError
```

### Scenario 2: Loop Variable Scope Issue

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Classic interview question - setTimeout in loop
// ═══════════════════════════════════════════════════════════════

// THE PROBLEM:
console.log("=== THE PROBLEM ===");
for (var i= 1; i<= 3; i++) {
    setTimeout(function() {
        console.log("var loop:", i);// All print 4!
    }, i* 100);
}
// Output: 4, 4, 4

// WHY?
// - var is function-scoped, not block-scoped
// - There's only ONE 'i' variable
// - By the time setTimeout callbacks run, loop has finished
// - At that point, i = 4

// ═══════════════════════════════════════════════════════════════

// SOLUTION 1: Use let (block scope)
console.log("\n=== SOLUTION 1: let ===");
for (let i= 1; i<= 3; i++) {
    setTimeout(function() {
        console.log("let loop:", i);// 1, 2, 3
    }, i* 100);
}
// Each iteration gets its own 'i' in block scope

// ═══════════════════════════════════════════════════════════════

// SOLUTION 2: IIFE (creates new scope per iteration)
console.log("\n=== SOLUTION 2: IIFE ===");
for (var i= 1; i<= 3; i++) {
    (function(j) {
        setTimeout(function() {
            console.log("IIFE loop:", j);// 1, 2, 3
        }, j* 100);
    })(i);// Pass current 'i' as argument
}

// ═══════════════════════════════════════════════════════════════

// SOLUTION 3: setTimeout's third parameter
console.log("\n=== SOLUTION 3: Third parameter ===");
for (var i= 1; i<= 3; i++) {
    setTimeout(function(j) {
        console.log("Third param loop:", j);// 1, 2, 3
    }, i* 100, i);// Third param is passed to callback
}
```

### Scenario 3: Event Handler Scope Issues

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: React component scope issues
// ═══════════════════════════════════════════════════════════════

// PROBLEM IN REACT (conceptual example):
/*
function ButtonList() {
    const buttons = ['One', 'Two', 'Three'];

    // WRONG WAY:
    const handleClick = () => {
        // Which button was clicked?
        // No way to know - all share same scope
    };

    return buttons.map((btn, index) => (
        <button onClick={handleClick}>{btn}</button>
    ));
}
*/

// SOLUTION: Use closure to capture the value
/*
function ButtonList() {
    const buttons = ['One', 'Two', 'Three'];

    // RIGHT WAY: Create new scope for each button
    const createHandler = (index) => () => {
        console.log(`Button ${index} clicked`);
    };

    return buttons.map((btn, index) => (
        <button onClick={createHandler(index)}>{btn}</button>
    ));
}
*/

// VANILLA JS EXAMPLE:
function setupButtons() {
    const buttonNames = ['Save','Delete','Update'];

    buttonNames.forEach((name,index)=> {
        const button = document.createElement('button');
        button.textContent= name;

        // Each callback has its own scope with its own 'name' and 'index'
        button.addEventListener('click', ()=> {
            console.log(`${name} button (index: ${index}) clicked`);
        });

        document.body.appendChild(button);
    });
}
```

## 📝 PRACTICE QUESTIONS

### 🟢 EASY QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// EASY Q1: Basic scope identification
// ═══════════════════════════════════════════════════════════════

var a= 1;
let b= 2;
const c = 3;

function test() {
    var d= 4;
    let e= 5;

    console.log(a, b, c, d, e);
}

test();
console.log(a, b, c);
// console.log(d);  // What happens?
// console.log(e);  // What happens?

/*
YOUR ANSWER:
test() output: _______________
After test() output: _______________
console.log(d): _______________
console.log(e): _______________

EXPECTED:
test() output: 1 2 3 4 5
After test() output: 1 2 3
console.log(d): ReferenceError (d is function-scoped to test)
console.log(e): ReferenceError (e is function-scoped to test)
*/

// ═══════════════════════════════════════════════════════════════
// EASY Q2: Block scope
// ═══════════════════════════════════════════════════════════════

let x= 10;

if (true) {
    let x= 20;
    console.log("Inside:", x);
}

console.log("Outside:", x);

/*
YOUR ANSWER:
Inside: _______________
Outside: _______________

EXPECTED:
Inside: 20
Outside: 10
*/

// ═══════════════════════════════════════════════════════════════
// EASY Q3: var in block
// ═══════════════════════════════════════════════════════════════

if (true) {
    var message= "Hello";
}

console.log(message);

/*
YOUR ANSWER:
Output: _______________

EXPECTED:
Output: "Hello"
(var ignores block scope, only respects function scope)
*/
```

### 🟡 MEDIUM QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// MEDIUM Q1: Scope chain lookup
// ═══════════════════════════════════════════════════════════════

const name = "Global";

function first() {
    const name = "First";

    function second() {
        console.log(name);
    }

    second();
}

function third() {
    const name = "Third";
    first();
}

third();

/*
YOUR ANSWER:
Output: _______________

EXPECTED:
Output: "First"

EXPLANATION:
- third() calls first()
- first() calls second()
- second() looks for 'name' in its scope chain
- Scope chain: second → first → global
- Finds "First" in first's scope
- "Third" is NOT in second's scope chain!
*/

// ═══════════════════════════════════════════════════════════════
// MEDIUM Q2: for loop scope
// ═══════════════════════════════════════════════════════════════

for (var i= 0; i< 3; i++) {
    // empty loop
}
console.log("After var loop:", i);

for (let j= 0; j< 3; j++) {
    // empty loop
}
// console.log("After let loop:", j);  // What happens?

/*
YOUR ANSWER:
After var loop: _______________
After let loop: _______________

EXPECTED:
After var loop: 3
After let loop: ReferenceError (j is not defined)
*/

// ═══════════════════════════════════════════════════════════════
// MEDIUM Q3: Nested function scope
// ═══════════════════════════════════════════════════════════════

function outer() {
    var x= 1;

    function inner() {
        var y= 2;
        console.log(x+ y);
    }

    inner();
    // console.log(y);  // What happens?
}

outer();

/*
YOUR ANSWER:
inner() output: _______________
console.log(y): _______________

EXPECTED:
inner() output: 3
console.log(y): ReferenceError (y is local to inner)
*/
```

### 🔴 HARD QUESTIONS

```jsx
// ═══════════════════════════════════════════════════════════════
// HARD Q1: Complex scope chain
// ═══════════════════════════════════════════════════════════════

var x= 10;

function foo() {
    console.log(x);
}

function bar() {
    var x= 20;
    foo();
}

bar();

/*
YOUR ANSWER:
Output: _______________

EXPECTED:
Output: 10

EXPLANATION:
This is about LEXICAL scope vs DYNAMIC scope.
JavaScript uses LEXICAL scope.

foo() is DEFINED in global scope, so its scope chain is:
foo → global

When foo() is CALLED from bar():
- It still uses its original scope chain (foo → global)
- It finds x = 10 in global scope
- bar's x = 20 is NOT in foo's scope chain

If JavaScript used dynamic scope:
- Output would be 20
- Scope would be based on call stack
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q2: Multiple nested scopes
// ═══════════════════════════════════════════════════════════════

function level1() {
    let a= 1;

    function level2() {
        let b= 2;

        function level3() {
            let c= 3;

            function level4() {
                let d= 4;
                console.log(a+ b+ c+ d);
            }

            level4();
        }

        level3();
    }

    level2();
}

level1();

/*
YOUR ANSWER:
Output: _______________

EXPECTED:
Output: 10 (1 + 2 + 3 + 4)

SCOPE CHAIN for level4:
level4 (d=4) → level3 (c=3) → level2 (b=2) → level1 (a=1) → global
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q3: Returned function scope
// ═══════════════════════════════════════════════════════════════

function createMultiplier(factor) {
    return function(number) {
        return number* factor;
    };
}

const double = createMultiplier(2);
const triple = createMultiplier(3);

console.log(double(5));
console.log(triple(5));
console.log(double(10));

/*
YOUR ANSWER:
Output 1: _______________
Output 2: _______________
Output 3: _______________

EXPECTED:
Output 1: 10
Output 2: 15
Output 3: 20

EXPLANATION:
Each call to createMultiplier creates a new scope.
The returned functions maintain access to their original scope.
- double's scope chain has factor = 2
- triple's scope chain has factor = 3
*/

// ═══════════════════════════════════════════════════════════════
// HARD Q4: Interview question - Fix the bug
// ═══════════════════════════════════════════════════════════════

// BUGGY CODE:
const handlers = [];

for (var i= 0; i< 3; i++) {
    handlers.push(function() {
        return i;
    });
}

console.log(handlers[0]());// Expected: 0, Actual: ?
console.log(handlers[1]());// Expected: 1, Actual: ?
console.log(handlers[2]());// Expected: 2, Actual: ?

/*
YOUR ANSWER:
Actual outputs:
handlers[0](): _______________
handlers[1](): _______________
handlers[2](): _______________

Fix the code:
_______________

EXPECTED:
Actual outputs: 3, 3, 3 (all return 3)

FIX 1 - Use let:
for (let i = 0; i < 3; i++) { ... }

FIX 2 - Use IIFE:
for (var i = 0; i < 3; i++) {
    handlers.push((function(j) {
        return function() {
            return j;
        };
    })(i));
}

FIX 3 - Use bind:
for (var i = 0; i < 3; i++) {
    handlers.push(function(j) {
        return j;
    }.bind(null, i));
}
*/
```

---

# 📘 MODULE 4: Closures

## 📚 THEORY

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                              CLOSURES                                       │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  DEFINITION:                                                                │
│  A closure is a function that has access to variables from its outer        │
│  (enclosing) scope, even after the outer function has returned.             │
│                                                                             │
│  In simple terms: A function "remembers" the environment where it was       │
│  created.                                                                   │
│                                                                             │
│  ┌──────────────────────────────────────────────────────────────────────┐   │
│  │                    HOW CLOSURES WORK                                 │   │
│  ├──────────────────────────────────────────────────────────────────────┤   │
│  │                                                                      │   │
│  │  1. A function is created inside another function                    │   │
│  │                                                                      │   │
│  │  2. The inner function references variables from the outer function  │   │
│  │                                                                      │   │
│  │  3. The inner function is returned (or passed somewhere)             │   │
│  │                                                                      │   │
│  │  4. The outer function finishes executing                            │   │
│  │                                                                      │   │
│  │  5. Normally, outer function's variables would be garbage collected  │   │
│  │                                                                      │   │
│  │  6. BUT: The inner function keeps a reference to those variables     │   │
│  │                                                                      │   │
│  │  7. So those variables stay in memory - this is the CLOSURE          │   │
│  │                                                                      │   │
│  └──────────────────────────────────────────────────────────────────────┘   │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Visual Representation

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                    CLOSURE VISUALIZATION                                    │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│   function outer() {                                                        │
│       let count = 0;  ───────────────────────────────────────────┐          │
│                                                                  │          │
│       return function inner() {                                  │          │
│           count++;  ←────────────────────────────────────────────┘          │
│           return count;    │                                                │
│       };                   │ CLOSURE                                        │
│   }                        │ (inner function + its lexical environment)     │
│                            │                                                │
│   const increment = outer();                                                │
│                                                                             │
│   ┌──────────────────────────────────────────────────────────────────────┐  │
│   │                     AFTER outer() RETURNS                            │  │
│   │                                                                      │  │
│   │   outer's execution context is gone from call stack                  │  │
│   │                                                                      │  │
│   │   BUT: 'increment' function still has a reference to outer's         │  │
│   │        variable environment (the closure)                            │  │
│   │                                                                      │  │
│   │   ┌─────────────────────┐                                            │  │
│   │   │ increment function  │                                            │  │
│   │   ├─────────────────────┤                                            │  │
│   │   │ [[Scope]]:          │                                            │  │
│   │   │ ├── Closure(outer)  │──→ { count: 0 }                            │  │
│   │   │ └── Global          │                                            │  │
│   │   └─────────────────────┘                                            │  │
│   │                                                                      │  │
│   └──────────────────────────────────────────────────────────────────────┘  │
│                                                                             │
│   increment()  // count becomes 1, returns 1                                │
│   increment()  // count becomes 2, returns 2                                │
│   increment()  // count becomes 3, returns 3                                │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘

```

### Common Use Cases for Closures

```jsx
┌─────────────────────────────────────────────────────────────────────────────┐
│                    CLOSURE USE CASES                                        │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  1. DATA PRIVACY / ENCAPSULATION                                            │
│     └── Create private variables not accessible from outside                │
│                                                                             │
│  2. FUNCTION FACTORIES                                                      │
│     └── Create specialized functions with pre-configured values             │
│                                                                             │
│  3. MAINTAINING STATE                                                       │
│     └── Remember values between function calls                              │
│                                                                             │
│  4. CALLBACKS & EVENT HANDLERS                                              │
│     └── Preserve context in async operations                                │
│                                                                             │
│  5. CURRYING & PARTIAL APPLICATION                                          │
│     └── Transform functions with multiple arguments                         │
│                                                                             │
│  6. MEMOIZATION                                                             │
│     └── Cache results of expensive function calls                           │
│                                                                             │
│  7. MODULE PATTERN                                                          │
│     └── Create modules with public and private members                      │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

## 💻 PRACTICAL EXAMPLES

### Example 1: Basic Closure

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Basic Closure Demonstration
// ═══════════════════════════════════════════════════════════════

function createCounter() {
    let count= 0;// Private variable

    return function() {
        count++;
        return count;
    };
}

const counter1 = createCounter();
const counter2 = createCounter();

console.log(counter1());// 1
console.log(counter1());// 2
console.log(counter1());// 3

console.log(counter2());// 1 (separate closure, separate count!)
console.log(counter2());// 2

console.log(counter1());// 4 (counter1 maintains its own state)

/*
EXPLANATION:
- Each call to createCounter() creates a NEW closure
- Each closure has its OWN 'count' variable
- The returned functions "close over" their respective 'count'
- Even though createCounter() has returned, the count persists
*/
```

### Example 2: Data Privacy

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Using Closures for Data Privacy
// ═══════════════════════════════════════════════════════════════

function createBankAccount(initialBalance) {
    // PRIVATE: Not accessible from outside
    let balance= initialBalance;
    const transactionHistory = [];

    // Private helper function
    function recordTransaction(type,amount) {
        transactionHistory.push({
            type,
            amount,
            balance: balance,
            date:new Date().toISOString()
        });
    }

    // PUBLIC API (returned object)
    return {
        deposit(amount) {
            if (amount> 0) {
                balance+= amount;
                recordTransaction('deposit', amount);
                return `Deposited $${amount}. New balance: $${balance}`;
            }
            return 'Invalid amount';
        },

        withdraw(amount) {
            if (amount> 0 && amount<= balance) {
                balance-= amount;
                recordTransaction('withdrawal', amount);
                return `Withdrew $${amount}. New balance: $${balance}`;
            }
            return 'Invalid amount or insufficient funds';
        },

        getBalance() {
            return `Current balance: $${balance}`;
        },

        getHistory() {
            return [...transactionHistory];// Return copy, not original
        }
    };
}

const account = createBankAccount(1000);

console.log(account.getBalance());// Current balance: $1000
console.log(account.deposit(500));// Deposited $500. New balance: $1500
console.log(account.withdraw(200));// Withdrew $200. New balance: $1300
console.log(account.getBalance());// Current balance: $1300

// Can't access private variables!
console.log(account.balance);// undefined
console.log(account.transactionHistory);// undefined

// But we can get a copy of history through the API
console.log(account.getHistory());

```

### Example 3: Function Factory

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Function Factory using Closures
// ═══════════════════════════════════════════════════════════════

// Create a greeting function factory
function createGreeter(greeting,punctuation = '!') {
    return function(name) {
        return `${greeting}, ${name}${punctuation}`;
    };
}

// Create specialized greeting functions
const sayHello = createGreeter('Hello');
const sayHi = createGreeter('Hi','!');
const sayGoodMorning = createGreeter('Good morning','. Have a great day!');
const askHowAreYou = createGreeter('How are you','?');

console.log(sayHello('Tiasha'));// Hello, Tiasha!
console.log(sayHi('World'));// Hi, World!
console.log(sayGoodMorning('Team'));// Good morning, Team. Have a great day!
console.log(askHowAreYou('Everyone'));// How are you, Everyone?

// ═══════════════════════════════════════════════════════════════
// ANOTHER EXAMPLE: Tax Calculator Factory
// ═══════════════════════════════════════════════════════════════

function createTaxCalculator(taxRate,taxName) {
    return function(amount) {
        const tax = amount* (taxRate/ 100);
        return {
            name: taxName,
            originalAmount: amount,
            taxRate:`${taxRate}%`,
            taxAmount: tax,
            total: amount+ tax
        };
    };
}

const calculateGST = createTaxCalculator(18,'GST');
const calculateVAT = createTaxCalculator(20,'VAT');
const calculateServiceTax = createTaxCalculator(12.5,'Service Tax');

console.log(calculateGST(1000));
// { name: 'GST', originalAmount: 1000, taxRate: '18%', taxAmount: 180, total: 1180 }

console.log(calculateVAT(1000));
// { name: 'VAT', originalAmount: 1000, taxRate: '20%', taxAmount: 200, total: 1200 }
```

### Example 4: Memoization with Closures

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Memoization - Caching Expensive Computations
// ═══════════════════════════════════════════════════════════════

function memoize(fn) {
    const cache = {};// Private cache stored in closure

    return function(...args) {
        const key = JSON.stringify(args);

        if (cache[key]!== undefined) {
            console.log(`Cache hit for key: ${key}`);
            return cache[key];
        }

        console.log(`Computing for key: ${key}`);
        const result = fn.apply(this, args);
        cache[key]= result;
        return result;
    };
}

// Expensive function (simulated)
function fibonacci(n) {
    if (n<= 1)return n;
    return fibonacci(n- 1)+ fibonacci(n- 2);
}

// Create memoized version
const memoizedFib = memoize(function fib(n) {
    if (n<= 1)return n;
    return memoizedFib(n- 1)+ memoizedFib(n- 2);
});

console.log(memoizedFib(10));// Computing... then result
console.log(memoizedFib(10));// Cache hit! Instant result
console.log(memoizedFib(10));// Cache hit! Instant result

// ═══════════════════════════════════════════════════════════════
// PRACTICAL EXAMPLE: API Call Memoization
// ═══════════════════════════════════════════════════════════════

function createAPIFetcher(baseURL) {
    const cache = {};
    const cacheTimeout = 5 * 60 * 1000;// 5 minutes

    return async function(endpoint) {
        const cacheKey = `${baseURL}${endpoint}`;
        const cached = cache[cacheKey];

        if (cached&& Date.now()- cached.timestamp< cacheTimeout) {
            console.log(`Returning cached data for ${endpoint}`);
            return cached.data;
        }

        console.log(`Fetching fresh data for ${endpoint}`);
        const response = await fetch(`${baseURL}${endpoint}`);
        const data = await response.json();

        cache[cacheKey]= {
            data,
            timestamp: Date.now()
        };

        return data;
    };
}

const fetchFromAPI = createAPIFetcher('https://api.example.com');
// First call: fetches from network
// Subsequent calls within 5 min: returns from cache
```

### Example 5: Event Handlers with Closures

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Event Handlers - Preserving Context
// ═══════════════════════════════════════════════════════════════

function createButtonHandler(buttonId,message) {
    let clickCount= 0;// Closure variable

    return function handleClick(event) {
        clickCount++;
        console.log(`Button ${buttonId}: "${message}" (clicked ${clickCount} times)`);

        if (clickCount>= 5) {
            console.log(`Button ${buttonId} is tired of being clicked!`);
        }
    };
}

// Create handlers for different buttons
const handler1 = createButtonHandler('save','Saving your work...');
const handler2 = createButtonHandler('delete','Are you sure?');

// Simulate button clicks
handler1();// Button save: "Saving your work..." (clicked 1 times)
handler1();// Button save: "Saving your work..." (clicked 2 times)
handler2();// Button delete: "Are you sure?" (clicked 1 times)
handler1();// Button save: "Saving your work..." (clicked 3 times)

// Each handler has its own clickCount in its closure

// ═══════════════════════════════════════════════════════════════
// REACT-STYLE EXAMPLE: Closure in useEffect
// ═══════════════════════════════════════════════════════════════

function simulateReactComponent() {
    let count= 0;

    function useState(initial) {
        let state= initial;
        const setState = (newValue)=> {
            state= newValue;
            // In React, this would trigger re-render
            console.log('State updated to:', state);
        };
        return [state, setState];
    }

    function useEffect(callback,deps) {
        // Simulating effect
        console.log('Effect running with count:', count);
        callback();
    }

    const [value,setValue]= useState(0);

    useEffect(()=> {
        // This closure captures the current 'count'
        console.log('Effect sees count as:', count);

        // Common bug: stale closure
        // If this runs after count changes, it still sees old value
    }, [count]);

    count= 10;// Simulating state change

    useEffect(()=> {
        console.log('New effect sees count as:', count);
    }, [count]);
}

simulateReactComponent();
```

### Example 6: Currying with Closures

```jsx
// ═══════════════════════════════════════════════════════════════
// EXAMPLE: Currying - Transform Function with Multiple Arguments
// ═══════════════════════════════════════════════════════════════

// Regular function
function add(a,b,c) {
    return a+ b+ c;
}

// Curried version using closures
function curriedAdd(a) {
    return function(b) {
        return function(c) {
            return a+ b+ c;
        };
    };
}

// Usage
console.log(add(1,2,3));// 6
console.log(curriedAdd(1)(2)(3));// 6

// Partial application
const add5 = curriedAdd(5);
const add5and10 = add5(10);

console.log(add5and10(3));// 18
console.log(add5and10(7));// 22
console.log(add5(20)(5));// 30

// ═══════════════════════════════════════════════════════════════
// GENERIC CURRY FUNCTION
// ═══════════════════════════════════════════════════════════════

function curry(fn) {
    return function curried(...args) {
        if (args.length >= fn.length) {
            return fn.apply(this, args);
        }
        return function(...moreArgs) {
            return curried.apply(this, args.concat(moreArgs));
        };
    };
}

// Apply to any function
function greet(greeting,punctuation,name) {
    return `${greeting}, ${name}${punctuation}`;
}

const curriedGreet = curry(greet);

console.log(curriedGreet('Hello')('!')('Tiasha'));// Hello, Tiasha!
console.log(curriedGreet('Hi','?','World'));// Hi, World?

const sayHello = curriedGreet('Hello','!');
console.log(sayHello('Everyone'));// Hello, Everyone!
```

## 🌍 REAL-LIFE SCENARIOS

### Scenario 1: Module Pattern (Production Code)

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Shopping Cart Module
// ═══════════════════════════════════════════════════════════════

const ShoppingCart = (function() {
    // Private state
    let items= [];
    let discountCode= null;

    // Private helper functions
    function calculateSubtotal() {
        return items.reduce((sum,item)=> sum+ (item.price* item.quantity),0);
    }

    function getDiscountMultiplier() {
        const discounts = {
            'SAVE10':0.10,
            'SAVE20':0.20,
            'HALFOFF':0.50
        };
        return discounts[discountCode]|| 0;
    }

    function formatCurrency(amount) {
        return `$${amount.toFixed(2)}`;
    }

    // Public API
    return {
        addItem(product,quantity = 1) {
            const existingItem = items.find(item => item.id=== product.id);

            if (existingItem) {
                existingItem.quantity+= quantity;
            }else {
                items.push({...product, quantity });
            }

            console.log(`Added ${quantity}x ${product.name} to cart`);
            return this;// For chaining
        },

        removeItem(productId) {
            const index = items.findIndex(item => item.id=== productId);
            if (index!== -1) {
                const removed = items.splice(index,1)[0];
                console.log(`Removed ${removed.name} from cart`);
            }
            return this;
        },

        updateQuantity(productId,quantity) {
            const item = items.find(item => item.id=== productId);
            if (item) {
                item.quantity= Math.max(0, quantity);
                if (item.quantity=== 0) {
                    this.removeItem(productId);
                }
            }
            return this;
        },

        applyDiscount(code) {
            discountCode= code.toUpperCase();
            if (getDiscountMultiplier()> 0) {
                console.log(`Discount code ${discountCode} applied!`);
            }else {
                console.log('Invalid discount code');
                discountCode= null;
            }
            return this;
        },

        getTotal() {
            const subtotal = calculateSubtotal();
            const discount = subtotal* getDiscountMultiplier();
            return {
                subtotal:formatCurrency(subtotal),
                discount:formatCurrency(discount),
                total:formatCurrency(subtotal- discount),
                itemCount: items.reduce((sum,item)=> sum+ item.quantity,0)
            };
        },

        getItems() {
            return items.map(item => ({...item }));// Return copy
        },

        clear() {
            items= [];
            discountCode= null;
            console.log('Cart cleared');
            return this;
        }
    };
})();

// Usage
ShoppingCart
    .addItem({ id:1, name:'Laptop', price:999.99 })
    .addItem({ id:2, name:'Mouse', price:49.99 },2)
    .addItem({ id:3, name:'Keyboard', price:149.99 })
    .applyDiscount('SAVE10');

console.log(ShoppingCart.getTotal());
// { subtotal: '$1249.96', discount: '$124.00', total: '$1125.96', itemCount: 4 }

// Can't access private data
console.log(ShoppingCart.items);// undefined
console.log(ShoppingCart.discountCode);// undefined

```

### Scenario 2: Debounce and Throttle (Common Interview Question)

```jsx
// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Debounce Function (Search Input)
// ═══════════════════════════════════════════════════════════════

function debounce(func,delay) {
    let timeoutId;// Stored in closure

    return function(...args) {
        // Clear previous timeout
        clearTimeout(timeoutId);

        // Set new timeout
        timeoutId= setTimeout(()=> {
            func.apply(this, args);
        }, delay);
    };
}

// Usage: Search input that waits for user to stop typing
const searchAPI = (query)=> {
    console.log(`Searching for: ${query}`);
    // Actual API call would go here
};

const debouncedSearch = debounce(searchAPI,300);

// Simulating rapid typing
debouncedSearch('j');// Cancelled
debouncedSearch('ja');// Cancelled
debouncedSearch('jav');// Cancelled
debouncedSearch('java');// Cancelled
debouncedSearch('javas');// Cancelled
debouncedSearch('javasc');// Cancelled
debouncedSearch('javascr');// Cancelled
debouncedSearch('javascri');// Cancelled
debouncedSearch('javascript');// Only this one executes after 300ms

// ═══════════════════════════════════════════════════════════════
// REAL-LIFE SCENARIO: Throttle Function (Scroll Handler)
// ═══════════════════════════════════════════════════════════════

function throttle(func,limit) {
    let inThrottle;// Stored in closure
    let lastResult;// Store last result

    return function(...args) {
        if (!inThrottle) {
            lastResult= func.apply(this, args);
            inThrottle= true;

            setTimeout(()=> {
                inThrottle= false;

```

# please continue from here
