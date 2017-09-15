bool search(int value, int values[], int n)
{
    if (n < 0)
    {
        printf("Needle must be a positive value\n");
        return 1;
    }

    int i;

    for (i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return value;
        }
    }
    return false;
}