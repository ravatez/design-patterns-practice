using System;

abstract class Handler
{
    protected Handler next;
    
    public void SetNext(Handler nextHandler)
    {
        next = nextHandler;
    }

    public abstract void Handle(string request);
}