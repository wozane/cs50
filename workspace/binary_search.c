bool search(int value, int values[], int n)
{
    int first_n, middle_n, last_n;

    values += n;
    first_n = 0;
    last_n = values[n - 1];
    middle_n = (first_n + last_n) / 2;

    while (values[n] > 0)
    {
        if (values[middle_n] == value)
        {
            return 0;
        }
        else if (values[middle_n] < value)
        {
            first_n = middle_n + 1;
        }
        else
            last_n = middle_n - 1;

        middle_n = (first_n + last_n) / 2;
    }
    return 1;

    if (n < 0)
    {
        printf("Needle must be a positive value\n");
        return 1;
    }
}