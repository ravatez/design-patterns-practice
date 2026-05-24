# Chain of Responsibility Design Pattern (C#)

## Overview

The **Chain of Responsibility Pattern** is a **behavioral design pattern** that allows a request to pass through a chain of handlers.

Each handler decides:

- Whether it can process the request
- Or pass the request to the next handler in the chain

This pattern helps in building flexible and extensible processing pipelines.

---

## Real World Example

Think of an **HTTP Request Pipeline** in web applications.

A request passes through multiple stages:

- Authentication
- Authorization
- Validation
- Logging
- Business Logic

Each middleware processes the request and forwards it to the next middleware.

### Request → Auth → Validation → Logging → Business Logic

---

## Structure of Chain of Responsibility Pattern

There are **3 main components**:

### 1. Handler (Abstract/Base Class)

Defines:
- Reference to next handler
- Request handling method

Example:
```
abstract class Handler
{
    protected Handler next;

    public void SetNext(Handler nextHandler)
    {
        next = nextHandler;
    }

    public abstract void Handle(string request);
}
```
### 2. Concrete Handlers
These handlers perform actual processing.

Example:
```
class AuthHandler : Handler
{
    public override void Handle(string request)
    {
        Console.WriteLine("Authentication checked");

        next?.Handle(request);
    }
}
```
Another Example:
```
class ValidationHandler : Handler
{
    public override void Handle(string request)
    {
        Console.WriteLine("Validation checked");

        next?.Handle(request);
    }
}
```
### 3. Client

Creates and connects the chain.

Example:
```
var auth = new AuthHandler();
var validation = new ValidationHandler();
var business = new BusinessHandler();

auth.SetNext(validation);
validation.SetNext(business);

auth.Handle("Create Order");
```
## Implementation in This Project

| Component | Class |
|---|---|
| Abstract Handler | `Handler` |
| Concrete Handler | `AuthHandler` |
| Concrete Handler | `ValidationHandler` |
| Concrete Handler | `BusinessHandler` |
| Client | `Program.cs` |

---

## Request Flow

```text
Request
   ↓
AuthHandler
   ↓
ValidationHandler
   ↓
BusinessHandler
```

Each handler:

- Processes part of the request
- Passes control to next handler

---

## Example Output

```text
Authentication checked
Validation checked
Business logic executed
```

---

## Advantages

- Decouples sender and receiver
- Easy to add new handlers
- Improves flexibility
- Follows Single Responsibility Principle
- Supports dynamic request pipelines

---

## Disadvantages

- Can increase number of classes
- Debugging request flow can become difficult
- No guarantee request will always be handled

---

## When to Use

Use Chain of Responsibility Pattern when:

```text
Multiple objects can handle a request

Request processing order matters

You want flexible processing pipelines

You want to avoid large if-else or switch statements

You want modular validation or middleware systems
```

---

## Real Industry Use Cases

### ASP.NET Middleware Pipeline

```text
Request
   ↓
Authentication
   ↓
Authorization
   ↓
Routing
   ↓
Controller
```

---

### QA Automation Framework

```text
Test Request
   ↓
Environment Validation
   ↓
Data Setup
   ↓
Execution
   ↓
Reporting
```

---

### Game Event Processing

```text
Input
   ↓
UI Handler
   ↓
Gameplay Handler
   ↓
Debug Handler
```

---

## Learning Notes

Each handler should focus on a single responsibility.

The sender should not know which handler processes the request.

Handlers can:

- Process the request
- Modify the request
- Stop the request
- Pass the request forward

This makes the system:

- Flexible
- Scalable
- Easier to extend

---

## Summary

The Chain of Responsibility Pattern is highly useful in:

- Middleware systems
- Validation pipelines
- Logging systems
- QA automation frameworks
- Game engines
- AI processing pipelines

It is one of the most commonly used patterns in scalable enterprise architectures.