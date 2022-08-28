var k,i:longint;
    t:qword;
///////////////////////////////////////
begin
assign(output,'2mukduk.out');rewrite(output);
for k := 1 to 29 do
    begin
    t := 1;
    for i := 1 to k do
        t := (t * 2) mod k;
    writeln(t mod k);
    end;
end.