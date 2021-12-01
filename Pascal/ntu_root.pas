var a,b,d,i,test,tests:longint;
    testcases:array[1..100000000] of longint;

begin
readln(tests);
for test:=1 to tests do
    readln(testcases[test]);
for test:=1 to tests do
    begin
    a:=testcases[test];
    i:=2;
    b:=1;
    while sqr(i)<=a do
        begin
        while (a mod sqr(i)=0) do
            begin
            b:=b*i;
            a:=a div sqr(i);
            end;
        i:=i+1;
        end;
    writeln(b,' ',a);
    end;
end.