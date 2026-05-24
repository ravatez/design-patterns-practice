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