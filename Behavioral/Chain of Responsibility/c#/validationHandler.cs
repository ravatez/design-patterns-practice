class ValidationsHandler : Handler
{
    public override void Handle(string request)
    {
        Console.WriteLine("Validations Checked");

        next?.Handle(request);
    }
}