var n,i,k,test,tests,mx:longint;
    fib:array[0..150] of ansistring;
///////////////////////////////
function count(a:ansistring):longint;
    begin
    count := 0;
    while (pos('a',a) <> 0) do
        begin
        count := count + 1;
        delete(a,pos('a',a),1);
        end;
    end;
//////////////////////////////////
begin
readln(tests);
fib[0] := 'a';
fib[1] := 'b';
mx := 1;
for test:=1 to tests do
    begin
    readln(n,k);
    if (n > mx) then
        begin
        for i:=(mx + 1) to n do
            begin
            fib[i] := fib[i - 2] + fib[i - 1];
            end;
        end;
    writeln(count(copy(fib[n],1,k)));
    end;
end.