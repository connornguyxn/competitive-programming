procedure init_sieve();
    var i,j:longint;
    /////////////////
    begin
    fillchar(isprime,sizeof(isprime),true);
    isprime[1] := false;
    i := 2;
    while (i <= trunc(sqrt(sizeof(isprime)))) do
        begin
        while (not isprime[i]) do
            i := i + 1;
        for j := 2 to (sizeof(isprime) div i) do
            isprime[i * j] := false;
        i := i + 1;
        end;
    end;