# Interpreter Design Pattern (C#)

## Overview

The **Interpreter Pattern** is a **behavioral design pattern** used to define grammar rules and interpret expressions.

This pattern is useful when:

- You need to evaluate expressions
- You want to create small scripting languages
- You need rule engines or parsers
- You want to interpret structured text or commands

The Interpreter Pattern represents grammar rules as classes.

---

# Real World Example

Think of a calculator interpreting:

```text
5 + 3 - 2
```

The system:
- Reads numbers
- Understands operators
- Evaluates the expression

Another example:

```text
IF playerLevel > 10
THEN Unlock Quest
```

A game engine interprets the rule and executes behavior.

---

# Structure of Interpreter Pattern

There are **4 main components**:

## 1. Abstract Expression

Defines the interpret method.

Example:

```csharp
abstract class Expression
{
    public abstract int Interpret();
}
```

---

## 2. Terminal Expression

Represents basic elements like:
- numbers
- variables
- words

Example:

```csharp
class NumberExpression : Expression
{
    private int number;

    public NumberExpression(int number)
    {
        this.number = number;
    }

    public override int Interpret()
    {
        return number;
    }
}
```

---

## 3. Non-Terminal Expression

Represents grammar operations like:
- addition
- subtraction
- conditions

Example:

```csharp
class AddExpression : Expression
{
    private Expression left;
    private Expression right;

    public AddExpression(Expression left, Expression right)
    {
        this.left = left;
        this.right = right;
    }

    public override int Interpret()
    {
        return left.Interpret() + right.Interpret();
    }
}
```

---

## 4. Client

Builds and evaluates expressions.

Example:

```csharp
Expression five = new NumberExpression(5);
Expression three = new NumberExpression(3);

Expression addition = new AddExpression(five, three);

Console.WriteLine(addition.Interpret());
```

---

# Implementation in This Project

| Component | Class |
|---|---|
| Abstract Expression | `Expression` |
| Terminal Expression | `NumberExpression` |
| Non-Terminal Expression | `AddExpression` |
| Client | `Program.cs` |

---

# Expression Tree Structure

```text
        AddExpression
           /      \
NumberExpression  NumberExpression
       (5)               (3)
```

---

# Request Flow

```text
AddExpression
   ↓
Interpret Left Expression
   ↓
Interpret Right Expression
   ↓
Combine Results
```

---

# Example Output

```text
8
```

---

# Advantages

- Easy to extend grammar
- Follows Open/Closed Principle
- Good for rule engines and parsers
- Improves grammar organization
- Makes expression trees manageable

---

# Disadvantages

- Can become very complex for large grammars
- Many classes may be required
- Difficult to maintain large interpreters
- Recursive structures may affect readability

---

# When to Use

Use Interpreter Pattern when:

```text
You need to interpret expressions

You want to build small scripting languages

You need rule engines

You need expression evaluation systems

You want to represent grammar as objects
```

---

# Real Industry Use Cases

## SQL Query Parsers

```text
SELECT * FROM Users WHERE Age > 18
```

Database systems interpret:
- SELECT
- WHERE
- conditions
- operators

---

## Game Rule Engines

```text
IF health < 20
THEN use potion
```

Game engine interprets gameplay rules.

---

## AI Prompt Processing

```text
Summarize this document
```

AI systems interpret:
- intent
- action
- target

---

## Automation Frameworks

```text
IF browser == Chrome
THEN run test
```

Automation systems interpret execution rules.

---

## Mathematical Expression Evaluators

```text
5 + 3 - 2
```

Expressions are interpreted recursively.

---

# Learning Notes

Interpreter Pattern works heavily with:

- Recursive structures
- Expression trees
- Grammar rules
- Parsing systems

Each expression object:
- Knows how to interpret itself
- Can combine with other expressions
- Forms a tree structure

This pattern is closely related to:

- Compiler Design
- Abstract Syntax Trees (AST)
- Rule Engines
- Parsers

---

# Terminal vs Non-Terminal Expressions

| Type | Purpose |
|---|---|
| Terminal Expression | Basic values or variables |
| Non-Terminal Expression | Complex grammar operations |

Example:

```text
5 → Terminal Expression

5 + 3 → Non-Terminal Expression
```

---

# Difference Between Behavioral Patterns

| Pattern | Focus |
|---|---|
| Command | Encapsulate actions |
| Chain of Responsibility | Request pipelines |
| Interpreter | Grammar and expression evaluation |

---

# Abstract Syntax Tree (AST)

Interpreter Pattern often creates tree structures like:

```text
        -
       / \
      +   2
     / \
    5   3
```

Each node interprets itself recursively.

This concept is heavily used in:
- compilers
- scripting engines
- parsers
- AI systems

---

# Summary

The Interpreter Pattern is useful for:

- Rule engines
- Expression evaluators
- Scripting systems
- Game logic systems
- Automation rules
- AI processing pipelines

It is one of the foundational patterns behind:
- parsers
- compilers
- interpreters
- domain specific languages (DSLs)

The pattern becomes especially powerful when working with:
- recursive logic
- grammar trees
- structured expressions
- dynamic rule evaluation