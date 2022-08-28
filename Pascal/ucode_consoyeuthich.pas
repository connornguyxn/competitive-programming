var list:array[1..100000000] of longint;
    i, j, pairCount, listLength:longint;

begin
readln(listLength);
for i:=1 to listLength do
    readln(list[i]);
for i:=1 to listLength-1 do
    for j:=i+1 to listLength do
        if ((list[i]-list[j]) mod 200 = 0) then
            pairCount := pairCount + 1;
writeln(pairCount);
end.