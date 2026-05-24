class Program
{
    static void Main()
    {
        var auth = new AuthHandler();
        var validation = new ValidationHandler();
        var business = new BusinessHandler();

        auth.SetNext(validation);
        validation.SetNext(business);

        auth.Handle("Create Order");
    }
}