class AuthHandler: Handler
{
    public override void Handle(string request)
    {
        Console.WriteLine("Authentication Checked");

        next?.Handle(request);
    }
}